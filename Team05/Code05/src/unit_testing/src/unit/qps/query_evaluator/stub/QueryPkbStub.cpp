//
// Created by tohzh on 21/2/2024.
//

#include "QueryPkbStub.h"

#include <utility>

std::vector<std::vector<std::string>> QueryPkbStub::getRead() {
    return pkb->readTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getCallStmt() {
    return pkb->callTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getWhile() {
    return pkb->whileTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getIf() {
    return pkb->ifTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getPrint() {
    return pkb->printTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getStatement() {
    return pkb->statementTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getProcedure() {
    return pkb->procedureTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getVar() {
    return pkb->varTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getConst() {
    return pkb->constTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getFollows() {
    return pkb->followsTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getFollowsT() {
    return pkb->followsTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getParent() {
    return pkb->parentTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getParentT() {
    return pkb->parentTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getUsesP() {
    return pkb->usesPTable->getAllProc();
}

std::vector<std::vector<std::string>> QueryPkbStub::getUses() {
    return pkb->usesSTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getModifies() {
    return pkb->modifiesSTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getModifiesP() {
    return pkb->modifiesPTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgn() {
    return pkb->patternAssignTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getCalls() {
    return pkb->callsTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkbStub::getCallsT() {
    return pkb->callsTTable->getAllAsStrings();
}

void QueryPkbStub::setRead(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->readTable->addRead(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPkbStub::setCallStmt(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->callTable->addCall(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPkbStub::setWhile(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->whileTable->addWhile(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPkbStub::setIf(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->ifTable->addIf(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPkbStub::setPrint(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->printTable->addPrint(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

// final statement no
void QueryPkbStub::setStatement(int ending) {
    pkb->statementTable->addFinalStatementNo(ending);
}

// {"a", "a"}
void QueryPkbStub::setProcedure(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->procedureTable->addProc(t[i][0]);
    }
}

void QueryPkbStub::setVar(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->varTable->addVar(std::stoi(pair[0]), pair[1]);
    }
}

void QueryPkbStub::setConst(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->constTable->addConst(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPkbStub::setFollows(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->followsTable->addFollows(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPkbStub::setFollowsT(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->followsTTable->addFollowsT(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPkbStub::setParent(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->parentTable->addParent(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPkbStub::setParentT(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->parentTTable->addParentT(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPkbStub::setUses(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->usesSTable->addUsesS(std::stoi(pair[0]), pair[1]);
    }
}

void QueryPkbStub::setModifies(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->modifiesSTable->addModifiesS(std::stoi(pair[0]), pair[1]);
    }
}

void QueryPkbStub::setPatternAsgn(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->patternAssignTable->addStmtLhs(std::stoi(pair[0]), pair[1]);
        pkb->patternAssignTable->addStmtRhs(std::stoi(pair[0]), pair[2]);
        pkb->patternAssignTable->addLhsRhs(pair[1], pair[2]);
    }
}

void QueryPkbStub::setUsesP(std::vector<std::vector<std::string>> t) {
    // TODO: not implemented, will probably be replaced by better testing methods
    // usesPTable = std::move(t);
}

void QueryPkbStub::setModifiesP(std::vector<std::vector<std::string>> t) {
    // TODO: not implemented
    // modifiesPTable = std::move(t);
}

void QueryPkbStub::setCalls(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->callsTable->addCalls(pair[0], pair[1]);
    }
}

void QueryPkbStub::setCallsT(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->callsTTable->addCallsT(pair[0], pair[1]);
    }
}

std::vector<std::vector<std::string>> QueryPkbStub::getCallByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallByProc(ProcName proc) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getProcByName(ProcName proc) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getProcTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getReadByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getReadByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getReadTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getIfByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getIfByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getIfTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getWhileByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getWhileByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getWhileTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPrintByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPrintByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPrintTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getStmtByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getStmtTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getVarByName(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getVarTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getConstByName(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getConstTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getFollowsTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getParentByParent(StmtNo parent) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getParentByChild(StmtNo child) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getParentTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getParentTByParent(StmtNo parent) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getParentTByChild(StmtNo child) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getParentTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getUsesSByNum(StmtNo user) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getUsesSByVar(VarName used) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getUsesSTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getUsesPTable() { return {{}}; }
// TODO: add UsesP
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesSByNum(StmtNo modifier) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesSByVar(VarName modified) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesSTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesPByProc(ProcName modifier) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesPByVar(VarName modified) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getModifiesPTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByLhs(std::string Lhs) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByRhs(std::string Rhs) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByLhsPartial(std::string LhsPartial) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnByRhsPartial(std::string RhsPartial) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternAsgnTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternIfByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternIfByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternIfTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternWhileByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternWhileByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getPatternWhileTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallsByCaller(ProcName caller) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallsByCalled(ProcName called) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTByCaller(ProcName caller) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTByCalled(ProcName called) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getCallsTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getNextByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getNextByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getNextTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getNextTByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getNextTByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getNextTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getAffectsByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getAffectsByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPkbStub::getAffectsTable() { return {{}}; }
