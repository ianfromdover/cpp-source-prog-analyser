//
// Created by tohzh on 21/3/2024.
//

#include "WhilePatternConstraintBuilder.h"

void WhilePatternConstraintBuilder::addPatternClause(std::shared_ptr<PatternClause> pattern, shared_ptr<QueryObject> qo) {
    std::string synName = pattern->getPatternSynonym();
    syn = ConstraintArgCreator::createWhileEntity(synName);
    arg1 = buildArgAsEntityRef(pattern->getArgAtIndex(0), pattern->getReferenceTypeAtIndex(0), qo);
//    arg2 = buildArgAsExpressionRef(pattern->getSecondArg(), pattern->getSecondReferenceType(), qo);
    shared_ptr<WhilePatternConstraint> patternConstraint =  make_shared<WhilePatternConstraint>(arg1, syn);
    constraintClause = patternConstraint;
}

void WhilePatternConstraintBuilder::addConstraintClause(shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    addPatternClause(std::move(patternClause), std::move(qo));
}

