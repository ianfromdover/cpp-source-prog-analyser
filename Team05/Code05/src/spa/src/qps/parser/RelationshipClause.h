//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_RELATIONSHIPCLAUSE_H
#define SPA_RELATIONSHIPCLAUSE_H

#include <memory>
#include "Clause.h"
#include "qps/tokenizer/QPSToken.h"

namespace qps {
    class RelationshipClause : public Clause {
    public:
        RelationshipClause(QPSTokenType::TypeInfo type, QPSToken &t1, QPSTokenType::TypeInfo type1, QPSToken &t2, QPSTokenType::TypeInfo type2) : Clause(ClauseType::RELATIONSHIP) {
            relationshipType = type;

            firstArg = std::make_shared<QPSToken>(t1);
            firstArgRefType = type1;
            secondArg = std::make_shared<QPSToken>(t2);
            secondArgRefType = type2;
        }

        QPSTokenType::TypeInfo getRelationshipType();

        QPSTokenType::TypeInfo getFirstArgType();
        QPSTokenType::TypeInfo getFirstReferenceType();
        QPSToken& getFirstArg();

        QPSTokenType::TypeInfo getSecondArgType();
        QPSTokenType::TypeInfo getSecondReferenceType();
        QPSToken& getSecondArg();

    private:
        QPSTokenType::TypeInfo relationshipType;

        std::shared_ptr<QPSToken> firstArg;
        QPSTokenType::TypeInfo firstArgRefType;

        std::shared_ptr<QPSToken> secondArg;
        QPSTokenType::TypeInfo secondArgRefType;
    };
}


#endif //SPA_RELATIONSHIPCLAUSE_H
