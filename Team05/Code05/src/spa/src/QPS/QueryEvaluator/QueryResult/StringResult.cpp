//
// Created by Alex on 11/2/2024.
//

#include "StringResult.h"

QueryResultEnum StringResult::getType() {
    return STRING;
}

StringResult::StringResult(std::shared_ptr<std::vector<std::string>> res) {
    results = res;
}

std::shared_ptr<std::vector<std::string>> StringResult::getResults() {
    return results;
}
