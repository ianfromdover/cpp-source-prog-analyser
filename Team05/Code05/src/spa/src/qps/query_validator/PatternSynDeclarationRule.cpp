//
// Created by tohzh on 10/2/2024.
//

#include "PatternSynDeclarationRule.h"

std::string PatternSynDeclarationRule::validate(IntermediateQuery& query) {
    if (!query.hasPatternClause()) return "";

    std::string patternSyn = query.getPatternClause()->getPatternSynonym(); // Assumed to only have one select element

    for (const auto& clause : query.clauses){
        if (clause->getType() == Clause::ClauseType::PATTERN) {
            auto synonymTypeMap = query.getSynonymTypeMap();
            PatternClause cl = static_cast<PatternClause&>(*clause);
            if (!(validatePatternClause(cl, synonymTypeMap))) {
                return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
            }
        }
    }

    return "";
}

bool PatternSynDeclarationRule::validatePatternClause(PatternClause & cl, std::map<std::string,QType> declarationTypeMap){
    std::string patternSyn = cl.getPatternSynonym();

    auto it = declarationTypeMap.find(patternSyn);

    if (it == declarationTypeMap.end()){
        return false;
    }

    return it->second == QType::ASSIGN || it->second == QType::WHILE || it->second == QType::IF;
}
