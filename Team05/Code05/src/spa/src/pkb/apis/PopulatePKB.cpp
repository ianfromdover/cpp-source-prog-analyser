#include "PopulatePKB.h"

#include <utility>

PopulatePKB::PopulatePKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

// ----------- entity
bool PopulatePKB::addCallStmt(int stmtNo, std::string name) {
    return pkb->callTable->addCall(stmtNo, name);
}

bool PopulatePKB::addConst(int stmtNo, int val) {
    return pkb->constTable->addConst(stmtNo, val);
}

bool PopulatePKB::addIf(int stmtNo, std::string name) {
    return pkb->ifTable->addIf(stmtNo, name);
}

bool PopulatePKB::addPrint(int stmtNo, std::string name) {
    return pkb->printTable->addPrint(stmtNo, name);
}

bool PopulatePKB::addRead(int stmtNo, std::string name) {
    return pkb->readTable->addRead(stmtNo, name);
}

bool PopulatePKB::addProcedure(std::string name) {
    return pkb->procedureTable->addProc(name);
}

bool PopulatePKB::addFinalStatementNo(int stmtNo) {
    if (stmtNo < 1) {
        return false;
    }
    return pkb->statementTable->addFinalStatementNo(stmtNo);
}

bool PopulatePKB::addVar(int stmtNo, std::string name) {
    return pkb->varTable->addVar(stmtNo, name);
}

bool PopulatePKB::addWhile(int stmtNo, std::string name) {
    return pkb->whileTable->addWhile(stmtNo, name);
}

// ----------- relation
bool PopulatePKB::addAffects(int before, int after) {
    return pkb->affectsTable->addAffects(before, after);
}

bool PopulatePKB::addCalls(std::string caller, std::string called) {
    return pkb->callsTable->addCalls(caller, called);
}

bool PopulatePKB::addCallsT(std::string caller, std::string called) {
    return pkb->callsTTable->addCallsT(caller, called);
}

bool PopulatePKB::addFollows(int before, int after) {
    return pkb->followsTable->addFollows(before, after);
}

bool PopulatePKB::addFollowsT(int before, int after) {
    return pkb->followsTTable->addFollowsT(before, after);
}

bool PopulatePKB::addModifiesS(int stmtNo, std::string name) {
    return pkb->modifiesSTable->addModifiesS(stmtNo, name);
}

bool PopulatePKB::addModifiesP(std::string procName, std::string name) {
    return pkb->modifiesPTable->addModifiesP(procName, name);
}

bool PopulatePKB::addNext(int before, int after) {
    return pkb->nextTable->addNext(before, after);
}

bool PopulatePKB::addNextT(int before, int after) {
    return pkb->nextTTable->addNextT(before, after);
}

bool PopulatePKB::addParent(int parent, int child) {
    return pkb->parentTable->addParent(parent, child);
}

bool PopulatePKB::addParentT(int ancestor, int descendant) {
    return pkb->parentTTable->addParentT(ancestor, descendant);
}

bool PopulatePKB::addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) {
    bool lhsSuccess = pkb->patternAssignTable->addStmtLhs(stmtNo, lhs);
    bool rhsSuccess = pkb->patternAssignTable->addStmtRhs(stmtNo, rhs);
    bool varSuccess = pkb->patternAssignTable->addLhsRhs(lhs, rhs);
    return lhsSuccess && rhsSuccess && varSuccess;
}

bool PopulatePKB::addPatternIf(int stmtNo, std::string name) {
    return pkb->patternIfTable->addIf(stmtNo, name);
}

bool PopulatePKB::addPatternWhile(int stmtNo, std::string name) {
    return pkb->patternWhileTable->addWhile(stmtNo, name);
}

bool PopulatePKB::addUsesS(int stmtNo, std::string name) {
    return pkb->usesSTable->addUsesS(stmtNo, name);
}

bool PopulatePKB::addUsesP(std::string procName, std::string name) {
    return pkb->usesPTable->addUsesP(procName, name);
}
