//
// Created by tohzh on 31/3/2024.
//

#include "TupleStringResult.h"


QueryResultEnum TupleStringResult::getType() {
    return TUPLE_STRING;
}

std::vector<std::vector<std::string>> TupleStringResult::getResults() {
    return results;
}

TupleStringResult::TupleStringResult(std::vector<std::vector<std::string>>& res) {
    results = res;
}

std::vector<std::string> TupleStringResult::format() {
    std::vector<std::string> ans;
    if (results.empty() || results[0].empty()) {
        return ans;
    }
    for (int i = 0; i < results.size(); i++) {
        std::string row;
        for (int j = 0; j < results[0].size(); j ++) {
            row += results[i][j];
        }
        ans.push_back(row);
    }
    return ans;
}

// not implemented as the function intersect is not used.
std::vector<std::vector<std::string>> TupleStringResult::intersect(std::shared_ptr<TupleStringResult> anotherPointer) {
    return {{}};
}

