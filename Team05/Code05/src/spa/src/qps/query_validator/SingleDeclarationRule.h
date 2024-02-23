//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_SINGLEDECLARATIONRULE_H
#define PROJECT_SINGLEDECLARATIONRULE_H

#include "Rule.h"

//A synonym name can only be declared once.
class SingleDeclarationRule : public Rule {
public:
    std::string validate(IntermediateQuery&) override;
};


#endif //PROJECT_SINGLEDECLARATIONRULE_H
