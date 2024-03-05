//
// Created by sjh_9 on 15/2/2024.
//
#include "TokenStrategy.h"

void TokenStrategy::addToken(TokenType type, const std::string &lexeme,
                              std::shared_ptr<std::vector<std::shared_ptr<Token>>> &tokens) {
    std::shared_ptr<Token> token = std::make_shared<Token>(type, lexeme);
    tokens->push_back(token);
}