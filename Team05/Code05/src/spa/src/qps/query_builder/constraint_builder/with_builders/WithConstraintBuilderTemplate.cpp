//
// Created by tohzh on 5/4/2024.
//

#include "WithConstraintBuilderTemplate.h"

void WithConstraintBuilderTemplate::setNotAttribute(shared_ptr<WithClause> wClause) {
    if (wClause->isNot()) {
        this->constraintClause->setNot(true);
    }
}

std::shared_ptr<Constraint> WithConstraintBuilderTemplate::buildWithConstraint(shared_ptr<WithClause> Wclause, shared_ptr<QueryObject> qo) {
    this->reset();
    this->addConstraintClause(Wclause, std::move(qo));
    this->setNotAttribute(Wclause);
    return this->build();
}
