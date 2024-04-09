//
// Created by Alex Teo on 4/5/2024.
//

#include "WithAttributeRule.h"

std::string WithAttributeRule::validate(IntermediateQuery & query) {
  std::map<std::string, QPSTokenType::QPSTypeInfo> synonymTypeMap = query.getSynonymTypeMap();
  for (auto & cl : query.getAllWithClauses()){
    // check first arg
    if (cl->getFirstArgType() == QPSTokenType::QPSTypeInfo::ATTR_REF){
      std::string syn = cl->getFirstArg().getLexeme();
      QPSTokenType::QPSTypeInfo synType = synonymTypeMap[syn];
      QPSTokenType::QPSTypeInfo attrType = cl->getFirstArgAttribute();
      if (std::find(compatibleTypes[synType].begin(), compatibleTypes[synType].end(), attrType) == compatibleTypes[synType].end()){
        return VALIDATION_RULE_WITH_ATTRIBUTE;
      }
    }

    // check second arg
    if (cl->getSecondArgType() == QPSTokenType::QPSTypeInfo::ATTR_REF){
      std::string syn = cl->getSecondArg().getLexeme();
      QPSTokenType::QPSTypeInfo synType = synonymTypeMap[syn];
      QPSTokenType::QPSTypeInfo attrType = cl->getSecondArgAttribute();
      if (std::find(compatibleTypes[synType].begin(), compatibleTypes[synType].end(), attrType) == compatibleTypes[synType].end()){
        return VALIDATION_RULE_WITH_ATTRIBUTE;
      }
    }
  }

  return "";
}
