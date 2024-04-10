//
// Created by tohzh on 20/3/2024.
//

#include "VariableWith.h"

#include <utility>

VariableWith::VariableWith(std::string name, QPSTokenType::QPSTypeInfo attribute) {
    varName = std::move(name);
    varAttribute = attribute;
}


std::vector<std::string> VariableWith::getArgumentValue() {
    return {getVarName()};
}

// column that returns value based on SELECT should be synonym name
// return columns of tables are {statement number, synonym name}
std::vector<std::string> VariableWith::getHeadersForTable() {
    std::set<std::string> returnSynName = {TYPE_VARIABLE, TYPE_PROCEDURE, TYPE_CALL};
    std::string currType = this->variable->getEntityType();
    if (returnSynName.find(currType) == returnSynName.end()) {
        // not inside the set
        // this entity returns statement number
        return {this->varName, HEADER_ENT_WITHVAR};
    } else {
        return {HEADER_ENT_WITHVAR, this->varName};
    }
}

std::vector<std::vector<std::string>> VariableWith::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = getRawTable(pkb);
    if (!hasMoreThanOneColumn(entityTable)) {
        // only has one column, duplicate that column
        entityTable.insert(entityTable.begin(), {this->varName});
        return ResultTable::duplicateColumn(entityTable, this->varName, HEADER_ENT_WITH_TOMERGE);
    }
    std::shared_ptr<table> duplicatedTable;
    auto headers = getHeadersForTable();
    entityTable.insert(entityTable.begin(), headers);
    if (varAttribute == QPSTokenType::WITHSTMT) {
        //duplicate left
        duplicatedTable = make_shared<table>(ResultTable::duplicateColumnBasedOnIndex(entityTable,
                                                                                      0, HEADER_ENT_WITH_TOMERGE));
    } else if (varAttribute == QPSTokenType::WITHVARNAME || varAttribute == QPSTokenType::WITHPROCNAME || varAttribute == QPSTokenType::WITHVALUE) {
        //duplicate right
        duplicatedTable = make_shared<table>(ResultTable::duplicateColumnBasedOnIndex(entityTable,
                                                                                      1, HEADER_ENT_WITH_TOMERGE));
    } else {
        throw new QPSException("Invalid token type provided for with variable");
    }

    auto res  = ResultTable(*duplicatedTable);
    res.removeColumnByHeader(HEADER_ENT_WITHVAR);
    return res.getTable();
}

std::string VariableWith::toString() {
    return varName + "." + to_string(varAttribute) + " [VAR_WITH]";
}

std::string VariableWith::getEntityType() {
    return TYPE_VAR_WITH;
}

std::string VariableWith::getReturnType() {
    if (this->varAttribute == QPSTokenType::VARNAME || this->varAttribute == QPSTokenType::PROCNAME) {
        return RETURN_STR_RESULT;
    } else {
        return RETURN_INT_RESULT;
    }
}

std::string VariableWith::getVarName() {
    return varName;
}

QPSTokenType::QPSTypeInfo VariableWith::getVarAttribute() {
    return varAttribute;
}

void VariableWith::setVariable(std::shared_ptr<QueryObject> qo) {
    variable = qo->getEntityInDeclaration(varName);
}

std::vector<std::vector<std::string>> VariableWith::getRawTable(QueryPkbVirtual &pkb) {
    if (variable == nullptr) {
        throw QPSException("Invalid PKB Query");
    }
    return variable->getRawTable(pkb);
}

bool VariableWith::hasMoreThanOneColumn(std::vector<std::vector<std::string>> entityTable) {
    if (entityTable.size() < 0) {
        return false;
    }
    return entityTable[0].size() > 1;
}

std::vector<std::vector<std::string>> VariableWith::removeColumnByIndex(int i, std::vector<std::vector<std::string>> table){
    if (i >= 0 && i < table[0].size()) {
        for (int j = 0; j < table.size(); ++j) {
            table[j].erase(table[j].begin() + i);
        }
    }
    return table;
}

bool isInSet(std::set<QPSTokenType::QPSTypeInfo> set, QPSTokenType::QPSTypeInfo token) {
    if (set.find(token) == set.end()) {
        // not inside the set
        return false;
    } else {
        return true;
    }
}

std::shared_ptr<Formattable>
VariableWith::getSelectResults(QueryPkbVirtual &pkb, shared_ptr<ResultTable> rTable, shared_ptr<ResultTable> resultTable) {
    std::vector<std::vector<std::string>> wholeTable = this->getEntityTable(pkb);
    std::vector<string> val = rTable->getDistinctColumn(varName);
    val.insert(val.begin(), {varName});
    std::vector<std::vector<std::string>> subTable = {val};
    table ans = ResultTable::hashJoin(wholeTable, subTable);
    auto type = variable->getEntityType();
    std::set<QPSTokenType::QPSTypeInfo> leftColSet = {QPSTokenType::PROCNAME, QPSTokenType::VARNAME};
    std::set<QPSTokenType::QPSTypeInfo> rightColSet = {QPSTokenType::WITHVALUE, QPSTokenType::WITHSTMT};
    if (isInSet(leftColSet, this->getVarAttribute())) {
        return std::make_shared<StringResult>(ans[0]);
    } else if (isInSet(rightColSet, this->getVarAttribute())) {
        return std::make_shared<StringResult>(ans[1]);
    } else {
        throw QPSException("qps attribute token is neither in left or right set");
    }
}
