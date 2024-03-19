//
// Created by tohzahnqing on 21/2/2024.
//

#include "QueryPkbStub.h"

#include <utility>

void QueryPkbStub::setRead(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setCallStmt(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setWhile(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setIf(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setPrint(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setStatement(int ending) {
    std::vector<std::vector<std::string>> t;
    for (int i = 1; i <= ending; i++) {
        t.push_back({std::to_string(i)});
    }
    table = std::move(t);
}

// {"a", "a"}
void QueryPkbStub::setProcedure(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setVar(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setConst(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setFollows(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setFollowsT(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setParent(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setParentT(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setUses(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setModifies(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setPatternAsgn(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setUsesP(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setModifiesP(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setCalls(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

void QueryPkbStub::setCallsT(std::vector<std::vector<std::string>> t) {
    table = std::move(t);
}

std::vector<std::vector<std::string>> QueryPkbStub::getCallByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallByProc(ProcName proc) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getProcByName(ProcName proc) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getProcTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getReadByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getReadByVar(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getReadTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getIfByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getIfByVar(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getIfTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getWhileByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getWhileByVar(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getWhileTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getPrintByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPrintByVar(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPrintTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getStmtByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getStmtTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getVarByName(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getVarTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getConstByName(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getConstTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsByBefore(StmtNo before) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsByAfter(StmtNo after) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTByBefore(StmtNo before) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTByAfter(StmtNo after) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getParentByParent(StmtNo parent) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getParentByChild(StmtNo child) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getParentTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getParentTByParent(StmtNo parent) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getParentTByChild(StmtNo child) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getParentTTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getUsesSByNum(StmtNo user) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getUsesSByVar(VarName used) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getUsesSTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getUsesPTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesSByNum(StmtNo modifier) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesSByVar(VarName modified) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesSTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesPByProc(ProcName modifier) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesPByVar(VarName modified) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesPTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByLhs(std::string Lhs) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByRhs(std::string Rhs) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByLhsPartial(std::string LhsPartial) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByRhsPartial(std::string RhsPartial) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternIfByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternIfByVar(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternIfTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternWhileByNum(StmtNo sNum) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternWhileByVar(VarName var) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getPatternWhileTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallsByCaller(ProcName caller) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallsByCalled(ProcName called) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTByCaller(ProcName caller) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTByCalled(ProcName called) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getNextByBefore(StmtNo before) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getNextByAfter(StmtNo after) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getNextTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getNextTByBefore(StmtNo before) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getNextTByAfter(StmtNo after) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getNextTTable() {
    return table;
}
std::vector<std::vector<std::string>> QueryPkbStub::getAffectsByBefore(StmtNo before) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getAffectsByAfter(StmtNo after) {
    return {{}};
}
std::vector<std::vector<std::string>> QueryPkbStub::getAffectsTable() {
    return table;
}
