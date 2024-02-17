//
// Created by tohzh on 10/2/2024.
//

#include "SynAssignDeclarationRule.h"

std::string SynAssignDeclarationRule::validate(QueryObject& qo) {
    bool followsRule = followsSynAssignDeclaration(qo);
    if (followsRule) {
        return "";
    } else {
        return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
    }
}

std::string SynAssignDeclarationRule::validate(IntermediateQuery& query) {
    std::string selectSyn = query.getSelectClause().getAllSelect()[0]; // Assumed to only have one select element
    auto it = query.getSynonymTypeMap().find(selectSyn);
    if (it == query.getSynonymTypeMap().end()) {
        return VALIDATION_RULE_NO_DECLARATION;
    } else {
        if (it->second != TokenType::TypeInfo::ASSIGN) {
            return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
        }
    }
    return "";
}

//to be implemented in next sprint
bool SynAssignDeclarationRule::followsSynAssignDeclaration(QueryObject& qo) {
    return true;
}