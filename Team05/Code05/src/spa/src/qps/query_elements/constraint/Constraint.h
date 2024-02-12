//
// Created by tohzh on 7/2/2024.
//

#ifndef SPA_CONSTRAINT_H
#define SPA_CONSTRAINT_H

#include <string>
#include <vector>
#include <memory>
#include "qps/query_elements/constraint_argument/ConstraintArgument.h"
#include "qps/query_elements/QueryEnums.h"
#include "utilSpa/SpaTypes.h"


class Constraint {
public:
    virtual std::string getConstraintClass() = 0;
    virtual std::string getConstraintType() = 0;
    virtual std::vector<std::shared_ptr<ConstraintArgument>>  getConstraintArguments() = 0;

};


#endif //SPA_CONSTRAINT_H
