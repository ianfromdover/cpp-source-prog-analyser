//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "RelationshipClause.h"

namespace qps {
    QPSToken& RelationshipClause::getSecondArg() {
        if (secondArg != nullptr) {
            return *secondArg;
        }
        throw std::runtime_error("Second argument is not set");
    }
    QPSToken& RelationshipClause::getFirstArg() {
        if (firstArg != nullptr) {
            return *firstArg;
        }
        throw std::runtime_error("First argument is not set");
    }

    QPSTokenType::TypeInfo RelationshipClause::getSecondArgType() {
        if (secondArg != nullptr) {
            return secondArg->getType().getInfo();
        }
        throw std::runtime_error("Second argument is not set");
    }

    QPSTokenType::TypeInfo RelationshipClause::getFirstArgType() {
        if (firstArg != nullptr) {
            return firstArg->getType().getInfo();
        }
        throw std::runtime_error("First argument is not set");
    }

    QPSTokenType::TypeInfo RelationshipClause::getRelationshipType() {
        return relationshipType;
    }

    QPSTokenType::TypeInfo RelationshipClause::getFirstReferenceType() {
        return firstArgRefType;
    }

    QPSTokenType::TypeInfo RelationshipClause::getSecondReferenceType() {
        return secondArgRefType;
    }
}
