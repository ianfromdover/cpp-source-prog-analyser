//
// Created by tohzh on 8/2/2024.
//

#include "RelationshipConstraint.h"

std::string RelationshipConstraint::getConstraintClass() {
    return QueryEnums::ENUM_CONSTRAINT_CLASS[enumConstraintClass::Relationship];
}