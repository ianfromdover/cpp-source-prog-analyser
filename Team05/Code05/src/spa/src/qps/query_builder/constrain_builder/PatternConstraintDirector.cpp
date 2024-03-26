//
// Created by tohzh on 16/3/2024.
//

#include "PatternConstraintDirector.h"

#include <utility>

std::shared_ptr<Constraint> PatternConstraintDirector::process(shared_ptr<PatternClause> r,
                                                                    shared_ptr<QueryObject> qo) {
    // only assign for now
    // TODO: wait for alex's preprocessing to determine how patternclause is structured.
    AssignPatternConstraintBuilder b;
    b.addConstraintClause(std::move(r), std::move(qo));
    return b.build();
}