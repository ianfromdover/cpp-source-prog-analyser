//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSTOKENTYPE_H
#define SPA_QPSTOKENTYPE_H

#include <string>


class QPSTokenType {
public:
    enum QPSTypeInfo {
        // Lexical Tokens
        IDENTIFIER,

        // Punctuation
        SEMICOLON, LEFT_PAREN, RIGHT_PAREN, COMMA, QUOTE, LEFT_A_BRAC, RIGHT_A_BRAC,DECIMAL, EQUAL,

        // Design Entities
        STMT1, READ, PRINT, CALL, WHILE, IF, ASSIGN, VARIABLE, CONSTANT, PROCEDURE,

        // Select Keywords
        SELECT, BOOLEAN,

        // Such That Keywords
        SUCH, THAT,

        // With Keywords
        WITH, WITHPROCNAME, WITHVARNAME, WITHVALUE, WITHSTMT,
        ATTR_REF,

        // Relationships
        PARENT, PARENT_T,
        FOLLOWS, FOLLOWS_T,
        MODIFIES,
        MODIFIES_S,
        MODIFIES_P,
        USES,
        USES_S,
        USES_P,
        CALLS,
        CALLS_T,
        AND, NOT,

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

        // With References
        WITH_REF,
        VAR_WITH,
        INT_WITH,

        // Pattern Keywords
        PATTERN,

        // expression-spec :
        EXPR_REF,
        EXPR,               // '"' expr '"'
        EXPR_WILDCARD,      // '_' '"' expr '"' '_'
        // WILDCARD         // '_' : already exists

        // Tokens for pattern expression
        FACTOR, TERM, EMPTY,

        // Expression Operators
        PLUS, MINUS, STAR, SLASH, PERCENT,

        // With clause attributes
        PROCNAME, VARNAME, STMT,

        // Others
        END_OF_FILE, TODO, ERR_NULL
    };

private:
    QPSTypeInfo info;

public:
    explicit QPSTokenType(QPSTypeInfo info);

    QPSTypeInfo getInfo();

    [[nodiscard]] std::string toString() const;

    friend bool operator<(const QPSTokenType &lhs, const QPSTokenType &rhs) {
        return lhs.info < rhs.info && lhs.toString() < rhs.toString();
    }

    friend bool operator==(const QPSTokenType &lhs, const QPSTokenType &rhs) {
//        return (lhs.info == rhs.info) && (lhs.toString() == rhs.toString());
        return true;
    }
};


#endif //SPA_QPSTOKENTYPE_H
