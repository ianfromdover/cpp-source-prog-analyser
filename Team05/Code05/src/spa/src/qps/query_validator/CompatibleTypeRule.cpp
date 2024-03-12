//
// Created by Alex on 20/2/2024.
//

#include <algorithm>

#include "CompatibleTypeRule.h"

std::string CompatibleTypeRule::validate(IntermediateQuery & query) {
    std::string results;
    std::map<std::string, QPSTokenType::QPSTypeInfo> declarationMap = query.getSynonymTypeMap();
    if (query.hasRelationshipClause()){
        results += validateRelationship(*query.getRelationshipClause(),declarationMap);
    }
    if (query.hasPatternClause()){
        results += validatePattern(*query.getPatternClause(),declarationMap);
    }
    return results;
}

std::string CompatibleTypeRule::validateRelationship(RelationshipClause cl, std::map<std::string, QPSTokenType::QPSTypeInfo> declarationMap){
    QPSTokenType::QPSTypeInfo relationshipType = cl.getRelationshipType();
    QPSTokenType::QPSTypeInfo arg1Type = cl.getFirstArgType()==QPSTokenType::QPSTypeInfo::SYNONYM ? declarationMap.find(cl.getFirstArg().getLexeme())->second : cl.getFirstArgType();
    QPSTokenType::QPSTypeInfo arg2Type = cl.getSecondArgType()==QPSTokenType::QPSTypeInfo::SYNONYM ? declarationMap.find(cl.getSecondArg().getLexeme())->second : cl.getSecondArgType();

    if (typeMap.find(relationshipType) == typeMap.end()){
        throw std::runtime_error("invalid relationship type");
    }

    if (relationshipType == QPSTokenType::QPSTypeInfo::MODIFIES_S || relationshipType == QPSTokenType::QPSTypeInfo::USES_S){
        if (arg1Type == QPSTokenType::QPSTypeInfo::WILDCARD) return VALIDATION_RULE_WILDCARD_ARGUMENT;
    }

    auto it = typeMap.find(relationshipType);

    std::pair<std::vector<QPSTokenType::QPSTypeInfo>, std::vector<QPSTokenType::QPSTypeInfo>> typePair = it->second;

    auto first = std::find(typePair.first.begin(),typePair.first.end(), arg1Type);
    if (first == typePair.first.end()) return VALIDATION_RULE_RELATIONSHIP_ARGUMENT;
    auto second = std::find(typePair.second.begin(),typePair.second.end(), arg2Type);
    if (second == typePair.second.end()) return VALIDATION_RULE_RELATIONSHIP_ARGUMENT;

    return "";
}

std::string CompatibleTypeRule::validatePattern(PatternClause cl, std::map<std::string, QPSTokenType::QPSTypeInfo> declarationMap) {
    QPSTokenType::QPSTypeInfo arg1Type = cl.getFirstArgType()==QPSTokenType::QPSTypeInfo::SYNONYM ? declarationMap.find(cl.getFirstArg().getLexeme())->second : cl.getFirstArgType();

    if (arg1Type == QPSTokenType::QPSTypeInfo::VARIABLE ||
    arg1Type == QPSTokenType::QPSTypeInfo::QUOTED_IDENT ||
    arg1Type == QPSTokenType::QPSTypeInfo::WILDCARD) {
        return "";
    }

    return VALIDATION_RULE_PATTERN_ARGUMENT;

}
