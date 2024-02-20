#include "TwoSideMapTwoSet.h"

template<typename A, typename B>
TwoSideMapTwoSet<A, B>::TwoSideMapTwoSet() {};

template<typename A, typename B>
bool TwoSideMapTwoSet<A, B>::insert(const A key, const B value) {
    auto kPtr = std::make_shared<A>(key);
    auto vPtr = std::make_shared<B>(value);

    // if key does not exist, create a new set with the value
    if (!containsKey(key)) {
        forwardMap[*kPtr] = {vPtr};
    } else {
        forwardMap[*kPtr].insert(vPtr);
    }

    if (!containsValue(value)) {
        backwardMap[*vPtr] = {kPtr};
    } else {
        backwardMap[*vPtr].insert(kPtr);
    }
    return true;
}

template<typename A, typename B>
std::vector<B> TwoSideMapTwoSet<A, B>::getValues(A key) {
    std::vector<B> result;
    if (!containsKey(key)) {
        std::cout << "Warning: TwoSideMapTwoSet-getValues: Key not found in forward map" << std::endl;
        // TODO: make my own GetException that inherits from BaseException
        return result;
    }
    for (auto ptr : forwardMap[key]) {
        result.push_back(*ptr);
    }
    return result;
}

template<typename A, typename B>
std::vector<A> TwoSideMapTwoSet<A, B>::getKeys(B value) {
    std::vector<B> result;
    if (!containsValue(value)) {
        std::cout << "Warning: TwoSideMapTwoSet-getKeys: Value not found in backward map" << std::endl;
        // TODO: make my own GetException that inherits from BaseException
        return result;
    }
    for (auto ptr : backwardMap[value]) {
        result.push_back(*ptr);
    }
    return result;
}

template<typename A, typename B>
bool TwoSideMapTwoSet<A, B>::containsKey(const A key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideMapTwoSet<A, B>::containsValue(const B value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
int TwoSideMapTwoSet<A, B>::size() const {
    int totalSize = 0;
    for (const auto& set : forwardMap) {
        totalSize += set->size();
    }
    return totalSize;
}
