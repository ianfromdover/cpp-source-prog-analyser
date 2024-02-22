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

void QueryValidator::validateQuery(IntermediateQuery & intermediateQuery) {

    auto* ruleSet = new class RuleSet();
    std::vector<std::string> validationResults;

    for (auto& rule : ruleSet->getDeclarationRules()){
        std::string result = rule->validate(intermediateQuery);
        if (!result.empty()){
            validationResults.push_back(result);
        }
    }

    if (validationResults.empty()){
        intermediateQuery.processDeclarations();

        for (auto& rule : ruleSet->getRules()){
            std::string result = rule->validate(intermediateQuery);
            if (!result.empty()){
                validationResults.push_back(result);
            }
        }
    }

    if (!validationResults.empty()){
        std::string msg = "semantic error: ";
        for (auto& result : validationResults){
            msg += result + " ";
        }
        throw std::exception(msg.c_str());
    }
}
