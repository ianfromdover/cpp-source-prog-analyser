//
// Created by Chua Bing Quan on 11/2/24.
//

#ifndef SPA_PARSER_H
#define SPA_PARSER_H

#include "Expr.h"
#include "Stmt.h"

class Parser {
private:
    int current = 0;
    StmtNo currentStmtNo = 0;
    std::shared_ptr<std::vector<std::shared_ptr<Token>>> tokens;

public:
    explicit Parser(std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens) : tokens(tokens) {};
    Program parse();

private:
    bool match(std::initializer_list<TokenType::TypeInfo> types);
    bool check(TokenType::TypeInfo type);
    bool isAtEnd();
    Token advance();
    Token peek();
    Token previous();
    Token consume(TokenType::TypeInfo type, std::string message);

    StmtNo nextStmtNo();

    std::unique_ptr<Procedure> procedure();
    std::unique_ptr<StmtList> stmtList();
    std::unique_ptr<Stmt> stmt();
    std::unique_ptr<Stmt> read();
    std::unique_ptr<Stmt> print();
    std::unique_ptr<Stmt> call();
    std::unique_ptr<Stmt> loop();
    std::unique_ptr<Stmt> cond();
    std::unique_ptr<Stmt> assign();

    std::unique_ptr<Expr> condExpr();
    std::unique_ptr<Expr> relExpr();
    std::unique_ptr<Expr> relFactor();
    std::unique_ptr<Expr> expr();
    std::unique_ptr<Expr> exprTail(std::unique_ptr<Expr> left);
    std::unique_ptr<Expr> term();
    std::unique_ptr<Expr> termTail(std::unique_ptr<Expr> left);
    std::unique_ptr<Expr> factor();
};


#endif //SPA_PARSER_H
