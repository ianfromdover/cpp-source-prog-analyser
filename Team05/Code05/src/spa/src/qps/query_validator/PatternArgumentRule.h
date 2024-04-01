//
// Created by Alex on 28/3/2024.
//

#ifndef SPA_PATTERNARGUMENTRULE_H
#define SPA_PATTERNARGUMENTRULE_H


#include "Rule.h"

typedef QPSTokenType::QPSTypeInfo QType;

class PatternArgumentRule : public Rule {
    std::string validate(IntermediateQuery&) override;

    static inline std::map<QType ,int> argCountMap = {
            {QType::ASSIGN, 2},
            {QType::WHILE, 2},
            {QType::IF, 3}
    };


    bool validateArgCount(PatternClause &patternClause, QType type);

    bool validateArgType(PatternClause &patternClause, QType type, map<std::string, QType> synonymTypeMap);
};


#endif //SPA_PATTERNARGUMENTRULE_H
