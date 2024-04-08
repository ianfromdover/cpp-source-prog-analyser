//
// Created by sjh_9 on 4/4/2024.
//

#include "NextT.h"

NextT::NextT(const std::shared_ptr<CFGCollection>& cfgCollection) {
    this->transfer = [&](const std::shared_ptr<Block>& block, const Aggregator& tempIn) {
        auto tempOut = Aggregator(tempIn);
        tempOut.info.insert(block);
        return tempOut;
    };
    this->meet = [](const Aggregator& s1, const Aggregator& s2) {
        auto result = Aggregator(s1);
        result.merge(s2);
        return result;
    };
    this->cfgCollection = cfgCollection;
}


bool NextT::get(StmtNo s1, StmtNo s2) {
    // Check if the two statements belong in the same cfg
    const auto cfg = this->cfgCollection->find(s1);
    if (!cfg || !(*cfg)->containsStmtNo(s2)) {
        return false;
    };

    // Check if the two statements belong in the same block and s1 < s2
    const auto blockS1 = (*cfg)->find(s1);
    const auto blockS2 = (*cfg)->find(s2);
    if (blockS1 == blockS2 && s1 < s2) {
        return true;
    }
    // Check if solver was previously ran
    const auto procedureName = (*cfg)->getProcedureName();
    auto factChainIt = this->factChainMap.find(procedureName);
    if (factChainIt == this->factChainMap.end()) {
        this->compute(*cfg, procedureName);
        factChainIt = this->factChainMap.find(procedureName);
    }
    // Check if BlockS1 is in the Aggregator of BlockS2
    if (factChainIt->second.first[*blockS2].info.find(*blockS1) != factChainIt->second.first[*blockS2].info.end()) {
        return true;
    }
    return false;
}

void NextT::flush() {
    this->factChainMap.clear();
}

void NextT::compute(const shared_ptr<CFG> &cfg, const std::string& procedureName) {
    std::cout << "Computed for " << procedureName << std::endl;
    const auto [tempIn, tempOut] =Solver<Aggregator>::solve(cfg, this->meet, this->transfer, Aggregator());
    this->factChainMap.insert({procedureName, {tempIn, tempOut}});
}
