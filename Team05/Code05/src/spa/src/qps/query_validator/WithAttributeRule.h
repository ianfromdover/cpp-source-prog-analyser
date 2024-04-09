//
// Created by Alex Teo on 4/5/2024.
//

#ifndef SPA_WITHATTRIBUTERULE_H
#define SPA_WITHATTRIBUTERULE_H

#include "Rule.h"

using QType = QPSTokenType::QPSTypeInfo;

class WithAttributeRule : public Rule {
  std::string validate(IntermediateQuery &) override;

//  std::map<QType, QType> compatibleTypes = {
//      {QType::PROCEDURE, QType ::WITHPROCNAME},
//      {QType::CALL, QType ::WITHPROCNAME},
//      {QType::VARIABLE, QType ::WITHVARNAME},
//      {QType::READ, QType ::WITHVARNAME},
//      {QType::PRINT, QType ::WITHVARNAME},
//
//      {QType::CONSTANT, QType ::INTEGER},
//
//      {QType::STMT1, QType ::WITHSTMT},
//      {QType::READ, QType ::WITHSTMT},
//      {QType::PRINT, QType ::WITHSTMT},
//      {QType::CALL, QType ::WITHSTMT},
//      {QType::WHILE, QType ::WITHSTMT},
//      {QType::IF, QType ::WITHSTMT},
//      {QType::ASSIGN, QType ::WITHSTMT},
//  };

  std::map<QType, std::vector<QType>> compatibleTypes = {
      {QType::PROCEDURE, {QType ::WITHPROCNAME}},
      {QType::CALL, {QType ::WITHPROCNAME, QType ::WITHSTMT}},
      {QType::VARIABLE, {QType ::WITHVARNAME}},
      {QType::READ, {QType ::WITHVARNAME, QType ::WITHSTMT}},
      {QType::PRINT, {QType ::WITHVARNAME, QType ::WITHSTMT}},
      {QType::CONSTANT, {QType ::INTEGER}},
      {QType::STMT1, {QType ::WITHSTMT}},
      {QType::WHILE, {QType ::WITHSTMT}},
      {QType::IF, {QType ::WITHSTMT}},
      {QType::ASSIGN, {QType ::WITHSTMT}},

  };
};

#endif // SPA_WITHATTRIBUTERULE_H
