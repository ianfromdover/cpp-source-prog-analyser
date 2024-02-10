//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_SYNASSIGNDECLARATIONRULE_H
#define PROJECT_SYNASSIGNDECLARATIONRULE_H

#include "Rule.h"

class SynAssignDeclarationRule : Rule{
private:
    bool followsSynAssignDeclaration(QueryObject&);
public:
    std::string validate(QueryObject&) override;
};


#endif //PROJECT_SYNASSIGNDECLARATIONRULE_H
