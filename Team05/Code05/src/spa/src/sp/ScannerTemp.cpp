
//
// Created by sjh_9 on 8/2/2024.
//

#include <sstream>
#include "ScannerTemp.h"

ScannerTemp::ScannerTemp(const std::string& source) {
    this->source = source;
}

void ScannerTemp::scanTokens() {
    std::stringstream stream(this->source);
    char character;
    bool prevTokenIsKeyword = false;
    while (stream.get(character)) {
        std::string characterStr(1, character);
        switch(character) {
            case '{': addToken(TokenType::LEFT_BRACE, characterStr); prevTokenIsKeyword = false; break;
            case '}': addToken(TokenType::RIGHT_BRACE, characterStr); prevTokenIsKeyword = false; break;
            case ';': addToken(TokenType::SEMICOLON, characterStr); prevTokenIsKeyword = false; break;
            case '(': addToken(TokenType::LEFT_PAREN, characterStr); break;
            case ')': addToken(TokenType::RIGHT_PAREN, characterStr); prevTokenIsKeyword = false; break;
            case '+': addToken(TokenType::ADD, characterStr); prevTokenIsKeyword = false; break;
            case '-': addToken(TokenType::SUBTRACT, characterStr); prevTokenIsKeyword = false; break;
            case '*': addToken(TokenType::MULTIPLY, characterStr); prevTokenIsKeyword = false; break;
            case '%': addToken(TokenType::MOD, characterStr); prevTokenIsKeyword = false; break;
            case '=':
                if (stream.peek() == '=') {
                    stream.get(character);
                    addToken(TokenType::EQUAL_EQUAL, "==");
                } else {
                    addToken(TokenType::ASSIGN, characterStr);
                }
                prevTokenIsKeyword = false;
                break;
            case '>':
                if (stream.peek() == '=') {
                    stream.get(character);
                    addToken(TokenType::GREATER_EQUAL, ">=");
                } else {
                    addToken(TokenType::GREATER, characterStr);
                }
                prevTokenIsKeyword = false;
                break;
            case '!':
                if (stream.peek() == '=') {
                    stream.get(character);
                    addToken(TokenType::BANG_EQUAL, "!=");
                } else {
                    addToken(TokenType::BANG, characterStr);
                }
                prevTokenIsKeyword = false;
                break;
            case '<':
                if (stream.peek() == '=') {
                    stream.get(character);
                    addToken(TokenType::LESSER_EQUAL, "<=");
                } else {
                    addToken(TokenType::LESSER, characterStr);
                }
                prevTokenIsKeyword = false;
                break;
            case '|':
                if (stream.peek() == '|') {
                    stream.get(character);
                    addToken(TokenType::OR, "||");
                    prevTokenIsKeyword = false;
                    break;
                }
            case '&':
                if (stream.peek() == '&') {
                    stream.get(character);
                    addToken(TokenType::AND, "&&");
                    prevTokenIsKeyword = false;
                    break;
                }
            case '/':
                if (stream.peek() == '/') {
                    stream.get(character);
                    addToken(TokenType::DIVIDE, "//");
                    prevTokenIsKeyword = false;
                    break;
                }
            default:
                if (std::isalpha(character)) {
                    std::string name;
                    name += character;
                    while (stream.peek() != EOF && (std::isdigit(stream.peek()) || std::isalpha(stream.peek()))) {
                        char nextChar = static_cast<char>(stream.get());
                        name += nextChar;
                    }
                    prevTokenIsKeyword = isKeyword(name, prevTokenIsKeyword);
                } else if (std::isdigit(character)) {
                    std::string integer;
                    integer += character;
                    while (stream.peek() != EOF && std::isdigit(stream.peek())) {
                        char nextChar = static_cast<char>(stream.get());
                        integer += nextChar;
                    }
                    addToken(TokenType::INTEGER, integer);
                    prevTokenIsKeyword = false;
                } else {
                    if (character == ' ' || character == '\n') {

                    } else {
                        addToken(TokenType::UNKNOWN, characterStr);
                    }
                }
        }
    }

    std::cout << std::endl;

    for (const auto& token : tokenList) {
        std::cout << token->toString() << std::endl;
    }
}

void ScannerTemp::addToken(TokenType type, const std::string& lexeme) {
    std::shared_ptr<Token> token = std::make_shared<Token>(type, lexeme);
    tokenList.push_back(token);
}

bool ScannerTemp::isKeyword(const std::string& name, bool prevTokenIsKeyword) {
    if (name == "program" && !prevTokenIsKeyword) {
        addToken(TokenType::PROGRAM, name);
    } else if (name == "procedure" && !prevTokenIsKeyword) {
        addToken(TokenType::PROCEDURE, name);
    } else if (name == "read" && !prevTokenIsKeyword) {
        addToken(TokenType::READ, name);
    } else if (name == "print" && !prevTokenIsKeyword) {
        addToken(TokenType::PRINT, name);
    } else if (name == "while" && !prevTokenIsKeyword) {
        addToken(TokenType::WHILE, name);
    } else if (name == "if" && !prevTokenIsKeyword) {
        addToken(TokenType::IF, name);
    } else if (name == "else" && !prevTokenIsKeyword) {
        addToken(TokenType::ELSE, name);
    } else if (name == "call" && !prevTokenIsKeyword) {
        addToken(TokenType::CALL, name);
    } else {
        addToken(TokenType::NAME, name);
        return false;
    }
    return true;
}