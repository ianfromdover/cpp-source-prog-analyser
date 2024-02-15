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
        RelationshipClause() : Clause(ClauseType::RELATIONSHIP) {}

        TokenType::TypeInfo getFirstArgType();

        TokenType::TypeInfo getSecondArgType();

        std::string getFirstArgValue();

        std::string getSecondArgValue();

        void setFirstArg(Token &t1);

        void setSecondArg(Token &t2);

        std::shared_ptr<Token> firstArg;
        std::shared_ptr<Token> secondArg;

    };
}


#endif //SPA_RELATIONSHIPCLAUSE_H
