//
// Created by tohzh on 10/2/2024.
//

#include "RuleSet.h"
#include "CompatibleTypeRule.h"
#include "NoDeclarationRule.h"
#include "PatternSynDeclarationRule.h"
#include "SingleDeclarationRule.h"
#include "PatternArgumentRule.h"

RuleSet::RuleSet() {
    rules.push_back(new class PatternSynDeclarationRule());
    rules.push_back(new class CompatibleTypeRule());
    rules.push_back(new class PatternArgumentRule());

}

std::vector<Rule *> RuleSet::getRules() {
    return rules;
}

std::vector<Rule *> RuleSet::getDeclarationRules() {
    return {new class SingleDeclarationRule(), new class NoDeclarationRule()};
}