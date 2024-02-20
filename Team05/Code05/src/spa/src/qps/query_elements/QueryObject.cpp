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

std::vector<std::shared_ptr<Constraint>> QueryObject::getConstraints() {
    return constraints;
}

void QueryObject::addConstraint(std::shared_ptr<Constraint> c) {
    constraints.push_back(c);
}

std::vector<std::shared_ptr<Entity>> QueryObject::getDeclarations() {
    return declarations;
}

void QueryObject::addDeclaration(const std::shared_ptr<Entity>& d) {
    declarations.push_back(d);
}

std::shared_ptr<Entity> QueryObject::getEntityInDeclaration(std::string toFind) {
    for (shared_ptr<Entity> ent : declarations) {
        if (ent->getIdentifier() == toFind) {
            return ent;
        }
    }
    return nullptr;
}

std::string QueryObject::toString() {
    std::string returnString = getReturnString();
    std::string declarationString = getDeclarationString();
    std::string constraintString = getConstraintString();
    return returnString + "\n" + declarationString + "\n" + constraintString;
}

std::string QueryObject::getReturnString() {
    if (this->returnType == nullptr) {
        return "";
    } else {
        return "{RETURN}: " + this->getReturnType()->toString();
    }

}

std::string QueryObject::getDeclarationString() {
    if (this->declarations.empty()) {
        return "";
    }
    std::string declarationString = "{DECLARATIONS}: ";
    for (auto it = declarations.begin(); it != declarations.end(); ++it) {
        declarationString += (*it)->toString();
        if (std::next(it) != declarations.end()){
            declarationString += ", ";
        }
    }
    return declarationString;
}

std::string QueryObject::getConstraintString() {
    if (this->constraints.empty()) {
        return "";
    }
    std::string constraintString = "{CONSTRAINTS}: ";

    for (auto it = constraints.begin(); it != constraints.end(); ++it) {
        constraintString += (*it)->toString();
        if (std::next(it) != constraints.end()){
            constraintString += ", ";
        }
    }
    return constraintString;
}

