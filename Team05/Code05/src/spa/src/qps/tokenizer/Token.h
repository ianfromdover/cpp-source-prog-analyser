//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_TOKEN_H
#define SPA_TOKEN_H


#include "TokenType.h"

namespace qps {
    class Token {
    private:
        TokenType type;
        std::string lexeme;

    public:
        // Constructor
        Token(TokenType type, std::string lexeme);

        // Getter
        [[nodiscard]] TokenType getType() const;

        [[nodiscard]] std::string getLexeme() const;

        [[nodiscard]] std::string toString() const;
    };
}


#endif //SPA_TOKEN_H
