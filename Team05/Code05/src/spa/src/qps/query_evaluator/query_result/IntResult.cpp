//
// Created by Alex on 11/2/2024.
//

#include "IntResult.h"

#include <utility>
#include <algorithm>
#include <iterator>
#include "common/StringUtils.h"

QueryResultEnum IntResult::getType() {
    return INTEGER;
}

std::vector<int> IntResult::getResults() {
    return results;
}

IntResult::IntResult(std::vector<int>& res) {
    results = res;
}

std::vector<std::string> IntResult::format() {
    std::vector<std::string> strings;

    // Use std::transform to map integers to strings
    std::transform(results.begin(), results.end(), std::back_inserter(strings),
                   [](int i) { return std::to_string(i); });

    return strings;
}

std::vector<int> IntResult::intersect(std::shared_ptr<IntResult> anotherPointer) {
    std::vector<int> anotherResult = anotherPointer->getResults();
    std::sort(anotherResult.begin(), anotherResult.end());
    std::vector<int> currResult = this->getResults();
    std::sort(currResult.begin(), currResult.end());
    std::vector<int> finalResult;
    std::set_intersection(anotherResult.begin(), anotherResult.end(),
                          currResult.begin(), currResult.end(),
                          back_inserter(finalResult));
    return finalResult;
}
