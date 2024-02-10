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
        return QueryEnums::ENUM_VALIDATION_RULE[enumValidationRule::SingleDeclarationRule];
    }
}

bool SingleDeclarationRule::followsSingleDeclaration(QueryObject& qo) {
    std::vector<Declaration*> declarations = qo.getDeclarations();
    std::map<std::string, int> declarationMap;
    bool ruleFollowed = true;
    for (Declaration* declaration : declarations) {
        std::string declarationName = declaration->getDeclarationEntity()->getIdentifier();
        if (declarationMap.count(declarationName)) {
            ruleFollowed = false;
            break;
        } else {
            declarationMap[declarationName] = 1;
        }
    }
    return ruleFollowed;
}