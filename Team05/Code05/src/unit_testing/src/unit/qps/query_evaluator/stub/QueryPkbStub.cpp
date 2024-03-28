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
    return false;
}
bool QueryPkbStub::checkNextT(StmtNo before, StmtNo after) {
    return false;
}
bool QueryPkbStub::resetAffects() {
    return false;
}
bool QueryPkbStub::resetNextT() {
    return false;
}

Table QueryPkbStub::getCallTable() {
    return callTable;
}

Table QueryPkbStub::getCallAllStmts() {
    return {{}};
}

Table QueryPkbStub::getCallAllProcs() {
    return {{}};
}

Table QueryPkbStub::getCallProcsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getCallStmtsByProc(ProcName proc) {
    return {{}};
}

Table QueryPkbStub::getConstTable() {
    return constTable;
}

Table QueryPkbStub::getConstAllStmts() {
    return {{}};
}

Table QueryPkbStub::getConstAllValues() {
    return {{}};
}

Table QueryPkbStub::getConstStmtsByVal(ConstVal val) {
    return {{}};
}

Table QueryPkbStub::getConstValuesByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getIfTable() {
    return ifTable;
}

Table QueryPkbStub::getIfAllStmts() {
    return {{}};
}

Table QueryPkbStub::getIfAllVars() {
    return {{}};
}

Table QueryPkbStub::getIfVarsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getIfStmtsByVar(VarName var) {
    return {{}};
}

Table QueryPkbStub::getPrintTable() {
    return printTable;
}

Table QueryPkbStub::getPrintAllStmts() {
    return {{}};
}

Table QueryPkbStub::getPrintAllVars() {
    return {{}};
}

Table QueryPkbStub::getPrintVarsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getPrintStmtsByVar(VarName var) {
    return {{}};
}

Table QueryPkbStub::getProcTable() {
    return procedureTable;
}

Table QueryPkbStub::getReadTable() {
    return readTable;
}

Table QueryPkbStub::getReadAllStmts() {
    return {{}};
}

Table QueryPkbStub::getReadAllVars() {
    return {{}};
}

Table QueryPkbStub::getReadVarsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getReadStmtsByVar(VarName var) {
    return {{}};
}

Table QueryPkbStub::getStmtTable() {
    return statementTable;
}

Table QueryPkbStub::getVarTable() {
    return varTable;
}

Table QueryPkbStub::getVarAllStmts() {
    return {{}};
}

Table QueryPkbStub::getVarAllVars() {
    return {{}};
}

Table QueryPkbStub::getVarVarsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getVarStmtsByVar(VarName var) {
    return {{}};
}

Table QueryPkbStub::getWhileTable() {
    return whileTable;
}

Table QueryPkbStub::getWhileAllStmts() {
    return {{}};
}

Table QueryPkbStub::getWhileAllVars() {
    return {{}};
}

Table QueryPkbStub::getWhileVarsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getWhileStmtsByVar(VarName var) {
    return {{}};
}

/*
Table QueryPkbStub::getAffectsTable() {
    return affectsTable;
}

Table QueryPkbStub::getAffectsAllAffectors() {
    return {{}};
}

Table QueryPkbStub::getAffectsAllAffected() {
    return {{}};
}

Table QueryPkbStub::getAffectsAffectedByAffector(StmtNo before) {
    return {{}};
}

Table QueryPkbStub::getAffectsAffectorsByAffected(StmtNo after) {
    return {{}};
}
 */

Table QueryPkbStub::getCallsTable() {
    return callsTable;
}

Table QueryPkbStub::getCallsAllCallers() {
    return {{}};
}

Table QueryPkbStub::getCallsAllCalled() {
    return {{}};
}

Table QueryPkbStub::getCallsCalledByCaller(ProcName caller) {
    return {{}};
}

Table QueryPkbStub::getCallsCallerByCalled(ProcName called) {
    return {{}};
}

Table QueryPkbStub::getCallsTTable() {
    return callsTTable;
}

Table QueryPkbStub::getCallsTAllCallers() {
    return {{}};
}

Table QueryPkbStub::getCallsTAllCalled() {
    return {{}};
}

Table QueryPkbStub::getCallsTCalledByCaller(ProcName caller) {
    return {{}};
}

Table QueryPkbStub::getCallsTCallerByCalled(ProcName called) {
    return {{}};
}

Table QueryPkbStub::getFollowsTable() {
    return followsTable;
}

Table QueryPkbStub::getFollowsAllBefore() {
    return {{}};
}

Table QueryPkbStub::getFollowsAllAfter() {
    return {{}};
}

Table QueryPkbStub::getFollowsAfterByBefore(StmtNo before) {
    return {{}};
}

Table QueryPkbStub::getFollowsBeforeByAfter(StmtNo after) {
    return {{}};
}

Table QueryPkbStub::getFollowsTTable() {
    return followsTTable;
}

Table QueryPkbStub::getFollowsTAllBefore() {
    return {{}};
}

Table QueryPkbStub::getFollowsTAllAfter() {
    return {{}};
}

Table QueryPkbStub::getFollowsTAfterByBefore(StmtNo before) {
    return {{}};
}

Table QueryPkbStub::getFollowsTBeforeByAfter(StmtNo after) {
    return {{}};
}

Table QueryPkbStub::getModifiesPTable() {
    return modifiesPTable;
}

Table QueryPkbStub::getModifiesPAllProcs() {
    return {{}};
}

Table QueryPkbStub::getModifiesPAllVars() {
    return {{}};
}

Table QueryPkbStub::getModifiesPVarsByProc(ProcName modifier) {
    return {{}};
}

Table QueryPkbStub::getModifiesPProcsByVar(VarName modified) {
    return {{}};
}

Table QueryPkbStub::getModifiesSTable() {
    return modifiesSTable;
}

Table QueryPkbStub::getModifiesSAllStmts() {
    return {{}};
}

Table QueryPkbStub::getModifiesSAllVars() {
    return {{}};
}

Table QueryPkbStub::getModifiesSVarsByStmt(StmtNo modifier) {
    return {{}};
}

Table QueryPkbStub::getModifiesSStmtsByVar(VarName modified) {
    return {{}};
}

Table QueryPkbStub::getNextTable() {
    return nextTable;
}

Table QueryPkbStub::getNextAllBefore() {
    return {{}};
}

Table QueryPkbStub::getNextAllAfter() {
    return {{}};
}

Table QueryPkbStub::getNextAfterByBefore(StmtNo before) {
    return {{}};
}

Table QueryPkbStub::getNextBeforeByAfter(StmtNo after) {
    return {{}};
}

/*
Table QueryPkbStub::getNextTTable() {
    return nextTTable;
}

Table QueryPkbStub::getNextTAllBefore() {
    return {{}};
}

Table QueryPkbStub::getNextTAllAfter() {
    return {{}};
}

Table QueryPkbStub::getNextTAfterByBefore(StmtNo before) {
    return {{}};
}

Table QueryPkbStub::getNextTBeforeByAfter(StmtNo after) {
    return {{}};
}
 */

Table QueryPkbStub::getParentTable() {
    return parentTable;
}

Table QueryPkbStub::getParentAllChildren() {
    return {{}};
}

Table QueryPkbStub::getParentAllParents() {
    return {{}};
}

Table QueryPkbStub::getParentChildByParent(StmtNo parent) {
    return {{}};
}

Table QueryPkbStub::getParentParentByChild(StmtNo child) {
    return {{}};
}

Table QueryPkbStub::getParentTTable() {
    return parentTTable;
}

Table QueryPkbStub::getParentTAllChildren() {
    return {{}};
}

Table QueryPkbStub::getParentTAllParents() {
    return {{}};
}

Table QueryPkbStub::getParentTChildByParent(StmtNo parent) {
    return {{}};
}

Table QueryPkbStub::getParentTParentByChild(StmtNo child) {
    return {{}};
}

Table QueryPkbStub::getPatternAsgnTable() {
    return patternAsgnTable;
}

Table QueryPkbStub::getPatternAsgnByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getPatternAsgnByLhs(VarName Lhs) {
    return {{}};
}
Table QueryPkbStub::getPatternAsgnByRhs(std::string Rhs) {
    return {{}};
}

Table QueryPkbStub::getPatternIfTable() {
    return patternIfTable;
}

Table QueryPkbStub::getPatternIfAllStmts() {
    return {{}};
}

Table QueryPkbStub::getPatternIfAllVars() {
    return {{}};
}

Table QueryPkbStub::getPatternIfVarsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getPatternIfStmtsByVar(VarName var) {
    return {{}};
}

Table QueryPkbStub::getPatternWhileTable() {
    return patternWhileTable;
}

Table QueryPkbStub::getPatternWhileAllStmts() {
    return {{}};
}

Table QueryPkbStub::getPatternWhileAllVars() {
    return {{}};
}

Table QueryPkbStub::getPatternWhileVarsByStmt(StmtNo sNum) {
    return {{}};
}

Table QueryPkbStub::getPatternWhileStmtsByVar(VarName var) {
    return {{}};
}

Table QueryPkbStub::getUsesPTable() {
    return usesPTable;
}

Table QueryPkbStub::getUsesPAllProcs() {
    return {{}};
}

Table QueryPkbStub::getUsesPAllVars() {
    return {{}};
}

Table QueryPkbStub::getUsesPVarsByProc(ProcName user) {
    return {{}};
}

Table QueryPkbStub::getUsesPProcsByVar(VarName used) {
    return {{}};
}

Table QueryPkbStub::getUsesSTable() {
    return usesSTable;
}

Table QueryPkbStub::getUsesSAllStmts() {
    return {{}};
}

Table QueryPkbStub::getUsesSAllVars() {
    return {{}};
}

Table QueryPkbStub::getUsesSVarsByStmt(StmtNo user) {
    return {{}};
}

Table QueryPkbStub::getUsesSStmtsByVar(VarName used) {
    return {{}};
}

