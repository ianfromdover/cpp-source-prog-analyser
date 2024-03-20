#include "QueryPkb.h"
#include "pkb/storage/base/TwoSideMap.hpp"
#include "common/TableUtils.h"

#include <utility>

QueryPkb::QueryPkb(std::shared_ptr<PkbStorage> p) {
    pkb = std::move(p);
}

// CallStmt

Table QueryPkb::getCallByNum(StmtNo sNum) {
    return TableUtils::toTable(pkb->callTable->getProc(sNum));
}

Table QueryPkb::getCallByProc(ProcName proc) {
    return TableUtils::toTable(pkb->callTable->getStmts(proc));
}

Table QueryPkb::getCallTable() {
    return pkb->callTable->getAllAsStrings();
}

// Proc

Table QueryPkb::getProcByName(ProcName proc) {
    return TableUtils::toTable(pkb->procedureTable->getProcByName(proc));
}

Table QueryPkb::getProcTable() {
    return pkb->procedureTable->getAllAsStrings();
}

// Read

Table QueryPkb::getReadByNum(StmtNo sNum) {
    return TableUtils::toTable(pkb->readTable->getReadVar(sNum));
}

Table QueryPkb::getReadByVar(VarName var) {
    return TableUtils::toTable(pkb->readTable->getReadStmts(var));
}

Table QueryPkb::getReadTable() {
    return pkb->readTable->getAllAsStrings();
}

// If

Table QueryPkb::getIfByNum(StmtNo sNum) {
    // using the pattern if table cuz the entity if table is redundant
    return TableUtils::toTable(pkb->patternIfTable->getPatternByNum(sNum));
}

Table QueryPkb::getIfByVar(VarName var) {
    // using the pattern if table cuz the entity if table is redundant
    return TableUtils::toTable(pkb->patternIfTable->getPatternByVar(var));
}

Table QueryPkb::getIfStmts() {
    // using the pattern if table cuz the entity if table is redundant
    return pkb->patternIfTable->getIfNums();
}

Table QueryPkb::getIfTable() {
    return pkb->patternIfTable->getAllAsStrings();
}

// While

Table QueryPkb::getWhileByNum(StmtNo sNum) {
    // using the pattern while table cuz the entity while table is redundant
    return TableUtils::toTable(pkb->patternWhileTable->getPatternByNum(sNum));
}

Table QueryPkb::getWhileByVar(VarName var) {
    // using the pattern while table cuz the entity while table is redundant
    return TableUtils::toTable(pkb->patternWhileTable->getPatternByVar(var));
}

Table QueryPkb::getWhileStmts() {
    // using the pattern while table cuz the entity while table is redundant
    return pkb->patternWhileTable->getWhileNums();
}

Table QueryPkb::getWhileTable() {
    return pkb->patternWhileTable->getAllAsStrings();
}

// Print

Table QueryPkb::getPrintByNum(StmtNo sNum) {
    return TableUtils::toTable(pkb->printTable->getPrintVar(sNum));
}

Table QueryPkb::getPrintByVar(VarName var) {
    return TableUtils::toTable(pkb->printTable->getPrintStmts(var));
}

Table QueryPkb::getPrintTable() {
    return pkb->printTable->getAllAsStrings();
}

// Stmt

// TODO
Table QueryPkb::getStmtByNum(int StmtNo) {
    return {{}};
//    return TableUtils::toTable(pkb->statementTable->getAllStmts());
}

Table QueryPkb::getStmtTable() {
    return pkb->statementTable->getAllAsStrings();
}

// Var

// TODO
Table QueryPkb::getVarByName(VarName var) {
    return {{}};
    // return TableUtils::toTable(pkb->varTable->getVarByName(var));
}

Table QueryPkb::getVarTable() {
    return pkb->varTable->getAllAsStrings();
}

// Const

// TODO
// constants don't have names
// shouldn't it be getConstByNum(StmtNo sNum) and
// getConstByValue(ConstVal val) instead?
// and will QPS actually use this API?
Table QueryPkb::getConstByName(VarName var) {
    return {{}};
}

Table QueryPkb::getConstTable() {
    return pkb->constTable->getAllAsStrings();
}

// Follows

Table QueryPkb::getFollowsByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->followsTable->getFollower(before));
}

Table QueryPkb::getFollowsByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->followsTable->getStmtBefore(after));
}

Table QueryPkb::getFollowsTable() {
    return pkb->followsTable->getAllAsStrings();
}

// FollowsT

Table QueryPkb::getFollowsTByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->followsTTable->getStmtsAfter(before));
}

Table QueryPkb::getFollowsTByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->followsTTable->getStmtsBefore(after));
}

Table QueryPkb::getFollowsTTable() {
    return pkb->followsTTable->getAllAsStrings();
}

// Parent

Table QueryPkb::getParentByParent(StmtNo parent) {
    return TableUtils::toTable(pkb->parentTable->getChildren(parent));
}

Table QueryPkb::getParentByChild(StmtNo child) {
    return TableUtils::toTable(pkb->parentTable->getParent(child));
}

Table QueryPkb::getParentTable() {
    return pkb->parentTable->getAllAsStrings();
}

// ParentT

Table QueryPkb::getParentTByParent(StmtNo parent) {
    return TableUtils::toTable(pkb->parentTTable->getChildrenT(parent));
}

Table QueryPkb::getParentTByChild(StmtNo child) {
    return TableUtils::toTable(pkb->parentTTable->getParentsT(child));
}

Table QueryPkb::getParentTTable() {
    return pkb->parentTTable->getAllAsStrings();
}

// UsesS

Table QueryPkb::getUsesSByNum(StmtNo user) {
    return TableUtils::toTable(pkb->usesSTable->getUsesBySNum(user));
}

Table QueryPkb::getUsesSByVar(VarName used) {
    return TableUtils::toTable(pkb->usesSTable->getUsesByVar(used));
}

//template <typename A, typename B>
//Table QueryPKB::TableUtils::toTable(TwoSideMap<A, B> map) {
//
//    Table result;
//
//    return result;
//}
//
//Table QueryPKB::TableUtils::toTable(std::string element) {
//
//    Table result;
//
//    // Create a vector<string> to hold the current element
//    std::vector<std::string> strElem;
//
//    // Put the element into the str vector
//    strElem.push_back((element));
//
//    return result;
//}
//template <typename A, typename B>
//Table QueryPKB::TableUtils::toTable(TwoSideMap<A, B> map) {
//
//    Table result;
//
//    return result;
//}
Table QueryPkb::getUsesSTable() {
    return pkb->usesSTable->getAllAsStrings();
}

// ModifiesS

Table QueryPkb::getModifiesSByNum(StmtNo modifier) {
    return TableUtils::toTable(pkb->modifiesSTable->getModifiedS(modifier));
}

Table QueryPkb::getModifiesSByVar(VarName modified) {
    return TableUtils::toTable(pkb->modifiesSTable->getModifiersS(modified));
}

Table QueryPkb::getModifiesSTable() {
    return pkb->modifiesSTable->getAllAsStrings();
}

// ModifiesP

Table QueryPkb::getModifiesPByProc(ProcName modifier) {
    return TableUtils::toTable(pkb->modifiesPTable->getModifiedP(modifier));
}

Table QueryPkb::getModifiesPByVar(VarName modified) {
    return TableUtils::toTable(pkb->modifiesPTable->getModifiersP(modified));
}

Table QueryPkb::getModifiesPTable() {
    return pkb->modifiesPTable->getAllAsStrings();
}

// PatternAssign
// TODO: patternAssign methods in the class are not ready
Table QueryPkb::getPatternAsgnByNum(StmtNo sNum) {
    return {{}};
//    return TableUtils::toTable(pkb->patternAssignTable.get);
}

Table QueryPkb::getPatternAsgnByLhs(std::string Lhs) {
    return {{}};
//    return TableUtils::toTable(pkb->patternAssignTable->getRhsFromLhs(Lhs));
}

Table QueryPkb::getPatternAsgnByRhs(std::string Rhs) {
    return {{}};
//    return TableUtils::toTable(pkb->patternAssignTable->getLhsFromRhs(Rhs));
}

Table QueryPkb::getPatternAsgnByLhsPartial(std::string LhsPartial) {
    return {{}};
//    return TableUtils::toTable(pkb->patternAssignTable.get);
}

Table QueryPkb::getPatternAsgnByRhsPartial(std::string RhsPartial) {
    return {{}};
//    return Table();
}

Table QueryPkb::getPatternAsgnTable() {
    return pkb->patternAssignTable->getAllAsStrings();
}

// Calls

Table QueryPkb::getCallsByCaller(ProcName caller) {
    return TableUtils::toTable(pkb->callsTable->getCalled(caller));
}

Table QueryPkb::getCallsByCalled(ProcName called) {
    return TableUtils::toTable(pkb->callsTable->getCallers(called));
}

Table QueryPkb::getCallsTable() {
    return pkb->callsTable->getAllAsStrings();
}

Table QueryPkb::getCallsTByCaller(ProcName caller) {
    return TableUtils::toTable(pkb->callsTTable->getCalledT(caller));
}

Table QueryPkb::getCallsTByCalled(ProcName called) {
    return TableUtils::toTable(pkb->callsTTable->getCallersT(called));
}

Table QueryPkb::getCallsTTable() {
    return pkb->callsTTable->getAllAsStrings();
}

Table QueryPkb::getNextByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->nextTable->getAfter(before));
}

Table QueryPkb::getNextByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->nextTable->getBefore(after));
}

Table QueryPkb::getNextTable() {
    return pkb->nextTable->getAllAsStrings();
}

Table QueryPkb::getNextTByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->nextTTable->getAfter(before));
}

Table QueryPkb::getNextTByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->nextTTable->getBefore(after));
}

Table QueryPkb::getNextTTable() {
    return pkb->nextTTable->getAllAsStrings();
}

Table QueryPkb::getAffectsByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->affectsTable->getAffected(before));
}

Table QueryPkb::getAffectsByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->affectsTable->getAffector(after));
}

Table QueryPkb::getAffectsTable() {
    return pkb->affectsTable->getAllAsStrings();
}

// TODO: reorder

Table QueryPkb::getUsesPTable() {
    return pkb->usesPTable->getAllProc();
}

Table QueryPkb::getPatternIfTable() {
    return pkb->patternIfTable->getAllAsStrings();
}

Table QueryPkb::getPatternWhileTable() {
    return pkb->patternWhileTable->getAllAsStrings();
}

Table QueryPkb::getPatternIfByNum(StmtNo sNum) {
    return TableUtils::toTable(pkb->patternIfTable->getPatternByNum(sNum));
}

Table QueryPkb::getPatternIfByVar(VarName var) {
    return TableUtils::toTable(pkb->patternIfTable->getPatternByVar(var));
}

Table QueryPkb::getPatternWhileByNum(StmtNo sNum) {
    return TableUtils::toTable(pkb->patternWhileTable->getPatternByNum(sNum));
}

Table QueryPkb::getPatternWhileByVar(VarName var) {
    return TableUtils::toTable(pkb->patternWhileTable->getPatternByVar(var));
}







