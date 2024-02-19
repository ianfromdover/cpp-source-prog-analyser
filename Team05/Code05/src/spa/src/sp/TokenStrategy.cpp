//
// Created by sjh_9 on 15/2/2024.
//
#include "TokenStrategy.h"

void TokenStrategy::addToken(TokenType::TypeInfo typeInfo, const std::string &lexeme,
                              std::shared_ptr<std::vector<std::shared_ptr<Token>>> &tokens) {
    TokenType tokenType(typeInfo);
    std::shared_ptr<Token> token = std::make_shared<Token>(tokenType, lexeme);
    tokens->push_back(token);
}