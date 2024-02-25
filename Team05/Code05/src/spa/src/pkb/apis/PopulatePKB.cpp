//
// Created by sjh_9 on 25/2/2024.
//

#include "PopulatePKB.h"

#include <utility>

PopulatePKB::PopulatePKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}


bool PopulatePKB::addRead(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addCallStmt(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addIf(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addWhile(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addPrint(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addFinalStatementNo(int stmtNo) {
    return false;
}

bool PopulatePKB::addProcedure(std::string name) {
    return false;
}

bool PopulatePKB::addVar(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addConst(int stmtNo, int val) {
    return false;
}

bool PopulatePKB::addFollows(int before, int after) {
    return false;
}

bool PopulatePKB::addFollowsT(int before, int after) {
    return false;
}

bool PopulatePKB::addParent(int parent, int child) {
    return false;
}

bool PopulatePKB::addUses(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addParentT(int parent, int child) {
    return false;
}

bool PopulatePKB::addModifies(int stmtNo, std::string name) {
    return false;
}

bool PopulatePKB::addPatternAsgn(int stmtNo, std::string lhs, std::string rhs) {
    return false;
}
