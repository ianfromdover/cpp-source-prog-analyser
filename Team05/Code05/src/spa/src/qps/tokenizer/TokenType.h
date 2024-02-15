//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_TOKENTYPE_H
#define SPA_TOKENTYPE_H

#include <string>

namespace qps {
    class TokenType {
    public:
        enum TypeInfo {
            // Lexical Tokens
            INTEGER, IDENTIFIER,
            // Complex tokens
            SYNONYM,

            // Punctuation
            SEMICOLON, LEFT_PAREN, RIGHT_PAREN, COMMA, QUOTE,

            // Design Entities
            STMT, // TODO: Add more design entities

            // Select Keywords
            SELECT,

            // Such That Keywords
            SUCH, THAT,

            // Relationships
            PARENT, // TODO: Add more relationships
            // Constraint Arguments
            WILDCARD, QUOTED_IDENT, STMT_REF, ENT_REF,

            // Pattern Keywords
            PATTERN,

            // Pattern Arguments
            PLUS, MINUS, STAR, SLASH, PERCENT,

            // Others
            END_OF_FILE
        };

    private:
        TypeInfo info;

    public:
        explicit TokenType(TypeInfo info);

        TypeInfo getInfo();

        [[nodiscard]] std::string toString() const;

        friend bool operator<(const TokenType &lhs, const TokenType &rhs) {
            return lhs.info < rhs.info && lhs.toString() < rhs.toString();
        }

        friend bool operator==(const TokenType &lhs, const TokenType &rhs) {
            return (lhs.info == rhs.info) && (lhs.toString() == rhs.toString());
        }

    };
}

#endif //SPA_TOKENTYPE_H
