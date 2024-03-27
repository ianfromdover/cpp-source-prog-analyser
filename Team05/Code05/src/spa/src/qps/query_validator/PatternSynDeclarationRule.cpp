//
// Created by tohzh on 10/2/2024.
//

#include "PatternSynDeclarationRule.h"

std::string PatternSynDeclarationRule::validate(IntermediateQuery& query) {
    if (!query.hasPatternClause()) return "";

    std::string patternSyn = query.getPatternClause()->getPatternSynonym(); // Assumed to only have one select element

    for (const auto& clause : query.clauses){
        if (clause->getType() == Clause::ClauseType::DECLARATION) {
            std::shared_ptr<DeclarationClause> declarationCl = std::dynamic_pointer_cast<DeclarationClause>(clause);
            for (const auto& kvp : declarationCl->getAllDeclarations()){
                if (kvp.first == QPSTokenType::QPSTypeInfo::ASSIGN && kvp.second == patternSyn) {
                    return "";
                }
                if (kvp.first == QPSTokenType::QPSTypeInfo::WHILE && kvp.second == patternSyn) {
                  return "";
                }
            }
        }
    }

    return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
}
