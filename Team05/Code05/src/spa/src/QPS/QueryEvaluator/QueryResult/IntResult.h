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
    IntResult(std::vector<int>&);
    QueryResultEnum getType();
    std::vector<int> getResults();
private:
    std::vector<int> results;
};


#endif //SPA_INTRESULT_H
