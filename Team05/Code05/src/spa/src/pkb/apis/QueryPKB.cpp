//
// Created by sjh_9 on 25/2/2024.
//

#include "QueryPKB.h"

#include <utility>

QueryPKB::QueryPKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

pair<IntColumn, StringColumn> QueryPKB::getRead() {
    return pkb->readTable->getRead();
}

pair<IntColumn, StringColumn> QueryPKB::getCallStmt() {
    return pkb->callTable->getCall();
}

pair<IntColumn, StringColumn> QueryPKB::getIf() {
    return pkb->ifTable->getIf();
}

pair<IntColumn, StringColumn> QueryPKB::getWhile() {
    return pkb->whileTable->getWhile();
}

pair<IntColumn, StringColumn> QueryPKB::getPrint() {
    return pkb->printTable->getPrint();
}

pair<IntColumn, IntColumn> QueryPKB::getStatement() {
    return pkb->statementTable->getStatement();
}

pair<StringColumn, StringColumn> QueryPKB::getProcedure() {
    return pkb->procedureTable->getProcedure();
}

pair<IntColumn, StringColumn> QueryPKB::getVar() {
    return pkb->variableTable->getVariable();
}

pair<IntColumn, IntColumn> QueryPKB::getConst() {
    return pkb->constantTable->getConstant();
}

pair<IntColumn, IntColumn> QueryPKB::getFollows() {
    return pkb->followsTable->getFollows();
}

pair<IntColumn, IntColumn> QueryPKB::getFollowsT() {
    return pkb->followsTTable->getFollowsT();
}

pair<IntColumn, IntColumn> QueryPKB::getParent() {
    return pkb->parentTable->getParent();
}

pair<IntColumn, IntColumn> QueryPKB::getParentT() {
    return pkb->parentTTable->getParentT();
}

pair<IntColumn, StringColumn> QueryPKB::getUses() {
    return pkb->usesTable->getUses();
}

pair<IntColumn, StringColumn> QueryPKB::getModifies() {
    return pkb->modifiesTable->getModifies();
}

pair<IntColumn, StringColumn> QueryPKB::getPatternAsgn() {
    return pkb->assignTable->getAssign();
}





