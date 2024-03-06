//
// Created by sjh_9 on 25/2/2024.
//

#include "QueryPKB.h"

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

std::vector<std::vector<std::string>> QueryPKB::getParent() {
    return pkb->parentTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getParentT() {
    return pkb->parentTTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getUses() {
    return pkb->usesSTable->getTable();
}

std::vector<std::vector<std::string>> QueryPKB::getUsesP() {
    return pkb->usesPTable->getTable();
}

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

// CallTable methods

std::vector<std::vector<std::string>> QueryPKB::getCallByProc(ProcName name) {
    return toVecVecStr(pkb->callTable->getStmts(name));
}

std::vector<std::vector<std::string>> QueryPKB::getProc(StmtNo sNum) {
    return toVecVecStr(pkb->callTable->getProc(sNum));
}

std::vector<std::vector<std::string>> QueryPKB::getReadByNum(int StmtNo) {
    return toVecVecStr(pkb->readTable->getReadVar(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getReadByVar(VarName var) {
    return toVecVecStr(pkb->readTable->getReadStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getIfByNum(int StmtNo) {
    return toVecVecStr(pkb->ifTable->getIfVars(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getWhileByNum(int StmtNo) {
    return toVecVecStr(pkb->whileTable->getWhiles(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getWhileByVar(string var) {
    return toVecVecStr(pkb->whileTable->getWhileStmts(var));
}

std::vector<std::vector<std::string>> QueryPKB::getPrintByNum(int StmtNo) {
    return toVecVecStr(pkb->printTable->getPrintVar(StmtNo));
}

std::vector<std::vector<std::string>> QueryPKB::getPrintByVar(string var) {
    return toVecVecStr(pkb->printTable->getPrintStmts(var));
}

// TODO
std::vector<std::vector<std::string>> QueryPKB::getStmtByNum(int StmtNo) {
    return {{}};
}

std::vector<std::vector<std::string>> QueryPKB::getProcByName(string proc) {
    return toVecVecStr(pkb->procedureTable->getAllProcs());
}

// TODO
std::vector<std::vector<std::string>> QueryPKB::getVarByName(string var) {
    return {{}};
}

// TODO
std::vector<std::vector<std::string>> QueryPKB::getConstByName(string var) {
    return {{}};
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsByBefore(int StmtNo) {
    return std::vector<std::vector<std::string>>();
}

std::vector<std::vector<std::string>> QueryPKB::getFollowsByAfter(int StmtNo) {
    return std::vector<std::vector<std::string>>();
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

    for (const A& element : vec) {
        // Create a vector<string> to hold the current element
        std::vector<std::string> strElem;

        // Put the element into the str vector
        strElem.push_back(std::to_string(element));

        // Add the vector to the result
        result.push_back(strElem);
    }

    return result;
}

template <typename A, typename B>
std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(TwoSideMap<A, B> map) {

    std::vector<std::vector<std::string>> result;

    return result;
}

std::vector<std::vector<std::string>> QueryPKB::toVecVecStr(std::string element) {

    std::vector<std::vector<std::string>> result;

    // Create a vector<string> to hold the current element
    std::vector<std::string> strElem;

    // Put the element into the str vector
    strElem.push_back((element));

    return result;
}

//std::shared_ptr<QueryResult> QueryPKB::getResult(Returnable &, std::shared_ptr<Constraint>) {
//    return std::shared_ptr<QueryResult>();
//}





