//
// Created by Alex on 15/2/2024.
//

#include "QPSSingleCharacterStrategy.h"

bool QPSSingleCharacterStrategy::tokenize(char character, std::stringstream &stream, QPSTokenList &tokens,
                                          bool &prevTokenIsKeyword) {
    QPSTokenType::QPSTypeInfo type;
    std::string lexeme(1, character);
    bool isTokenFound = true;

    switch (character) {
        case ';':
            type = QPSTokenType::SEMICOLON;
            prevTokenIsKeyword = false;
            break;
        case ',':
            type = QPSTokenType::COMMA;
            break;
        case '(' :
            type = QPSTokenType::LEFT_PAREN;
            break;
        case ')' :
            type = QPSTokenType::RIGHT_PAREN;
            prevTokenIsKeyword = false;
            break;
        case '_' :
            type = QPSTokenType::WILDCARD;
            break;
        case '"' :
            type = QPSTokenType::QUOTE;
            prevTokenIsKeyword = false;
            break;
        case '+':
            type = QPSTokenType::PLUS;
            break;
        case '-':
            type = QPSTokenType::MINUS;
            break;
        case '*':
            type = QPSTokenType::STAR;
            break;
        case '/':
            type = QPSTokenType::SLASH;
            break;
        case '%':
            type = QPSTokenType::PERCENT;
            break;
        case '<':
          type = QPSTokenType::LEFT_A_BRAC;
          prevTokenIsKeyword = true;
          break;
        case '=':
          type = QPSTokenType::EQUAL;
          prevTokenIsKeyword = true;
          break;
        case '>':
          type = QPSTokenType::RIGHT_A_BRAC;
          prevTokenIsKeyword = false;
          break;
        case '.':
          if (!tokens.getTokens().empty()){
            std::string s = tokens.getTokens().back()->getLexeme();
            tokens.getTokens().pop_back();
            tokens.addToken(QPSTokenType::IDENTIFIER, s);
          }
          type = QPSTokenType::DECIMAL;
          prevTokenIsKeyword = false;
          break;

        default:
            isTokenFound = false;
            break;
    }

    if (isTokenFound)
        tokens.addToken(type, lexeme);


    return isTokenFound;
}

