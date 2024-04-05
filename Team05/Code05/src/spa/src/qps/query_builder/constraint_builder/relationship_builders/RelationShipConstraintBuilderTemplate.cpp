//
// Created by tohzh on 17/2/2024.
//

#include "RelationshipConstraintBuilderTemplate.h"

#include <utility>

std::shared_ptr<Constraint> RelationshipConstraintBuilderTemplate::buildRelationConstraint(shared_ptr<RelationshipClause> rsClause, shared_ptr<QueryObject> qo) {
    this->reset();
    this->setNotAttribute(rsClause);
    this->addConstraintClause(std::move(rsClause), qo);
    return this->build();
}

// this function assumes that a constraintclause has already been created.
void RelationshipConstraintBuilderTemplate::setNotAttribute(shared_ptr<RelationshipClause> rs) {
    if (rs->isNot()) {
        this->constraintClause->setNot(true);
    }
}


