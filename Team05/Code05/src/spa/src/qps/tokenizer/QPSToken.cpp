//
// Created by Alex on 15/2/2024.
//

#include "QPSToken.h"


QPSToken::QPSToken(QPSTokenType type, std::string lexeme) : type(type), lexeme(std::move(lexeme)) {}

QPSTokenType QPSToken::getType() const {
    return type;
}

std::string QPSToken::getLexeme() const {
    return lexeme;
}

std::string QPSToken::toString() const {
    return "[" + getType().toString() + ", " + getLexeme() + "]";
}

