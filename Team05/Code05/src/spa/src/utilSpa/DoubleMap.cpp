#include "DoubleMap.h"

// ai-gen start(gpt, 0, e)

template<typename A, typename B>
void DoubleMap<A, B>::insert(const A& key, const B& value) {
    forwardMap[key] = value;
    backwardMap[value] = key;
}

template<typename A, typename B>
B DoubleMap<A, B>::getValue(const A& key) {
    return forwardMap[key];
}

template<typename A, typename B>
A DoubleMap<A, B>::getKey(const B& value) {
    return backwardMap[value];
}

template<typename A, typename B>
bool DoubleMap<A, B>::containsKey(const A& key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool DoubleMap<A, B>::containsValue(const B& value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
void DoubleMap<A, B>::eraseKey(const A& key) {
    if (containsKey(key)) {
        backwardMap.erase(forwardMap[key]);
        forwardMap.erase(key);
    }
}

template<typename A, typename B>
void DoubleMap<A, B>::eraseValue(const B& value) {
    if (containsValue(value)) {
        forwardMap.erase(backwardMap[value]);
        backwardMap.erase(value);
    }
}

// ai-gen end
