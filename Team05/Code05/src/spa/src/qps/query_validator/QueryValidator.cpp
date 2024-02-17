//
// Created by tohzh on 10/2/2024.
//

#include "QueryValidator.h"

std::vector<std::string> QueryValidator::validateQuery(QueryObject& qo) {
    auto* rules = new class RuleSet();
    std::vector<std::string> failedRules;
    for (Rule* r : rules->getRules()) {
        std::string failedRule = r->validate(qo);
        if (!failedRule.empty()) {
            failedRules.push_back(failedRule);
        }
    }
    return failedRules;
}

std::vector<std::string> QueryValidator::validateQuery(IntermediateQuery &) {

    return std::vector<std::string>();
}
