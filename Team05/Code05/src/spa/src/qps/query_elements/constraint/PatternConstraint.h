//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_PATTERNCONSTRAINT_H
#define PROJECT_PATTERNCONSTRAINT_H

#include "qps/query_elements/constraint/Constraint.h"

class PatternConstrain : Constraint {
public:
    std::string getConstraintClass() override;
};

#endif //PROJECT_PATTERNCONSTRAINT_H
