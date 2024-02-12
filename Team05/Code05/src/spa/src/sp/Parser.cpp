//
// Created by Chua Bing Quan on 11/2/24.
//

#include <string>
#include "Parser.h"

Program Parser::parse() {
    Program program = std::make_unique<std::vector<std::unique_ptr<Procedure>>>();
    while (!this->isAtEnd()) {
        program->push_back(this->procedure());
    }
    return program;
}

bool Parser::match(std::initializer_list<TokenType::TypeInfo> types) {
    for (const auto& type : types) {
        if (this->check(type)) {
            this->advance();
            return true;
        }
    }
    return false;
}

bool Parser::check(TokenType::TypeInfo type) {
    if (this->isAtEnd()) {
        return false;
    }
    return this->peek().getType().getInfo() == type;
}

bool Parser::isAtEnd() {
    return this->peek().getType().getInfo() == TokenType::END_OF_FILE;
}

Token Parser::advance() {
    if (!this->isAtEnd()) {
        this->current++;
    }
    return this->previous();
}

Token Parser::peek() {
    return *this->tokens.at(this->current);
}

Token Parser::previous() {
    return *this->tokens.at(this->current - 1);
}

Token Parser::consume(TokenType::TypeInfo type, std::string message) {
    if (this->check(type)) {
        return this->advance();
    }

    // TODO: Handle parse errors according to requirements.
    throw message;
}

StmtNo Parser::nextStmtNo() {
    this->currentStmtNo++;
    return this->currentStmtNo;
}

std::unique_ptr<Procedure> Parser::procedure() {
    // 'procedure' proc_name '{' stmtLst '}'
    this->consume(TokenType::PROCEDURE, "Expect procedure in source file.");
    this->consume(TokenType::NAME, "Expect procedure name after procedure declaration.");
    auto procName = this->previous().getLexeme();
    this->consume(TokenType::LEFT_BRACE, "Expect '{' after procedure name.");
    auto body = this->stmtList();
    this->consume(TokenType::RIGHT_BRACE, "Expect '}' after procedure body.");
    return std::make_unique<Procedure>(procName, std::move(body));
}

std::unique_ptr<StmtList> Parser::stmtList() {
    StmtList stmts = std::vector<std::unique_ptr<Stmt>>();
    do {
        stmts.push_back(this->stmt());
    } while (!this->check(TokenType::RIGHT_BRACE) && !this->isAtEnd());
    return std::make_unique<StmtList>(std::move(stmts));
}

std::unique_ptr<Stmt> Parser::stmt() {
    if (this->match({ TokenType::READ })) {
        return this->read();
    }

    if (this->match({ TokenType::PRINT })) {
        return this->print();
    }

    if (this->match({ TokenType::CALL })) {
        return this->call();
    }

    if (this->match({ TokenType::WHILE })) {
        return this->loop();
    }

    if (this->match({ TokenType::IF })) {
        return this->cond();
    }

    return this->assign();
}

std::unique_ptr<Stmt> Parser::read() {
    this->consume(TokenType::NAME, "Expect variable name after 'read'.");
    auto variable = std::make_unique<Variable>(this->previous().getLexeme());
    this->consume(TokenType::SEMICOLON, "Expect ';' at the end of 'read' statement.");
    return std::make_unique<Read>(this->nextStmtNo(), std::move(variable));
}

std::unique_ptr<Stmt> Parser::print() {
    this->consume(TokenType::NAME, "Expect variable name after 'print'.");
    auto variable = std::make_unique<Variable>(this->previous().getLexeme());
    this->consume(TokenType::SEMICOLON, "Expect ';' at the end of 'print' statement.");
    return std::make_unique<Print>(this->nextStmtNo(), std::move(variable));
}

std::unique_ptr<Stmt> Parser::call() {
    this->consume(TokenType::NAME, "Expect procedure name after 'call'.");
    auto procName = this->previous().getLexeme();
    this->consume(TokenType::SEMICOLON, "Expect ';' at the end of 'call' statement.");
    return std::make_unique<Call>(this->nextStmtNo(), procName);
}

std::unique_ptr<Stmt> Parser::loop() {
    this->consume(TokenType::LEFT_PAREN, "Expect '(' before conditional expression.");
    auto condition = this->condExpr();
    this->consume(TokenType::RIGHT_PAREN, "Expect ')' after conditional expression.");

    this->consume(TokenType::LEFT_BRACE, "Expect '{' before loop body.");
    auto body = this->stmtList();
    this->consume(TokenType::RIGHT_BRACE, "Expect '}' after loop body.");

    return std::make_unique<While>(this->nextStmtNo(), std::move(condition), std::move(body));
}

std::unique_ptr<Stmt> Parser::cond() {
    this->consume(TokenType::LEFT_PAREN, "Expect '(' before conditional expression.");
    auto condition = this->condExpr();
    this->consume(TokenType::RIGHT_PAREN, "Expect ')' after conditional expression.");

    this->consume(TokenType::THEN, "Expect 'then' in 'if' statement.");
    this->consume(TokenType::LEFT_BRACE, "Expect '{' after 'then'.");
    auto thenBranch = this->stmtList();
    this->consume(TokenType::RIGHT_BRACE, "Expect '}' at the end of 'then' branch.");

    this->consume(TokenType::ELSE, "Expect 'else' in 'if' statement.");
    this->consume(TokenType::LEFT_BRACE, "Expect '{' after 'else'.");
    auto elseBranch = this->stmtList();
    this->consume(TokenType::RIGHT_BRACE, "Expect '}' at the end of 'else' branch.");

    return std::make_unique<If>(this->nextStmtNo(), std::move(condition), std::move(thenBranch), std::move(elseBranch));
}

std::unique_ptr<Stmt> Parser::assign() {
    this->consume(TokenType::NAME, "Expect name for assignment.");
    auto variable = std::make_unique<Variable>(this->previous().getLexeme());
    this->consume(TokenType::ASSIGN, "Expect '=' after variable name.");
    auto value = this->expr();
    this->consume(TokenType::SEMICOLON, "Expect ';' at the end of assignment statement.");
    return std::make_unique<Assign>(this->nextStmtNo(), std::move(variable), std::move(value));
}

std::unique_ptr<Expr> Parser::condExpr() {
    // '(' cond_expr ')' ('&&' | '||') '(' cond_expr ')' | '!' '(' cond_expr ')' | rel_expr
    if (this->match({ TokenType::LEFT_PAREN })) {
        auto left = this->condExpr();
        this->consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");

        if (this->match({ TokenType::AND, TokenType::OR })) {
            auto op = std::make_unique<Token>(this->previous());

            this->consume(TokenType::LEFT_PAREN, "Expect '(' after logical operator.");
            auto right = this->condExpr();
            this->consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");

            return std::make_unique<Binary>(std::move(left), std::move(op), std::move(right));
        }
        // TODO: Unify handling of syntax errors.
        throw "Expect '&&' or '||' after expression.";
    }

    if (this->match({ TokenType::BANG })) {
        auto op = std::make_unique<Token>(this->previous());

        this->consume(TokenType::LEFT_PAREN, "Expect '(' after 'not' operator.");
        auto right = this->condExpr();
        this->consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");

        return std::make_unique<Unary>(std::move(op), std::move(right));
    }

    return this->relExpr();
}

std::unique_ptr<Expr> Parser::relExpr() {
    // rel_factor ('>' | '>=' | '<' | '<=' | '==' | '!=') rel_factor
    auto left = this->relFactor();
    if (this->match({ TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESSER,
                      TokenType::LESSER_EQUAL, TokenType::EQUAL_EQUAL, TokenType::BANG_EQUAL })) {
        auto op = std::make_unique<Token>(this->previous());
        auto right = this->relFactor();
        return std::make_unique<Binary>(std::move(left), std::move(op), std::move(right));
    }

    // TODO: Unify handling of syntax errors.
    throw "Expect '>', '>=', '<', '<=', '==', or '!=' after expression.";
}

std::unique_ptr<Expr> Parser::relFactor() {
    // var_name | const_value | expr
    if (this->match({ TokenType::NAME })) {
        return std::make_unique<Variable>(this->previous().getLexeme());
    }

    if (this->match({ TokenType::INTEGER })) {
        return std::make_unique<Literal>(std::stoi(this->previous().getLexeme()));
    }

    return this->expr();
}

std::unique_ptr<Expr> Parser::expr() {
    // term expr_tail
    return this->exprTail(this->term());
}

std::unique_ptr<Expr> Parser::exprTail(std::unique_ptr<Expr> left) {
    // ('+' | '-') term expr_tail | empty
    if (this->match({ TokenType::ADD, TokenType::SUBTRACT })) {
        auto op = std::make_unique<Token>(this->previous());
        auto right = this->term();
        return this->exprTail(std::make_unique<Binary>(std::move(left), std::move(op), std::move(right)));
    }
    return left;
}

std::unique_ptr<Expr> Parser::term() {
    // factor term_tail
    return this->termTail(this->factor());
}

std::unique_ptr<Expr> Parser::termTail(std::unique_ptr<Expr> left) {
    // ('*' | '/' | '%') factor term_tail | empty
    if (this->match({ TokenType::MULTIPLY, TokenType::DIVIDE, TokenType::MOD })) {
        auto op = std::make_unique<Token>(this->previous());
        auto right = this->factor();
        return this->termTail(std::make_unique<Binary>(std::move(left), std::move(op), std::move(right)));
    }
    return left;
}

std::unique_ptr<Expr> Parser::factor() {
    // var_name | const_value | '(' expr ')'
    if (this->match({ TokenType::NAME })) {
        return std::make_unique<Variable>(this->previous().getLexeme());
    }

    if (this->match({ TokenType::INTEGER })) {
        return std::make_unique<Literal>(std::stoi(this->previous().getLexeme()));
    }

    this->consume(TokenType::LEFT_PAREN, "Expect '(' before expression.");
    auto expr = this->expr();
    this->consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
    return expr;
}