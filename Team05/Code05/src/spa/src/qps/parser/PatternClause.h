//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_PATTERNCLAUSE_H
#define SPA_PATTERNCLAUSE_H

#include <memory>
#include "Clause.h"
#include "qps/tokenizer/Token.h"

namespace qps {
    class PatternClause : public Clause {
    public:
        PatternClause() : Clause(ClauseType::PATTERN) {}

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


#endif //SPA_PATTERNCLAUSE_H
