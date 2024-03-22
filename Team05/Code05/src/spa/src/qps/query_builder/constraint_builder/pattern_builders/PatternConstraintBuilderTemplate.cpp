//
// Created by tohzh on 16/3/2024.
//

#include "PatternConstraintBuilderTemplate.h"

#include <utility>

std::shared_ptr<Constraint>
PatternConstraintBuilderTemplate::buildRelationConstraint(shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    this->reset();
    this->addConstraintClause(std::move(patternClause), std::move(qo));
    return this->build();
}
