//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_PATTERNCLAUSE_H
#define SPA_PATTERNCLAUSE_H

#include <memory>
#include <utility>
#include "Clause.h"
#include "qps/tokenizer/QPSToken.h"

namespace qps {
    class PatternClause : public Clause {
    public:
        PatternClause(std::string syn, QPSToken& t1, QPSTokenType::QPSTypeInfo type1, QPSToken& t2, QPSTokenType::QPSTypeInfo type2) : Clause(ClauseType::PATTERN) {
            synonym = std::move(syn);
            firstArg = std::make_shared<QPSToken>(t1);
            firstArgType = type1;
            secondArg = std::make_shared<QPSToken>(t2);
            secondArgType = type2;
        }
        std::string getPatternSynonym();

        QPSTokenType::QPSTypeInfo getFirstArgType();
        QPSTokenType::QPSTypeInfo getFirstReferenceType();
        std::string getFirstArgValue();

        QPSTokenType::QPSTypeInfo getSecondArgType();
        QPSTokenType::QPSTypeInfo getSecondReferenceType();
        std::string getSecondArgValue();

        QPSToken& getFirstArg();
        QPSToken& getSecondArg();

    private:
        std::string synonym;

        std::shared_ptr<QPSToken> firstArg;
        QPSTokenType::QPSTypeInfo firstArgType;

        std::shared_ptr<QPSToken> secondArg;
        QPSTokenType::QPSTypeInfo secondArgType;
    };
}


#endif //SPA_PATTERNCLAUSE_H
