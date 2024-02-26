//
// Created by tohzh on 8/2/2024.
//

#include "StatementEntity.h"
#include "QPS/Exceptions/QPSException.h"

std::string StatementEntity::getReturnType() {
    return RETURN_INT_RESULT;
}

std::string StatementEntity::getEntityType() {
    return TYPE_STATEMENT;
}

StatementEntity::StatementEntity(std::string s) {
    identifier = std::move(s);
}

std::string StatementEntity::getArgumentValue() {
    return this->value;
}

std::string StatementEntity::toString() {
    return this->identifier + " [STMT]";
}

std::vector<std::vector<std::string>> StatementEntity::getEntityTable(QueryPKBVirtual &pkb) {
    throw QPSException("Invalid QPS Query");
}

//std::pair<Column<std::string>, Column<std::string>> StatementEntity::getPkbTable() {
//    // query pkb
//    return {};
//}

//std::pair<Column<std::string>,Column<std::string>> queryPkb(){
//    return {};
//}
