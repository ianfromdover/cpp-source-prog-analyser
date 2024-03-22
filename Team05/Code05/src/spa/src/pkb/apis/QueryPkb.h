#pragma once
#define SPA_QUERYPKB_H

#include "QueryPkbVirtual.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class QueryPkbVirtual;

class QueryPkb : public QueryPkbVirtual {
private:
    std::shared_ptr<PkbStorage> pkb;
public:
    explicit QueryPkb(std::shared_ptr<PkbStorage> p);

//    Table getRead() override override;
//    Table getCallStmt() override override;
//    Table getIf() override override;
//    Table getWhile() override override;
//    Table getPrint() override override;
//    Table getStatement() override override;
//    Table getProcedure() override override;
//    Table getVar() override override;
//    Table getConst() override override;
//    Table getFollows() override override;
//    Table getFollowsT() override override;
//    Table getParent() override override;
//    Table getParentT() override override;
//    Table getUses() override override;
//    Table getModifies() override override;
//    Table getPatternAsgn() override override;
//    Table getCalls() override override;
//    Table getCallsT() override override;

    // refactor get
    Table getCallByNum(StmtNo sNum) override;
    Table getCallByProc(ProcName proc) override;
    Table getCallTable() override;
    Table getProcByName(ProcName proc) override;
    Table getProcTable() override;
    Table getReadByNum(StmtNo sNum) override;
    Table getReadByVar(VarName var) override;
    Table getReadTable() override;
    Table getIfByNum(StmtNo sNum) override;
    Table getIfByVar(VarName var) override;
    Table getIfStmts() override;
    Table getIfTable() override;
    Table getWhileByNum(StmtNo sNum) override;
    Table getWhileByVar(VarName var) override;
    Table getWhileStmts() override;
    Table getWhileTable() override;
    Table getPrintByNum(StmtNo sNum) override;
    Table getPrintByVar(VarName var) override;
    Table getPrintTable() override;
    Table getStmtByNum(StmtNo sNum) override;
    Table getStmtTable() override;
    Table getVars() override;
    Table getVarTable() override;
    Table getConstByName(VarName var) override;
    Table getConsts() override;
    Table getConstTable() override;
    Table getFollowsByBefore(StmtNo before) override;
    Table getFollowsByAfter(StmtNo after) override;
    Table getFollowsTable() override;
    Table getFollowsTByBefore(StmtNo before) override;
    Table getFollowsTByAfter(StmtNo after) override;
    Table getFollowsTTable() override;
    Table getParentByParent(StmtNo parent) override;
    Table getParentByChild(StmtNo child) override;
    Table getParentTable() override;
    Table getParentTByParent(StmtNo parent) override;
    Table getParentTByChild(StmtNo child) override;
    Table getParentTTable() override;
    Table getUsesSByNum(StmtNo user) override;
    Table getUsesSByVar(VarName used) override;
    Table getUsesSTable() override;
    // TODO: add the other UsesP stuff
    Table getUsesPTable() override;
    Table getModifiesSByNum(StmtNo modifier) override;
    Table getModifiesSByVar(VarName modified) override;
    Table getModifiesSTable() override;
    Table getModifiesPByProc(ProcName modifier) override;
    Table getModifiesPByVar(VarName modified) override;
    Table getModifiesPTable() override;
    Table getPatternAsgnByNum(StmtNo sNum) override;
    Table getPatternAsgnByLhs(std::string Lhs) override;
    Table getPatternAsgnByRhs(std::string Rhs) override;
    Table getPatternAsgnByLhsPartial(std::string LhsPartial) override;
    Table getPatternAsgnByRhsPartial(std::string RhsPartial) override;
    Table getPatternAsgnTable() override;
    Table getPatternIfByNum(StmtNo sNum) override;
    Table getPatternIfByVar(VarName var) override;
    Table getPatternIfTable() override;
    Table getPatternWhileByNum(StmtNo sNum) override;
    Table getPatternWhileByVar(VarName var) override;
    Table getPatternWhileTable() override;
    Table getCallsByCaller(ProcName caller) override;
    Table getCallsByCalled(ProcName called) override;
    Table getCallsTable() override;
    Table getCallsTByCaller(ProcName caller) override;
    Table getCallsTByCalled(ProcName called) override;
    Table getCallsTTable() override;
    Table getNextByBefore(StmtNo before) override;
    Table getNextByAfter(StmtNo after) override;
    Table getNextTable() override;
    Table getNextTByBefore(StmtNo before) override;
    Table getNextTByAfter(StmtNo after) override;
    Table getNextTTable() override;
    Table getAffectsByBefore(StmtNo before) override;
    Table getAffectsByAfter(StmtNo after) override;
    Table getAffectsTable() override;
};
