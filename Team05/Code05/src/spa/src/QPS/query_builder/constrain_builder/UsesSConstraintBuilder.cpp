//
// Created by tohzh on 17/2/2024.
//

#include "UsesSConstraintBuilder.h"

void UsesSConstraintBuilder::addConstraintClause(shared_ptr<qps::RelationshipClause> rs) {
    if (rs->getRelationshipType() != qps::TokenType::USES_S) {
        throw std::invalid_argument( "Not UsesS argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType());
    arg2 = buildArgAsEntityRef(rs->getSecondArg(), rs->getSecondReferenceType());
    constraintClause = make_shared<UsesSConstraint>(arg1, arg2);
}