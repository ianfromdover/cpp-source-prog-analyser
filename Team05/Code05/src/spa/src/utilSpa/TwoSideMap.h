#pragma once
#define SPA_TWOSIDEMAP_H

#include <iostream>
#include <memory>
#include <unordered_map>

/**
 * @brief A double-sided map that allows bidirectional mapping between keys and values.
 * Used for entity tables in the PKB such as VarTable
 *
 * @tparam A The type of the keys. Needs to be hashable.
 * @tparam B The type of the values. Needs to be hashable.
 */
template<typename A, typename B>
class TwoSideMap {
private:
    std::unordered_map<A, std::shared_ptr<B>> forwardMap;
    std::unordered_map<B, std::weak_ptr<A>> backwardMap;
public:
    TwoSideMap();

    bool insert(A key, B value);

    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    std::optional<B> getValue(A key);

    std::optional<A> getKey(B value);

    bool containsKey(A key);

    bool containsValue(B value);

    bool containsPair(A key, B value);

    [[nodiscard]] int size() const;
    // ai-gen end
};
