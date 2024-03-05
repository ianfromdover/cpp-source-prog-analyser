//
// Created by tohzh on 10/2/2024.
//

#ifndef PROJECT_RULESET_H
#define PROJECT_RULESET_H

#include "Rule.h"
#include <memory>

class RuleSet {
private:
    std::vector<Rule*> rules;
public:
    RuleSet();
    std::vector<Rule*> getRules();
    std::vector<Rule*> getDeclarationRules();
};


#endif //PROJECT_RULESET_H
