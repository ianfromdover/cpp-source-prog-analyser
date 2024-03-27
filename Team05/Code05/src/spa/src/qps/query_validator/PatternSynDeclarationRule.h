//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_SYNASSIGNDECLARATIONRULE_H
#define PROJECT_SYNASSIGNDECLARATIONRULE_H

#include "Rule.h"

class PatternSynDeclarationRule : public Rule{
public:
    std::string validate(IntermediateQuery&) override;
};


#endif //PROJECT_SYNASSIGNDECLARATIONRULE_H
