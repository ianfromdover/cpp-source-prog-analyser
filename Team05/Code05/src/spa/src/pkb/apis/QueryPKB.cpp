//
// Created by sjh_9 on 25/2/2024.
//

#include "QueryPKB.h"

#include <utility>

QueryPKB::QueryPKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

std::vector<std::vector<std::string>> QueryPKB::getRead() {
    return pkb->readTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getCallStmt() {
    return pkb->callTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getIf() {
    return pkb->ifTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getWhile() {
    return pkb->whileTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getPrint() {
    return pkb->printTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getStatement() {
    return pkb->statementTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getProcedure() {
    return pkb->procedureTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getVar() {
    return pkb->variableTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getConst() {
    return pkb->constantTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getFollows() {
    return pkb->followsTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsT() {
    return pkb->followsTTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getParent() {
    return pkb->parentTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getParentT() {
    return pkb->parentTTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getUses() {
    return pkb->usesTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getModifies() {
    return pkb->modifiesTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getPatternAsgn() {
    return pkb->assignTable->getTable();
}





