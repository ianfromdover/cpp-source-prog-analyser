//
// Created by tohzh on 15/2/2024.
//

#include "VariableEntity.h"
#include "qps/QueryProjector/ResultTable/ResultTable.h"

std::string VariableEntity::getReturnType() {
    return RETURN_STR_RESULT;
}

std::string VariableEntity::getEntityType() {
    return TYPE_VARIABLE;
}

VariableEntity::VariableEntity(std::string s) {
    identifier = std::move(s);
}

std::string VariableEntity::toString() {
    return this->identifier + " [VARIABLE]";
}

std::string VariableEntity::getArgumentValue() {
    return this->identifier;
}

Table VariableEntity::getEntityTable(QueryPkbVirtual &pkb) {
    auto entityTable = pkb.getVarTable();
    // Insertion of headers into our entity table
    entityTable.insert(entityTable.begin(),
                       {this->identifier, this->identifier});
    // HOTFIX
    ResultTable table(entityTable);
    table.removeAllColumnsExceptIndex(1);
    return table.getTable();
}
