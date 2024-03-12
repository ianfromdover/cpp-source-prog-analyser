//
// Created by tohzh on 21/2/2024.
//

#include "QueryPKBStub.h"

#include <utility>

std::vector<std::vector<std::string>> QueryPKBStub::getRead() {
    return readTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getCallStmt() {
    return callStmtTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getWhile() {
    return whileTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getIf() {
    return ifTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getPrint() {
    return printTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getStatement() {
    return statementTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getProcedure() {
    return procedureTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getVar() {
    return varTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getConst() {
    return constTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getFollows() {
    return followsTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getFollowsT() {
    return followsTTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getParent() {
    return parentTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getParentT() {
    return parentTTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getUses() {
    return usesTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getModifies() {
    return modifiesTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getPatternAsgn() {
    return assignTable;
}

void QueryPKBStub::setRead(std::vector<std::vector<std::string>> t) {
    readTable = std::move(t);
}

void QueryPKBStub::setCallStmt(std::vector<std::vector<std::string>> t) {
    callStmtTable = std::move(t);
}

void QueryPKBStub::setWhile(std::vector<std::vector<std::string>> t) {
    whileTable = std::move(t);
}

void QueryPKBStub::setIf(std::vector<std::vector<std::string>> t) {
    ifTable = std::move(t);
}

void QueryPKBStub::setPrint(std::vector<std::vector<std::string>> t) {
    printTable = std::move(t);
}

void QueryPKBStub::setStatement(std::vector<std::vector<std::string>> t) {
    statementTable = std::move(t);
}

void QueryPKBStub::setProcedure(std::vector<std::vector<std::string>> t) {
    procedureTable = std::move(t);
}

void QueryPKBStub::setVar(std::vector<std::vector<std::string>> t) {
    varTable = std::move(t);
}

void QueryPKBStub::setConst(std::vector<std::vector<std::string>> t) {
    constTable = std::move(t);
}

void QueryPKBStub::setFollows(std::vector<std::vector<std::string>> t) {
    followsTable = std::move(t);
}

void QueryPKBStub::setFollowsT(std::vector<std::vector<std::string>> t) {
    followsTTable = std::move(t);
}

void QueryPKBStub::setParent(std::vector<std::vector<std::string>> t) {
    parentTable = std::move(t);
}

void QueryPKBStub::setParentT(std::vector<std::vector<std::string>> t) {
    parentTTable = std::move(t);
}

void QueryPKBStub::setUses(std::vector<std::vector<std::string>> t) {
    usesTable = std::move(t);
}

void QueryPKBStub::setModifies(std::vector<std::vector<std::string>> t) {
    modifiesTable = std::move(t);
}

void QueryPKBStub::setPatternAsgn(std::vector<std::vector<std::string>> t) {
    assignTable = std::move(t);
}

std::vector<std::vector<std::string>> QueryPKBStub::getUsesP() {
    return usesPTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getModifiesP() {
    return modifiesPTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getCalls() {
    return callsTable;
}

std::vector<std::vector<std::string>> QueryPKBStub::getCallsT() {
    return callsTTable;
}

void QueryPKBStub::setUsesP(std::vector<std::vector<std::string>> t) {
    usesPTable = std::move(t);
}

void QueryPKBStub::setModifiesP(std::vector<std::vector<std::string>> t) {
    modifiesPTable = std::move(t);
}

void QueryPKBStub::setCalls(std::vector<std::vector<std::string>> t) {
    callsTable = std::move(t);
}

void QueryPKBStub::setCallsT(std::vector<std::vector<std::string>> t) {
    callsTTable = std::move(t);
}
