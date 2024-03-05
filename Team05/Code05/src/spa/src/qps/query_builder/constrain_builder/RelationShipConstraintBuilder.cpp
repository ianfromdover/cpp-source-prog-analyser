//
// Created by tohzh on 17/2/2024.
//

#include "RelationshipConstraintBuilder.h"

#include <utility>

std::shared_ptr<Constraint> RelationshipConstraintBuilder::buildRelationConstraint(shared_ptr<RelationshipClause> rsClause, shared_ptr<QueryObject> qo) {
    this->reset();
    this->addConstraintClause(std::move(rsClause), qo);
    return this->build();
}


