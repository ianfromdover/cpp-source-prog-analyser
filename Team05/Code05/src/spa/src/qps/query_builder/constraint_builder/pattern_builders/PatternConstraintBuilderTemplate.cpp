//
// Created by tohzh on 16/3/2024.
//

#include "PatternConstraintBuilderTemplate.h"

#include <utility>

std::shared_ptr<Constraint>
PatternConstraintBuilderTemplate::buildPatternConstraint(shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    this->reset();
    this->addConstraintClause(patternClause, std::move(qo));
    this->setNotAttribute(patternClause);
    return this->build();
}

//assumes that constraint clause is created
void PatternConstraintBuilderTemplate::setNotAttribute(shared_ptr<PatternClause> cl) {
    if (cl->isNot()) {
        this->constraintClause->setNot(true);
    }
}
