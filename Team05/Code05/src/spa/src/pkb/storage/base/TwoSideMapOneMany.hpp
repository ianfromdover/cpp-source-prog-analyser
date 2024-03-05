#pragma once
#define SPA_TWO_SIDE_MAP_SET_H

// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/8ef1cf87-56eb-45bd-b91f-fbf309b86d98
#include <iostream>
#include <set>
#include <vector>
#include <optional>
#include <memory>
#include <unordered_map>

/**
 * @brief A double-sided map that allows bidirectional mapping between keys and values.
 * For One-Many relations
 * Used for relationship tables in the PKB such as ParentTable
 *
 * @tparam A The type of the keys. Needs to be hashable.
 * @tparam B The type of the values. Needs to be hashable.
 */
template<typename A, typename B>
class TwoSideMapOneMany {
private:
    std::unordered_map<A, std::set<std::shared_ptr<B>>> forwardMap;
    std::unordered_map<B, A> backwardMap;

public:
    TwoSideMapOneMany();

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

// ---------------------------- Implementation ----------------------------

template<typename A, typename B>
TwoSideMapOneMany<A, B>::TwoSideMapOneMany() {};
// ai-gen start(gpt, 2, e)
// prompt: https://chat.openai.com/share/8ef1cf87-56eb-45bd-b91f-fbf309b86d98

template<typename A, typename B>
bool TwoSideMapOneMany<A, B>::insert(A key, B value) {
    if (containsValue(value)) {
        std::cout << "Warning: TwoSideMapSet-insert: Value already exists in backward map" << std::endl;
        // TODO: make my own InsertException that inherits from BaseException
        return false;
    }

    auto kPtr = std::make_shared<A>(key);
    auto vPtr = std::make_shared<B>(value);

    // if key does not exist, create a new set with the value
    if (!containsKey(key)) {
        forwardMap[*kPtr] = {vPtr};
    } else {
        forwardMap[*kPtr].insert(vPtr);
    }

    backwardMap[*vPtr] = key; // TODO: use kPtr in next milestone for better memory management
    return true;
}

template<typename A, typename B>
std::vector<B> TwoSideMapOneMany<A, B>::getValues(A key) {
    std::vector<B> result;
    // guard clause for key not found
    if (!containsKey(key)) {
        std::cout << "Warning: TwoSideMapSet-getValues: Key not found in forward map" << std::endl;
        // TODO: make my own GetException that inherits from BaseException
        return result;
    }
    for (auto ptr : forwardMap[key]) {
        result.push_back(*ptr);
    }
    return result;
}

template<typename A, typename B>
std::optional<A> TwoSideMapOneMany<A, B>::getKey(B value) {
    // guard clause for value not found
    if (!containsValue(value)) {
        return std::nullopt;
    }
    return std::make_optional<A>(backwardMap[value]);
}

template<typename A, typename B>
bool TwoSideMapOneMany<A, B>::containsKey(A key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideMapOneMany<A, B>::containsValue(B value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
int TwoSideMapOneMany<A, B>::size() const {
    return backwardMap.size();
}
// ai-gen end
