//
// Created by Chua Bing Quan on 11/2/24.
//

#ifndef SPA_PARSER_H
#define SPA_PARSER_H

#include "sp/ast/Expr.h"
#include "sp/ast/Stmt.h"
#include "sp/ast/Program.h"

class Parser {
private:
    int current = 0;
    StmtNo currentStmtNo = 0;
    std::shared_ptr<std::vector<std::shared_ptr<Token>>> tokens;

public:
    explicit Parser(const std::shared_ptr<std::vector<std::shared_ptr<Token>>>& tokens) : tokens(tokens) {};
    std::shared_ptr<Program> parse();

private:
    bool match(std::initializer_list<TokenType> types);
    bool check(TokenType type);
    bool isAtEnd();
    Token advance();
    Token peek();
    Token previous();
    Token consume(TokenType type, std::string message);

    StmtNo nextStmtNo();

    std::shared_ptr<Procedure> procedure();
    std::shared_ptr<StmtList> stmtList();
    std::shared_ptr<Stmt> stmt();
    std::shared_ptr<Stmt> read();
    std::shared_ptr<Stmt> print();
    std::shared_ptr<Stmt> call();
    std::shared_ptr<Stmt> loop();
    std::shared_ptr<Stmt> cond();
    std::shared_ptr<Stmt> assign();

    static bool isRelOp(TokenType type);
    bool lookAheadForRelExpr();

    std::shared_ptr<Expr> condExpr();
    std::shared_ptr<Expr> relExpr();
    std::shared_ptr<Expr> relFactor();
    std::shared_ptr<Expr> expr();
    std::shared_ptr<Expr> exprTail(std::shared_ptr<Expr> left);
    std::shared_ptr<Expr> term();
    std::shared_ptr<Expr> termTail(std::shared_ptr<Expr> left);
    std::shared_ptr<Expr> factor();
};


#endif //SPA_PARSER_H
