//
// Created by tohzh on 17/2/2024.
//

#include "ConcretePatternConstraintBuilder.h"

#include <utility>

void ConcretePatternConstraintBuilder::addPatternClause(std::shared_ptr<PatternClause> pattern, shared_ptr<QueryObject> qo) {
    std::string synName = pattern->getPatternSynonym();
    syn = ConstraintArgCreator::createAssignEntity(synName);
    arg1 = buildArgAsEntityRef(pattern->getFirstArg(), pattern->getFirstArgType(), qo);
    arg2 = buildArgAsExpressionRef(pattern->getSecondArg(), pattern->getSecondArgType(), qo);
    shared_ptr<ConcretePatternConstraint> patternConstraint =  make_shared<ConcretePatternConstraint>(arg1, arg2, syn);
    constraintClause = patternConstraint;
}



shared_ptr<ConcretePatternConstraint> ConcretePatternConstraintBuilder::buildPatternConstraint(std::shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    addPatternClause(std::move(patternClause), std::move(qo));
    return dynamic_pointer_cast<ConcretePatternConstraint>(constraintClause);
}
