//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_PATTERNCLAUSE_H
#define SPA_PATTERNCLAUSE_H

#include <memory>
#include <utility>
#include "Clause.h"
#include "qps/tokenizer/Token.h"

namespace qps {
    class PatternClause : public Clause {
    public:
        PatternClause(std::string syn, Token& t1, TokenType::TypeInfo type1, Token& t2, TokenType::TypeInfo type2) : Clause(ClauseType::PATTERN) {
            synonym = std::move(syn);
            firstArg = std::make_shared<Token>(t1);
            firstArgType = type1;
            secondArg = std::make_shared<Token>(t2);
            secondArgType = type2;
        }
        std::string getPatternSynonym();

        TokenType::TypeInfo getFirstArgType();
        std::string getFirstArgValue();

        TokenType::TypeInfo getSecondArgType();
        std::string getSecondArgValue();

    private:
        std::string synonym;

        std::shared_ptr<Token> firstArg;
        TokenType::TypeInfo firstArgType;

        std::shared_ptr<Token> secondArg;
        TokenType::TypeInfo secondArgType;
    };
}


#endif //SPA_PATTERNCLAUSE_H
