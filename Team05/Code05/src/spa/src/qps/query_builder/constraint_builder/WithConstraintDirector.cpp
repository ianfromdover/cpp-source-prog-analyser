//
// Created by tohzh on 6/4/2024.
//

#include "WithConstraintDirector.h"

std::shared_ptr<Constraint> WithConstraintDirector::process(std::shared_ptr<WithClause> clause, shared_ptr<QueryObject> qo) {
    auto builder = make_shared<WithConstraintBuilder>();
    return builder->buildWithConstraint(clause, qo);
}
