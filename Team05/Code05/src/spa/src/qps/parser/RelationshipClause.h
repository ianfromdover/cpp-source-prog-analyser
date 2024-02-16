//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_RELATIONSHIPCLAUSE_H
#define SPA_RELATIONSHIPCLAUSE_H

#include <memory>
#include "Clause.h"
#include "qps/tokenizer/Token.h"

namespace qps {
    class RelationshipClause : public Clause {
    public:
        RelationshipClause(TokenType::TypeInfo type, Token &t1, TokenType::TypeInfo type1, Token &t2, TokenType::TypeInfo type2) : Clause(ClauseType::RELATIONSHIP) {
            relationshipType = type;

            firstArg = std::make_shared<Token>(t1);
            firstArgRefType = type1;
            secondArg = std::make_shared<Token>(t2);
            secondArgRefType = type2;
        }

        TokenType::TypeInfo getRelationshipType();

        TokenType::TypeInfo getFirstArgType();
        TokenType::TypeInfo getFirstReferenceType();
        Token& getFirstArg();

        TokenType::TypeInfo getSecondArgType();
        TokenType::TypeInfo getSecondReferenceType();
        Token& getSecondArg();

    private:
        TokenType::TypeInfo relationshipType;

        std::shared_ptr<Token> firstArg;
        TokenType::TypeInfo firstArgRefType;

        std::shared_ptr<Token> secondArg;
        TokenType::TypeInfo secondArgRefType;
    };
}


#endif //SPA_RELATIONSHIPCLAUSE_H
