//
// Created by sjh_9 on 8/2/2024.
//

#include "TokenType.h"

std::string toString(TokenType type) {
    switch (type) {
        case IDENTIFIER: return "IDENTIFIER";
        case STRING: return "STRING";
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
        case ASSIGN: return "ASSIGN";
        case BANG: return "BANG";
        case OR: return "OR";
        case AND: return "AND";
        case ADD: return "ADD";
        case SUBTRACT: return "SUBTRACT";
        case DIVIDE: return "DIVIDE";
        case MOD: return "MOD";
        default: return "UNKNOWN";
    }
}

