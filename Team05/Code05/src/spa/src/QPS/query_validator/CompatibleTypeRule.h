//
// Created by Alex on 20/2/2024.
//

#ifndef SPA_COMPATIBLETYPERULE_H
#define SPA_COMPATIBLETYPERULE_H


#include "Rule.h"

typedef QPSTokenType::QPSTypeInfo QType;

class CompatibleTypeRule : public Rule {
public:
    std::string validate(QueryObject &) override;

    std::string validate(IntermediateQuery &) override;

private:
    static inline std::map<QPSTokenType::QPSTypeInfo, std::pair<std::vector<QPSTokenType::QPSTypeInfo>, std::vector<QPSTokenType::QPSTypeInfo>>> typeMap =
            {
                    {QType::PARENT, {{QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD},
                                    {QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD}}},
                    {QType::PARENT_T, {{QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD},
                                     {QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD}}},
                    {QType::FOLLOWS, {{QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD},
                                     {QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD}}},
                    {QType::FOLLOWS_T, {{QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD},
                                     {QType::PRINT, QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::INTEGER,QType::WILDCARD}}},
                    {QType::MODIFIES_S, {{QType::READ, QType::WHILE,QType::IF,QType::ASSIGN,QType::PROCEDURE,QType::INTEGER,QType::WILDCARD},
                                         {QType::VARIABLE ,QType::WILDCARD, QType::QUOTED_IDENT}}},
                    {QType::USES_S, {{QType::PRINT, QType::WHILE,QType::IF,QType::ASSIGN,QType::PROCEDURE,QType::INTEGER,QType::WILDCARD},
                                     {QType::VARIABLE ,QType::WILDCARD, QType::QUOTED_IDENT}}},
            };
};


#endif //SPA_COMPATIBLETYPERULE_H
