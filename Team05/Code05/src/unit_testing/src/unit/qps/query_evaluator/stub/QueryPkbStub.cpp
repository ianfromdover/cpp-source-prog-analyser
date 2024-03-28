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

Table QueryPkbStub::getCallByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getCallByProc(ProcName proc) {
    return {{}};
}
Table QueryPkbStub::getCallTable() {
    return callTable;
}
Table QueryPkbStub::getProcByName(ProcName proc) {
    return {{}};
}
Table QueryPkbStub::getProcTable() {
    return procedureTable;
}
Table QueryPkbStub::getReadByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getReadByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getReadTable() {
    return readTable;
}
Table QueryPkbStub::getIfByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getIfByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getIfStmts() {
    return table;
}
Table QueryPkbStub::getIfTable() {
    return ifTable;
}
Table QueryPkbStub::getWhileByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getWhileByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getWhileStmts() {
    return table;
}
Table QueryPkbStub::getWhileTable() {
    return whileTable;
}
Table QueryPkbStub::getPrintByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getPrintByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getPrintTable() {
    return printTable;
}
Table QueryPkbStub::getStmtByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getStmtTable() {
    return statementTable;
}
Table QueryPkbStub::getVars() {
    return table;
}
Table QueryPkbStub::getVarTable() {
    return varTable;
}
Table QueryPkbStub::getConstByName(VarName var) {
    return {{}};
}
Table QueryPkbStub::getConsts() {
    return table;
}
Table QueryPkbStub::getConstTable() {
    return constTable;
}
Table QueryPkbStub::getFollowsByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getFollowsByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getFollowsTable() {
    return followsTable;
}
Table QueryPkbStub::getFollowsTByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getFollowsTByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getFollowsTTable() {
    return followsTTable;
}
Table QueryPkbStub::getParentByParent(StmtNo parent) {
    return {{}};
}
Table QueryPkbStub::getParentByChild(StmtNo child) {
    return {{}};
}
Table QueryPkbStub::getParentTable() {
    return parentTable;
}
Table QueryPkbStub::getParentTByParent(StmtNo parent) {
    return {{}};
}
Table QueryPkbStub::getParentTByChild(StmtNo child) {
    return {{}};
}
Table QueryPkbStub::getParentTTable() {
    return parentTTable;
}
Table QueryPkbStub::getUsesSByNum(StmtNo user) {
    return {{}};
}
Table QueryPkbStub::getUsesSByVar(VarName used) {
    return {{}};
}
Table QueryPkbStub::getUsesSTable() {
    return usesSTable;
}
Table QueryPkbStub::getUsesPTable() {
    return usesPTable;
}
Table QueryPkbStub::getModifiesSByNum(StmtNo modifier) {
    return {{}};
}
Table QueryPkbStub::getModifiesSByVar(VarName modified) {
    return {{}};
}
Table QueryPkbStub::getModifiesSTable() {
    return modifiesSTable;
}
Table QueryPkbStub::getModifiesPByProc(ProcName modifier) {
    return {{}};
}
Table QueryPkbStub::getModifiesPByVar(VarName modified) {
    return {{}};
}
Table QueryPkbStub::getModifiesPTable() {
    return modifiesPTable;
}
Table QueryPkbStub::getPatternAsgnByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getPatternAsgnByLhs(std::string Lhs) {
    return {{}};
}
Table QueryPkbStub::getPatternAsgnByRhs(std::string Rhs) {
    return {{}};
}
Table QueryPkbStub::getPatternAsgnByLhsPartial(std::string LhsPartial) {
    return {{}};
}
Table QueryPkbStub::getPatternAsgnByRhsPartial(std::string RhsPartial) {
    return {{}};
}
Table QueryPkbStub::getPatternAsgnTable() {
    return patternAsgnTable;
}
Table QueryPkbStub::getPatternIfByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getPatternIfByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getPatternIfTable() {
    return patternIfTable;
}
Table QueryPkbStub::getPatternWhileByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getPatternWhileByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getPatternWhileTable() {
    return patternWhileTable;
}
Table QueryPkbStub::getCallsByCaller(ProcName caller) {
    return {{}};
}
Table QueryPkbStub::getCallsByCalled(ProcName called) {
    return {{}};
}
Table QueryPkbStub::getCallsTable() {
    return callsTable;
}
Table QueryPkbStub::getCallsTByCaller(ProcName caller) {
    return {{}};
}
Table QueryPkbStub::getCallsTByCalled(ProcName called) {
    return {{}};
}
Table QueryPkbStub::getCallsTTable() {
    return callsTTable;
}
Table QueryPkbStub::getNextByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getNextByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getNextTable() {
    return nextTable;
}
Table QueryPkbStub::getNextTByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getNextTByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getNextTTable() {
    return nextTTable;
}
Table QueryPkbStub::getAffectsByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getAffectsByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getAffectsTable() {
    return table;
}
