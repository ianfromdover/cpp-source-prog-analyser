#include "PopulatePKB.h"
#include "PKB.h"

// TODO: Implement PopulatePKB
PopulatePKB::PopulatePKB(std::shared_ptr<PKB> p) {
    pkb = p;
}
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
    pkb->parentTable->addParent(parent, child);
    return false;
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
