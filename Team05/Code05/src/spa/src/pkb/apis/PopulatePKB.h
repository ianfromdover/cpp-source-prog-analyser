//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_POPULATEPKB_H
#define SPA_POPULATEPKB_H

#include "BasePKBPopulator.h"
#include "PKBStorage.h"

class PopulatePKB : public BasePKBPopulator {
private:
    std::shared_ptr<PKBStorage> pkb;
public:
    PopulatePKB(std::shared_ptr<PKBStorage> p);

    bool addRead(int stmtNo, std::string name) override;
    bool addCallStmt(int stmtNo, std::string name) override;
    bool addIf(int stmtNo, std::string name) override;
    bool addWhile(int stmtNo, std::string name) override;
    bool addPrint(int stmtNo, std::string name) override;
    bool addFinalStatementNo(int stmtNo) override;
    bool addProcedure(std::string name) override;
    bool addVar(int stmtNo, std::string name) override;
    bool addConst(int stmtNo, int val) override;
    bool addFollows(int before, int after) override;
    bool addFollowsT(int before, int after) override;
    bool addParent(int parent, int child) override;
    bool addParentT(int parent, int child) override;
    bool addUsesS(int stmtNo, std::string name) override;
    bool addUsesP(std::string procName, std::string name) override;
    bool addModifiesS(int stmtNo, std::string name) override;
    bool addModifiesP(std::string procName, std::string name) override;
    bool addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) override;
    bool addCalls(std::string caller, std::string called) override;
    bool addCallsT(std::string caller, std::string called) override;
};


#endif //SPA_POPULATEPKB_H
