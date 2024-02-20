#include "TwoSideMap.h"

template<typename A, typename B>
bool TwoSideMap<A, B>::insert(A key, B value) {
    if (containsPair(key, value)) {
        std::cout << "Warning: TwoSideMap-insert: Pair already exists" << std::endl;
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
    return std::make_optional<B>(*forwardMap[key]);
}

template<typename A, typename B>
std::optional<A> TwoSideMap<A, B>::getKey(B value) {
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
    return getKey(value) == key && getValue(key) == value;
}

template<typename A, typename B>
[[nodiscard]] int TwoSideMap<A, B>::size() const {
    return forwardMap.size();
}
// ai-gen end
