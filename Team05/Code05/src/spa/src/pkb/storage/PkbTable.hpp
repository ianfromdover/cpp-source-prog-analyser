#pragma once
#define SPA_PKBTABLE_H

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
class PkbTable {
private:
    std::unordered_map<A, std::set<std::shared_ptr<B>>> forwardMap; // TODO: print out addr to see if ptr is pointing to the key objects
    std::unordered_map<B, std::set<std::shared_ptr<A>>> backwardMap; // TODO: change to weak_ptr to prevent memory leak

    // Check if a key exists in the forwardMap.
    bool containsKey(A key);

    // Check if a value exists in the backwardMap.
    bool containsValue(B value);

    // Check if a pair exists in the map.
    bool containsPair(A key, B value);

    // Convert a map into a table
    std::shared_ptr<Table> makeTable(bool isFwdMap);

public:
    PkbTable() = default;
    ~PkbTable() = default;

    /**
     * @brief Insert a mapping from key to value. If the mapping already exists, nothing is done.
     * @returns True if the mapping is inserted, false if the mapping already exists.
     */
    bool add(const A& key, const B& value);

    /**
     * @brief Retrieve the values associated using its key.
     * @return The value associated with the key. Returns an empty vector if the key does not exist.
     */
    std::vector<B> getRelatedValues(A key);

    /**
     * @brief Retrieve the keys associated using its value.
     * @return The key associated with the value. Returns an empty vector if the value does not exist.
     */
    std::vector<A> getRelatedKeys(B value);

    /**
     * @return Returns a 1-column table of all the keys in the map as strings
     */
    Table getAllKeys();
    Table getAllValues();

    /**
     * @return Returns a 2-column table of all the key-value pairs in the map as strings
     */
    Table getAll();
};

// ---------------------------- Implementation ----------------------------
template<typename T>
inline std::string to_string(const T& val) {
    return std::to_string(val);
}

inline std::string to_string(const std::string& str) {
    return str;
}

template<typename A, typename B>
bool PkbTable<A, B>::containsKey(const A key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool PkbTable<A, B>::containsValue(const B value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
bool PkbTable<A, B>::containsPair(A key, B value) {
    // ai-gen start (gpt, 0, e)
    // prompt: https://chat.openai.com/share/aa74c9ed-3538-44b9-9e67-b7ed58d4e913
    // check if the key and value are in the maps
    auto fwdIter = forwardMap.find(key);
    if (fwdIter == forwardMap.end()) {
        return false;
    }

    // directly search for shared_ptr with value in the set
    auto& valSet = fwdIter->second;
    for (const auto& valPtr : valSet) {
        if (*valPtr != value) {
            continue;
        }

        auto bkwdIter = backwardMap.find(value);
        if (bkwdIter == backwardMap.end()) {
            return false; // found value in fwdMap but not in bkwdMap
        }
        auto keySet = bkwdIter->second;
        for (const auto& keyPtr : keySet) {
            if (*keyPtr == key) {
                return true; // found the pair in both directions
            }
        }
    }
    return false;
    // ai-gen end
}

// ai-gen start (gpt, 2, e)
// prompt: https://chat.openai.com/share/4bb3d614-d4ca-4580-ad0e-b664ace5e254
template<typename A, typename B>
std::shared_ptr<Table> PkbTable<A, B>::makeTable(bool isFwdMap) {
    auto result = std::make_shared<Table>();
    try {
        // lambda function
        auto processMap = [&](auto& map) {
            for (auto& pair : map) {
                result->push_back({to_string(pair.first)});
            }
        };

        if (isFwdMap) {
            processMap(forwardMap);
        } else {
            processMap(backwardMap);
        }
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
    return result;
}
// ai-gen end

template<typename A, typename B>
bool PkbTable<A, B>::add(const A& key, const B& value) {
    // ai-gen start (gpt, 0, e)
    // prompt: https://chat.openai.com/share/aa74c9ed-3538-44b9-9e67-b7ed58d4e913
    try {
        if (containsPair(key, value)) {
            return false;
        }

        // directly insert shared_ptr of val into fwdMap
        auto& valSet = forwardMap[key]; // create a new set if key does not exist
        valSet.emplace(std::make_shared<B>(value));

        // directly insert shared_ptr of key into bkwdMap
        auto& keySet = backwardMap[value]; // create a new set if value does not exist
        keySet.emplace(std::make_shared<A>(key));
    } catch (std::exception e) {
        throw PkbException(e.what());
    }
    return true;
    // ai-gen end
}

template<typename A, typename B>
std::vector<B> PkbTable<A, B>::getRelatedValues(A key) {
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
std::vector<A> PkbTable<A, B>::getRelatedKeys(B value) {
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

// ai-gen start (gpt, 2, e)
// prompt: https://chat.openai.com/share/4bb3d614-d4ca-4580-ad0e-b664ace5e254
template<typename A, typename B>
Table PkbTable<A, B>::getAllKeys() {
    return *makeTable(true);
}

template<typename A, typename B>
Table PkbTable<A, B>::getAllValues() {
    return *makeTable(false);
}

template<typename A, typename B>
Table PkbTable<A, B>::getAll() {
    auto result = std::make_shared<Table>();
    for (auto& pair : forwardMap) {
        std::string key = to_string(pair.first);
        for (auto& ptr : pair.second) {
            std::string item = to_string(*ptr);
            result->push_back({key, item});
        }
    }
    return *result;
}
// ai-gen end
