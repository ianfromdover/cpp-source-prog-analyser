#include "TokenType.h"

std::string TokenTypeFmt::toString(TokenType type) {
    switch (type) {
        case TokenType::INTEGER: return "INTEGER";
        case TokenType::NAME: return "NAME";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESSER_EQUAL: return "LESSER_EQUAL";
        case TokenType::LESSER: return "LESSER";
        case TokenType::PROGRAM: return "PROGRAM";
        case TokenType::PROCEDURE: return "PROCEDURE";
        case TokenType::READ: return "READ";
        case TokenType::PRINT: return "PRINT";
        case TokenType::WHILE: return "WHILE";
        case TokenType::IF: return "IF";
        case TokenType::THEN: return "THEN";
        case TokenType::ELSE: return "ELSE";
        case TokenType::ASSIGN: return "ASSIGN";
        case TokenType::CALL: return "CALL";
        case TokenType::BANG: return "BANG";
        case TokenType::OR: return "OR";
        case TokenType::AND: return "AND";
        case TokenType::ADD: return "ADD";
        case TokenType::SUBTRACT: return "SUBTRACT";
        case TokenType::MULTIPLY: return "MULTIPLY";
        case TokenType::DIVIDE: return "DIVIDE";
        case TokenType::MOD: return "MOD";
        case TokenType::END_OF_FILE: return "EOF";
        default: return "UNKNOWN";
    }
}
