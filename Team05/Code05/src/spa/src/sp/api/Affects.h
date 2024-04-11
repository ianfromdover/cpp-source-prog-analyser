//
// Created by Chua Bing Quan on 27/3/24.
//

#ifndef SPA_AFFECTS_H
#define SPA_AFFECTS_H

#include <unordered_map>
#include "sp/cfg/CFGCollection.h"
#include "sp/solver/Solver.h"
#include "DefUseExtractor.h"

class QueryPkb;

using DefinitionSet = std::unordered_set<std::shared_ptr<VarOccurrence>>;
using DefUseChain = std::unordered_map<StmtNo, std::unordered_set<StmtNo>>;

class Affects {
private:
    std::shared_ptr<CFGCollection> cfgCollection;
    std::shared_ptr<QueryPkb> queryPkb;
    std::unordered_map<std::string, DefUseChain> defUseChainMap;
    Solver<DefinitionSet>::Meet meet;
    Solver<DefinitionSet>::Transfer transfer;
    DefUseExtractor extractor;
    Definitions currentCFGDefinitions;
    Uses currentCFGUses;
private:
    void compute(const std::shared_ptr<CFG>& cfg);
    static DefinitionSet computeKillSet(const DefinitionSet& in, const DefinitionSet& gen);
    static void computeSetDifference(DefinitionSet& minuend, const DefinitionSet& subtrahend);
public:
    explicit Affects(const std::shared_ptr<CFGCollection>& cfgCollection, const std::shared_ptr<QueryPkb>& queryPkb);
    bool get(StmtNo s1, StmtNo s2);
    void flush();
};


#endif //SPA_AFFECTS_H
