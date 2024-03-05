#pragma once
#define SPA_TABLEOO_H

#include "TwoSideMapOneOne.hpp"

/**
 * @brief Implements the logic for tables that support one-to-one relations.
 * Used for entity tables in the PKB such as VarTable
 *
 * @tparam A The type of the keys. Needs to be hashable.
 * @tparam B The type of the values. Needs to be hashable.
 */
template<typename A, typename B>
class TableOO {
private:
    TwoSideMapOneOne<A, B> map;
public:
    TableOO();

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

    // Returns the associated value of a key wrapped in an optional.
    // Returns an optional of the fallback if not found.
    // TODO: should it just return the fallback? does it violate return type?
    std::optional<B> getValue(A key, B fallback);

    [[nodiscard]] int size() const;
};

// ---------------------------- Implementation ----------------------------

template<typename A, typename B>
TableOO<A, B>::TableOO() {};

template<typename A, typename B>
bool TableOO<A, B>::add(A key, B value) {
    if (hasPair(key, value)) {
        return false;
    }
    return map.insert(key, value);
}

template<typename A, typename B>
bool TableOO<A, B>::hasPair(A key, B value) {
    if (!map.containsKey(key)
        || !map.containsValue(value)) {
        return false;
    }
    return map.getKey(value).value() == key;
}

template<typename A, typename B>
bool TableOO<A, B>::hasKey(A key) {
    return map.containsKey(key);
}

template<typename A, typename B>
bool TableOO<A, B>::hasValue(B value) {
    return map.containsValue(value);
}

template<typename A, typename B>
bool TableOO<A, B>::hasAssociatedKey(B value) {
    return map.getKey(value).has_value();
}

template<typename A, typename B>
bool TableOO<A, B>::hasAssociatedValue(A key) {
    return map.getValue(key).has_value();
}

template<typename A, typename B>
std::optional<A> TableOO<A, B>::getKey(B value, A fallback) {
    auto k = map.getKey(value);
    if (!k.has_value()) {
        return std::make_optional<A>(fallback); // TODO: should i do this? how do i check?
        // return fallback;
    }
    return k.value();
}

template<typename A, typename B>
std::optional<B> TableOO<A, B>::getValue(A key, B fallback) {
    auto v = map.getValue(key);
    if (!v.has_value()) {
        return std::make_optional<B>(fallback);
        // return fallback;
    }
    return v.value();
}

template<typename A, typename B>
[[nodiscard]] int TableOO<A, B>::size() const {
    return map.size();
}
