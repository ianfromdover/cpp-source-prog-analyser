#pragma once
#define SPA_TWO_SIDE_MAP_TWO_SET_H

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include "pkb/exceptions/PkbException.h"
#include "common/SpaTypes.h"

/**
 * @brief A double-sided map for O(1) retrieval of elements that have Many-Many relations.
 * Used for tables in the PKB. Does not support storage of classes, structs or pointers,
 * and behaviour is not tested for T, as they need to have an overloaded std::to_string defined.
 *
 * @tparam A The type of the keys. Can only be int or std::string.
 * @tparam B The type of the values. Can only be int or std::string.
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

    std::shared_ptr<Table> getCol(std::unordered_map<int, std::set<std::shared_ptr<B>>> map);
    std::shared_ptr<Table> getColForStr(std::unordered_map<std::string, std::set<std::shared_ptr<std::string>>> map);
    void addPtrSetToResult(const set<shared_ptr<int>>& setOfPtr, shared_ptr<Table>& result, int curr);
    void addStrPtrSetToResult(const set<shared_ptr<std::string>>& setOfPtr, shared_ptr<Table>& result, std::string curr);

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
     * @return Returns a 1-column table of all the keys in the map as strings
     * Call the appropriate function based on whether A and B are strings
     */
    Table getFirstColA();
    Table getFirstColStr(); // call this if typeof(A) is a string
    Table getSecondColB();
    Table getSecondColStr(); // call this if typeof(B) is a string

    /**
     * @return Returns a 2-column table of all the key-value pairs in the map as strings
     * Call the appropriate function based on whether A and B are strings
     */
    Table getAllForStrStr();
    Table getAllForStrB(); // eg. call this if typeof(A) is a string and B is not
    Table getAllForAStr();
    Table getAllForAB();
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

    // e.g. does this contains pair(1, "x") in my StmtNo-VarName table?
    // line 1 associated with  [x, y, z], find x
    // var "x" appears on line [1, 2, 3], find 1
    bool keyHasThisValue = std::find(values.begin(), values.end(), value) != values.end();
    bool valueHasThisKey = std::find(keys.begin(), keys.end(), key) != keys.end();
    return keyHasThisValue && valueHasThisKey;
}

template<typename A, typename B>
// restricted to int because other types will not be used in the scope of SPA
shared_ptr<Table> TwoSideMap<A, B>::getCol(std::unordered_map<int, std::set<std::shared_ptr<B>>> map) {
    auto result = std::make_shared<Table>();
    try {
        for (auto& pair : map) {
            result->push_back({to_string(pair.first)});
        }
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
    return result;
}

template<typename A, typename B>
shared_ptr<Table> TwoSideMap<A, B>::getColForStr(std::unordered_map<std::string, std::set<std::shared_ptr<std::string>>> map) {
    auto result = std::make_shared<Table>();
    try {
        for (auto& pair : map) {
            result->push_back({pair.first});
        }
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
    return result;
}

template<typename A, typename B>
bool TwoSideMap<A, B>::insert(const A key, const B value) {
    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    if (containsPair(key, value)) {
        return false;
    }
    // ai-gen end
    auto kPtr = std::make_shared<A>(key);
    auto vPtr = std::make_shared<B>(value);

    // if key does not exist, create a new set with the value
    try {
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
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
    return true;
}

template<typename A, typename B>
std::vector<B> TwoSideMap<A, B>::getValues(A key) {
    std::vector<B> result;
    if (!containsKey(key)) {
        return result;
    }
    try {
        for (auto ptr : forwardMap[key]) {
            result.push_back(*ptr);
        }
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
    return result;
}

template<typename A, typename B>
std::vector<A> TwoSideMap<A, B>::getKeys(B value) {
    std::vector<A> result;
    if (!containsValue(value)) {
        return result;
    }
    try {
        for (auto ptr : backwardMap[value]) {
            result.push_back(*ptr);
        }
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
    return result;
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getFirstColA() {
    return *(getCol(forwardMap));
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getFirstColStr() {
    return *(getColForStr(forwardMap));
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getSecondColB() {
    return *(getCol(backwardMap));
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getSecondColStr() {
    return *(getColForStr(backwardMap));
}

/*
 * error: non-constant-expression cannot be narrowed from type 'int' to 'std::vector<std::string>::size_type' (aka 'unsigned long') in initializer list
            result->push_back({intCurr, item});

template<typename A, typename B>
void TwoSideMap<A, B>::addPtrSetToResult(const set<shared_ptr<int>>& setOfPtr, shared_ptr<Table>& result, int intCurr) {
    try {
        for (auto& ptr : setOfPtr) {
            std::string item = std::to_string(*ptr);
            result->push_back({intCurr, item}); // intCurr is causing an error
        }
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
}
 */

template<typename A, typename B>
void TwoSideMap<A, B>::addStrPtrSetToResult(const set<shared_ptr<std::string>>& setOfPtr, shared_ptr<Table>& result, std::string curr) {
    try {
        for (auto &ptr: setOfPtr) {
            result->push_back({curr, *ptr});
        }
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getAllForStrStr() {
    auto result = std::make_shared<Table>();
    for (auto &pair: forwardMap) {
        /*
        for (auto &ptr: pair.second) {
            result->push_back({pair.first, *ptr});
        }
        // this replacement needs testing
         */
        addStrPtrSetToResult(pair.second, result, pair.first);
    }
    return *result;
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getAllForStrB() {
    auto result = std::make_shared<Table>();
    for (auto& pair : forwardMap) {
        for (auto& ptr : pair.second) {
            std::string item = std::to_string(*ptr);
            result->push_back({pair.first, item});
        }
        // strange bug
        // addPtrSetToResult(pair.second, result, pair.first);
    }
    return *result;
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getAllForAStr() {
    auto result = std::make_shared<Table>();
    for (auto& pair : forwardMap) {
        /*
        std::string key = std::to_string(pair.first);
        for (auto& ptr : pair.second) {
            result->push_back({key, *ptr});
        }
         */
        // this replacement needs testing
        addStrPtrSetToResult(pair.second, result, to_string(pair.first));
    }
    return *result;
}

template<typename A, typename B>
Table TwoSideMap<A, B>::getAllForAB() {
    auto result = std::make_shared<Table>();
    for (auto& pair : forwardMap) {
        std::string key = std::to_string(pair.first);
        for (auto& ptr : pair.second) {
            std::string item = std::to_string(*ptr); // T needs to have an overloaded std::to_string defined
            result->push_back({key, item});
        }
        // addPtrSetToResult(pair.second, result, to_string(pair.first));
    }
    return *result;
}
