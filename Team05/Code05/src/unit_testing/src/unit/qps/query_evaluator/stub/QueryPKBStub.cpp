//
// Created by tohzh on 21/2/2024.
//

#include "QueryPKBStub.h"

// method under test, always return fixed QueryResult based on constraint.
std::shared_ptr<QueryResult> QueryPKBStub::getResult(Returnable &r, std::shared_ptr<Constraint> c) {
    if (c==nullptr){
        std::vector<std::string> vector = {};
        auto strResult = make_shared<StringResult>(vector);
        return strResult;
    }
    if (c->getConstraintType() == CONSTRAINT_TYPE_PARENT) {
        std::vector<std::string> vector = {"a", "b", "c", "f"};
        auto strResult = make_shared<StringResult>(vector);
        return strResult;
    } else if (c->getConstraintType() == CONSTRAINT_TYPE_PARENTT) {
        std::vector<std::string> vector = {"c", "d", "e"};
        auto strResult = make_shared<StringResult>(vector);
        return strResult;
    } else if (c->getConstraintType() == CONSTRAINT_TYPE_FOLLOWS) {
        std::vector<int> vector = {1, 2, 3};
        auto intResult = make_shared<IntResult>(vector);
        return intResult;
    } else if (c->getConstraintType() == CONSTRAINT_TYPE_FOLLOWST) {
        std::vector<int> vector = {3, 4, 5};
        auto intResult = make_shared<IntResult>(vector);
        return intResult;
    } else if (c->getConstraintType() == CONSTRAINT_CLASS_PATTERN) {
        std::vector<std::string> vector = {"c", "d", "e" , "f"};
        auto strResult = make_shared<StringResult>(vector);
        return strResult;
    } else if (c->getConstraintType() == CONSTRAINT_TYPE_MODIFIESS) {
        std::vector<int> vector = {2, 3, 4};
        auto intResult = make_shared<IntResult>(vector);
        return intResult;
    } else if (c->getConstraintType() == CONSTRAINT_TYPE_USESS) {
        std::vector<int> vector = {2, 4, 3};
        auto intResult = make_shared<IntResult>(vector);
        return intResult;
    } else {
        std::vector<std::string> vector = {};
        auto emptyResult = make_shared<StringResult>(vector);
        return emptyResult;
    }

}


vector<StmtNo> QueryPKBStub::getChildren(StmtNo parent) {
    return {};
}

vector<shared_ptr<ConstraintArgument>> QueryPKBStub::getContraintArgs() {
    return {};
}

bool QueryPKBStub::getParent(StmtNo parent, StmtNo child) {
    return true;
}

bool QueryPKBStub::getFollows(StmtNo before, StmtNo after) {
    return true;
}

vector<StmtNo> QueryPKBStub::getSiblings(StmtNo child) {
    return {};
}

StmtNo QueryPKBStub::getParent(StmtNo child) {
    return 0;
}

