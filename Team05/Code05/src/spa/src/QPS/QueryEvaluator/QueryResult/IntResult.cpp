//
// Created by Alex on 11/2/2024.
//

#include "IntResult.h"

#include <utility>

QueryResultEnum IntResult::getType() {
    return INTEGER;
}

std::shared_ptr<std::vector<int>> IntResult::getResults() {
    return results;
}

IntResult::IntResult(std::shared_ptr<std::vector<int>> res) {
    results = std::move(res);
}
