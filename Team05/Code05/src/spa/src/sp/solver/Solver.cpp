//
// Created by Chua Bing Quan on 25/3/24.
//

#include "Solver.h"
#include <queue>

template <typename T>
void Solver<T>::solve(const std::shared_ptr<CFG>& cfg, Meet meet, Transfer transfer, T init) {
    std::unordered_map<std::shared_ptr<Block>, T> in;
    std::unordered_map<std::shared_ptr<Block>, T> out;
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
}