//
// Created by Alex on 11/2/2024.
//

#ifndef SPA_STRINGRESULT_H
#define SPA_STRINGRESULT_H


#include <memory>
#include <vector>
#include <string>
#include "QueryResultEnum.h"
#include "qps/QueryProjector/Formattable.h"
#include "QueryResult.h"

class StringResult : public QueryResult {
public:
    StringResult(std::vector<std::string>&);
    QueryResultEnum getType();
    std::vector<std::string> getResults();
    std::vector<std::string> format() override;
private:
    std::vector<std::string> results;

};


#endif //SPA_STRINGRESULT_H
