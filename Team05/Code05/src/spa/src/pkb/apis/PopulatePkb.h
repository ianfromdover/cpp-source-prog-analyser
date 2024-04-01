#pragma once
#define SPA_POPULATEPKB_H

#include "pkb/apis/BasePkbPopulator.h"
#include "PkbStorage.h"

/**
 * Methods arranged alphabetically to easily compare with project files
 */
class PopulatePkb : public BasePkbPopulator {
private:
    std::shared_ptr<PkbStorage> pkb;
public:
    PopulatePkb(std::shared_ptr<PkbStorage> p);

    // on-demand
    virtual bool setAffectsObj() override; // add param after SP implements
    virtual bool setNextTObj() override; // add param after SP implements

    // entity
    bool addCallStmt(int stmtNo, std::string name) override;
    bool addConst(int stmtNo, int val) override;
    bool addPrint(int stmtNo, std::string name) override;
    bool addProcedure(std::string name) override;
    bool addRead(int stmtNo, std::string name) override;
    bool addFinalStatementNo(int stmtNo) override;
    bool addVar(int stmtNo, std::string name) override;

    // relation
    bool addCalls(std::string caller, std::string called) override;
    bool addCallsT(std::string caller, std::string called) override;
    bool addFollows(int before, int after) override;
    bool addFollowsT(int before, int after) override;
    bool addModifiesS(int stmtNo, std::string name) override;
    bool addModifiesP(std::string procName, std::string name) override;
    bool addNext(int before, int after) override;
    bool addParent(int parent, int child) override;
    bool addParentT(int ancestor, int descendant) override;
    bool addUsesS(int stmtNo, std::string name) override;
    bool addUsesP(std::string procName, std::string name) override;
    bool addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) override;
    bool addPatternIf(int stmtNo, std::string name) override;
    bool addPatternWhile(int stmtNo, std::string name) override;
};
