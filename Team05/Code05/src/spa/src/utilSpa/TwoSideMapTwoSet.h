#pragma once
#define SPA_TWO_SIDE_MAP_TWO_SET_H

#include <iostream>
#include <set>
#include <unordered_map>
#include <memory>
#include <optional>

/**
 * @brief A double-sided map that allows bidirectional mapping between keys and values.
 * Used for transitive tables in the PKB such as ParentTTable
 * Also Used for transitive tables in the PKB such as ParentTTable
 *
 * @tparam A The type of the keys.
 * @tparam B The type of the values.
 */
template<typename A, typename B>
class TwoSideMapTwoSet {
private:
    std::unordered_map<A, std::set<std::shared_ptr<B>>> forwardMap; // TODO: print out addr to see if ptr is pointing to the key objects
    std::unordered_map<B, std::set<std::shared_ptr<A>>> backwardMap; // TODO: change to weak_ptr to prevent memory leak

public:
    TwoSideMapTwoSet();

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