//
// Created by sjh_9 on 25/2/2024.
//

#include "PopulatePKB.h"

#include <utility>

PopulatePKB::PopulatePKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}


bool PopulatePKB::addRead(int stmtNo, std::string name) {
    return pkb->readTable->addRead(stmtNo, name);
}

bool PopulatePKB::addCallStmt(int stmtNo, std::string name) {
    return pkb->callTable->addCall(stmtNo, name);
}

bool PopulatePKB::addIf(int stmtNo, std::string name) {
    return pkb->ifTable->addIf(stmtNo, name);
}

bool PopulatePKB::addWhile(int stmtNo, std::string name) {
    return pkb->whileTable->addWhile(stmtNo, name);
}

bool PopulatePKB::addPrint(int stmtNo, std::string name) {
    return pkb->printTable->addPrint(stmtNo, name);
}

bool PopulatePKB::addFinalStatementNo(int stmtNo) {
    return pkb->statementTable->addStatement(stmtNo, stmtNo);
}

bool PopulatePKB::addProcedure(std::string name) {
    return pkb->procedureTable->addProcedure(name, name);
}

bool PopulatePKB::addVar(int stmtNo, std::string name) {
    return pkb->variableTable->addVariable(stmtNo, name);
}

bool PopulatePKB::addConst(int stmtNo, int val) {
    return pkb->constantTable->addConstant(stmtNo, val);
}

bool PopulatePKB::addFollows(int before, int after) {
    return pkb->followsTable->addFollows(before, after);
}

bool PopulatePKB::addFollowsT(int before, int after) {
    return pkb->followsTTable->addFollowsT(before, after);
}

bool PopulatePKB::addParent(int parent, int child) {
    return pkb->parentTable->addParent(parent, child);
}

bool PopulatePKB::addUses(int stmtNo, std::string name) {
    return pkb->usesTable->addUses(stmtNo, name);
}

bool PopulatePKB::addParentT(int parent, int child) {
    return pkb->parentTTable->addParentT(parent, child);
}

bool PopulatePKB::addModifies(int stmtNo, std::string name) {
    return pkb->modifiesTable->addModifies(stmtNo, name);
}

bool PopulatePKB::addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) {
    return pkb->assignTable->addAssign(stmtNo, lhs + "=" + rhs);
}
