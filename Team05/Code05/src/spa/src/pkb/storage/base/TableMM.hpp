#pragma once
#define SPA_TABLEMM_H

#include "TwoSideMapManyMany.hpp"

/**
 * @brief Implements the logic for tables that support one-to-one relations.
 * Used for entity tables in the PKB
 * Implemented using unordered_maps for speed.
 *
 * @tparam A The type of the keys. Needs to be hashable.
 * @tparam B The type of the values. Needs to be hashable.
 */
template<typename A, typename B>
class TableMM {
private:
    TwoSideMapManyMany<A, B> map;
public:
    TableMM();

    // Adds an association between a key and a value. Appends to existing associations.
    bool add(A key, B value);

    // Checks if the key is associated with the value.
    bool hasPair(A key, B value);

    // Checks if the key is stored in the table.
    bool hasKey(A key);

    // Checks if the value is stored in the table.
    bool hasValue(B value);

    // Checks if the value has an associated key.
    bool hasAssociatedKey(B value);

    // Checks if the key has an associated value.
    bool hasAssociatedValue(A key);

    // Returns a vector of keys that are associated with the value.
    // Returns empty vector if not found
    std::vector<A> getKeys(B value);

    // Returns a vector of values that are associated with the key.
    // Returns empty vector if not found
    std::vector<B> getValues(A key);

    // Returns the total number of relations in the table.
    [[nodiscard]] int size() const;
};

// ---------------------------- Implementation ----------------------------

template<typename A, typename B>
TableMM<A, B>::TableMM() {};

// private utility function for this file
template<typename C>
bool findInVector(std::vector<C> vec, C target) {
    return std::find(vec.begin(), vec.end(), target) != vec.end();
}

template<typename A, typename B>
bool TableMM<A, B>::add(A key, B value) {
    if (hasPair(key, value)) {
        return false;
    }
    return map.insert(key, value);
}

template<typename A, typename B>
bool TableMM<A, B>::hasPair(A key, B value) {
    if (!map.containsKey(key)
        || !map.containsValue(value)) {
        return false;
    }
    // find key in associated keys of this value
    // find value in associated values of this key
    return findInVector(map.getKeys(value), key)
        && findInVector(map.getValues(key), value);
    // TODO: Discuss and compare with yew meng's solution in FollowsTTable.cpp
}

template<typename A, typename B>
bool TableMM<A, B>::hasKey(A key) {
    return map.containsKey(key);
}

template<typename A, typename B>
bool TableMM<A, B>::hasValue(B value) {
    return map.containsValue(value);
}

template<typename A, typename B>
bool TableMM<A, B>::hasAssociatedKey(B value) {
    return findInVector(map.getKey(value), value);
}

template<typename A, typename B>
bool TableMM<A, B>::hasAssociatedValue(A key) {
    return findInVector(map.getValue(key), key);
}

template<typename A, typename B>
std::vector<A> TableMM<A, B>::getKeys(B value) {
    return map.getKeys(value);
}

template<typename A, typename B>
std::vector<B> TableMM<A, B>::getValues(A key) {
    return map.getValues(key);
}

template<typename A, typename B>
[[nodiscard]] int TableMM<A, B>::size() const {
    // assumes that the number of relations in the fwd map ==
    // the number of relations in the bkwd map.
    // TODO: is this true?
    return map.size();
}
