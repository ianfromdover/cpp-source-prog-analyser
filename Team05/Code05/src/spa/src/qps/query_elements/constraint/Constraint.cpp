//
// Created by tohzh on 20/2/2024.
//

#include "Constraint.h"

std::string Constraint::toString() {

    std::string str = getConstraintType() + "(" + this->getConstraintArguments()[0]->toString();

    if (this->getConstraintArguments().size() > 1) {
        str += ", " + this->getConstraintArguments()[1]->toString();
    }

    str += + ")";

    return str;
}

Table Constraint::getRelationshipTable(QueryPkbVirtual &) {
    return {};
}
