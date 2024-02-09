
//
// Created by sjh_9 on 9/2/2024.
//

#include "SingleCharacterStrategy.h"

bool SingleCharacterStrategy::tokenize(char character, std::stringstream& stream, TokenList& tokens, bool& prevTokenIsKeyword) {
    TokenType::TypeInfo type;
    std::string lexeme(1, character);
    bool isTokenFound = true;

    switch(character) {
        case '{': type = TokenType::LEFT_BRACE; break;
        case '}': type = TokenType::RIGHT_BRACE; break;
        case ';': type = TokenType::SEMICOLON; break;
        case '(': type = TokenType::LEFT_PAREN; break;
        case ')': type = TokenType::RIGHT_PAREN; break;
        case '+': type = TokenType::ADD; break;
        case '-': type = TokenType::SUBTRACT; break;
        case '*': type = TokenType::MULTIPLY; break;
        case '%': type = TokenType::MOD; break;
        default: isTokenFound = false; break;
    }

    if (isTokenFound) {
        tokens.addToken(type, lexeme);
        if (!(type == TokenType::LEFT_PAREN || type == TokenType::RIGHT_PAREN)) {
            prevTokenIsKeyword = false;
        }
    }

    return isTokenFound;
}
