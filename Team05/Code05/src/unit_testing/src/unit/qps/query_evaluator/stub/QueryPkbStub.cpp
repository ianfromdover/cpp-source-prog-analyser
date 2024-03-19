//
// Created by tohzahnqing on 21/2/2024.
//

#include "QueryPkbStub.h"

#include <utility>

void QueryPkbStub::setRead(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setCallStmt(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setWhile(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setIf(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setPrint(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setStatement(int ending) {
    Table t;
    for (int i = 1; i <= ending; i++) {
        t.push_back({std::to_string(i)});
    }
    table = std::move(t);
}

// {"a", "a"}
void QueryPkbStub::setProcedure(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setVar(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setConst(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setFollows(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setFollowsT(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setParent(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setParentT(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setUses(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setModifies(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setPatternAsgn(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setUsesP(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setModifiesP(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setCalls(Table t) {
    table = std::move(t);
}

void QueryPkbStub::setCallsT(Table t) {
    table = std::move(t);
}

Table QueryPkbStub::getCallByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getCallByProc(ProcName proc) {
    return {{}};
}
Table QueryPkbStub::getCallTable() {
    return table;
}
Table QueryPkbStub::getProcByName(ProcName proc) {
    return {{}};
}
Table QueryPkbStub::getProcTable() {
    return table;
}
Table QueryPkbStub::getReadByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getReadByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getReadTable() {
    return table;
}
Table QueryPkbStub::getIfByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getIfByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getIfTable() {
    return table;
}
Table QueryPkbStub::getWhileByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getWhileByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getWhileTable() {
    return table;
}
Table QueryPkbStub::getPrintByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getPrintByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getPrintTable() {
    return table;
}
Table QueryPkbStub::getStmtByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getStmtTable() {
    return table;
}
Table QueryPkbStub::getVarByName(VarName var) {
    return {{}};
}
Table QueryPkbStub::getVarTable() {
    return table;
}
Table QueryPkbStub::getConstByName(VarName var) {
    return {{}};
}
Table QueryPkbStub::getConstTable() {
    return table;
}
Table QueryPkbStub::getFollowsByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getFollowsByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getFollowsTable() {
    return table;
}
Table QueryPkbStub::getFollowsTByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getFollowsTByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getFollowsTTable() {
    return table;
}
Table QueryPkbStub::getParentByParent(StmtNo parent) {
    return {{}};
}
Table QueryPkbStub::getParentByChild(StmtNo child) {
    return {{}};
}
Table QueryPkbStub::getParentTable() {
    return table;
}
Table QueryPkbStub::getParentTByParent(StmtNo parent) {
    return {{}};
}
Table QueryPkbStub::getParentTByChild(StmtNo child) {
    return {{}};
}
Table QueryPkbStub::getParentTTable() {
    return table;
}
Table QueryPkbStub::getUsesSByNum(StmtNo user) {
    return {{}};
}
Table QueryPkbStub::getUsesSByVar(VarName used) {
    return {{}};
}
Table QueryPkbStub::getUsesSTable() {
    return table;
}
Table QueryPkbStub::getUsesPTable() {
    return table;
}
Table QueryPkbStub::getModifiesSByNum(StmtNo modifier) {
    return {{}};
}
Table QueryPkbStub::getModifiesSByVar(VarName modified) {
    return {{}};
}
Table QueryPkbStub::getModifiesSTable() {
    return table;
}
Table QueryPkbStub::getModifiesPByProc(ProcName modifier) {
    return {{}};
}
Table QueryPkbStub::getModifiesPByVar(VarName modified) {
    return {{}};
}
Table QueryPkbStub::getModifiesPTable() {
    return table;
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
    return table;
}
Table QueryPkbStub::getPatternIfByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getPatternIfByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getPatternIfTable() {
    return table;
}
Table QueryPkbStub::getPatternWhileByNum(StmtNo sNum) {
    return {{}};
}
Table QueryPkbStub::getPatternWhileByVar(VarName var) {
    return {{}};
}
Table QueryPkbStub::getPatternWhileTable() {
    return table;
}
Table QueryPkbStub::getCallsByCaller(ProcName caller) {
    return {{}};
}
Table QueryPkbStub::getCallsByCalled(ProcName called) {
    return {{}};
}
Table QueryPkbStub::getCallsTable() {
    return table;
}
Table QueryPkbStub::getCallsTByCaller(ProcName caller) {
    return {{}};
}
Table QueryPkbStub::getCallsTByCalled(ProcName called) {
    return {{}};
}
Table QueryPkbStub::getCallsTTable() {
    return table;
}
Table QueryPkbStub::getNextByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getNextByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getNextTable() {
    return table;
}
Table QueryPkbStub::getNextTByBefore(StmtNo before) {
    return {{}};
}
Table QueryPkbStub::getNextTByAfter(StmtNo after) {
    return {{}};
}
Table QueryPkbStub::getNextTTable() {
    return table;
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
