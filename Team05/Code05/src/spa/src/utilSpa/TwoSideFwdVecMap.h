#pragma once
#define SPA_TWO_SIDE_FWD_VEC_MAP_H

// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/8ef1cf87-56eb-45bd-b91f-fbf309b86d98
#include <iostream>
#include <set>
#include <optional>
#include <memory>

/**
 * @brief A double-sided map that allows bidirectional mapping between keys and values.
 * Used for tables in the PKB such as ParentTable
 *
 * @tparam A The type of the keys. Needs to be hashable.
 * @tparam B The type of the values. Needs to be hashable.
 */
template<typename A, typename B>
class TwoSideFwdVecMap {
private:
    std::unordered_map<A, std::set<std::shared_ptr<B>>> forwardMap;
    std::unordered_map<B, A> backwardMap;

public:
    TwoSideFwdVecMap();

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
     * @return The value associated with the key. If not found, returns an empty vector.
     */
    std::vector<B> getValues(A key);

    /**
     * @brief Retrieve the key associated with a value.
     *
     * @param value The value.
     * @return The key associated with the value.
     */
    std::optional<A> getKey(B value);

    /**
     * @brief Check if a key exists in the map.
     *
     * @param key The key to check.
     * @return True if the key exists, false otherwise.
     */
    bool containsKey(A key);

    /**
     * @brief Check if a value exists in the map.
     *
     * @param value The value to check.
     * @return True if the value exists, false otherwise.
     */
    bool containsValue(B value);

    [[nodiscard]] int size() const;
};

// ai-gen end