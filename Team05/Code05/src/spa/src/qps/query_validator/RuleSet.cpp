//
// Created by tohzh on 10/2/2024.
//

#include "RuleSet.h"
#include "SingleDeclarationRule.h"
#include "NoDeclarationRule.h"
#include "SynAssignDeclarationRule.h"
#include "CompatibleTypeRule.h"

RuleSet::RuleSet() {
    rules.push_back(new class SynAssignDeclarationRule());
    rules.push_back(new class CompatibleTypeRule());

}

std::vector<Rule *> RuleSet::getRules() {
    return rules;
}

std::vector<Rule *> RuleSet::getDeclarationRules() {
    return {new class SingleDeclarationRule(), new class NoDeclarationRule()};
}