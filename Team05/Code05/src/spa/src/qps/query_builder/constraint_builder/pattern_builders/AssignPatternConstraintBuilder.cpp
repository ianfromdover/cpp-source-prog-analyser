//
// Created by tohzh on 17/2/2024.
//

#include "AssignPatternConstraintBuilder.h"

#include <utility>

void AssignPatternConstraintBuilder::addPatternClause(std::shared_ptr<PatternClause> pattern, shared_ptr<QueryObject> qo) {
    std::string synName = pattern->getPatternSynonym();
    syn = ConstraintArgCreator::createAssignEntity(synName);
    arg1 = buildArgAsEntityRef(pattern->getArgAtIndex(0), pattern->getReferenceTypeAtIndex(0), qo);
    arg2 = buildArgAsExpressionRef(pattern->getArgAtIndex(1), pattern->getReferenceTypeAtIndex(1), qo);
    shared_ptr<AssignPatternConstraint> patternConstraint =  make_shared<AssignPatternConstraint>(arg1, arg2, syn);
    constraintClause = patternConstraint;
}

void AssignPatternConstraintBuilder::addConstraintClause(shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    addPatternClause(std::move(patternClause), std::move(qo));
}
