//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYRESULT_H
#define SPA_QUERYRESULT_H


#include <string>
#include "QueryResultEnum.h"
#include "../../QueryProjector/Formattable.h"

class QueryResult : public Formattable {
public:
    virtual QueryResultEnum getType() = 0;
    std::vector<std::string> format() override = 0;
};


#endif //SPA_QUERYRESULT_H
