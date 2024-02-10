//
// Created by tohzh on 10/2/2024.
//

#include "PatternConstraint.h"


std::string PatternConstrain::getConstraintClass() {
    return QueryEnums::ENUM_CONSTRAINT_CLASS[enumConstraintClass::Pattern];
}
