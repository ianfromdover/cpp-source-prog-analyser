//
// Created by Alex on 20/2/2024.
//

#ifndef SPA_COMPATIBLETYPERULE_H
#define SPA_COMPATIBLETYPERULE_H

#include "Rule.h"

typedef QPSTokenType::QPSTypeInfo QType;

class CompatibleTypeRule : public Rule {
public:
  std::string validate(IntermediateQuery &) override;

private:
  std::string validateRelationship(
      RelationshipClause &cl,
      std::map<std::string, QPSTokenType::QPSTypeInfo> declarationMap);
  std::string validatePattern(
      PatternClause cl,
      std::map<std::string, QPSTokenType::QPSTypeInfo> declarationMap);
  static bool isStatementType(const QPSTokenType::QPSTypeInfo &type);

  static inline std::map<QType ,int> typeArgCountMap = {
          {QType::ASSIGN, 2},
          {QType::WHILE, 2},
          {QType::IF, 3}
  };

  static inline std::map<QPSTokenType::QPSTypeInfo,
                         std::pair<std::vector<QPSTokenType::QPSTypeInfo>,
                                   std::vector<QPSTokenType::QPSTypeInfo>>>
      typeMap = {
          {QType::PARENT,
           {{QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD},
            {QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD}}},
          {QType::PARENT_T,
           {{QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD},
            {QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD}}},
          {QType::FOLLOWS,
           {{QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD},
            {QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD}}},
          {QType::FOLLOWS_T,
           {{QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD},
            {QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::INTEGER, QType::WILDCARD}}},
          {QType::MODIFIES_S,
           {{QType::CALL, QType::STMT1, QType::PRINT, QType::READ, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::PROCEDURE, QType::INTEGER,
             QType::WILDCARD},
            {QType::VARIABLE, QType::WILDCARD, QType::QUOTED_IDENT}}},
          {QType::MODIFIES_P,
           {{QType::PROCEDURE, QType::QUOTED_IDENT, QType::WILDCARD},
            {QType::VARIABLE, QType::WILDCARD, QType::QUOTED_IDENT}}},
          {QType::USES_S,
           {{QType::CALL, QType::STMT1, QType::READ, QType::PRINT, QType::WHILE,
             QType::IF, QType::ASSIGN, QType::PROCEDURE, QType::INTEGER,
             QType::WILDCARD},
            {QType::STMT1, QType::VARIABLE, QType::WILDCARD,
             QType::QUOTED_IDENT}}},
          {QType::USES_P,
           {{QType::PROCEDURE, QType::QUOTED_IDENT, QType::WILDCARD},
            {QType::VARIABLE, QType::WILDCARD, QType::QUOTED_IDENT}}},
          {QType::CALLS,
           {{QType::PROCEDURE, QType::QUOTED_IDENT, QType::WILDCARD},
            {QType::PROCEDURE, QType::WILDCARD, QType::QUOTED_IDENT}}},
          {QType::CALLS_T,
           {{QType::PROCEDURE, QType::QUOTED_IDENT, QType::WILDCARD},
            {QType::PROCEDURE, QType::WILDCARD, QType::QUOTED_IDENT}}},
          {QType::USES_P,
           {{QType::PROCEDURE, QType::QUOTED_IDENT, QType::WILDCARD},
            {QType::VARIABLE, QType::WILDCARD, QType::QUOTED_IDENT}}},
          {QType::MODIFIES_P,
           {{QType::PROCEDURE, QType::QUOTED_IDENT, QType::WILDCARD},
            {QType::VARIABLE, QType::WILDCARD, QType::QUOTED_IDENT}}}};
};

#endif // SPA_COMPATIBLETYPERULE_H
