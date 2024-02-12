//
// Created by Chua Bing Quan on 11/2/24.
//

#ifndef SPA_EXPR_H
#define SPA_EXPR_H


#include "Token.h"

class Expr;
class Binary;
class Variable;
class Literal;
class Unary;

class Expr {
public:
    virtual ~Expr() = default;
};

class Binary : public Expr {
private:
    std::unique_ptr<Expr> left;
    std::unique_ptr<Token> op;
    std::unique_ptr<Expr> right;

public:
    Binary(std::unique_ptr<Expr> left, std::unique_ptr<Token> op, std::unique_ptr<Expr> right)
        : left(std::move(left)), op(std::move(op)), right(std::move(right)) {}
};

class Variable : public Expr {
private:
    std::string name;

public:
    explicit Variable(std::string name) : name(std::move(name)) {}
};

class Literal : public Expr {
private:
    int value;

public:
    Literal(int value) : value(value) {}
};

class Unary : public Expr {
private:
    std::unique_ptr<Token> op;
    std::unique_ptr<Expr> right;

public:
    Unary(std::unique_ptr<Token> op, std::unique_ptr<Expr> right) : op(std::move(op)), right(std::move(right)) {}
};

#endif //SPA_EXPR_H
