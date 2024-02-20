//
// Created by Alex on 15/2/2024.
//

#include "SingleCharacterStrategy.h"

namespace qps {
    bool SingleCharacterStrategy::tokenize(char character, std::stringstream &stream, TokenList &tokens,
                                           bool &prevTokenIsKeyword) {
        TokenType::TypeInfo type;
        std::string lexeme(1, character);
        bool isTokenFound = true;

        switch (character) {
            case ';':
                type = TokenType::SEMICOLON;
                prevTokenIsKeyword = false;
                break;
            case ',':
                type = TokenType::COMMA;
                break;
            case '(' :
                type = TokenType::LEFT_PAREN;
                break;
            case ')' :
                type = TokenType::RIGHT_PAREN;
                prevTokenIsKeyword = false;
                break;
            case '_' :
                type = TokenType::WILDCARD;
                break;
            case '"' :
                type = TokenType::QUOTE;
                break;
            case '+':
                type = TokenType::PLUS;
                break;
            case '-':
                type = TokenType::MINUS;
                break;
            case '*':
                type = TokenType::STAR;
                break;
            case '/':
                type = TokenType::SLASH;
                break;
            case '%':
                type = TokenType::PERCENT;
                break;

            default:
                isTokenFound = false;
                break;
        }

        if (isTokenFound)
            tokens.addToken(type, lexeme);


        return isTokenFound;
    }
}
