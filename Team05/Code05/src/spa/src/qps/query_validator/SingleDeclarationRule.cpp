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

std::string SingleDeclarationRule::validate(IntermediateQuery &) {
    return std::string();
}
