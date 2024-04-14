
//
// Created by sjh_9 on 9/2/2024.
//
// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/7295ea70-2fb1-40e1-a767-0da8113ec557

#include "SingleCharacterStrategy.h"

bool SingleCharacterStrategy::tokenize(char character, std::stringstream& stream, std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens,
                                       bool& prevTokenIsKeyword) {
    TokenType type;
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
        case '/': type = TokenType::DIVIDE; break;
        default: isTokenFound = false; break;
    }

    if (isTokenFound) {
        this->addToken(type, lexeme, tokens);
        if (!(type == TokenType::LEFT_PAREN || type == TokenType::RIGHT_PAREN)) {
            prevTokenIsKeyword = false;
        }
    }

    return isTokenFound;
}

// ai-gen end