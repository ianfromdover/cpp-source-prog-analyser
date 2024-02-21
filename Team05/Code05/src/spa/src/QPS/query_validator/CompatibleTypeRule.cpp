//
// Created by Alex on 20/2/2024.
//

#include "CompatibleTypeRule.h"

std::string CompatibleTypeRule::validate(QueryObject &) {
    return std::string();
}

std::string CompatibleTypeRule::validate(IntermediateQuery & query) {
    if (!query.hasRelationshipClause()) return "";

    RelationshipClause cl = *query.getRelationshipClause();

    QPSTokenType::QPSTypeInfo relationshipType = cl.getRelationshipType();
    QPSTokenType::QPSTypeInfo arg1Type = cl.getFirstArgType()==QPSTokenType::QPSTypeInfo::SYNONYM ? query.getSynonymTypeMap().find(cl.getFirstArg().getLexeme())->second : cl.getFirstArgType();
    QPSTokenType::QPSTypeInfo arg2Type = cl.getSecondArgType()==QPSTokenType::QPSTypeInfo::SYNONYM ? query.getSynonymTypeMap().find(cl.getSecondArg().getLexeme())->second : cl.getSecondArgType();

    if (typeMap.find(relationshipType) == typeMap.end()){
        throw std::exception("invalid relationship type");
    }

    auto it = typeMap.find(relationshipType);
    std::pair<std::vector<QPSTokenType::QPSTypeInfo>, std::vector<QPSTokenType::QPSTypeInfo>> typePair = it->second;

    auto first = std::find(typePair.first.begin(),typePair.first.end(), arg1Type);
    if (first == typePair.first.end()) return VALIDATION_RULE_INCOMPATIBLE_RELATIONSHIP_ARGUMENT_TYPE;
    auto second = std::find(typePair.second.begin(),typePair.second.end(), arg2Type);
    if (second == typePair.second.end()) return VALIDATION_RULE_INCOMPATIBLE_RELATIONSHIP_ARGUMENT_TYPE;

    return "";
}
