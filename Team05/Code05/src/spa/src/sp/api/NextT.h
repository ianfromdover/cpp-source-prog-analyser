//
// Created by sjh_9 on 4/4/2024.
//

#ifndef SPA_NEXTT_H
#define SPA_NEXTT_H

#include "sp/solver/Solver.h"
#include "sp/cfg/CFGCollection.h"
#include "Aggregator.h"

class NextT {
private:
    Solver<Aggregator>::Meet meet;
    Solver<Aggregator>::Transfer transfer;
    std::shared_ptr<CFGCollection> cfgCollection;
    std::unordered_map<std::string, pair<Solver<Aggregator>::Facts, Solver<Aggregator>::Facts>> factChainMap;

public:
    explicit NextT(const std::shared_ptr<CFGCollection>& cfgCollection);
    bool get(StmtNo s1, StmtNo s2);
    void flush();

    void compute(const shared_ptr<CFG> &cfg, const string &procedureName);
};


#endif //SPA_NEXTT_H
