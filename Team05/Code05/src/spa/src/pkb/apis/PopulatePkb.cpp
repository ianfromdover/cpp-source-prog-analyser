#include "PopulatePkb.h"

PopulatePkb::PopulatePkb(std::shared_ptr<PkbStorage> p) {
    pkb = std::move(p);
}

// ----------- entity
bool PopulatePkb::addCallStmt(int stmtNo, std::string name) {
    return pkb->callTable->addCall(stmtNo, name);
}

bool PopulatePkb::addConst(int stmtNo, int val) {
    return pkb->constTable->addConst(stmtNo, val);
}

bool PopulatePkb::addIf(int stmtNo, std::string name) {
    return pkb->ifTable->addIf(stmtNo, name);
}

bool PopulatePkb::addPrint(int stmtNo, std::string name) {
    return pkb->printTable->addPrint(stmtNo, name);
}

bool PopulatePkb::addProcedure(std::string name) {
    return pkb->procedureTable->addProc(name);
}

bool PopulatePkb::addRead(int stmtNo, std::string name) {
    return pkb->readTable->addRead(stmtNo, name);
}

bool PopulatePkb::addFinalStatementNo(int stmtNo) {
    if (stmtNo < 1) {
        return false;
    }
    return pkb->statementTable->addFinalStatementNo(stmtNo);
}

bool PopulatePkb::addVar(int stmtNo, std::string name) {
    return pkb->varTable->addVar(stmtNo, name);
}

bool PopulatePkb::addWhile(int stmtNo, std::string name) {
    return pkb->whileTable->addWhile(stmtNo, name);
}

// ----------- relation
bool PopulatePkb::addAffects(int before, int after) {
    return pkb->affectsTable->addAffects(before, after);
}

bool PopulatePkb::addCalls(std::string caller, std::string called) {
    return pkb->callsTable->addCalls(caller, called);
}

bool PopulatePkb::addCallsT(std::string caller, std::string called) {
    return pkb->callsTTable->addCallsT(caller, called);
}

bool PopulatePkb::addFollows(int before, int after) {
    return pkb->followsTable->addFollows(before, after);
}

bool PopulatePkb::addFollowsT(int before, int after) {
    return pkb->followsTTable->addFollowsT(before, after);
}

bool PopulatePkb::addModifiesP(std::string procName, std::string name) {
    return pkb->modifiesPTable->addModifiesP(procName, name);
}

bool PopulatePkb::addModifiesS(int stmtNo, std::string name) {
    return pkb->modifiesSTable->addModifiesS(stmtNo, name);
}

bool PopulatePkb::addNext(int before, int after) {
    return pkb->nextTable->addNext(before, after);
}

bool PopulatePkb::addNextT(int before, int after) {
    return pkb->nextTTable->addNextT(before, after);
}

bool PopulatePkb::addParent(int parent, int child) {
    return pkb->parentTable->addParent(parent, child);
}

bool PopulatePkb::addParentT(int ancestor, int descendant) {
    return pkb->parentTTable->addParentT(ancestor, descendant);
}

bool PopulatePkb::addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) {
    bool lhsSuccess = pkb->patternAssignTable->addStmtLhs(stmtNo, lhs);
    bool rhsSuccess = pkb->patternAssignTable->addStmtRhs(stmtNo, rhs);
    bool varSuccess = pkb->patternAssignTable->addLhsRhs(lhs, rhs);
    return lhsSuccess && rhsSuccess && varSuccess;
}

bool PopulatePkb::addPatternIf(int stmtNo, std::string name) {
    return pkb->patternIfTable->addIf(stmtNo, name);
}

bool PopulatePkb::addPatternWhile(int stmtNo, std::string name) {
    return pkb->patternWhileTable->addWhile(stmtNo, name);
}

bool PopulatePkb::addUsesP(std::string procName, std::string name) {
    return pkb->usesPTable->addUsesP(procName, name);
}

bool PopulatePkb::addUsesS(int stmtNo, std::string name) {
    return pkb->usesSTable->addUsesS(stmtNo, name);
}
