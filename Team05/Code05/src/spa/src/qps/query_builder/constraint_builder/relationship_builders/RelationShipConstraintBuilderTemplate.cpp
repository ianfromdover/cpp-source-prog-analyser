//
// Created by tohzh on 17/2/2024.
//

#include "RelationshipConstraintBuilderTemplate.h"

#include <utility>

std::shared_ptr<Constraint> RelationshipConstraintBuilderTemplate::buildRelationConstraint(shared_ptr<RelationshipClause> rsClause, shared_ptr<QueryObject> qo) {
    this->reset();
    this->addConstraintClause(std::move(rsClause), qo);
    this->setNotAttribute(rsClause);
    return this->build();
}

// this function assumes that a constraintclause has already been created.
void RelationshipConstraintBuilderTemplate::setNotAttribute(shared_ptr<RelationshipClause> rs) {
    // NOT TODO: find rs not attribute
    if (false) {
        this->constraintClause->setNot(true);
    }
}


