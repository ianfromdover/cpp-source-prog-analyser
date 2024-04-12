//
// Created by Alex Teo on 4/5/2024.
//

#include "WithAttributeRule.h"

std::string WithAttributeRule::validate(IntermediateQuery & query) {
  std::map<std::string, QPSTokenType::QPSTypeInfo> synonymTypeMap = query.getSynonymTypeMap();
  for (auto & cl : query.getAllWithClauses()){
    if (checkArgument(cl->getFirstArgType(), cl->getFirstArgAttribute(), cl->getFirstArg(), synonymTypeMap) ||
     checkArgument(cl->getSecondArgType(), cl->getSecondArgAttribute(), cl->getSecondArg(), synonymTypeMap)) {
      return VALIDATION_RULE_WITH_ATTRIBUTE;
    }
    if (checkComparison(*cl)){
      return VALIDATION_RULE_WITH_ATTRIBUTE;
    }
  }

  if (query.hasSelectClause()) {
    std::shared_ptr<SelectClause> selectClause = query.getSelectClause();
    for (int i = 0; i < selectClause->getAllSelectEntities().size(); i++) {
      QPSTokenType::QPSTypeInfo attrType =
          selectClause->getSelectAttributeAt(i).getType().getInfo();

      if (attrType != QPSTokenType::QPSTypeInfo::ERR_NULL &&
          checkArgument(QPSTokenType::QPSTypeInfo::ATTR_REF, attrType,
                        selectClause->getSelectEntityAt(i), synonymTypeMap)) {
        return VALIDATION_RULE_WITH_ATTRIBUTE;
      }
    }
  }



  return "";
}

bool WithAttributeRule::checkArgument(QPSTokenType::QPSTypeInfo type, QPSTokenType::QPSTypeInfo attrType, QPSToken arg, std::map<std::string, QPSTokenType::QPSTypeInfo> synonymTypeMap){
  if (type == QPSTokenType::QPSTypeInfo::ATTR_REF){
    std::string syn = arg.getLexeme();
    QPSTokenType::QPSTypeInfo synType = synonymTypeMap[syn];
    if (std::find(compatibleTypes[synType].begin(), compatibleTypes[synType].end(), attrType) == compatibleTypes[synType].end()){
      return true;
    }
  }
  return false;
}

bool WithAttributeRule::checkComparison(WithClause& cl){

  QPSTokenType::QPSTypeInfo firstType = cl.getFirstArgType() == QPSTokenType::QPSTypeInfo::ATTR_REF ? cl.getFirstArgAttribute() : cl.getFirstArgType();
  QPSTokenType::QPSTypeInfo secondType = cl.getSecondArgType() == QPSTokenType::QPSTypeInfo::ATTR_REF ? cl.getSecondArgAttribute() : cl.getSecondArgType();

  if (dataType.find(firstType) == dataType.end() || dataType.find(secondType) == dataType.end()){
    throw QPSException("Invalid data type");
  }
  if (dataType.find(firstType)->second != dataType.find(secondType)->second){
    return true;
  }

  return false;
}

