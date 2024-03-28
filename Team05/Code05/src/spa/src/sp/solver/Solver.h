//
// Created by Chua Bing Quan on 25/3/24.
//

#ifndef SPA_SOLVER_H
#define SPA_SOLVER_H

#include <queue>
#include "sp/cfg/CFG.h"

template<typename T>
class Solver {
public:
    using Meet = std::function<T(const T&, const T&)>;
    using Transfer = std::function<T(const std::shared_ptr<Block>&, const T&)>;
    using Facts = std::unordered_map<std::shared_ptr<Block>, T>;
public:
    static auto solve(const std::shared_ptr<CFG>& cfg, Meet meet, Transfer transfer, T init) -> std::pair<Facts, Facts>;
};

template <typename T>
auto Solver<T>::solve(const std::shared_ptr<CFG>& cfg, Meet meet, Transfer transfer, T init) -> std::pair<Facts, Facts> {
    Facts in;
    Facts out;
    std::queue<std::shared_ptr<Block>> worklist;

    in.insert({ cfg->getEntryBlock(), init });
    for (const auto& block : *cfg->getBlocks()) {
        out.insert({ block, init });
        worklist.push(block);
    }

    while (!worklist.empty()) {
        const auto& block = worklist.front();
        worklist.pop();

        auto newIn = init;
        for (const auto& pred : *block->getPredecessors()) {
            newIn = meet(out[pred], newIn);
        }
        in[block] = newIn;

        const auto newOut = transfer(block, in[block]);
        // TODO: Ensure that `!=` is correctly overloaded or correctly compares the content between the objects.
        if (newOut != out[block]) {
            out[block] = newOut;
            for (const auto& succ : *block->getSuccessors()) {
                worklist.push(succ);
            }
        }
    }

    return { std::move(in), std::move(out) };
}


#endif //SPA_SOLVER_H
