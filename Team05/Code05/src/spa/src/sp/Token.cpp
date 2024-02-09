#include "Token.h"

#include <utility>

Token::Token(TokenType type, std::string  lexeme) : type(type), lexeme(std::move(lexeme)) {

}

TokenType Token::getType() const {
    return type;
}

std::string Token::getLexeme() const {
    return lexeme;
}

std::string Token::toString() const {
   return "(" + getType().toString() + ", " + getLexeme() + ")";
}