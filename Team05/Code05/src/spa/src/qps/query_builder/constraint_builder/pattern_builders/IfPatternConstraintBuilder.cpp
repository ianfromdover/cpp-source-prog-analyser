//
// Created by tohzh on 21/3/2024.
//

#include "IfPatternConstraintBuilder.h"

void IfPatternConstraintBuilder::addPatternClause(std::shared_ptr<PatternClause> pattern, shared_ptr<QueryObject> qo) {
//    std::string synName = pattern->getPatternSynonym();
//    syn = ConstraintArgCreator::createIfEntity(synName);
    auto entity = qo->getEntityInDeclaration(pattern->getPatternSynonym());
    if (entity->getEntityType() != TYPE_IF) {
        throw QPSException("Not of type if for if pattern");
    }
    syn = dynamic_pointer_cast<IfEntity>(entity);
    arg1 = buildArgAsEntityRef(pattern->getArgAtIndex(0), pattern->getReferenceTypeAtIndex(0), qo);
    shared_ptr<IfPatternConstraint> patternConstraint =  make_shared<IfPatternConstraint>(arg1, syn);
    constraintClause = patternConstraint;
}

void IfPatternConstraintBuilder::addConstraintClause(shared_ptr<PatternClause> patternClause, shared_ptr<QueryObject> qo) {
    addPatternClause(std::move(patternClause), std::move(qo));
}
