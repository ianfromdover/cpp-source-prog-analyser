//
// Created by sjh_9 on 25/2/2024.
//

#include "PopulatePKB.h"

#include <utility>

PopulatePKB::PopulatePKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

bool PopulatePKB::addRead(int stmtNo, std::string name) {
    return pkb->readTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addCallStmt(int stmtNo, std::string name) {
    return pkb->callTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addIf(int stmtNo, std::string name) {
    return pkb->ifTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addWhile(int stmtNo, std::string name) {
    return pkb->whileTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addPrint(int stmtNo, std::string name) {
    return pkb->printTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addFinalStatementNo(int stmtNo) {
    return pkb->statementTable->addRecord(std::to_string(stmtNo), std::to_string(stmtNo));
}

bool PopulatePKB::addProcedure(std::string name) {
    return pkb->procedureTable->addRecord(name, name);
}

bool PopulatePKB::addVar(int stmtNo, std::string name) {
    return pkb->variableTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addConst(int stmtNo, int val) {
    return pkb->constantTable->addRecord(std::to_string(stmtNo), std::to_string(val));
}

bool PopulatePKB::addFollows(int before, int after) {
    return pkb->followsTable->addRecord(std::to_string(before), std::to_string(after));
}

bool PopulatePKB::addFollowsT(int before, int after) {
    return pkb->followsTTable->addRecord(std::to_string(before), std::to_string(after));
}

bool PopulatePKB::addParent(int parent, int child) {
    return pkb->parentTable->addRecord(std::to_string(parent), std::to_string(child));
}

bool PopulatePKB::addUses(int stmtNo, std::string name) {
    return pkb->usesTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addParentT(int parent, int child) {
    return pkb->parentTTable->addRecord(std::to_string(parent), std::to_string(child));
}

bool PopulatePKB::addModifies(int stmtNo, std::string name) {
    return pkb->modifiesTable->addRecord(std::to_string(stmtNo), name);
}

bool PopulatePKB::addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) {
    return pkb->assignTable->addRecord(std::to_string(stmtNo), lhs + "=" + rhs);
}

bool PopulatePKB::addCalls(std::string caller, std::string called) {
    return pkb->callsTable->addRecord(caller, called);
}

bool PopulatePKB::addCallsT(std::string caller, std::string called) {
    return pkb->callsTTable->addRecord(caller, called);
}