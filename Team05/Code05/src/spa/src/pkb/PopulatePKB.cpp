#include "PopulatePKB.h"
#include "PKBStorage.h"

PopulatePKB::PopulatePKB(std::shared_ptr<PKBStorage> p) {
    pkb = p;
}

bool PopulatePKB::exists() {
    return pkb != nullptr;
}
// ai-gen start (copilot, 1, e)
// prompt: used copilot
/*
bool PopulatePKB::addVar() {
    return false;
}
bool PopulatePKB::addConst() {
    return false;
}
bool PopulatePKB::addProcedure() {
    return false;
}
bool PopulatePKB::addStmt(StmtNo stmtNo, Str stmtType, ProcId procIndex) {
    return false;
}
bool PopulatePKB::addFollows() {
    return false;
}
 */
bool PopulatePKB::addParent(StmtNo parent, StmtNo child) {
    return pkb->parentTable->addParent(parent, child);
}
/*
bool PopulatePKB::addUses() {
    return false;
}
bool PopulatePKB::addModifies() {
    return false;
}
// ai-gen end
bool PopulatePKB::generateFollowsT() {
    return false;
}
bool PopulatePKB::generateParentT() {
    return false;
}
*/
// ai-gen end
