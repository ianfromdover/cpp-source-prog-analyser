//
// Created by tohzh on 10/2/2024.
//

#include "QueryValidator.h"

std::vector<std::string> QueryValidator::validateQuery(IntermediateQuery & intermediateQuery) {

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
                return validationResults;
            }
        }
    }
    return validationResults;
}
