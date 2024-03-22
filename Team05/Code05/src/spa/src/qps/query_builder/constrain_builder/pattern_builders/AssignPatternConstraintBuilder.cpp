//
// Created by tohzh on 17/2/2024.
//

#include "AssignPatternConstraintBuilder.h"

#include <utility>

void AssignPatternConstraintBuilder::addPatternClause(std::shared_ptr<PatternClause> pattern, shared_ptr<QueryObject> qo) {
    std::string synName = pattern->getPatternSynonym();
    syn = ConstraintArgCreator::createAssignEntity(synName);
    arg1 = buildArgAsEntityRef(pattern->getFirstArg(), pattern->getFirstReferenceType(), qo);
    arg2 = buildArgAsExpressionRef(pattern->getSecondArg(), pattern->getSecondReferenceType(), qo);
    shared_ptr<AssignPatternConstraint> patternConstraint =  make_shared<AssignPatternConstraint>(arg1, arg2, syn);
    constraintClause = patternConstraint;
}

void AssignPatternConstraintBuilder::addConstraintClause(shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    addPatternClause(std::move(patternClause), std::move(qo));
}
