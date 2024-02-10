//
// Created by Alex on 11/2/2024.
//

#ifndef SPA_STRINGRESULT_H
#define SPA_STRINGRESULT_H


#include <memory>
#include <vector>
#include <string>
#include "QueryResultEnum.h"

class StringResult {
public:
    StringResult(std::shared_ptr<std::vector<std::string>>);
    QueryResultEnum getType();
    std::shared_ptr<std::vector<std::string>> getResults();
private:
    std::shared_ptr<std::vector<std::string>> results;
};


#endif //SPA_STRINGRESULT_H
