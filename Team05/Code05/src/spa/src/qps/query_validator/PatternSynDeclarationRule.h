//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_SYNASSIGNDECLARATIONRULE_H
#define PROJECT_SYNASSIGNDECLARATIONRULE_H

#include "Rule.h"

typedef QPSTokenType::QPSTypeInfo QType;

class PatternSynDeclarationRule : public Rule{
public:
    std::string validate(IntermediateQuery&) override;

    bool validatePatternClause(PatternClause &cl, map<std::string, QType> declarationTypeMap);
};


#endif //PROJECT_SYNASSIGNDECLARATIONRULE_H
