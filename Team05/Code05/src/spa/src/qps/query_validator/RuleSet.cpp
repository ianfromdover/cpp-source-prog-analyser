//
// Created by tohzh on 10/2/2024.
//

#include "RuleSet.h"
#include "SingleDeclarationRule.h"
#include "NoDeclarationRule.h"
#include "SynAssignDeclarationRule.h"

RuleSet::RuleSet() {
    rules.push_back(new class SingleDeclarationRule());
    rules.push_back(new class NoDeclarationRule());
    rules.push_back(new class SynAssignDeclarationRule());
}

std::vector<Rule *> RuleSet::getRules() {
    return rules;
}