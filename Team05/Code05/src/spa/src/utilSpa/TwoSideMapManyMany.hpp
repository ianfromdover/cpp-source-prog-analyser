#pragma once
#define SPA_TWO_SIDE_MAP_TWO_SET_H

#include <iostream>
#include <set>
#include <unordered_map>
#include <memory>
#include <optional>

/**
 * @brief A double-sided map that allows bidirectional mapping between keys and values.
 * For Many-Many relations
 * Used for transitive tables in the PKB such as ParentTTable
 * Also Used for transitive tables in the PKB such as ParentTTable
 *
 * @tparam A The type of the keys.
 * @tparam B The type of the values.
 */
template<typename A, typename B>
class TwoSideMapManyMany {
private:
    std::unordered_map<A, std::set<std::shared_ptr<B>>> forwardMap; // TODO: print out addr to see if ptr is pointing to the key objects
    std::unordered_map<B, std::set<std::shared_ptr<A>>> backwardMap; // TODO: change to weak_ptr to prevent memory leak

public:
    TwoSideMapManyMany();

    /**
     * @brief Insert a mapping from key to value.
     *
     * @param key The key.
     * @param value The value.
     */
    bool insert(A key, B value);

    /**
     * @brief Retrieve the value associated with a key.
     *
     * @param key The key.
     * @return The value associated with the key.
     */
    std::vector<B> getValues(A key);

    /**
     * @brief Retrieve the key associated with a value.
     *
     * @param value The value.
     * @return The key associated with the value.
     */
    std::vector<A> getKeys(B value);

    /**
     * @brief Check if a key exists in the map.
     *
     * @param key The key to check.
     * @return True if the key exists, false otherwise.
     */
    bool containsKey(const A key);

    /**
     * @brief Check if a value exists in the map.
     *
     * @param value The value to check.
     * @return True if the value exists, false otherwise.
     */
    bool containsValue(const B value);

    /**
     * Check if a pair exists in the map.
     *
     * @param key
     * @param value
     * @return
     */
    bool containsPair(A key, B value);

    /**
     * @brief Get the size of the map.
     * @return The size of the map.
     */
    [[nodiscard]] int size () const;
};

// ai-gen end

// ---------------------------- Implementation ----------------------------

template<typename A, typename B>
TwoSideMapManyMany<A, B>::TwoSideMapManyMany() {};

template<typename A, typename B>
bool TwoSideMapManyMany<A, B>::insert(const A key, const B value) {
    // ai-gen start (copilot, 0, e)
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
std::vector<B> TwoSideMapManyMany<A, B>::getValues(A key) {
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
std::vector<A> TwoSideMapManyMany<A, B>::getKeys(B value) {
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
bool TwoSideMapManyMany<A, B>::containsKey(const A key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideMapManyMany<A, B>::containsValue(const B value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
bool TwoSideMapManyMany<A, B>::containsPair(A key, B value) {
    if (!containsKey(key) || !containsValue(value)) {
        return false;
    }

    // eg. does this contains pair(1, "x") in my StmtNo-VarName table?
    std::vector<B> values = getValues(key); // eg. line 1 has vars x, y, z
    for (const B& v : values) {
        if (v == value) {
            return true;
        }
    }
    return false;
}

template<typename A, typename B>
int TwoSideMapManyMany<A, B>::size() const {
    int totalSize = 0;
    for (const auto& pair : forwardMap) {
        totalSize += pair.second.size();
    }
    return totalSize;
}
