//
// Created by tohzh on 31/3/2024.
//

#ifndef SPA_TUPLESTRINGRESULT_H
#define SPA_TUPLESTRINGRESULT_H

#include <memory>
#include <vector>
#include <string>
#include "QueryResultEnum.h"
#include "QueryResult.h"
#include "qps/query_projector/Formattable.h"

class TupleStringResult : public QueryResult {
public:
    explicit TupleStringResult(std::vector<std::vector<std::string>>& res);
    QueryResultEnum getType() override;
    std::vector<std::vector<std::string>> getResults();
    std::vector<std::string> format() override;
    std::vector<std::vector<std::string>> intersect(std::shared_ptr<TupleStringResult>);
private:
    std::vector<std::vector<std::string>> results;

};

#endif //SPA_TUPLESTRINGRESULT_H
