//
// Created by tohzh on 17/2/2024.
//

#include "ConcretePatternConstraintBuilder.h"

#include <utility>

void ConcretePatternConstraintBuilder::addPatternClause(std::shared_ptr<qps::PatternClause> pattern) {
    std::string synName = pattern->getPatternSynonym();
    syn = ConstraintArgCreator::createAssignEntity(synName);
    arg1 = buildArgAsEntityRef(pattern->getFirstArg(), pattern->getFirstArgType());
    arg2 = buildArgAsExpressionRef(pattern->getSecondArg(), pattern->getSecondArgType());
    shared_ptr<ConcretePatternConstraint> patternConstraint =  make_shared<ConcretePatternConstraint>(arg1, arg2, syn);
    constraintClause = patternConstraint;
}



shared_ptr<ConcretePatternConstraint> ConcretePatternConstraintBuilder::buildPatternConstraint(std::shared_ptr<qps::PatternClause> patternClause) {
    addPatternClause(std::move(patternClause));
    return dynamic_pointer_cast<ConcretePatternConstraint>(constraintClause);
}
