//
// Created by Alex on 28/3/2024.
//

#include "PatternArgumentRule.h"

std::string PatternArgumentRule::validate(IntermediateQuery & query) {
    for (auto& cl : query.getAllPatternClauses()){
        auto synTypeMap = query.getSynonymTypeMap();
        if (!validateArgCount(*cl, synTypeMap.at(cl->getPatternSynonym()))){
            return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
        }
        if (!validateArgType(*cl, synTypeMap.at(cl->getPatternSynonym()))){
            return VALIDATION_RULE_SYN_ASSIGN_DECLARATION;
        }
    }
}

bool PatternArgumentRule::validateArgCount(PatternClause & patternClause, QType type) {
    return argCountMap.find(type)->second == patternClause.getArgCount();
}

bool PatternArgumentRule::validateArgType(PatternClause & patternClause, QType type) {
    if (type == QType::ASSIGN){
        QType firstArgType = patternClause.getArgTypeAtIndex(0);
        QType secondArgType = patternClause.getArgTypeAtIndex(1);
        return
          (firstArgType == QType::VARIABLE || firstArgType == QType::WILDCARD || QType::QUOTED_IDENT) &&
          (secondArgType == QType::WILDCARD || secondArgType == QType::EXPR || secondArgType == QType::EXPR_WILDCARD);
    } else if (type == QType::WHILE){
        QType firstArgType = patternClause.getArgTypeAtIndex(0);
        QType secondArgType = patternClause.getArgTypeAtIndex(1);
        return
        (firstArgType == QType::VARIABLE || firstArgType == QType::WILDCARD || QType::QUOTED_IDENT) &&
        (secondArgType == QType::WILDCARD);
    } else if (type == QType::IF){
        QType firstArgType = patternClause.getArgTypeAtIndex(0);
        QType secondArgType = patternClause.getArgTypeAtIndex(1);
        QType thirdArgType = patternClause.getArgTypeAtIndex(2);

        return
        (firstArgType == QType::VARIABLE || firstArgType == QType::WILDCARD || QType::QUOTED_IDENT) &&
        (secondArgType == QType::WILDCARD) &&
        (thirdArgType == QType::WILDCARD);
    } else {
        return false;
    }
}
