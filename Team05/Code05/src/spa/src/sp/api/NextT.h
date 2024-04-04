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
    Solver<Aggregator>::Facts in;
    Solver<Aggregator>::Facts out;


public:
    explicit NextT(const std::shared_ptr<CFGCollection>& cfgCollection);
    bool get(StmtNo s1, StmtNo s2);

};


#endif //SPA_NEXTT_H
