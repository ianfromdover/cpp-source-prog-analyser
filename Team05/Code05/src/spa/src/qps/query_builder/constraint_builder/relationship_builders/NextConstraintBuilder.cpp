//
// Created by sjh_9 on 22/3/2024.
//

#include "NextConstraintBuilder.h"

void NextConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs, shared_ptr<QueryObject> qo) {
    if (rs->getRelationshipType() != QPSTokenType::NEXT) {
        throw std::invalid_argument( "Not Next argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType(), qo);
    arg2 = buildArgAsStatementRef(rs->getSecondArg(), rs->getSecondReferenceType(), qo);
    constraintClause = make_shared<NextConstraint>(arg1, arg2);
}
