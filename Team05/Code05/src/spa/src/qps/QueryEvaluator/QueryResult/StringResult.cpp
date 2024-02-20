//
// Created by Alex on 11/2/2024.
//

#include "StringResult.h"
#include "utilSpa/StringUtils.h"
#include <algorithm>
#include <iterator>

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

std::vector<std::string> StringResult::intersect(std::shared_ptr<StringResult> anotherPointer) {
    std::vector<std::string> anotherResult = anotherPointer->getResults();
    std::sort(anotherResult.begin(), anotherResult.end());
    std::sort(this->getResults().begin(), this->getResults().end());
    std::vector<std::string> finalResult;
    std::set_intersection(anotherResult.begin(), anotherResult.end(),
                          this->getResults().begin(), this->getResults().end(),
                          back_inserter(finalResult));
    return finalResult;
}