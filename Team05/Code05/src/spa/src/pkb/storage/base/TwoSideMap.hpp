#pragma once
#define SPA_TWO_SIDE_MAP_TWO_SET_H

#include <iostream>
#include <sstream> // for convertToString
#include <set>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include <type_traits>

/**
 * @brief A double-sided map for O(1) retrieval of elements that have Many-Many relations.
 * Used for transitive tables in the PKB such as ParentTTable
 *
 * @tparam A The type of the keys.
 * @tparam B The type of the values.
 */
template<typename A, typename B>
class TwoSideMap {
private:
    std::unordered_map<A, std::set<std::shared_ptr<B>>> forwardMap; // TODO: print out addr to see if ptr is pointing to the key objects
    std::unordered_map<B, std::set<std::shared_ptr<A>>> backwardMap; // TODO: change to weak_ptr to prevent memory leak

    // Check if a key exists in the forwardMap.
    bool containsKey(A key);

    // Check if a value exists in the backwardMap.
    bool containsValue(B value);

    // Check if a pair exists in the map.
    bool containsPair(A key, B value);

    // Combines pairs in the forward map of type string into a 2-column table in the result
    void add(const std::shared_ptr<std::vector<std::vector<std::string>>>& result,
             const std::string& key, std::set<std::shared_ptr<std::string>>& strPtrSet);

    // Combines pairs in the forward map of any type into a 2-column table in the result
    void addAndConvert(const std::shared_ptr<std::vector<std::vector<std::string>>>& result,
                       const std::string& key, std::set<std::shared_ptr<B>>& tPtrSet);

public:
    TwoSideMap();

    /**
     * @brief Insert a mapping from key to value. If the mapping already exists, nothing is done.
     * @returns True if the mapping is inserted, false if the mapping already exists.
     */
    bool insert(A key, B value);

    /**
     * @brief Retrieve the values associated using its key.
     * @return The value associated with the key. Returns an empty vector if the key does not exist.
     */
    std::vector<B> getValues(A key);

    /**
     * @brief Retrieve the keys associated using its value.
     * @return The key associated with the value. Returns an empty vector if the value does not exist.
     */
    std::vector<A> getKeys(B value);

    /**
     * @return Returns a 2-column table of all the key-value pairs in the map as strings
     */
    std::vector<std::vector<std::string>> getAll();
};

// ---------------------------- Implementation ----------------------------

template<typename A, typename B>
TwoSideMap<A, B>::TwoSideMap() {};

template<typename A, typename B>
bool TwoSideMap<A, B>::containsKey(const A key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideMap<A, B>::containsValue(const B value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
bool TwoSideMap<A, B>::containsPair(A key, B value) {
    // check if the key and value are in the maps
    if (!containsKey(key) || !containsValue(value)) {
        return false;
    }

    // check if there are values associated with the key and value
    const std::vector<A>& keys = getKeys(value);
    const std::vector<B>& values = getValues(key);
    if (keys.empty() || values.empty()) {
        return false;
    }

    // eg. does this contains pair(1, "x") in my StmtNo-VarName table?
    // line 1 associated with  [x, y, z], find x
    // var "x" appears on line [1, 2, 3], find 1
    bool keyHasThisValue = std::find(values.begin(), values.end(), value) != values.end();
    bool valueHasThisKey = std::find(keys.begin(), keys.end(), key) != keys.end();
    return keyHasThisValue && valueHasThisKey;
}

// helper for getAll
void add(const std::shared_ptr<std::vector<std::vector<std::string>>>& result,
         const std::string& key, std::set<std::shared_ptr<std::string>>& strPtrSet) {
    for (const auto& ptr : strPtrSet) {
        result->push_back({key, *ptr});
    }
}

// helper for getAll
// assumes that TwoSideMap is only used on primitives
template<typename B>
void addAndConvert(const std::shared_ptr<std::vector<std::vector<std::string>>>& result,
                   const std::string& key, std::set<std::shared_ptr<B>>& tPtrSet) {
    for (const auto& ptr : tPtrSet) {
        std::string item = std::to_string(*ptr); // T needs to have an overloaded std::to_string defined
        result->push_back({key, item});
    }
}

template<typename A, typename B>
bool TwoSideMap<A, B>::insert(const A key, const B value) {
    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    if (containsPair(key, value)) {
        std::cout << "Warning: TwoSideMapTwoSet-insert: Pair already exists" << std::endl;
        return false;
    }
    // ai-gen end
    auto kPtr = std::make_shared<A>(key);
    auto vPtr = std::make_shared<B>(value);

    // if key does not exist, create a new set with the value
    if (!containsKey(key)) {
        forwardMap[*kPtr] = {vPtr};
    } else {
        forwardMap[*kPtr].insert(vPtr);
    }

    if (!containsValue(value)) {
        backwardMap[*vPtr] = {kPtr};
    } else {
        backwardMap[*vPtr].insert(kPtr);
    }
    return true;
}

template<typename A, typename B>
std::vector<B> TwoSideMap<A, B>::getValues(A key) {
    std::vector<B> result;
    if (!containsKey(key)) {
        std::cout << "Warning: TwoSideMapTwoSet-getValues: Key not found in forward map" << std::endl;
        // TODO: make my own GetException that inherits from BaseException
        return result;
    }
    for (auto ptr : forwardMap[key]) {
        result.push_back(*ptr);
    }
    return result;
}

template<typename A, typename B>
std::vector<A> TwoSideMap<A, B>::getKeys(B value) {
    std::vector<A> result;
    if (!containsValue(value)) {
        std::cout << "Warning: TwoSideMapTwoSet-getKeys: Value not found in backward map" << std::endl;
        // TODO: make my own GetException that inherits from BaseException
        return result;
    }
    for (auto ptr : backwardMap[value]) {
        result.push_back(*ptr);
    }
    return result;
}

template<typename A, typename B>
std::vector<std::vector<std::string>> TwoSideMap<A, B>::getAll() {
    auto result = make_shared<std::vector<std::vector<std::string>>>();

    // check if A is string, B is string
    bool AStrBStr = std::is_same_v<A, std::string> && std::is_same_v<B, std::string>;
    bool AStrBNotStr = !std::is_same_v<B, std::string>;
    bool ANotStrBStr = !std::is_same_v<A, std::string>;

    if (AStrBStr) {
        for (const auto& pair : forwardMap) {
            add(result, pair.first, pair.second);
        }
    } else if (AStrBNotStr) {
        for (const auto& pair : forwardMap) {
            addAndConvert(result, pair.first, pair.second);
        }
    } else if (ANotStrBStr) {
        for (const auto& pair : forwardMap) {
            std::string key = std::to_string(pair.first);
            add(result, key, pair.second);
        }
    } else {
        // A and B are not strings
        for (const auto& pair : forwardMap) {
            std::string key = std::to_string(pair.first);
            addAndConvert(result, key, pair.second);
        }
    }
    return *result;
}
