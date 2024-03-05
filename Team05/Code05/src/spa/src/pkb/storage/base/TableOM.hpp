#pragma once
#define SPA_TABLEOM_H

#include "TwoSideMapOneMany.hpp"

/**
 * @brief Implements the logic for tables that support one-to-one relations.
 * Used for entity tables in the PKB
 * Implemented using unordered_maps for speed.
 *
 * @tparam A The type of the keys. Needs to be hashable.
 * @tparam B The type of the values. Needs to be hashable.
 */
template<typename A, typename B>
class TableOM {
private:
    TwoSideMapOneMany<A, B> map;
public:
    TableOM();

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

    // Returns the associated key of a value wrapped in an optional.
    // Returns an optional of the fallback if not found.
    // TODO: should it just return the fallback? does it violate return type?
    std::optional<A> getKey(B value, A fallback);

    // Returns a vector of values that are associated with the key.
    // Returns empty vector if not found
    std::vector<B> getValues(A key);

    // Returns the total number of relations in the table.
    [[nodiscard]] int size() const;
};

// ---------------------------- Implementation ----------------------------

template<typename A, typename B>
TableOM<A, B>::TableOM() {};

// private utility function for this file
template<typename C>
bool findInVector(std::vector<C> vec, C target) {
    return std::find(vec.begin(), vec.end(), target) != vec.end();
}

template<typename A, typename B>
bool TableOM<A, B>::add(A key, B value) {
    if (hasPair(key, value)) {
        return false;
    }
    return map.insert(key, value);
}

template<typename A, typename B>
bool TableOM<A, B>::hasPair(A key, B value) {
    if (!map.containsKey(key)
        || !map.containsValue(value)) {
        return false;
    }
    // find value in associated values of this key
    return map.getKey(value).value() == key
        && findInVector(map.getValues(key), value);
    // TODO: Edit from TableMM after comparing with yew meng's solution in FollowsTTable.cpp
}

template<typename A, typename B>
bool TableOM<A, B>::hasKey(A key) {
    return map.containsKey(std::move(key));
}

template<typename A, typename B>
bool TableOM<A, B>::hasValue(B value) {
    return map.containsValue(std::move(value));
}

template<typename A, typename B>
bool TableOM<A, B>::hasAssociatedKey(B value) {
    return findInVector(map.getKey(value), value);
}

template<typename A, typename B>
bool TableOM<A, B>::hasAssociatedValue(A key) {
    return findInVector(map.getValue(key), key);
}

template<typename A, typename B>
std::optional<A> TableOM<A, B>::getKey(B value, A fallback) {
    auto k = map.getKey(value);
    if (!k.has_value()) {
        return std::make_optional<A>(fallback); // TODO: should i do this? how do i check?
        // return fallback;
    }
    return k.value();
}

template<typename A, typename B>
std::vector<B> TableOM<A, B>::getValues(A key) {
    return map.getValues(key);
}

template<typename A, typename B>
[[nodiscard]] int TableOM<A, B>::size() const {
    // assumes that the number of relations in the fwd map ==
    // the number of relations in the bkwd map.
    // TODO: is this true?
    return map.size();
}
