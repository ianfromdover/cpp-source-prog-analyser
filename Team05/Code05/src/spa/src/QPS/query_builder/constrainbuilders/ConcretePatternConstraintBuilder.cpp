//
// Created by tohzh on 17/2/2024.
//

#include "ConcretePatternConstraintBuilder.h"

void ConcretePatternConstraintBuilder::addConstraintClause(shared_ptr<qps::RelationshipClause> rs) {
    if (rs->getRelationshipType() != qps::TokenType::PATTERN) {
        throw std::invalid_argument( "Not Pattern argument" );
    }

    arg1 = buildArgAsEntityRef(rs->getFirstArg(), rs->getFirstReferenceType());
    arg2 = buildArgAsExpressionRef(rs->getSecondArg(), rs->getSecondReferenceType());
//    constraintClause = make_shared<ConcretePatternConstraint>(arg1, arg2); // TODO: implement concrete constructtor
}