#include "TwoSideMapSet.h"

template<typename A, typename B>
TwoSideMapSet<A, B>::TwoSideMapSet() {};
// ai-gen start(gpt, 2, e)
// prompt: https://chat.openai.com/share/8ef1cf87-56eb-45bd-b91f-fbf309b86d98
// ai-gen start(copilot, 1, e)
// prompt: used copilot
// copilot wrote code according to given comments

template<typename A, typename B>
bool TwoSideMapSet<A, B>::insert(A key, B value) {
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
std::vector<B> TwoSideMapSet<A, B>::getValues(A key) {
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
std::optional<A> TwoSideMapSet<A, B>::getKey(B value) {
    // guard clause for value not found
    if (!containsValue(value)) {
        return std::nullopt;
    }
    return std::make_optional<A>(backwardMap[value]);
}

template<typename A, typename B>
bool TwoSideMapSet<A, B>::containsKey(A key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideMapSet<A, B>::containsValue(B value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
int TwoSideMapSet<A, B>::size() const {
    return backwardMap.size();
}

// ai-gen end
// ai-gen end
