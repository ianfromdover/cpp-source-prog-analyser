//
// Created by tohzh on 21/3/2024.
//

#include "Boolean.h"

std::string Boolean::getReturnType() {
    return RETURN_BOOL_RESULT;
}

std::string Boolean::toString() {
    return std::string();
}

std::vector<std::string> Boolean::getArgumentValue() {
    return std::vector<std::string>();
}

std::vector<std::vector<std::string>> Boolean::getEntityTable(QueryPkbVirtual &pkb) {
    return std::vector<std::vector<std::string>>();
}
