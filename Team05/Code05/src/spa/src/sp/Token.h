#ifndef SPA_TOKEN_H
#define SPA_TOKEN_H

#include <iostream>
#include "TokenType.h"

class Token {
private:
    TokenType type;
    std::string lexeme;

public:
    // Constructor
    Token(TokenType type, std::string  lexeme);
    // Getter
    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getLexeme() const;
    [[nodiscard]] std::string toString() const;
};

#endif //SPA_TOKEN_H
