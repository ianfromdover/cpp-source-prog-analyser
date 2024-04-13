#include "PopulatePkb.h"

PopulatePkb::PopulatePkb(std::shared_ptr<PkbStorage> p) {
    pkb = std::move(p);
}

// ----------- on-demand
bool PopulatePkb::setAffectsObj(std::shared_ptr<Affects> a) {
    if (pkb == nullptr || a == nullptr) {
        return false;
    }
    pkb->affects = std::move(a);
    return true;
}
bool PopulatePkb::setNextTObj(std::shared_ptr<NextT> n) {
    if (pkb == nullptr || n == nullptr) {
        return false;
    }
    pkb->nextT = std::move(n);
    return true;
}

// ----------- entity
bool PopulatePkb::addCallStmt(int stmtNo, std::string name) {
    return pkb->callTable->add(stmtNo, name);
}

bool PopulatePkb::addConst(int stmtNo, int val) {
    return pkb->constTable->add(stmtNo, val);
}

bool PopulatePkb::addPrint(int stmtNo, std::string name) {
    return pkb->printTable->add(stmtNo, name);
}

bool PopulatePkb::addProcedure(std::string name) {
    return pkb->procedureTable->add(name);
}

bool PopulatePkb::addRead(int stmtNo, std::string name) {
    return pkb->readTable->add(stmtNo, name);
}

bool PopulatePkb::addFinalStatementNo(int stmtNo) {
    if (stmtNo < 1) {
        return false;
    }
    return pkb->statementTable->addFinalStatementNo(stmtNo);
}

bool PopulatePkb::addVar(int stmtNo, std::string name) {
    return pkb->varTable->add(stmtNo, name);
}

// ----------- relation
bool PopulatePkb::addCalls(std::string caller, std::string called) {
    return pkb->callsTable->add(caller, called);
}

bool PopulatePkb::addCallsT(std::string caller, std::string called) {
    return pkb->callsTTable->add(caller, called);
}

bool PopulatePkb::addFollows(int before, int after) {
    return pkb->followsTable->add(before, after);
}

bool PopulatePkb::addFollowsT(int before, int after) {
    return pkb->followsTTable->add(before, after);
}

bool PopulatePkb::addModifiesP(std::string procName, std::string name) {
    return pkb->modifiesPTable->add(procName, name);
}

bool PopulatePkb::addModifiesS(int stmtNo, std::string name) {
    return pkb->modifiesSTable->add(stmtNo, name);
}

bool PopulatePkb::addNext(int before, int after) {
    return pkb->nextTable->add(before, after);
}

bool PopulatePkb::addParent(int parent, int child) {
    return pkb->parentTable->add(parent, child);
}

bool PopulatePkb::addParentT(int ancestor, int descendant) {
    return pkb->parentTTable->add(ancestor, descendant);
}

bool PopulatePkb::addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) {
    bool lhsSuccess = pkb->patternAssignTable->addStmtLhs(stmtNo, lhs);
    bool rhsSuccess = pkb->patternAssignTable->addStmtRhs(stmtNo, rhs);
    bool varSuccess = pkb->patternAssignTable->addLhsRhs(lhs, rhs);
    return lhsSuccess && rhsSuccess && varSuccess;
}

bool PopulatePkb::addPatternIf(int stmtNo, std::string name) {
    return pkb->patternIfTable->add(stmtNo, name);
}

bool PopulatePkb::addPatternWhile(int stmtNo, std::string name) {
    return pkb->patternWhileTable->add(stmtNo, name);
}

bool PopulatePkb::addUsesP(std::string procName, std::string name) {
    return pkb->usesPTable->add(procName, name);
}

bool PopulatePkb::addUsesS(int stmtNo, std::string name) {
    return pkb->usesSTable->add(stmtNo, name);
}
