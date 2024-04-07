#pragma once
#define SPA_BASEPKBPOPULATOR_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "sp/api/Affects.h"
#include "sp/api/NextT.h"

// should rename to virtual also, and have ref to pkb
// add destructuors to others
class BasePkbPopulator {
public:
    virtual ~BasePkbPopulator() = default;

    // on-demand
    virtual bool setAffectsObj(std::shared_ptr<Affects> a) = 0;
    virtual bool setNextTObj(std::shared_ptr<NextT> n) = 0;

    // entity
    virtual bool addCallStmt(int stmtNo, std::string name) = 0;
    virtual bool addConst(int stmtNo, int val) = 0;
    virtual bool addPrint(int stmtNo, std::string name) = 0;
    virtual bool addProcedure(std::string name) = 0;
    virtual bool addRead(int stmtNo, std::string name) = 0;
    virtual bool addFinalStatementNo(int stmtNo) = 0;
    virtual bool addVar(int stmtNo, std::string name) = 0;

    // relation
    virtual bool addCalls(std::string caller, std::string called) = 0;
    virtual bool addCallsT(std::string caller, std::string called) = 0;
    virtual bool addFollows(int before, int after) = 0;
    virtual bool addFollowsT(int before, int after) = 0;
    virtual bool addModifiesP(std::string procName, std::string name) = 0;
    virtual bool addModifiesS(int stmtNo, std::string name) = 0;
    virtual bool addNext(int before, int after) = 0;
    virtual bool addParent(int parent, int child) = 0;
    virtual bool addParentT(int ancestor, int descendant) = 0;
    virtual bool addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) = 0;
    virtual bool addPatternIf(int stmtNo, std::string name) = 0;
    virtual bool addPatternWhile(int stmtNo, std::string name) = 0;
    virtual bool addUsesP(std::string procName, std::string name) = 0;
    virtual bool addUsesS(int stmtNo, std::string name) = 0;
};
