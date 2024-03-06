#ifndef SPA_TOKENTYPE_H
#define SPA_TOKENTYPE_H
#include <iostream>

enum class TokenType {
    //Literals
    INTEGER, NAME,
    //Grouping Symbols
    LEFT_BRACE, RIGHT_BRACE, SEMICOLON, LEFT_PAREN, RIGHT_PAREN,
    //Comparison Operators
    BANG_EQUAL, EQUAL_EQUAL, GREATER, GREATER_EQUAL, LESSER_EQUAL, LESSER,
    //Keywords
    PROGRAM, PROCEDURE, READ, PRINT, WHILE, IF, THEN, ELSE, ASSIGN, CALL,
    //Logical Operators
    BANG, OR, AND,
    //Mathematical Operators
    ADD, SUBTRACT, MULTIPLY, DIVIDE, MOD,
    // Others
    END_OF_FILE,
    // Invalid
    UNKNOWN
};

class TokenTypeFmt {
public:
    static std::string toString(TokenType type);
};

#endif //SPA_TOKENTYPE_H