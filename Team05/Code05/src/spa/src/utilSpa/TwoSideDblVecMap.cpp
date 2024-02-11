#include "TwoSideDblVecMap.h"

// TODO: for every PBR note, check, did I pass by reference?

template<typename A, typename B>
TwoSideDblVecMap<A, B>::TwoSideDblVecMap() {};

/**
 * @brief Construct a new TwoSideDblVecMap from a given TwoSideFwdVecMap.
 * Note: untested and likely to be buggy.
 *
 * @param other The other TwoSideFwdVecMap.
template<typename A, typename B>
TwoSideDblVecMap<A, B>::TwoSideDblVecMap(const TwoSideFwdVecMap<A, B>& other) {

    // ai-gen start (copilot, 1, e)
    // prompt: copilot used
    // Make an intermediate of forwardMap and backwardMap
    auto intermFwdMap = std::unordered_map<A, std::vector<B>>(other.forwardMap);

    // iterating through the intermFwdMap,
    // while we have not reached the end of the forwardMap,
    // if the element is a key in the forwardMap,
    // append its value vector to the intermFwdMap
    for (auto it = intermFwdMap.begin(); it != intermFwdMap.end(); it++) {
        // yikes this is O(n log n)
        // TODO: will this cause never-ending appending?
        if (intermFwdMap.find(it->first) != intermFwdMap.end()) {
            intermFwdMap[it->first].insert(intermFwdMap[it->first].end(), it->second.begin(), it->second.end());
        } else {
            intermFwdMap[it->first] = it->second; // what does this do?
        }
    }
    // ai-gen end
    forwardMap = intermFwdMap;

    // backwardMap
    // ai-gen start (copilot, 1, e)
    // prompt: copilot used
    auto intermBkwdMap = std::unordered_map<B, std::vector<A>>();
    // for each key-value pair in the other backwardMap,
    // insert a new key-value pair into the intermBkwdMap, where the value is a vector containing the value from the other backwardMap
    for (auto it = other.backwardMap.begin(); it != other.backwardMap.end(); it++) {
        intermBkwdMap[it->first] = it->second;
    }
    // for each key-value pair in the intermBkwdMap (w, x)
    // if x is a key y in the intermBkwdMap, its corresponding value vector is z.
    // append vector z to vector x in intermBkwdMap
    // TODO: check if generated code does what I want
    for (auto it = intermBkwdMap.begin(); it != intermBkwdMap.end(); it++) {
        if (intermBkwdMap.find(it->first) != intermBkwdMap.end()) {
            intermBkwdMap[it->first].insert(intermBkwdMap[it->first].end(), it->second.begin(), it->second.end());
        } else {
            intermBkwdMap[it->first] = it->second;
        }
    }
    // ai-gen end
}
 */

template<typename A, typename B>
void TwoSideDblVecMap<A, B>::insert(const A& key, const B& value) {
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
    // if value does not exist, create a new vector and insert A into it
    if (backwardMap.find(value) == backwardMap.end()) {
        auto vec = std::vector<A>();
        vec.push_back(key);
        backwardMap[value] = vec; // TODO: PBR?
    } else {
        backwardMap[value].push_back(key); // TODO: PBR?
    }
}

template<typename A, typename B>
std::vector<B> TwoSideDblVecMap<A, B>::getValues(const A& key) {
    // guard clause for key not found
    if (forwardMap.find(key) == forwardMap.end()) {
        std::cerr << "Warning: TwoSideDblVecMap: Key not found in forward map" << std::endl;
    }
    return forwardMap[key]; // TODO: PBR?
}

template<typename A, typename B>
std::vector<A> TwoSideDblVecMap<A, B>::getKeys(const B& value) {
    // guard clause for value not found
    if (backwardMap.find(value) == backwardMap.end()) {
        std::cerr << "Warning: TwoSideFedVecMap: Value not found in backward map" << std::endl;
    }
    return backwardMap[value]; // TODO: PBR?
}

template<typename A, typename B>
bool TwoSideDblVecMap<A, B>::containsKey(const A& key) {
    return forwardMap.find(key) != forwardMap.end();
}

template<typename A, typename B>
bool TwoSideDblVecMap<A, B>::containsValue(const B& value) {
    return backwardMap.find(value) != backwardMap.end();
}
// removed erase functions because unlikely to use and too lazy to implement
