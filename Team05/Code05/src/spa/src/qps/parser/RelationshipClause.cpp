//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "RelationshipClause.h"
#include "qps/exceptions/QPSException.h"


QPSToken &RelationshipClause::getSecondArg() {
    if (secondArg != nullptr) {
        return *secondArg;
    }
    throw QPSException("Second argument is not set");
}

QPSToken &RelationshipClause::getFirstArg() {
    if (firstArg != nullptr) {
        return *firstArg;
    }
    throw QPSException("First argument is not set");
}

QPSTokenType::QPSTypeInfo RelationshipClause::getSecondArgType() {
    if (secondArg != nullptr) {
        return secondArg->getType().getInfo();
    }
    throw QPSException("Second argument is not set");
}

QPSTokenType::QPSTypeInfo RelationshipClause::getFirstArgType() {
    if (firstArg != nullptr) {
        return firstArg->getType().getInfo();
    }
    throw QPSException("First argument is not set");
}

QPSTokenType::QPSTypeInfo RelationshipClause::getRelationshipType() {
    return relationshipType;
}

QPSTokenType::QPSTypeInfo RelationshipClause::getFirstReferenceType() {
    return firstArgRefType;
}

QPSTokenType::QPSTypeInfo RelationshipClause::getSecondReferenceType() {
    return secondArgRefType;
}
void RelationshipClause::setRelationshipType(QPSTokenType::QPSTypeInfo &type) {
  this->relationshipType = type;
}
void RelationshipClause::setFirstReferenceType(
    QPSTokenType::QPSTypeInfo &type) {
  firstArgRefType = type;
}
