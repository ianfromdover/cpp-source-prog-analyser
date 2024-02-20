//
// Created by tohzh on 17/2/2024.
//

#include "ModifiesSConstraintBuilder.h"

void ModifiesSConstraintBuilder::addConstraintClause(shared_ptr<RelationshipClause> rs) {
    if (rs->getRelationshipType() != QPSTokenType::MODIFIES_S) {
        throw std::invalid_argument( "Not Modifies S argument" );
    }

    arg1 = buildArgAsStatementRef(rs->getFirstArg(), rs->getFirstReferenceType());
    arg2 = buildArgAsEntityRef(rs->getSecondArg(), rs->getSecondReferenceType());
    constraintClause = make_shared<ModifiesSConstraint>(arg1, arg2);
}