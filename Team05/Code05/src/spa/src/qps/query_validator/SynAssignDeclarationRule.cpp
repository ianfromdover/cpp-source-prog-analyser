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

    for (const auto& clause : query.clauses){
        if (clause->getType() == Clause::ClauseType::DECLARATION) {
            std::shared_ptr<DeclarationClause> declarationCl = std::dynamic_pointer_cast<DeclarationClause>(clause);
            for (const auto& kvp : declarationCl->getAllDeclarations()){
                if (kvp.first == QPSTokenType::QPSTypeInfo::ASSIGN && kvp.second == selectSyn) {
                    return "";
                }

            }
        }
    }

    return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
}

//to be implemented in next sprint
bool SynAssignDeclarationRule::followsSynAssignDeclaration(QueryObject& qo) {
    return true;
}