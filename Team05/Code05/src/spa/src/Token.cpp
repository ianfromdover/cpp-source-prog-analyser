//
// Created by sjh_9 on 8/2/2024.
//

#include "Token.h"

Token::Token(TokenType type, std::string lexeme, int stmtNo) {
  this->type = type;
  this->lexeme = lexeme;
  this->stmtNo = stmtNo;
}

TokenType Token::getType() const {
    return type;
}

std::string Token::getLexeme() const {
    return lexeme;
}

int Token::getStmtNo() const {
    return stmtNo;
}