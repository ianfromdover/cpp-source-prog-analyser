//
// Created by sjh_9 on 9/2/2024.
//

#include "MultiCharacterStrategy.h"

bool MultiCharacterStrategy::tokenize(char character, std::stringstream& stream, TokenList& tokens, bool& prevTokenIsKeyword) {
    if (std::isalpha(character)) {
        std::string name = character + readWhile(stream, [](char ch) { return std::isalnum(ch); });
        prevTokenIsKeyword = isKeyword(name, tokens, prevTokenIsKeyword);
    } else if (std::isdigit(character)) {
        std::string integer = character + readWhile(stream, [](char ch) { return std::isdigit(ch); });
        tokens.addToken(TokenType::INTEGER, integer);
        prevTokenIsKeyword = false;
    } else if (character != ' ' && character != '\n') {
        //Do nothing
    }
    return true;
}

bool MultiCharacterStrategy::isKeyword(const std::string& name, TokenList& tokens, bool& prevTokenIsKeyword) {
    static const std::map<std::string, TokenType::TypeInfo> keywords = {
            {"program", TokenType::PROGRAM}, {"procedure", TokenType::PROCEDURE},
            {"read", TokenType::READ}, {"print", TokenType::PRINT},
            {"while", TokenType::WHILE}, {"if", TokenType::IF},
            {"else", TokenType::ELSE}, {"call", TokenType::CALL},
    };

    auto it = keywords.find(name);
    if (it != keywords.end() && !prevTokenIsKeyword) {
        tokens.addToken(it->second, name);
        return true;
    } else {
        tokens.addToken(TokenType::NAME, name);
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