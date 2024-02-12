#pragma once
#define SPA_FN_H

#include <set>
#include <vector>
#include <memory>

// Utility functions
class Fn {
public:
    template<typename A>
    static std::vector<A> toVec(std::set<A> set);
};
