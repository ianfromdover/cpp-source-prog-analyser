//
// Created by tohzh on 7/2/2024.
//

#include "QueryObject.h"

std::shared_ptr<Returnable> QueryObject::getReturnType() {
    return returnType;
}

void QueryObject::setReturnType(std::shared_ptr<Returnable> ptr) {
    returnType = std::move(ptr);
}

std::vector<Constraint>& QueryObject::getConstraints() {
    return constraints;
}

void QueryObject::addConstraint(Constraint& c) {
    constraints.push_back(c);
}

std::vector<Declaration>& QueryObject::getDeclarations() {
    return declarations;
}

void QueryObject::addDeclaration(Declaration& d) {
    declarations.push_back(d);
}
