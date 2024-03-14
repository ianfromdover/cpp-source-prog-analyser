#include "QueryPKB.h"
#include "pkb/storage/base/TwoSideMap.hpp"

#include <utility>

QueryPKB::QueryPKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

// Conversion methods

std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(std::vector<std::string> vec) {

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
std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(std::vector<A> vec) {

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

std::vector<std::vector<std::string>> QueryPKB::getCallByNum(StmtNo sNum) {
    return toVecVecStr(pkb->callTable->getProc(sNum));
}

std::vector<std::vector<std::string>> QueryPKB::getCallByProc(ProcName proc) {
    return toVecVecStr(pkb->callTable->getStmts(proc));
}

std::vector<std::vector<std::string>> QueryPKB::getCallTable() {
    return pkb->callTable->getAllAsStrings();
}

// Proc

std::vector<std::vector<std::string>> QueryPKB::getProcByName(ProcName proc) {
    return toVecVecStr(pkb->procedureTable->getProcByName(proc));
}

std::vector<std::vector<std::string>> QueryPKB::getProcTable() {
    return pkb->procedureTable->getAllAsStrings();
}

// Read

std::vector<std::vector<std::string>> QueryPKB::getReadByNum(StmtNo sNum) {
    return toVecVecStr(pkb->readTable->getReadVar(sNum));
}

std::vector<std::vector<std::string>> QueryPKB::getReadByVar(VarName var) {
    return toVecVecStr(pkb->readTable->getReadStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getReadTable() {
    return pkb->readTable->getAllAsStrings();
}

// If

std::vector<std::vector<std::string>> QueryPKB::getIfByNum(StmtNo sNum) {
    return toVecVecStr(pkb->ifTable->getIfVars(sNum));
}

std::vector<std::vector<std::string>> QueryPKB::getIfByVar(VarName var) {
    return toVecVecStr(pkb->ifTable->getIfStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getIfTable() {
    return pkb->ifTable->getAllAsStrings();
}

// While

std::vector<std::vector<std::string>> QueryPKB::getWhileByNum(StmtNo sNum) {
    return toVecVecStr(pkb->whileTable->getWhileVars(sNum));
}

std::vector<std::vector<std::string>> QueryPKB::getWhileByVar(VarName var) {
    return toVecVecStr(pkb->whileTable->getWhileStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getWhileTable() {
    return pkb->whileTable->getAllAsStrings();
}

// Print

std::vector<std::vector<std::string>> QueryPKB::getPrintByNum(StmtNo sNum) {
    return toVecVecStr(pkb->printTable->getPrintVar(sNum));
}

std::vector<std::vector<std::string>> QueryPKB::getPrintByVar(VarName var) {
    return toVecVecStr(pkb->printTable->getPrintStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getPrintTable() {
    return pkb->whileTable->getAllAsStrings();
}

// Stmt

// TODO
std::vector<std::vector<std::string>> QueryPKB::getStmtByNum(int StmtNo) {
    return {{}};
//    return toVecVecStr(pkb->statementTable->getAllStmts());
}

std::vector<std::vector<std::string>> QueryPKB::getStmtTable() {
    return pkb->statementTable->getAllAsStrings();
}

// Var

// TODO
std::vector<std::vector<std::string>> QueryPKB::getVarByName(VarName var) {
    return {{}};
    // return toVecVecStr(pkb->varTable->getVarByName(var));
}

std::vector<std::vector<std::string>> QueryPKB::getVarTable() {
    return pkb->varTable->getAllAsStrings();
}

// Const

// TODO
// constants don't have names
// shouldn't it be getConstByNum(StmtNo sNum) and
// getConstByValue(ConstVal val) instead?
// and will QPS actually use this API?
std::vector<std::vector<std::string>> QueryPKB::getConstByName(VarName var) {
    return {{}};
}

std::vector<std::vector<std::string>> QueryPKB::getConstTable() {
    return pkb->constTable->getAllAsStrings();
}

// Follows

std::vector<std::vector<std::string>> QueryPKB::getFollowsByBefore(StmtNo before) {
    return toVecVecStr(pkb->followsTable->getFollower(before));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsByAfter(StmtNo after) {
    return toVecVecStr(pkb->followsTable->getStmtBefore(after));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsTable() {
    return pkb->followsTable->getAllAsStrings();
}

// FollowsT

std::vector<std::vector<std::string>> QueryPKB::getFollowsTByBefore(StmtNo before) {
    return toVecVecStr(pkb->followsTTable->getStmtsAfter(before));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsTByAfter(StmtNo after) {
    return toVecVecStr(pkb->followsTTable->getStmtsBefore(after));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsTTable() {
    return pkb->followsTTable->getAllAsStrings();
}

// Parent

std::vector<std::vector<std::string>> QueryPKB::getParentByParent(StmtNo parent) {
    return toVecVecStr(pkb->parentTable->getChildren(parent));
}

std::vector<std::vector<std::string>> QueryPKB::getParentByChild(StmtNo child) {
    return toVecVecStr(pkb->parentTable->getParent(child));
}

std::vector<std::vector<std::string>> QueryPKB::getParentTable() {
    return pkb->parentTable->getAllAsStrings();
}

// ParentT

std::vector<std::vector<std::string>> QueryPKB::getParentTByParent(StmtNo parent) {
    return toVecVecStr(pkb->parentTTable->getChildrenT(parent));
}

std::vector<std::vector<std::string>> QueryPKB::getParentTByChild(StmtNo child) {
    return toVecVecStr(pkb->parentTTable->getParentsT(child));
}

std::vector<std::vector<std::string>> QueryPKB::getParentTTable() {
    return pkb->parentTTable->getAllAsStrings();
}

// UsesS

std::vector<std::vector<std::string>> QueryPKB::getUsesSByNum(StmtNo user) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getUsesSByVar(VarName used) {
    return std::vector<std::vector<std::string>>();
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
std::vector<std::vector<std::string>> QueryPKB::getUsesSTable() {
    return pkb->usesSTable->getAllAsStrings();
}

// ModifiesS

std::vector<std::vector<std::string>> QueryPKB::getModifiesSByNum(StmtNo modifier) {
    return toVecVecStr(pkb->modifiesSTable->getModifiedS(modifier));
}

std::vector<std::vector<std::string>> QueryPKB::getModifiesSByVar(VarName modified) {
    return toVecVecStr(pkb->modifiesSTable->getModifiersS(modified));
}

std::vector<std::vector<std::string>> QueryPKB::getModifiesSTable() {
    return pkb->modifiesSTable->getAllAsStrings();
}

// ModifiesP

std::vector<std::vector<std::string>> QueryPKB::getModifiesPByProc(ProcName modifier) {
    return toVecVecStr(pkb->modifiesPTable->getModifiedP(modifier));
}

std::vector<std::vector<std::string>> QueryPKB::getModifiesPByVar(VarName modified) {
    return toVecVecStr(pkb->modifiesPTable->getModifiersP(modified));
}

std::vector<std::vector<std::string>> QueryPKB::getModifiesPTable() {
    return pkb->modifiesPTable->getAllAsStrings();
}

// PatternAssign
// TODO: patternAssign methods in the class are not ready
std::vector<std::vector<std::string>> QueryPKB::getPatternByNum(StmtNo sNum) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable.get);
}

std::vector<std::vector<std::string>> QueryPKB::getPatternByLhs(std::string Lhs) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable->getRhsFromLhs(Lhs));
}

std::vector<std::vector<std::string>> QueryPKB::getPatternByRhs(std::string Rhs) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable->getLhsFromRhs(Rhs));
}

std::vector<std::vector<std::string>> QueryPKB::getPatternByLhsPartial(std::string LhsPartial) {
    return {{}};
//    return toVecVecStr(pkb->patternAssignTable.get);
}

std::vector<std::vector<std::string>> QueryPKB::getPatternByRhsPartial(std::string RhsPartial) {
    return {{}};
//    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getPatternTable() {
//    return pkb->patternAssignTable
    // TODO: need to return the whole pattern table with stmtno as well
    return pkb->patternAssignTable->getAllLhsRhs();
}

// Calls

std::vector<std::vector<std::string>> QueryPKB::getCallsByCaller(ProcName caller) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getCallsByCalled(ProcName called) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getCallsTable() {
    return pkb->callsTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKB::getCallsTByCaller(ProcName caller) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getCallsTByCalled(ProcName called) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getCallsTTable() {
    return pkb->callsTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKB::getNextByBefore(StmtNo before) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getNextByAfter(StmtNo after) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getNextTable() {
    return pkb->nextTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKB::getNextTByBefore(StmtNo before) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getNextTByAfter(StmtNo after) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getNextTTable() {
    return pkb->nextTTable->getAllAsStrings();
}

std::vector<std::vector<std::string>> QueryPKB::getAffectsByBefore(StmtNo before) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getAffectsByAfter(StmtNo after) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getAffectsTable() {
    return pkb->affectsTable->getAllAsStrings();
}

// TODO: reorder

std::vector<std::vector<std::string>> QueryPKB::getUsesPTable() {
    return pkb->usesPTable->getAllProc();
}







