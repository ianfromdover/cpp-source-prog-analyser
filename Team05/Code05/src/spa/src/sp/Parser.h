//
// Created by Chua Bing Quan on 11/2/24.
//

#ifndef SPA_PARSER_H
#define SPA_PARSER_H

#include "TokenList.h"
#include "Expr.h"

class Parser {
private:
    int current = 0;
    // TODO: Re-look at the design and ownership of TokenList.
    std::vector<std::shared_ptr<Token>> tokens;

public:
    explicit Parser(TokenList& tokens) : tokens(tokens.getTokens()) {};

private:
    bool match(std::initializer_list<TokenType::TypeInfo> types);
    bool check(TokenType::TypeInfo type);
    Token advance();
    bool isAtEnd();
    Token peek();
    Token previous();
    Token consume(TokenType::TypeInfo type, std::string message);

    std::unique_ptr<Expr> condExpr();
    std::unique_ptr<Expr> relExpr();
    std::unique_ptr<Expr> relFactor();

    Expr expr();
    Expr exprTail();
    std::unique_ptr<Expr> term();
    std::optional<std::unique_ptr<Expr>> termTail();
    std::unique_ptr<Expr> factor();
};


#endif //SPA_PARSER_H
