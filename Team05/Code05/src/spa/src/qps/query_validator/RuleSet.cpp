//
// Created by tohzh on 10/2/2024.
//

#include "RuleSet.h"
#include "SingleDeclarationRule.h"
#include "NoDeclarationRule.h"

RuleSet::RuleSet() {
    rules.push_back(new class SingleDeclarationRule());
    rules.push_back(new class NoDeclarationRule());
}

std::vector<Rule *> RuleSet::getRules() {
    return rules;
}