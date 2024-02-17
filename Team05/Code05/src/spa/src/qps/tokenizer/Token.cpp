//
// Created by Alex on 15/2/2024.
//

#include "Token.h"

namespace qps {
    Token::Token(TokenType type, std::string lexeme) : type(type), lexeme(std::move(lexeme)) {}

    TokenType Token::getType() const {
        return type;
    }

    std::string Token::getLexeme() const {
        return lexeme;
    }

    std::string Token::toString() const {
        return "[" + getType().toString() + ", " + getLexeme() + "]";
    }
}
