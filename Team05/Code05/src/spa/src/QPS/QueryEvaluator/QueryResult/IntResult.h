//
// Created by Alex on 11/2/2024.
//

#ifndef SPA_INTRESULT_H
#define SPA_INTRESULT_H


#include <vector>
#include <memory>
#include "QueryResult.h"

class IntResult : public QueryResult {
public:
    IntResult(std::shared_ptr<std::vector<int>>);
    QueryResultEnum getType();
    std::shared_ptr<std::vector<int>> getResults();
private:
    std::shared_ptr<std::vector<int>> results;
};


#endif //SPA_INTRESULT_H
