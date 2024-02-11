//
// Created by Alex on 11/2/2024.
//

#include "IntResult.h"

#include <utility>
#include <algorithm>
#include <iterator>
#include "utilSpa/StringUtils.h"

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
