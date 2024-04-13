//
// Created by tohzahnqing on 21/2/2024.
//

#include "QueryPkbStub.h"

#include <utility>

void QueryPkbStub::setRead(Table t) {
    readTable = std::move(t);
}

void QueryPkbStub::setCallStmt(Table t) {
    callTable = std::move(t);
}

void QueryPkbStub::setWhile(Table t) {
    whileTable = std::move(t);
}

void QueryPkbStub::setIf(Table t) {
    ifTable = std::move(t);
}

void QueryPkbStub::setPrint(Table t) {
    printTable = std::move(t);
}

void QueryPkbStub::setStatement(int ending) {
    Table t;
    for (int i = 1; i <= ending; i++) {
        t.push_back({std::to_string(i)});
    }
    statementTable = std::move(t);
}

void QueryPkbStub::setStatement(std::vector<std::vector<std::string>> t) {
    statementTable = std::move(t);
}

// {"a", "a"}
void QueryPkbStub::setProcedure(Table t) {
    procedureTable = std::move(t);
}

void QueryPkbStub::setVar(Table t) {
    varTable = std::move(t);
}

void QueryPkbStub::setConst(Table t) {
    constTable = std::move(t);
}

void QueryPkbStub::setFollows(Table t) {
    followsTable = std::move(t);
}

void QueryPkbStub::setFollowsT(Table t) {
    followsTTable = std::move(t);
}

void QueryPkbStub::setParent(Table t) {
    parentTable = std::move(t);
}

void QueryPkbStub::setParentT(Table t) {
    parentTTable = std::move(t);
}

void QueryPkbStub::setUses(Table t) {
    usesSTable = std::move(t);
}

void QueryPkbStub::setModifies(Table t) {
    modifiesSTable = std::move(t);
}

void QueryPkbStub::setPatternAsgn(Table t) {
    patternAsgnTable = std::move(t);
}

void QueryPkbStub::setPatternWhile(Table t) {
    patternWhileTable = std::move(t);
}

void QueryPkbStub::setPatternIf(Table t) {
    patternIfTable = std::move(t);
}

void QueryPkbStub::setUsesP(Table t) {
    usesPTable = std::move(t);
}

void QueryPkbStub::setModifiesP(Table t) {
    modifiesPTable = std::move(t);
}

void QueryPkbStub::setCalls(Table t) {
    callsTable = std::move(t);
}

void QueryPkbStub::setCallsT(Table t) {
    callsTTable = std::move(t);
}

bool QueryPkbStub::checkAffects(StmtNo affector, StmtNo affected) {
    // TODO: QPS to implement
    return false;
}
bool QueryPkbStub::checkNextT(StmtNo before, StmtNo after) {
    // TODO: QPS to implement
    return false;
}
bool QueryPkbStub::resetAffects() {
    // TODO: QPS to implement
    return false;
}
bool QueryPkbStub::resetNextT() {
    // TODO: QPS to implement
    return false;
}

Table QueryPkbStub::getCallTable() {
    return callTable;
}

Table QueryPkbStub::getCallAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getCallAllProcs() {
    return emptyTable;
}

Table QueryPkbStub::getCallProcsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getCallStmtsByProc(ProcName proc) {
    return emptyTable;
}

Table QueryPkbStub::getConstTable() {
    return constTable;
}

Table QueryPkbStub::getConstAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getConstAllValues() {
    return emptyTable;
}

Table QueryPkbStub::getConstStmtsByVal(ConstVal val) {
    return emptyTable;
}

Table QueryPkbStub::getConstValuesByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getIfTable() {
    return ifTable;
}

Table QueryPkbStub::getIfAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getIfAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getIfVarsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getIfStmtsByVar(VarName var) {
    return emptyTable;
}

Table QueryPkbStub::getPrintTable() {
    return printTable;
}

Table QueryPkbStub::getPrintAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getPrintAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getPrintVarsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getPrintStmtsByVar(VarName var) {
    return emptyTable;
}

Table QueryPkbStub::getProcTable() {
    return procedureTable;
}

Table QueryPkbStub::getReadTable() {
    return readTable;
}

Table QueryPkbStub::getReadAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getReadAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getReadVarsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getReadStmtsByVar(VarName var) {
    return emptyTable;
}

Table QueryPkbStub::getStmtTable() {
    return statementTable;
}

Table QueryPkbStub::getVarTable() {
    return varTable;
}

Table QueryPkbStub::getVarAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getVarAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getVarVarsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getVarStmtsByVar(VarName var) {
    return emptyTable;
}

Table QueryPkbStub::getWhileTable() {
    return whileTable;
}

Table QueryPkbStub::getWhileAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getWhileAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getWhileVarsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getWhileStmtsByVar(VarName var) {
    return emptyTable;
}

/*
Table QueryPkbStub::getAffectsTable() {
    return affectsTable;
}

Table QueryPkbStub::getAffectsAllAffectors() {
    return emptyTable;
}

Table QueryPkbStub::getAffectsAllAffected() {
    return emptyTable;
}

Table QueryPkbStub::getAffectsAffectedByAffector(StmtNo before) {
    return emptyTable;
}

Table QueryPkbStub::getAffectsAffectorsByAffected(StmtNo after) {
    return emptyTable;
}
 */

Table QueryPkbStub::getCallsTable() {
    return callsTable;
}

Table QueryPkbStub::getCallsAllCallers() {
    return emptyTable;
}

Table QueryPkbStub::getCallsAllCalled() {
    return emptyTable;
}

Table QueryPkbStub::getCallsCalledByCaller(ProcName caller) {
    return emptyTable;
}

Table QueryPkbStub::getCallsCallerByCalled(ProcName called) {
    return emptyTable;
}

Table QueryPkbStub::getCallsTTable() {
    return callsTTable;
}

Table QueryPkbStub::getCallsTAllCallers() {
    return emptyTable;
}

Table QueryPkbStub::getCallsTAllCalled() {
    return emptyTable;
}

Table QueryPkbStub::getCallsTCalledByCaller(ProcName caller) {
    return emptyTable;
}

Table QueryPkbStub::getCallsTCallerByCalled(ProcName called) {
    return emptyTable;
}

Table QueryPkbStub::getFollowsTable() {
    return followsTable;
}

Table QueryPkbStub::getFollowsAllBefore() {
    return emptyTable;
}

Table QueryPkbStub::getFollowsAllAfter() {
    return emptyTable;
}

Table QueryPkbStub::getFollowsAfterByBefore(StmtNo before) {
    return emptyTable;
}

Table QueryPkbStub::getFollowsBeforeByAfter(StmtNo after) {
    return emptyTable;
}

Table QueryPkbStub::getFollowsTTable() {
    return followsTTable;
}

Table QueryPkbStub::getFollowsTAllBefore() {
    return emptyTable;
}

Table QueryPkbStub::getFollowsTAllAfter() {
    return emptyTable;
}

Table QueryPkbStub::getFollowsTAfterByBefore(StmtNo before) {
    return emptyTable;
}

Table QueryPkbStub::getFollowsTBeforeByAfter(StmtNo after) {
    return emptyTable;
}

Table QueryPkbStub::getModifiesPTable() {
    return modifiesPTable;
}

Table QueryPkbStub::getModifiesPAllProcs() {
    return emptyTable;
}

Table QueryPkbStub::getModifiesPAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getModifiesPVarsByProc(ProcName modifier) {
    return emptyTable;
}

Table QueryPkbStub::getModifiesPProcsByVar(VarName modified) {
    return emptyTable;
}
bool QueryPkbStub::isModifiesP(ProcName p, VarName v) {
    return false;
}

Table QueryPkbStub::getModifiesSTable() {
    return modifiesSTable;
}

Table QueryPkbStub::getModifiesSAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getModifiesSAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getModifiesSVarsByStmt(StmtNo modifier) {
    return emptyTable;
}

Table QueryPkbStub::getModifiesSStmtsByVar(VarName modified) {
    return emptyTable;
}

Table QueryPkbStub::getNextTable() {
    return nextTable;
}

Table QueryPkbStub::getNextAllBefore() {
    return emptyTable;
}

Table QueryPkbStub::getNextAllAfter() {
    return emptyTable;
}

Table QueryPkbStub::getNextAfterByBefore(StmtNo before) {
    return emptyTable;
}

Table QueryPkbStub::getNextBeforeByAfter(StmtNo after) {
    return emptyTable;
}

/*
Table QueryPkbStub::getNextTTable() {
    return nextTTable;
}

Table QueryPkbStub::getNextTAllBefore() {
    return emptyTable;
}

Table QueryPkbStub::getNextTAllAfter() {
    return emptyTable;
}

Table QueryPkbStub::getNextTAfterByBefore(StmtNo before) {
    return emptyTable;
}

Table QueryPkbStub::getNextTBeforeByAfter(StmtNo after) {
    return emptyTable;
}
 */

Table QueryPkbStub::getParentTable() {
    return parentTable;
}

Table QueryPkbStub::getParentAllChildren() {
    return emptyTable;
}

Table QueryPkbStub::getParentAllParents() {
    return emptyTable;
}

Table QueryPkbStub::getParentChildByParent(StmtNo parent) {
    return emptyTable;
}

Table QueryPkbStub::getParentParentByChild(StmtNo child) {
    return emptyTable;
}

Table QueryPkbStub::getParentTTable() {
    return parentTTable;
}

Table QueryPkbStub::getParentTAllChildren() {
    return emptyTable;
}

Table QueryPkbStub::getParentTAllParents() {
    return emptyTable;
}

Table QueryPkbStub::getParentTChildByParent(StmtNo parent) {
    return emptyTable;
}

Table QueryPkbStub::getParentTParentByChild(StmtNo child) {
    return emptyTable;
}

Table QueryPkbStub::getPatternAsgnTable() {
    return patternAsgnTable;
}

Table QueryPkbStub::getPatternAsgnByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getPatternAsgnByLhs(VarName Lhs) {
    return emptyTable;
}
Table QueryPkbStub::getPatternAsgnByRhs(std::string Rhs) {
    return emptyTable;
}
bool QueryPkbStub::isAsgn(StmtNo sNum) {
    return false;
}

Table QueryPkbStub::getPatternIfTable() {
    return patternIfTable;
}

Table QueryPkbStub::getPatternIfAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getPatternIfAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getPatternIfVarsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getPatternIfStmtsByVar(VarName var) {
    return emptyTable;
}

Table QueryPkbStub::getPatternWhileTable() {
    return patternWhileTable;
}

Table QueryPkbStub::getPatternWhileAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getPatternWhileAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getPatternWhileVarsByStmt(StmtNo sNum) {
    return emptyTable;
}

Table QueryPkbStub::getPatternWhileStmtsByVar(VarName var) {
    return emptyTable;
}

Table QueryPkbStub::getUsesPTable() {
    return usesPTable;
}

Table QueryPkbStub::getUsesPAllProcs() {
    return emptyTable;
}

Table QueryPkbStub::getUsesPAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getUsesPVarsByProc(ProcName user) {
    return emptyTable;
}

Table QueryPkbStub::getUsesPProcsByVar(VarName used) {
    return emptyTable;
}

Table QueryPkbStub::getUsesSTable() {
    return usesSTable;
}

Table QueryPkbStub::getUsesSAllStmts() {
    return emptyTable;
}

Table QueryPkbStub::getUsesSAllVars() {
    return emptyTable;
}

Table QueryPkbStub::getUsesSVarsByStmt(StmtNo user) {
    return emptyTable;
}

Table QueryPkbStub::getUsesSStmtsByVar(VarName used) {
    return emptyTable;
}

