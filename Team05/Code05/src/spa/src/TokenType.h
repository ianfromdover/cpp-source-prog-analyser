//
// Created by sjh_9 on 8/2/2024.
//

#ifndef SPA_TOKENTYPE_H
#define SPA_TOKENTYPE_H
#include <iostream>

enum TokenType {
    //Literals
    IDENTIFIER, STRING, NAME,
    //Grouping Symbols
    LEFT_BRACE, RIGHT_BRACE, SEMICOLON, LEFT_PAREN, RIGHT_PAREN,
    //Comparison Operators
    BANG_EQUAL, EQUAL_EQUAL, GREATER, GREATER_EQUAL, LESSER_EQUAL, LESSER,
    //Keywords
    PROGRAM, PROCEDURE, READ, PRINT, WHILE, IF, ASSIGN,
    //Logical Operators
    BANG, OR, AND,
    //Mathematical Operators
    ADD, SUBTRACT, DIVIDE, MOD
};

std::string toString(TokenType type);

#endif //SPA_TOKENTYPE_H
