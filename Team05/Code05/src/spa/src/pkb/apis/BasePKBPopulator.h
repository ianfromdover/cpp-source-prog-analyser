//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_BASEPKBPOPULATOR_H
#define SPA_BASEPKBPOPULATOR_H

#include <memory>
#include <iostream>
#include <vector>
#include <string>

class BasePKBPopulator {
public:
    virtual ~BasePKBPopulator() = default;

    virtual bool addRead(int stmtNo, std::string name) = 0;
    virtual bool addCallStmt(int stmtNo, std::string name) = 0;
    virtual bool addIf(int stmtNo, std::string name) = 0;
    virtual bool addWhile(int stmtNo, std::string name) = 0;
    virtual bool addPrint(int stmtNo, std::string name) = 0;
    virtual bool addFinalStatementNo(int stmtNo) = 0;
    virtual bool addProcedure(std::string name) = 0;
    virtual bool addVar(int stmtNo, std::string name) = 0;
    virtual bool addConst(int stmtNo, int val) = 0;
    virtual bool addFollows(int before, int after) = 0;
    virtual bool addFollowsT(int before, int after) = 0;
    virtual bool addParent(int parent, int child) = 0;
    virtual bool addParentT(int parent, int child) = 0;
    virtual bool addUses(int stmtNo, std::string name) = 0;
    virtual bool addModifies(int stmtNo, std::string name) = 0;
    virtual bool addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) = 0;
    virtual bool addCalls(std::string caller, std::string called) = 0;
    virtual bool addCallsT(std::string caller, std::string called) = 0;
};

#endif //SPA_BASEPKBPOPULATOR_H
