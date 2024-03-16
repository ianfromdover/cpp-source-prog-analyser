//
// Created by tohzh on 17/2/2024.
//

#include "UsesSConstraintBuilder.h"

void UsesSConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::USES_S) {
        throw std::invalid_argument( "Not UsesS argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsEntityRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<UsesSConstraint>(arg1, arg2);
}