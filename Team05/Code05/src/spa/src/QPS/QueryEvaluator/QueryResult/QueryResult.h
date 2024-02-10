//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYRESULT_H
#define SPA_QUERYRESULT_H


#include "QueryResultEnum.h"

class QueryResult {
public:
    virtual QueryResultEnum getType() = 0;
};


#endif //SPA_QUERYRESULT_H
