#pragma once
#define SPA_TWO_SIDE_DBL_VEC_MAP_H

#include <iostream>
#include "utilSpa/TwoSideFwdVecMap.h"

/**
 * @brief A double-sided map that allows bidirectional mapping between keys and values.
 * Used for transitive tables in the PKB such as ParentTTable
 *
 * @tparam A The type of the keys.
 * @tparam B The type of the values.
 */
template<typename A, typename B>
class TwoSideDblVecMap {
private:
    // TODO: should the vector be a set to prevent duplicates?
    std::unordered_map<A, std::vector<B>> forwardMap;
    std::unordered_map<B, std::vector<A>> backwardMap;

public:
    TwoSideDblVecMap();
    // TODO: how to construct a new TwoSideDblVecMap from a given TwoSideFedVecMap?
    // used when generating transitive tables (the star table)
    // benefit: faster than inserting one by one, just copy the maps and recurse 1 level
    // TwoSideDblVecMap(const TwoSideFwdVecMap<A, B>& other);

    /**
     * @brief Insert a mapping from key to value.
     *
     * @param key The key.
     * @param value The value.
     */
    void insert(const A& key, const B& value);

    /**
     * @brief Retrieve the value associated with a key.
     *
     * @param key The key.
     * @return The value associated with the key.
     */
    std::vector<B> getValues(const A& key);

    /**
     * @brief Retrieve the key associated with a value.
     *
     * @param value The value.
     * @return The key associated with the value.
     */
    std::vector<A> getKeys(const B& value);

    /**
     * @brief Check if a key exists in the map.
     *
     * @param key The key to check.
     * @return True if the key exists, false otherwise.
     */
    bool containsKey(const A& key);

    /**
     * @brief Check if a value exists in the map.
     *
     * @param value The value to check.
     * @return True if the value exists, false otherwise.
     */
    bool containsValue(const B& value);

    /**
     * @brief Remove a mapping by key.
     *
     * @param key The key to remove.
     */
    void eraseKey(const A& key);

    /**
     * @brief Remove a mapping by value.
     *
     * @param value The value to remove.
     */
    void eraseValue(const B& value);
};

// ai-gen end