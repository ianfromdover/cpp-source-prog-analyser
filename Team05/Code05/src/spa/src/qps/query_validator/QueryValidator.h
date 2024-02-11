//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_QUERYVALIDATOR_H
#define PROJECT_QUERYVALIDATOR_H

#include "../query_elements/QueryObject.h"
#include "RuleSet.h"

class QueryValidator {
public:
    std::vector<std::string> validateQuery(QueryObject&);
};


#endif //PROJECT_QUERYVALIDATOR_H
