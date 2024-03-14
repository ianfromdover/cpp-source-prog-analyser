//
// Created by tohzh on 21/2/2024.
//

#include "QueryPKBStub.h"

#include <utility>

std::vector<std::vector<std::string>> QueryPKBStub::getRead() {
    return pkb->readTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getCallStmt() {
    return pkb->callTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getWhile() {
    return pkb->whileTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getIf() {
    return pkb->ifTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getPrint() {
    return pkb->printTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getStatement() {
    return pkb->statementTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getProcedure() {
    return pkb->procedureTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getVar() {
    return pkb->varTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getConst() {
    return pkb->constTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getFollows() {
    return pkb->followsTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getFollowsT() {
    return pkb->followsTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getParent() {
    return pkb->parentTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getParentT() {
    return pkb->parentTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getUsesP() {
    return pkb->usesPTable->getAllProc();
}

std::vector<std::vector<std::string>> QueryPKBStub::getUses() {
    return pkb->usesSTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getModifies() {
    return pkb->modifiesSTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getModifiesP() {
    return pkb->modifiesPTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getPatternAsgn() {
    return pkb->patternAssignTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getCalls() {
    return pkb->callsTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKBStub::getCallsT() {
    return pkb->callsTTable->getAllAsStrings();
}

void QueryPKBStub::setRead(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->readTable->addRead(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPKBStub::setCallStmt(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->callTable->addCall(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPKBStub::setWhile(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->whileTable->addWhile(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPKBStub::setIf(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->ifTable->addIf(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

void QueryPKBStub::setPrint(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->printTable->addPrint(std::stoi(t[i][0]),
                                std::string(i, 'a'));
    }
}

// final statement no
void QueryPKBStub::setStatement(int ending) {
    pkb->statementTable->addFinalStatementNo(ending);
}

// {"a", "a"}
void QueryPKBStub::setProcedure(std::vector<std::vector<std::string>> t) {
    for (int i = 0; i < t.size(); i++) {
        pkb->procedureTable->addProc(t[i][0]);
    }
}

void QueryPKBStub::setVar(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->varTable->addVar(std::stoi(pair[0]), pair[1]);
    }
}

void QueryPKBStub::setConst(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->constTable->addConst(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPKBStub::setFollows(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->followsTable->addFollows(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPKBStub::setFollowsT(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->followsTTable->addFollowsT(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPKBStub::setParent(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->parentTable->addParent(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPKBStub::setParentT(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->parentTTable->addParentT(std::stoi(pair[0]), std::stoi(pair[1]));
    }
}

void QueryPKBStub::setUses(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->usesSTable->addUsesS(std::stoi(pair[0]), pair[1]);
    }
}

void QueryPKBStub::setModifies(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->modifiesSTable->addModifiesS(std::stoi(pair[0]), pair[1]);
    }
}

void QueryPKBStub::setPatternAsgn(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->patternAssignTable->addStmtLhs(std::stoi(pair[0]), pair[1]);
        pkb->patternAssignTable->addStmtRhs(std::stoi(pair[0]), pair[2]);
        pkb->patternAssignTable->addLhsRhs(pair[1], pair[2]);
    }
}

void QueryPKBStub::setUsesP(std::vector<std::vector<std::string>> t) {
    // TODO: not implemented, will probably be replaced by better testing methods
    // usesPTable = std::move(t);
}

void QueryPKBStub::setModifiesP(std::vector<std::vector<std::string>> t) {
    // TODO: not implemented
    // modifiesPTable = std::move(t);
}

void QueryPKBStub::setCalls(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->callsTable->addCalls(pair[0], pair[1]);
    }
}

void QueryPKBStub::setCallsT(std::vector<std::vector<std::string>> t) {
    for (auto pair : t) {
        pkb->callsTTable->addCallsT(pair[0], pair[1]);
    }
}

std::vector<std::vector<std::string>> QueryPKBStub::getCallByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallByProc(ProcName proc) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getProcByName(ProcName proc) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getProcTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getReadByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getReadByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getReadTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getIfByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getIfByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getIfTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getWhileByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getWhileByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getWhileTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPrintByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPrintByVar(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPrintTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getStmtByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getStmtTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getVarByName(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getVarTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getConstByName(VarName var) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getConstTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getFollowsByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getFollowsByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getFollowsTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getFollowsTByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getFollowsTByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getFollowsTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getParentByParent(StmtNo parent) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getParentByChild(StmtNo child) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getParentTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getParentTByParent(StmtNo parent) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getParentTByChild(StmtNo child) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getParentTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getUsesSByNum(StmtNo user) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getUsesSByVar(VarName used) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getUsesSTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getUsesPTable() { return {{}}; }
// TODO: add UsesP
std::vector<std::vector<std::string>> QueryPKBStub::getModifiesSByNum(StmtNo modifier) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getModifiesSByVar(VarName modified) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getModifiesSTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getModifiesPByProc(ProcName modifier) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getModifiesPByVar(VarName modified) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getModifiesPTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPatternByNum(StmtNo sNum) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPatternByLhs(std::string Lhs) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPatternByRhs(std::string Rhs) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPatternByLhsPartial(std::string LhsPartial) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPatternByRhsPartial(std::string RhsPartial) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getPatternTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallsByCaller(ProcName caller) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallsByCalled(ProcName called) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallsTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallsTByCaller(ProcName caller) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallsTByCalled(ProcName called) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getCallsTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getNextByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getNextByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getNextTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getNextTByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getNextTByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getNextTTable() { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getAffectsByBefore(StmtNo before) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getAffectsByAfter(StmtNo after) { return {{}}; }
std::vector<std::vector<std::string>> QueryPKBStub::getAffectsTable() { return {{}}; }
