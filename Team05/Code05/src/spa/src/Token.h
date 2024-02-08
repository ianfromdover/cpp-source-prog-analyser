//
// Created by sjh_9 on 8/2/2024.
//

#ifndef SPA_TOKEN_H
#define SPA_TOKEN_H

#include <iostream>
#include "TokenType.h"

class Token {
private:
    TokenType type;
    std::string lexeme;
    int stmtNo;

public:
    // Constructor
    Token(TokenType type, std::string lexeme, int stmtNo);
    // Getter
    TokenType getType() const;
    std::string getLexeme() const;
    int getStmtNo() const;


};

#endif //SPA_TOKEN_H
