//
// Created by tohzh on 10/2/2024.
//

#include "SingleDeclarationRule.h"
#include <map>

std::string SingleDeclarationRule::validate(QueryObject& qo) {
    bool followsRule = followsSingleDeclaration(qo);
    if (followsRule) {
        return "";
    } else {
        return VALIDATION_RULE_SINGLE_DECLARATION;
    }
}

bool SingleDeclarationRule::followsSingleDeclaration(QueryObject& qo) {
    std::vector<std::shared_ptr<Entity>> declarations = qo.getDeclarations();
    std::map<std::string, int> declarationMap;
    bool ruleFollowed = true;
    for (const std::shared_ptr<Entity>& declaration : declarations) {
        std::string declarationName = declaration->getIdentifier();
        if (declarationMap.count(declarationName)) {
            ruleFollowed = false;
            break;
        } else {
            declarationMap[declarationName] = 1;
        }
    }
    return ruleFollowed;
}

std::string SingleDeclarationRule::validate(IntermediateQuery & query) {
    std::unordered_set<std::string> declarations;
    for (const auto& clause : query.clauses){
        if (clause->getType() == Clause::ClauseType::DECLARATION) {
            std::shared_ptr<DeclarationClause> declarationCl = std::dynamic_pointer_cast<DeclarationClause>(clause);
            for (const auto& kvp : declarationCl->getAllDeclarations()){
                if (declarations.find(kvp.second) == declarations.end()){
                    declarations.insert(kvp.second);
                } else {
                    return VALIDATION_RULE_SINGLE_DECLARATION;
                }
            }
        }
    }

    return "";
}
