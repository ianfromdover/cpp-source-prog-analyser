#include "PopulatePKB.h"
//#include "PKBStorage.h"

PopulatePKB::PopulatePKB(std::shared_ptr<PKBStorage> p) {
    pkb = p;
}

bool PopulatePKB::exists() {
    return pkb != nullptr;
}
bool PopulatePKB::addRead(StmtNo sNum, VarName name) {
    return false;
}
bool PopulatePKB::addCallStmt(StmtNo sNum, ProcName name) {
    // implement using set
    return false;
}
bool PopulatePKB::addIf(StmtNo sNum, VarName ctrlVarName) {
    // implement using set
    return false;
}
bool PopulatePKB::addWhile(StmtNo sNum, VarName ctrlVarName) {
    return false;
}

bool PopulatePKB::addPrint(StmtNo s, VarName name) {
    return false;
}

bool PopulatePKB::addFinalStatementNo(StmtNo s) {
    return false;
}

bool PopulatePKB::addProcedure(Str procedureName) {
    // future: should this have an associated StmtList?
    return false;
}
bool PopulatePKB::addVar(StmtNo sNum, VarName name) {
    return false;
}
bool PopulatePKB::addConst(StmtNo sNum, ConstVal c) {
    return false;
}

// -- Add Abstractions --
bool PopulatePKB::addFollows(StmtNo before, StmtNo after) {
    return false;
}
bool PopulatePKB::addFollowsT(StmtNo before, StmtNo after) {
    return false;
}
bool PopulatePKB::addParent(StmtNo parent, StmtNo child) {
    return pkb->parentTable->addParent(parent, child);
}
bool PopulatePKB::addParentT(StmtNo ancestor, StmtNo descendant) {
    return false;
}
bool PopulatePKB::addUses(StmtNo sNum, VarName name) {
    return false;
}
bool PopulatePKB::addUses(ProcName ProcedureName, VarName name) {
    return false;
}
bool PopulatePKB::addModifies(StmtNo sNum, VarName name) {
    return false;
}
bool PopulatePKB::addModifies(ProcName ProcedureName, VarName name) {
    return false;
}
bool PopulatePKB::addPatternAsgn(StmtNo sNum, Str lhs, Str rhsBracketed) {
    return false;
}
