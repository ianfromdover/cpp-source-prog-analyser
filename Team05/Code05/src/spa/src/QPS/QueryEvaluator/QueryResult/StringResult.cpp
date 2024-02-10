//
// Created by Alex on 11/2/2024.
//

#include "StringResult.h"
#include "Utils/Utils.h"

QueryResultEnum StringResult::getType() {
    return STRING;
}

std::vector<std::string> StringResult::getResults() {
    return results;
}

StringResult::StringResult(std::vector<std::string>& res) {
    results = res;
}

std::vector<std::string> StringResult::format() {
    return results;
}
