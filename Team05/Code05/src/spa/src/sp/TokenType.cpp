#include "TokenType.h"

std::string TokenType::toString() const {
    switch (info) {
        case INTEGER: return "INTEGER";
        case NAME: return "NAME";
        case LEFT_BRACE: return "LEFT_BRACE";
        case RIGHT_BRACE: return "RIGHT_BRACE";
        case SEMICOLON: return "SEMICOLON";
        case LEFT_PAREN: return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case BANG_EQUAL: return "BANG_EQUAL";
        case EQUAL_EQUAL: return "EQUAL_EQUAL";
        case GREATER: return "GREATER";
        case GREATER_EQUAL: return "GREATER_EQUAL";
        case LESSER_EQUAL: return "LESSER_EQUAL";
        case LESSER: return "LESSER";
        case PROGRAM: return "PROGRAM";
        case PROCEDURE: return "PROCEDURE";
        case READ: return "READ";
        case PRINT: return "PRINT";
        case WHILE: return "WHILE";
        case IF: return "IF";
        case THEN: return "THEN";
        case ELSE: return "ELSE";
        case ASSIGN: return "ASSIGN";
        case CALL: return "CALL";
        case BANG: return "BANG";
        case OR: return "OR";
        case AND: return "AND";
        case ADD: return "ADD";
        case SUBTRACT: return "SUBTRACT";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE: return "DIVIDE";
        case MOD: return "MOD";
        case END_OF_FILE: return "EOF";
        default: return "UNKNOWN";
    }
}

TokenType::TokenType(TokenType::TypeInfo info) : info(info) {}

TokenType::TypeInfo TokenType::getInfo() {
    return this->info;
}
