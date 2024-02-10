//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_NODECLARATIONRULE_H
#define PROJECT_NODECLARATIONRULE_H

#include "Rule.h"

class NoDeclarationRule : public Rule{
private:
    bool followsNoDeclaration(QueryObject&);
public:
    std::string validate(QueryObject&) override;
};


#endif //PROJECT_NODECLARATIONRULE_H
