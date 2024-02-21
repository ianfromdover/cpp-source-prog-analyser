#include "PopulatePKB.h"

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

// this is what the assign Pattern() relationship will query
bool PopulatePKB::addAssign(StmtNo sNum, VarName LhsVarName, Str RhsExpression) {
    // do C++ substring match from QPS' string to stored SP string, chatGPT it
    return false;
}

bool PopulatePKB::addPrint(StmtNo s, VarName name) {
    return false;
}

bool PopulatePKB::addFinalStatementNo(StmtNo s) {
    return false;
}

bool PopulatePKB::addProcedure(Str procedureName) {
    // future: should each procedure have an associated StmtList?
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
    return pkb->followsTable->addFollows(before, after);
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
    // not required for ms 1
    return false;
}

