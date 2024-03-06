//
// Created by sjh_9 on 25/2/2024.
//

#include "QueryPKB.h"
#include "pkb/storage/base/TwoSideMap.hpp"

#include <utility>

QueryPKB::QueryPKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

//std::vector<std::vector<std::string>> QueryPKB::getRead() {
//    return pkb->readTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getCallStmt() {
//    return pkb->callTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getIf() {
//    return pkb->ifTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getWhile() {
//    return pkb->whileTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getPrint() {
//    return pkb->printTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getStatement() {
//    return pkb->statementTable->getTable();
//}
//
//std::vector<std::vector<std::string>> QueryPKB::getProcedure() {
//    return pkb->procedureTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getVar() {
//    return pkb->variableTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getConst() {
//    return pkb->constantTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getFollows() {
//    return pkb->followsTable->getTable();
//}
//
//std::vector<std::vector<std::string>> QueryPKB::getFollowsT() {
//    return pkb->followsTTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getParent() {
//    return pkb->parentTable->getTable();
//}
//
//std::vector<std::vector<std::string>> QueryPKB::getParentT() {
//    return pkb->parentTTable->getTable();
//}

//std::vector<std::vector<std::string>> QueryPKB::getUses() {
//    return pkb->usesTable->getTable();
//}
//
//std::vector<std::vector<std::string>> QueryPKB::getModifies() {
//    return pkb->modifiesTable->getTable();
//}
std::vector<std::vector<std::string>> QueryPKB::getUses() {
    return pkb->usesSTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getUsesP() {
    return pkb->usesPTable->getTable();
}

//std::vector<std::vector<std::string>> QueryPKB::getPatternAsgn() {
//    return pkb->assignTable->getTable();
//}
std::vector<std::vector<std::string>> QueryPKB::getModifies() {
    return pkb->modifiesSTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getModifiesP() {
    return pkb->modifiesPTable->getTable();
}



std::vector<std::vector<std::string>> QueryPKB::getPatternAsgn() {
    return pkb->assignTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getCalls() {
    return pkb->callsTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getCallsT() {
    return pkb->callsTTable->getTable();
}

// CallStmt

std::vector<std::vector<std::string>> QueryPKB::getCallByNum(int StmtNo) {
    return toVecVecStr(pkb->callTable->getProc(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getCallByProc(ProcName name) {
    return toVecVecStr(pkb->callTable->getStmts(name));
}

// TODO: not actually implemented yet
std::vector<std::vector<std::string>> QueryPKB::getCallTable() {
    return pkb->callTable->getAllAsStrings();
}

// Proc

// TODO: not actually implemented yet
std::vector<std::vector<std::string>> QueryPKB::getProcByName(ProcName name) {
//    return toVecVecStr(pkb->procedureTable->getAllProcs());
}

// TODO: not actually implemented yet
std::vector<std::vector<std::string>> QueryPKB::getProcTable() {
//    return toVecVecStr(pkb->procedureTable->getAllAsStrings());
}

// Read

std::vector<std::vector<std::string>> QueryPKB::getReadByNum(int StmtNo) {
    return toVecVecStr(pkb->readTable->getReadVar(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getReadByVar(VarName var) {
    return toVecVecStr(pkb->readTable->getReadStmts(var));
}

// TODO: not actually implemented yet
std::vector<std::vector<std::string>> QueryPKB::getReadTable() {
//    return pkb->readTable->getAllAsStrings();
}

// If

std::vector<std::vector<std::string>> QueryPKB::getIfByNum(int StmtNo) {
    return toVecVecStr(pkb->ifTable->getIfVars(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getIfByVar(VarName var) {
    return toVecVecStr(pkb->ifTable->getIfStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getIfTable() {
//    return std::vector<std::vector<std::string>>();
}

// While

std::vector<std::vector<std::string>> QueryPKB::getWhileByNum(int StmtNo) {
    return toVecVecStr(pkb->whileTable->getWhileVars(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getWhileByVar(string var) {
    return toVecVecStr(pkb->whileTable->getWhileStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getWhileTable() {
//    return std::vector<std::vector<std::string>>();
}

// Print

std::vector<std::vector<std::string>> QueryPKB::getPrintByNum(int StmtNo) {
    return toVecVecStr(pkb->printTable->getPrintVar(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getPrintByVar(string var) {
    return toVecVecStr(pkb->printTable->getPrintStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getPrintTable() {
//    return std::vector<std::vector<std::string>>();
}

// Stmt

// TODO
std::vector<std::vector<std::string>> QueryPKB::getStmtByNum(int StmtNo) {
    return {{}};
//    return toVecVecStr(pkb->statementTable->getAllStmts());
}

std::vector<std::vector<std::string>> QueryPKB::getStmtTable() {
    return toVecVecStr(pkb->statementTable->getAllStmts());
}

// Var

// TODO
std::vector<std::vector<std::string>> QueryPKB::getVarByName(string var) {
//    return toVecVecStr(pkb.varTable.get);
}

std::vector<std::vector<std::string>> QueryPKB::getVarTable() {
//    return toVecVecStr(pkb->varTable->getAllVars());
}

// Const

// TODO
std::vector<std::vector<std::string>> QueryPKB::getConstByName(string var) {
    return {{}};
}

std::vector<std::vector<std::string>> QueryPKB::getConstTable() {
    return pkb->constTable->getAllAsStrings();
}

// Follows

std::vector<std::vector<std::string>> QueryPKB::getFollowsByBefore(int StmtNo) {
    return toVecVecStr(pkb->followsTable->getFollower(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsByAfter(int StmtNo) {
    return toVecVecStr(pkb->followsTable->getStmtBefore(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsTable() {
    return pkb->followsTable->getAll();
}

// FollowsT

std::vector<std::vector<std::string>> QueryPKB::getFollowsTByBefore(int StmtNo) {
    return toVecVecStr(pkb->followsTTable->getFollowersT(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsTByAfter(int StmtNo) {
    return toVecVecStr(pkb->followsTTable->getStmtsBefore(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsTTable() {
    return pkb->followsTTable->getAll();
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
        strElem.push_back(std::to_string(element));

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





