#ifndef SPA_TOKENTYPE_H
#define SPA_TOKENTYPE_H
#include <iostream>

class TokenType {
public:
    enum TypeInfo {
        //Literals
        INTEGER, NAME,
        //Grouping Symbols
        LEFT_BRACE, RIGHT_BRACE, SEMICOLON, LEFT_PAREN, RIGHT_PAREN,
        //Comparison Operators
        BANG_EQUAL, EQUAL_EQUAL, GREATER, GREATER_EQUAL, LESSER_EQUAL, LESSER,
        //Keywords
        PROGRAM, PROCEDURE, READ, PRINT, WHILE, IF, ELSE, ASSIGN, CALL,
        //Logical Operators
        BANG, OR, AND,
        //Mathematical Operators
        ADD, SUBTRACT, MULTIPLY, DIVIDE, MOD,
        // Others
        END_OF_FILE,
        // Invalid
        UNKNOWN
    };

private:
    TypeInfo info;

public:
    explicit TokenType(TypeInfo info);
    TypeInfo getInfo();
    [[nodiscard]] std::string toString() const;
};

#endif //SPA_TOKENTYPE_H