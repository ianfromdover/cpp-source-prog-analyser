//
// Created by Chua Bing Quan on 11/2/24.
//

#include "Parser.h"

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

Token Parser::advance() {
    if (!this->isAtEnd()) {
        this->current++;
    }
    return this->previous();
}

bool Parser::isAtEnd() {
    return this->peek().getType().getInfo() == TokenType::END_OF_FILE;
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
    this->termTail(this->factor());
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