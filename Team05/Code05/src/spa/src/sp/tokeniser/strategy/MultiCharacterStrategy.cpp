//
// Created by sjh_9 on 9/2/2024.
//

#include "MultiCharacterStrategy.h"

bool MultiCharacterStrategy::tokenize(char character, std::stringstream& stream,
                                      std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens, bool& prevTokenIsKeyword) {
    if (std::isalpha(character)) {
        std::string name = character + readWhile(stream, [](char ch) { return std::isalnum(ch); });
        prevTokenIsKeyword = isKeyword(name, tokens, prevTokenIsKeyword);
    } else if (std::isdigit(character)) {
        if (character == '0' && std::isalnum(stream.peek())) {
            throw TokenException("Invalid Token Type");
        }
        std::string integer = character + readWhile(stream, [](char ch) { return std::isdigit(ch); });
        this->addToken(TokenType::INTEGER, integer, tokens);
        prevTokenIsKeyword = false;
    } else if (character == ' ' || character == '\n') {
        //Do nothing
    } else {
        throw TokenException("Invalid Token Type");
    }
    return true;
}

bool MultiCharacterStrategy::isKeyword(const std::string& name, std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens,
                                       bool& prevTokenIsKeyword) {
    static const std::map<std::string, TokenType> keywords = {
            {"program", TokenType::PROGRAM}, {"procedure", TokenType::PROCEDURE},
            {"read", TokenType::READ}, {"print", TokenType::PRINT},
            {"while", TokenType::WHILE}, {"if", TokenType::IF},
            {"then", TokenType::THEN}, {"else", TokenType::ELSE},
            {"call", TokenType::CALL},
    };

    auto it = keywords.find(name);
    if (it != keywords.end() && !prevTokenIsKeyword) {
        this->addToken(it->second, name, tokens);
        return true;
    } else {
        this->addToken(TokenType::NAME, name, tokens);
        return false;
    }
}

std::string MultiCharacterStrategy::readWhile(std::stringstream& stream, const std::function<bool(char)>& condition) {
    std::string result;
    char nextChar = static_cast<char>(stream.peek());
    while (condition(nextChar)) {
        result += static_cast<char>(stream.get());
        nextChar = static_cast<char>(stream.peek());
    }
    return result;
}