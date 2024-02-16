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
            IDENTIFIER,

            // Punctuation
            SEMICOLON, LEFT_PAREN, RIGHT_PAREN, COMMA, QUOTE,

            // Design Entities
            STMT, READ, PRINT, CALL, WHILE, IF, ASSIGN, VARIABLE, CONSTANT, PROCEDURE,

            // Select Keywords
            SELECT,

            // Such That Keywords
            SUCH, THAT,

            // Relationships
            PARENT, PARENT_T,
            FOLLOWS, FOLLOWS_T,
            MODIFIES_S, MODIFIES_T,
            USES_S, USES_T,

            // Entity References
            ENT_REF,
            WILDCARD,           // '_'
            SYNONYM,            // synonym
            QUOTED_IDENT,       // '"' IDENT '"'

            // Statement References
            STMT_REF,
            //WILDCARD,           // '_' : already exists
            //SYNONYM,            // synonym : already exists
            INTEGER,

            // Pattern Keywords
            PATTERN,

            // expression-spec :
            EXPR_SPEC,
            EXPR,               // '"' expr '"'
            EXPR_WILDCARD,      // '_' '"' expr '"' '_'
            // WILDCARD         // '_' : already exists

            // Tokens for pattern expression
            FACTOR, TERM, EMPTY,

            // Expression Operators
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
