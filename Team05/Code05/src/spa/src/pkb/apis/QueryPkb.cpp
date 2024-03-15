#include "QueryPkb.h"
#include "pkb/storage/base/TwoSideMap.hpp"

#include <utility>

QueryPkb::QueryPkb(std::shared_ptr<PkbStorage> p) {
    pkb = std::move(p);
}

// Conversion methods

std::vector<std::vector<std::string>> QueryPkb::toVecVecStr(std::vector<std::string> vec) {

    std::vector<std::vector<std::string>> result;

    for (const std::string& element : vec) {
        // Create a vector<string> to hold the current element
        std::vector<std::string> strElem;

        // Put the element into the str vector
        strElem.push_back((element));

        // Add the vector to the result
        result.push_back(strElem);
    }

    return result;
}


template <typename A>
std::vector<std::vector<std::string>> QueryPkb::toVecVecStr(std::vector<A> vec) {

    std::vector<std::vector<std::string>> result;

    for (const auto& element : vec) {
        // Create a vector<string> to hold the current element
        std::vector<std::string> strElem;

        // Put the element into the str vector
        strElem.push_back(std::to_string(element)); // TODO: ian's CLion says to_string not found here

        // Add the vector to the result
        result.push_back(strElem);
    }

    return result;
}

//template <typename A, typename B>
//std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(TwoSideMap<A, B> map) {
//
//    std::vector<std::vector<std::string>> result;
//
//    return result;
//}

//std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(std::string element) {
//
//    std::vector<std::vector<std::string>> result;
//
//    // Create a vector<string> to hold the current element
//    std::vector<std::string> strElem;
//
//    // Put the element into the str vector
//    strElem.push_back((element));
//
//    return result;
//}

//std::shared_ptr<QueryResult> QueryPKB::getResult(Returnable &, std::shared_ptr<Constraint>) {
//    return std::shared_ptr<QueryResult>();
//}

// CallStmt

std::vector<std::vector<std::string>> QueryPkb::getCallByNum(StmtNo sNum) {
    return toVecVecStr(pkb->callTable->getProc(sNum));
}

std::vector<std::vector<std::string>> QueryPkb::getCallByProc(ProcName proc) {
    return toVecVecStr(pkb->callTable->getStmts(proc));
}

std::vector<std::vector<std::string>> QueryPkb::getCallTable() {
    return pkb->callTable->getAllAsStrings();
}

// Proc

std::vector<std::vector<std::string>> QueryPkb::getProcByName(ProcName proc) {
    return toVecVecStr(pkb->procedureTable->getProcByName(proc));
}

std::vector<std::vector<std::string>> QueryPkb::getProcTable() {
    return pkb->procedureTable->getAllAsStrings();
}

// Read

std::vector<std::vector<std::string>> QueryPkb::getReadByNum(StmtNo sNum) {
    return toVecVecStr(pkb->readTable->getReadVar(sNum));
}

std::vector<std::vector<std::string>> QueryPkb::getReadByVar(VarName var) {
    return toVecVecStr(pkb->readTable->getReadStmts(var));
}

std::vector<std::vector<std::string>> QueryPkb::getReadTable() {
    return pkb->readTable->getAllAsStrings();
}

// If

std::vector<std::vector<std::string>> QueryPkb::getIfByNum(StmtNo sNum) {
    return toVecVecStr(pkb->ifTable->getIfVars(sNum));
}

std::vector<std::vector<std::string>> QueryPkb::getIfByVar(VarName var) {
    return toVecVecStr(pkb->ifTable->getIfStmts(var));
}

std::vector<std::vector<std::string>> QueryPkb::getIfTable() {
    return pkb->ifTable->getAllAsStrings();
}

// While

std::vector<std::vector<std::string>> QueryPkb::getWhileByNum(StmtNo sNum) {
    return toVecVecStr(pkb->whileTable->getWhileVars(sNum));
}

std::vector<std::vector<std::string>> QueryPkb::getWhileByVar(VarName var) {
    return toVecVecStr(pkb->whileTable->getWhileStmts(var));
}

std::vector<std::vector<std::string>> QueryPkb::getWhileTable() {
    return pkb->whileTable->getAllAsStrings();
}

// Print

std::vector<std::vector<std::string>> QueryPkb::getPrintByNum(StmtNo sNum) {
    return toVecVecStr(pkb->printTable->getPrintVar(sNum));
}

std::vector<std::vector<std::string>> QueryPkb::getPrintByVar(VarName var) {
    return toVecVecStr(pkb->printTable->getPrintStmts(var));
}

std::vector<std::vector<std::string>> QueryPkb::getPrintTable() {
    return pkb->whileTable->getAllAsStrings();
}

// Stmt

// TODO
std::vector<std::vector<std::string>> QueryPkb::getStmtByNum(int StmtNo) {
    return {{}};
//    return toVecVecStr(pkb->statementTable->getAllStmts());
}

std::vector<std::vector<std::string>> QueryPkb::getStmtTable() {
    return pkb->statementTable->getAllAsStrings();
}

// Var

// TODO
std::vector<std::vector<std::string>> QueryPkb::getVarByName(VarName var) {
    return {{}};
    // return toVecVecStr(pkb->varTable->getVarByName(var));
}

std::vector<std::vector<std::string>> QueryPkb::getVarTable() {
    return pkb->varTable->getAllAsStrings();
}

// Const

// TODO
// constants don't have names
// shouldn't it be getConstByNum(StmtNo sNum) and
// getConstByValue(ConstVal val) instead?
// and will QPS actually use this API?
std::vector<std::vector<std::string>> QueryPkb::getConstByName(VarName var) {
    return {{}};
}

std::vector<std::vector<std::string>> QueryPkb::getConstTable() {
    return pkb->constTable->getAllAsStrings();
}

// Follows

std::vector<std::vector<std::string>> QueryPkb::getFollowsByBefore(StmtNo before) {
    return toVecVecStr(pkb->followsTable->getFollower(before));
}

std::vector<std::vector<std::string>> QueryPkb::getFollowsByAfter(StmtNo after) {
    return toVecVecStr(pkb->followsTable->getStmtBefore(after));
}

std::vector<std::vector<std::string>> QueryPkb::getFollowsTable() {
    return pkb->followsTable->getAllAsStrings();
}

// FollowsT

std::vector<std::vector<std::string>> QueryPkb::getFollowsTByBefore(StmtNo before) {
    return toVecVecStr(pkb->followsTTable->getStmtsAfter(before));
}

std::vector<std::vector<std::string>> QueryPkb::getFollowsTByAfter(StmtNo after) {
    return toVecVecStr(pkb->followsTTable->getStmtsBefore(after));
}

std::vector<std::vector<std::string>> QueryPkb::getFollowsTTable() {
    return pkb->followsTTable->getAllAsStrings();
}

// Parent

std::vector<std::vector<std::string>> QueryPkb::getParentByParent(StmtNo parent) {
    return toVecVecStr(pkb->parentTable->getChildren(parent));
}

std::vector<std::vector<std::string>> QueryPkb::getParentByChild(StmtNo child) {
    return toVecVecStr(pkb->parentTable->getParent(child));
}

std::vector<std::vector<std::string>> QueryPkb::getParentTable() {
    return pkb->parentTable->getAllAsStrings();
}

// ParentT

std::vector<std::vector<std::string>> QueryPkb::getParentTByParent(StmtNo parent) {
    return toVecVecStr(pkb->parentTTable->getChildrenT(parent));
}

std::vector<std::vector<std::string>> QueryPkb::getParentTByChild(StmtNo child) {
    return toVecVecStr(pkb->parentTTable->getParentsT(child));
}

std::vector<std::vector<std::string>> QueryPkb::getParentTTable() {
    return pkb->parentTTable->getAllAsStrings();
}

// UsesS

std::vector<std::vector<std::string>> QueryPkb::getUsesSByNum(StmtNo user) {
    return toVecVecStr(pkb->usesSTable->getUsesBySNum(user));
}

std::vector<std::vector<std::string>> QueryPkb::getUsesSByVar(VarName used) {
    return toVecVecStr(pkb->usesSTable->getUsesByVar(used));
}

//template <typename A, typename B>
//std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(TwoSideMap<A, B> map) {
//
//    std::vector<std::vector<std::string>> result;
//
//    return result;
//}
//
//std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(std::string element) {
//
//    std::vector<std::vector<std::string>> result;
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
//std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(TwoSideMap<A, B> map) {
//
//    std::vector<std::vector<std::string>> result;
//
//    return result;
//}
std::vector<std::vector<std::string>> QueryPkb::getUsesSTable() {
    return pkb->usesSTable->getAllAsStrings();
}

// ModifiesS

std::vector<std::vector<std::string>> QueryPkb::getModifiesSByNum(StmtNo modifier) {
    return toVecVecStr(pkb->modifiesSTable->getModifiedS(modifier));
}

std::vector<std::vector<std::string>> QueryPkb::getModifiesSByVar(VarName modified) {
    return toVecVecStr(pkb->modifiesSTable->getModifiersS(modified));
}

std::vector<std::vector<std::string>> QueryPkb::getModifiesSTable() {
    return pkb->modifiesSTable->getAllAsStrings();
}

// ModifiesP

std::vector<std::vector<std::string>> QueryPkb::getModifiesPByProc(ProcName modifier) {
    return toVecVecStr(pkb->modifiesPTable->getModifiedP(modifier));
}

std::vector<std::vector<std::string>> QueryPkb::getModifiesPByVar(VarName modified) {
    return toVecVecStr(pkb->modifiesPTable->getModifiersP(modified));
}

std::vector<std::vector<std::string>> QueryPkb::getModifiesPTable() {
    return pkb->modifiesPTable->getAllAsStrings();
}

// PatternAssign
// TODO: patternAssign methods in the class are not ready
std::vector<std::vector<std::string>> QueryPkb::getPatternAsgnByNum(StmtNo sNum) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable.get);
}

std::vector<std::vector<std::string>> QueryPkb::getPatternAsgnByLhs(std::string Lhs) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable->getRhsFromLhs(Lhs));
}

std::vector<std::vector<std::string>> QueryPkb::getPatternAsgnByRhs(std::string Rhs) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable->getLhsFromRhs(Rhs));
}

std::vector<std::vector<std::string>> QueryPkb::getPatternAsgnByLhsPartial(std::string LhsPartial) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable.get);
}

std::vector<std::vector<std::string>> QueryPkb::getPatternAsgnByRhsPartial(std::string RhsPartial) {
    return {{}};
//    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPkb::getPatternAsgnTable() {
    return pkb->patternAssignTable->getAllAsStrings();
}

// Calls

std::vector<std::vector<std::string>> QueryPkb::getCallsByCaller(ProcName caller) {
    return toVecVecStr(pkb->callsTable->getCalled(caller));
}

std::vector<std::vector<std::string>> QueryPkb::getCallsByCalled(ProcName called) {
    return toVecVecStr(pkb->callsTable->getCallers(called));
}

std::vector<std::vector<std::string>> QueryPkb::getCallsTable() {
    return pkb->callsTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkb::getCallsTByCaller(ProcName caller) {
    return toVecVecStr(pkb->callsTTable->getCalledT(caller));
}

std::vector<std::vector<std::string>> QueryPkb::getCallsTByCalled(ProcName called) {
    return toVecVecStr(pkb->callsTTable->getCallersT(called));
}

std::vector<std::vector<std::string>> QueryPkb::getCallsTTable() {
    return pkb->callsTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkb::getNextByBefore(StmtNo before) {
    return toVecVecStr(pkb->nextTable->getAfter(before));
}

std::vector<std::vector<std::string>> QueryPkb::getNextByAfter(StmtNo after) {
    return toVecVecStr(pkb->nextTable->getBefore(after));
}

std::vector<std::vector<std::string>> QueryPkb::getNextTable() {
    return pkb->nextTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkb::getNextTByBefore(StmtNo before) {
    return toVecVecStr(pkb->nextTTable->getAfter(before));
}

std::vector<std::vector<std::string>> QueryPkb::getNextTByAfter(StmtNo after) {
    return toVecVecStr(pkb->nextTTable->getBefore(after));
}

std::vector<std::vector<std::string>> QueryPkb::getNextTTable() {
    return pkb->nextTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkb::getAffectsByBefore(StmtNo before) {
    return toVecVecStr(pkb->affectsTable->getAffected(before));
}

std::vector<std::vector<std::string>> QueryPkb::getAffectsByAfter(StmtNo after) {
    return toVecVecStr(pkb->affectsTable->getAffector(after));
}

std::vector<std::vector<std::string>> QueryPkb::getAffectsTable() {
    return pkb->affectsTable->getAllAsStrings();
}

// TODO: reorder

std::vector<std::vector<std::string>> QueryPkb::getUsesPTable() {
    return pkb->usesPTable->getAllProc();
}

std::vector<std::vector<std::string>> QueryPkb::getPatternIfTable() {
    return pkb->patternIfTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkb::getPatternWhileTable() {
    return pkb->patternWhileTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPkb::getPatternIfByNum(StmtNo sNum) {
    return toVecVecStr(pkb->patternIfTable->getPatternByNum(sNum));
}

std::vector<std::vector<std::string>> QueryPkb::getPatternIfByVar(VarName var) {
    return toVecVecStr(pkb->patternIfTable->getPatternByVar(var));
}

std::vector<std::vector<std::string>> QueryPkb::getPatternWhileByNum(StmtNo sNum) {
    return toVecVecStr(pkb->patternWhileTable->getPatternByNum(sNum));
}

std::vector<std::vector<std::string>> QueryPkb::getPatternWhileByVar(VarName var) {
    return toVecVecStr(pkb->patternWhileTable->getPatternByVar(var));
}







