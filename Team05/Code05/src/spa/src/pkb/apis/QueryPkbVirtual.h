#pragma once
#define SPA_QUERYPKBVIRTUAL_H

#include "PkbStorage.h"
#include "common/SpaTypes.h"

class QueryPkbVirtual {
public:

    // on-demand --------------------------------------------------------------
    virtual bool checkAffects(StmtNo affector, StmtNo affected) = 0;
    virtual bool checkNextT(StmtNo before, StmtNo after) = 0;
    virtual bool resetAffects() = 0;
    virtual bool resetNextT() = 0;

    // entities ----------------------------------------------------`----------
    // (StmtNo | ProcName)
    virtual Table getCallTable() = 0;
    virtual Table getCallAllStmts() = 0;
    virtual Table getCallAllProcs() = 0;
    virtual Table getCallProcsByStmt(StmtNo sNum) = 0;
    virtual Table getCallStmtsByProc(ProcName proc) = 0;

    // (StmtNo | ConstVal)
    virtual Table getConstTable() = 0;
    virtual Table getConstAllStmts() = 0;
    virtual Table getConstAllValues() = 0;
    virtual Table getConstStmtsByVal(ConstVal val) = 0;
    virtual Table getConstValuesByStmt(StmtNo sNum) = 0;

    // (StmtNo | VarName)
    virtual Table getIfTable() = 0;
    virtual Table getIfAllStmts() = 0;
    virtual Table getIfAllVars() = 0;
    virtual Table getIfVarsByStmt(StmtNo sNum) = 0;
    virtual Table getIfStmtsByVar(VarName var) = 0;

    // (StmtNo | VarName)
    virtual Table getPrintTable() = 0;
    virtual Table getPrintAllStmts() = 0;
    virtual Table getPrintAllVars() = 0;
    virtual Table getPrintVarsByStmt(StmtNo sNum) = 0;
    virtual Table getPrintStmtsByVar(VarName var) = 0;

    // (ProcName)
    virtual Table getProcTable() = 0;
    // should i add a containsProc method? for with clause

    // (StmtNo | VarName)
    virtual Table getReadTable() = 0;
    virtual Table getReadAllStmts() = 0;
    virtual Table getReadAllVars() = 0;
    virtual Table getReadVarsByStmt(StmtNo sNum) = 0;
    virtual Table getReadStmtsByVar(VarName var) = 0;

    // (StmtNo)
    virtual Table getStmtTable() = 0;
    // should i add a containsStmt method? for with clause

    // (StmtNo | VarName)
    virtual Table getVarTable() = 0;
    virtual Table getVarAllStmts() = 0;
    virtual Table getVarAllVars() = 0;
    virtual Table getVarVarsByStmt(StmtNo sNum) = 0;
    virtual Table getVarStmtsByVar(VarName var) = 0;

    // (StmtNo | VarName)
    virtual Table getWhileTable() = 0;
    virtual Table getWhileAllStmts() = 0;
    virtual Table getWhileAllVars() = 0;
    virtual Table getWhileVarsByStmt(StmtNo sNum) = 0;
    virtual Table getWhileStmtsByVar(VarName var) = 0;

    // relations --------------------------------------------------------------

    /*
    // (StmtNo | StmtNo)
    virtual Table getAffectsTable() = 0; // generated each query
    virtual Table getAffectsAllAffectors() = 0;
    virtual Table getAffectsAllAffected() = 0;
    virtual Table getAffectsAffectedByAffector(StmtNo affector) = 0;
    virtual Table getAffectsAffectorsByAffected(StmtNo affected) = 0;
     */

    // (ProcName | ProcName)
    virtual Table getCallsTable() = 0;
    virtual Table getCallsAllCallers() = 0;
    virtual Table getCallsAllCalled() = 0;
    virtual Table getCallsCalledByCaller(ProcName caller) = 0;
    virtual Table getCallsCallerByCalled(ProcName called) = 0;

    // (ProcName | ProcName)
    virtual Table getCallsTTable() = 0;
    virtual Table getCallsTAllCallers() = 0;
    virtual Table getCallsTAllCalled() = 0;
    virtual Table getCallsTCalledByCaller(ProcName caller) = 0;
    virtual Table getCallsTCallerByCalled(ProcName called) = 0;

    // (StmtNo | StmtNo)
    virtual Table getFollowsTable() = 0;
    virtual Table getFollowsAllBefore() = 0;
    virtual Table getFollowsAllAfter() = 0;
    virtual Table getFollowsAfterByBefore(StmtNo before) = 0;
    virtual Table getFollowsBeforeByAfter(StmtNo after) = 0;

    // (StmtNo | StmtNo)
    virtual Table getFollowsTTable() = 0;
    virtual Table getFollowsTAllBefore() = 0;
    virtual Table getFollowsTAllAfter() = 0;
    virtual Table getFollowsTAfterByBefore(StmtNo before) = 0;
    virtual Table getFollowsTBeforeByAfter(StmtNo after) = 0;

    // (ProcName | VarName)
    virtual Table getModifiesPTable() = 0;
    virtual Table getModifiesPAllProcs() = 0;
    virtual Table getModifiesPAllVars() = 0;
    virtual Table getModifiesPVarsByProc(ProcName modifier) = 0;
    virtual Table getModifiesPProcsByVar(VarName modified) = 0;

    // (StmtNo | VarName)
    virtual Table getModifiesSTable() = 0;
    virtual Table getModifiesSAllStmts() = 0;
    virtual Table getModifiesSAllVars() = 0;
    virtual Table getModifiesSVarsByStmt(StmtNo modifier) = 0;
    virtual Table getModifiesSStmtsByVar(VarName modified) = 0;

    // (StmtNo | StmtNo)
    virtual Table getNextTable() = 0;
    virtual Table getNextAllBefore() = 0;
    virtual Table getNextAllAfter() = 0;
    virtual Table getNextAfterByBefore(StmtNo before) = 0;
    virtual Table getNextBeforeByAfter(StmtNo after) = 0;

    /*
    // (StmtNo | StmtNo)
    virtual Table getNextTTable() = 0; // generated each query
    virtual Table getNextTAllBefore() = 0;
    virtual Table getNextTAllAfter() = 0;
    virtual Table getNextTAfterByBefore(StmtNo before) = 0;
    virtual Table getNextTBeforeByAfter(StmtNo after) = 0;
     */

    // (StmtNo | StmtNo)
    virtual Table getParentTable() = 0;
    virtual Table getParentAllChildren() = 0;
    virtual Table getParentAllParents() = 0;
    virtual Table getParentChildByParent(StmtNo parent) = 0;
    virtual Table getParentParentByChild(StmtNo child) = 0;

    // (StmtNo | StmtNo)
    virtual Table getParentTTable() = 0;
    virtual Table getParentTAllChildren() = 0;
    virtual Table getParentTAllParents() = 0;
    virtual Table getParentTChildByParent(StmtNo parent) = 0;
    virtual Table getParentTParentByChild(StmtNo child) = 0;

    // (StmtNo | VarName | std::string)
    virtual Table getPatternAsgnTable() = 0;
    virtual Table getPatternAsgnByStmt(StmtNo sNum) = 0;
    virtual Table getPatternAsgnByLhs(VarName Lhs) = 0;
    virtual Table getPatternAsgnByRhs(std::string Rhs) = 0;

    // (StmtNo | VarName)
    virtual Table getPatternIfTable() = 0;
    virtual Table getPatternIfAllStmts() = 0;
    virtual Table getPatternIfAllVars() = 0;
    virtual Table getPatternIfVarsByStmt(StmtNo sNum) = 0;
    virtual Table getPatternIfStmtsByVar(VarName var) = 0;

    // (StmtNo | VarName)
    virtual Table getPatternWhileTable() = 0;
    virtual Table getPatternWhileAllStmts() = 0;
    virtual Table getPatternWhileAllVars() = 0;
    virtual Table getPatternWhileVarsByStmt(StmtNo sNum) = 0;
    virtual Table getPatternWhileStmtsByVar(VarName var) = 0;

    // (ProcName | VarName)
    virtual Table getUsesPTable() = 0;
    virtual Table getUsesPAllProcs() = 0;
    virtual Table getUsesPAllVars() = 0;
    virtual Table getUsesPVarsByProc(ProcName user) = 0;
    virtual Table getUsesPProcsByVar(VarName used) = 0;

    // (StmtNo | VarName)
    virtual Table getUsesSTable() = 0;
    virtual Table getUsesSAllStmts() = 0;
    virtual Table getUsesSAllVars() = 0;
    virtual Table getUsesSVarsByStmt(StmtNo user) = 0;
    virtual Table getUsesSStmtsByVar(VarName used) = 0;
};
