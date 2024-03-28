#pragma once
#define SPA_QUERYPKB_H

#include "QueryPkbVirtual.h"

class QueryPkb : public QueryPkbVirtual {
private:
    std::shared_ptr<PkbStorage> pkb;
public:
    explicit QueryPkb(std::shared_ptr<PkbStorage> p);

    // on-demand --------------------------------------------------------------
    bool checkAffects(StmtNo affector, StmtNo affected) override;
    bool checkNextT(StmtNo before, StmtNo after) override;
    bool resetAffects() override;
    bool resetNextT() override;

    // entities --------------------------------------------------------------
    Table getCallTable() override;
    Table getCallAllStmts() override;
    Table getCallAllProcs() override;
    Table getCallProcsByStmt(StmtNo sNum) override;
    Table getCallStmtsByProc(ProcName proc) override;

    Table getConstTable() override;
    Table getConstAllStmts() override;
    Table getConstAllValues() override;
    Table getConstStmtsByVal(StmtNo sNum) override;
    Table getConstValuesByStmt(StmtNo sNum) override;

    Table getIfTable() override;
    Table getIfAllStmts() override;
    Table getIfAllVars() override;
    Table getIfVarsByStmt(StmtNo sNum) override;
    Table getIfStmtsByVar(VarName var) override;

    Table getPrintTable() override;
    Table getPrintAllStmts() override;
    Table getPrintAllVars() override;
    Table getPrintVarsByStmt(StmtNo sNum) override;
    Table getPrintStmtsByVar(VarName var) override;

    Table getProcTable() override;
    // should i add a containsProc method? for with clause

    Table getReadTable() override;
    Table getReadAllStmts() override;
    Table getReadAllVars() override;
    Table getReadVarsByStmt(StmtNo sNum) override;
    Table getReadStmtsByVar(VarName var) override;

    Table getStmtTable() override;
    // should i add a containsStmt method? for with clause

    Table getVarTable() override;
    Table getVarAllStmts() override;
    Table getVarAllVars() override;
    Table getVarVarsByStmt(StmtNo sNum) override;
    Table getVarStmtsByVar(VarName var) override;

    Table getWhileTable() override;
    Table getWhileAllStmts() override;
    Table getWhileAllVars() override;
    Table getWhileVarsByStmt(StmtNo sNum) override;
    Table getWhileStmtsByVar(VarName var) override;

    // relations --------------------------------------------------------------
    /*
    Table getAffectsTable() override; // generated each query
    Table getAffectsAllAffectors() override;
    Table getAffectsAllAffected() override;
    Table getAffectsAffectedByAffector(StmtNo affector) override;
    Table getAffectsAffectorsByAffected(StmtNo affected) override;
     */

    Table getCallsTable() override;
    Table getCallsAllCallers() override;
    Table getCallsAllCalled() override;
    Table getCallsCalledByCaller(ProcName caller) override;
    Table getCallsCallerByCalled(ProcName called) override;

    Table getCallsTTable() override;
    Table getCallsTAllCallers() override;
    Table getCallsTAllCalled() override;
    Table getCallsTCalledByCaller(ProcName caller) override;
    Table getCallsTCallerByCalled(ProcName called) override;

    Table getFollowsTable() override;
    Table getFollowsAllBefore() override;
    Table getFollowsAllAfter() override;
    Table getFollowsAfterByBefore(StmtNo before) override;
    Table getFollowsBeforeByAfter(StmtNo after) override;

    Table getFollowsTTable() override;
    Table getFollowsTAllBefore() override;
    Table getFollowsTAllAfter() override;
    Table getFollowsTAfterByBefore(StmtNo before) override;
    Table getFollowsTBeforeByAfter(StmtNo after) override;

    Table getModifiesPTable() override;
    Table getModifiesPAllProcs() override;
    Table getModifiesPAllVars() override;
    Table getModifiesPVarsByProc(ProcName modifier) override;
    Table getModifiesPProcsByVar(VarName modified) override;

    Table getModifiesSTable() override;
    Table getModifiesSAllStmts() override;
    Table getModifiesSAllVars() override;
    Table getModifiesSVarsByStmt(StmtNo modifier) override;
    Table getModifiesSStmtsByVar(VarName modified) override;

    Table getNextTable() override;
    Table getNextAllBefore() override;
    Table getNextAllAfter() override;
    Table getNextAfterByBefore(StmtNo before) override;
    Table getNextBeforeByAfter(StmtNo after) override;

    /*
    Table getNextTTable() override; // generated each query
    Table getNextTAllBefore() override;
    Table getNextTAllAfter() override;
    Table getNextTAfterByBefore(StmtNo before) override;
    Table getNextTBeforeByAfter(StmtNo after) override;
    */

    Table getParentTable() override;
    Table getParentAllChildren() override;
    Table getParentAllParents() override;
    Table getParentChildByParent(StmtNo parent) override;
    Table getParentParentByChild(StmtNo child) override;

    Table getParentTTable() override;
    Table getParentTAllChildren() override;
    Table getParentTAllParents() override;
    Table getParentTChildByParent(StmtNo parent) override;
    Table getParentTParentByChild(StmtNo child) override;

    Table getPatternAsgnTable() override;
    Table getPatternAsgnByStmt(StmtNo sNum) override;
    Table getPatternAsgnByLhs(VarName Lhs) override;
    Table getPatternAsgnByRhs(std::string Rhs) override;

    Table getPatternIfTable() override;
    Table getPatternIfAllStmts() override;
    Table getPatternIfAllVars() override;
    Table getPatternIfVarsByStmt(StmtNo sNum) override;
    Table getPatternIfStmtsByVar(VarName var) override;

    Table getPatternWhileTable() override;
    Table getPatternWhileAllStmts() override;
    Table getPatternWhileAllVars() override;
    Table getPatternWhileVarsByStmt(StmtNo sNum) override;
    Table getPatternWhileStmtsByVar(VarName var) override;

    Table getUsesPTable() override;
    Table getUsesPAllProcs() override;
    Table getUsesPAllVars() override;
    Table getUsesPVarsByProc(ProcName user) override;
    Table getUsesPProcsByVar(VarName used) override;

    Table getUsesSTable() override;
    Table getUsesSAllStmts() override;
    Table getUsesSAllVars() override;
    Table getUsesSVarsByStmt(StmtNo user) override;
    Table getUsesSStmtsByVar(VarName used) override;
};