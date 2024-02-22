//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_QUERYVALIDATOR_H
#define PROJECT_QUERYVALIDATOR_H

#include "../query_elements/QueryObject.h"
#include "RuleSet.h"
#include "qps/parser/IntermediateQuery.h"



class QueryValidator {
public:
    void validateQuery(IntermediateQuery&);
};


#endif //PROJECT_QUERYVALIDATOR_H
