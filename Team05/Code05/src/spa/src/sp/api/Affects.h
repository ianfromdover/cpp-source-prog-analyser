//
// Created by Chua Bing Quan on 27/3/24.
//

#ifndef SPA_AFFECTS_H
#define SPA_AFFECTS_H

#include <unordered_map>
#include "sp/cfg/CFG.h"
#include "sp/solver/Solver.h"
#include "DefUseExtractor.h"

using DefinitionSet = std::unordered_set<VarPoint>;
using DefUseChain = std::unordered_map<StmtNo, std::unordered_set<StmtNo>>;

class Affects {
private:
    std::shared_ptr<CFGs> cfgs;
    DefUseChain defUseChain;
    Solver<DefinitionSet>::Meet meet;
    Solver<DefinitionSet>::Transfer transfer;
    DefUseExtractor extractor;
    Definitions currentCFGDefinitions;
    Uses currentCFGUses;
private:
    std::pair<Solver<DefinitionSet>::Facts, Solver<DefinitionSet>::Facts> compute();
    static DefinitionSet computeKillSet(const DefinitionSet& in, const DefinitionSet& gen);
    static void computeSetDifference(DefinitionSet& minuend, const DefinitionSet& subtrahend);
public:
    explicit Affects(const std::shared_ptr<CFGs>& cfgs);
    std::pair<Solver<DefinitionSet>::Facts, Solver<DefinitionSet>::Facts> get(StmtNo s1, StmtNo s2);
    void flush();
};


#endif //SPA_AFFECTS_H
