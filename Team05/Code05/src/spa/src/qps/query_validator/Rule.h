//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_RULE_H
#define PROJECT_RULE_H

#include <string>
#include "../query_elements/QueryObject.h"
#include "../query_elements/QueryEnums.h"
#include "../../utilSpa/SpaTypes.h"
#include "qps/parser/IntermediateQuery.h"


class Rule {
public:
    virtual std::string validate(IntermediateQuery&) = 0;
};

#endif //PROJECT_RULE_H
