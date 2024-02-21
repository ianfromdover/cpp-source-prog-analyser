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
    std::unordered_map<B, std::shared_ptr<A>> backwardMap;
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

// ---------------------------- Implementation ----------------------------

template<typename A, typename B>
TwoSideMap<A, B>::TwoSideMap() {};

template<typename A, typename B>
bool TwoSideMap<A, B>::insert(A key, B value) {
    if (containsKey(key) || containsValue(value)) {
        std::cout << "Warning: TwoSideMap-insert: Key or Val already exists" << std::endl;
        // TODO: throw InsertException and catch it
        return false;
    }
    forwardMap[key] = std::make_shared<B>(value);
    backwardMap[value] = std::make_shared<A>(key);
    return true;
}

// ai-gen start (copilot, 1, e)
// prompt: used copilot
template<typename A, typename B>
std::optional<B> TwoSideMap<A, B>::getValue(A key) {
    if (!containsKey(key)) {
        return std::nullopt;
    }
    return std::make_optional<B>(*forwardMap[key]);
}

template<typename A, typename B>
std::optional<A> TwoSideMap<A, B>::getKey(B value) {
    if (!containsValue(value)) {
        return std::nullopt;
    }
    return std::make_optional<B>(*backwardMap[value]);
}

template<typename A, typename B>
bool TwoSideMap<A, B>::containsKey(A key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideMap<A, B>::containsValue(B value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
bool TwoSideMap<A, B>::containsPair(A key, B value) {
    auto k = getKey(value);
    auto v = getValue(key);
    if (!k.has_value() || ! v.has_value()) {
        return false;
    }
    return k.value() == key && v.value() == value;
}

template<typename A, typename B>
[[nodiscard]] int TwoSideMap<A, B>::size() const {
    return forwardMap.size();
}
// ai-gen end
