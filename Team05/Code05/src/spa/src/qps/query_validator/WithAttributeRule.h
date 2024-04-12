//
// Created by Alex Teo on 4/5/2024.
//

#ifndef SPA_WITHATTRIBUTERULE_H
#define SPA_WITHATTRIBUTERULE_H

#include "Rule.h"

using QType = QPSTokenType::QPSTypeInfo;

class WithAttributeRule : public Rule {
  std::string validate(IntermediateQuery &) override;

  std::map<QType, std::vector<QType>> compatibleTypes = {
      {QType::PROCEDURE, {QType ::WITHPROCNAME}},
      {QType::CALL, {QType ::WITHPROCNAME, QType ::WITHSTMT}},
      {QType::VARIABLE, {QType ::WITHVARNAME}},
      {QType::READ, {QType ::WITHVARNAME, QType ::WITHSTMT}},
      {QType::PRINT, {QType ::WITHVARNAME, QType ::WITHSTMT}},
      {QType::CONSTANT, {QType ::WITHVALUE}},
      {QType::STMT1, {QType ::WITHSTMT}},
      {QType::WHILE, {QType ::WITHSTMT}},
      {QType::IF, {QType ::WITHSTMT}},
      {QType::ASSIGN, {QType ::WITHSTMT}},
  };

  std::map<QType, std::string> dataType = {
      {QType::WITHPROCNAME, WITHNAME},
      {QType::WITHVARNAME, WITHNAME},
      {QType::QUOTED_IDENT, WITHNAME},
      {QType::WITHSTMT, WITHINT},
      {QType::WITHVALUE, WITHINT},
      {QType::INTEGER, WITHINT},
  };

  bool checkArgument(QPSTokenType::QPSTypeInfo type,
                     QPSTokenType::QPSTypeInfo attrType, QPSToken arg,
                     map<string, QPSTokenType::QPSTypeInfo> synonymTypeMap);
  bool checkComparison(WithClause &cl);
};

#endif // SPA_WITHATTRIBUTERULE_H
