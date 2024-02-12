//
// Created by yewme on 12/2/2024.
//

#include "TwoSideFwdVecMap.h"

// TODO: for every PBR note, check, did I pass by reference?

template<typename A, typename B>
TwoSideFwdVecMap<A, B>::TwoSideFwdVecMap() {};
// ai-gen start(gpt, 2, e)
// prompt: https://chat.openai.com/share/8ef1cf87-56eb-45bd-b91f-fbf309b86d98
// ai-gen start(copilot, 1, e)
// prompt: used copilot
// copilot wrote code according to given comments

template<typename A, typename B>
void TwoSideFwdVecMap<A, B>::insert(const A& key, const B& value) {
    // forward map
    // if key does not exist, create a new vector and insert B into it
    if (forwardMap.find(key) == forwardMap.end()) {
        auto vec = std::vector<B>();
        vec.push_back(value);
        forwardMap[key] = vec; // TODO: PBR?
    } else {
        forwardMap[key].push_back(value); // TODO: PBR?
    }

    // backward map
    // if value does not exist, insert key. Else, warn that value already exists
    if (backwardMap.find(value) == backwardMap.end()) {
        backwardMap[value] = key; // TODO: PBR?
    } else {
        std::cerr << "Warning: TwoSideFedVecMap: Value already exists in backward map" << std::endl;
    }
}

template<typename A, typename B>
std::vector<B> TwoSideFwdVecMap<A, B>::getValues(const A& key) {
    // guard clause for key not found
    if (forwardMap.find(key) == forwardMap.end()) {
        std::cerr << "Warning: TwoSideFwdVecMap: Key not found in forward map" << std::endl;
    }
    return forwardMap[key]; // TODO: PBR?
}

template<typename A, typename B>
A TwoSideFwdVecMap<A, B>::getKey(const B& value) {
    // guard clause for value not found
    if (backwardMap.find(value) == backwardMap.end()) {
        std::cerr << "Warning: TwoSideFwdVecMap: Value not found in backward map" << std::endl;
    }
    return backwardMap[value]; // TODO: PBR?
}

template<typename A, typename B>
bool TwoSideFwdVecMap<A, B>::containsKey(const A& key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideFwdVecMap<A, B>::containsValue(const B& value) {
    return backwardMap.find(value) != backwardMap.end();
}

template<typename A, typename B>
void TwoSideFwdVecMap<A, B>::eraseKey(const A& key) {
    if (containsKey(key)) {
        auto assocValues = forwardMap[key];
        for (auto val : assocValues) {
            backwardMap.erase(val);
        }
        forwardMap.erase(key);
    }
}

template<typename A, typename B>
void TwoSideFwdVecMap<A, B>::eraseValue(const B& value) {
    if (containsValue(value)) {
        auto assocKey = backwardMap[value];
        if (forwardMap[assocKey].size() == 1) {
            forwardMap.erase(assocKey);
        } else {
            auto vec = forwardMap[assocKey]; // TODO: PBR?
            // remove the value from the vector
            vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end()); // TODO: do i need the <algorithm> header for remove?
        }
        // for copilot:
        // ai-gen end
        backwardMap.erase(value);
    }
}

template<typename A, typename B>
int TwoSideFwdVecMap<A,B>::size() const {
    return forwardMap.size();
}

// ai-gen end

