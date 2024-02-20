//
// Created by tohzh on 17/2/2024.
//

#include "RelationshipConstraintDirector.h"


std::shared_ptr<Constraint> RelationshipConstraintDirector::process(shared_ptr<qps::RelationshipClause> r) {
    qps::TokenType::TypeInfo type = r->getRelationshipType();
    switch (type) {
        case (qps::TokenType::FOLLOWS): {
            FollowsConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (qps::TokenType::FOLLOWS_T): {
            FollowsTConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (qps::TokenType::PARENT): {
            ParentConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (qps::TokenType::PARENT_T): {
            ParentTConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (qps::TokenType::USES_S): {
            UsesSConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (qps::TokenType::USES_T): {
            UsesPConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (qps::TokenType::MODIFIES_T): {
            ModifiesPConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        case (qps::TokenType::MODIFIES_S): {
            ModifiesSConstraintBuilder b;
            b.addConstraintClause(r);
            return b.build();
        }
        default: {
            throw std::invalid_argument("Invalid relationship constraint token");
        }
    }
}
