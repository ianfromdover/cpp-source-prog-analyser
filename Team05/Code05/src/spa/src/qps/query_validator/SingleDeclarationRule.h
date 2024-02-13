//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_SINGLEDECLARATIONRULE_H
#define PROJECT_SINGLEDECLARATIONRULE_H

#include "Rule.h"

//A synonym name can only be declared once.
class SingleDeclarationRule : public Rule {
private:
    bool followsSingleDeclaration(QueryObject&);
public:
    std::string validate(QueryObject&) override;
};


#endif //PROJECT_SINGLEDECLARATIONRULE_H
