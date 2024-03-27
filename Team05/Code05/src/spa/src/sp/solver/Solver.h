//
// Created by Chua Bing Quan on 25/3/24.
//

#ifndef SPA_SOLVER_H
#define SPA_SOLVER_H

#include "sp/cfg/CFG.h"

template<typename T>
class Solver {
public:
    using Meet = std::function<T(const T&, const T&)>;
    using Transfer = std::function<T(const std::shared_ptr<Block>&, const T&)>;
public:
    static void solve(const std::shared_ptr<CFG>& cfg, Meet meet, Transfer transfer, T init);
};


#endif //SPA_SOLVER_H
