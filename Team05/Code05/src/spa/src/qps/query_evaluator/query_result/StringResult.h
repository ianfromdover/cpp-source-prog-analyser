//
// Created by Alex on 11/2/2024.
//

#ifndef SPA_STRINGRESULT_H
#define SPA_STRINGRESULT_H


#include <memory>
#include <vector>
#include <string>
#include "QueryResultEnum.h"
#include "QueryResult.h"
#include "qps/query_projector/Formattable.h"

class StringResult : public QueryResult {
public:
    explicit StringResult(std::vector<std::string>& res);
    QueryResultEnum getType() override;
    std::vector<std::string> getResults();
    std::vector<std::string> format() override;
    std::vector<std::string> intersect(std::shared_ptr<StringResult>);
private:
    std::vector<std::string> results;

};


#endif //SPA_STRINGRESULT_H
