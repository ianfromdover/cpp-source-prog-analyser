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
        duplicatedTable = make_shared<table>(ResultTable::duplicateColumn(entityTable, this->varName, HEADER_ENT_WITH_TOMERGE));
    } else if (varAttribute == QPSTokenType::WITHVARNAME || varAttribute == QPSTokenType::WITHPROCNAME) {
        //duplicate left
        duplicatedTable = make_shared<table>(ResultTable::duplicateColumn(entityTable, HEADER_ENT_WITHVAR, HEADER_ENT_WITH_TOMERGE));
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
    return entityTable.size() > 1;
}

std::vector<std::vector<std::string>> VariableWith::removeColumnByIndex(int i, std::vector<std::vector<std::string>> table){
    if (i >= 0 && i < table[0].size()) {
        for (int j = 0; j < table.size(); ++j) {
            table[j].erase(table[j].begin() + i);
        }
    }
    return table;
}