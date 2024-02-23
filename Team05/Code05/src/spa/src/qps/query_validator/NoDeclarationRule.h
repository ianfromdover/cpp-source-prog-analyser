//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_NODECLARATIONRULE_H
#define PROJECT_NODECLARATIONRULE_H

#include "Rule.h"

// All the synonyms used in clauses must be declared exactly once.
class NoDeclarationRule : public Rule {
public:
    std::string validate(IntermediateQuery&) override;
};


#endif //PROJECT_NODECLARATIONRULE_H
