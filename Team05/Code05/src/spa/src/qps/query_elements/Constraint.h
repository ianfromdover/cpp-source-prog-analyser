//
// Created by tohzh on 7/2/2024.
//

#ifndef SPA_CONSTRAINT_H
#define SPA_CONSTRAINT_H

#include <string>
#include <vector>
#include "ConstraintArgument.h"
#include "QueryEnums.h"


class Constraint {
public:
    virtual std::string getConstraintClass() = 0;
    virtual std::string getConstraintType() = 0;
    virtual std::vector<ConstraintArgument*> getConstraintArguments() = 0;

};


#endif //SPA_CONSTRAINT_H
