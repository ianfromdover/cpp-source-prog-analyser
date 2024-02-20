//
// Created by Chua Bing Quan on 11/2/24.
//

#ifndef SPA_EXPR_H
#define SPA_EXPR_H

#include <vector>
#include <variant>
#include "Token.h"
#include "RelationExtractor.h"

class Expr;
class Binary;
class Variable;
class Literal;
class Unary;

class Expr {
public:
    virtual ~Expr() = default;
    virtual void accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
};

class Binary : public Expr {
private:
    std::unique_ptr<Expr> left;
    std::unique_ptr<Token> op;
    std::unique_ptr<Expr> right;

public:
    Binary(std::unique_ptr<Expr> left, std::unique_ptr<Token> op, std::unique_ptr<Expr> right)
        : left(std::move(left)), op(std::move(op)), right(std::move(right)) {}
    void accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::unique_ptr<Expr> const& getLeft() const;
    [[nodiscard]] std::unique_ptr<Token> const& getOP() const;
    [[nodiscard]] std::unique_ptr<Expr> const& getRight() const;
};

class Variable : public Expr {
private:
    std::string name;

public:
    explicit Variable(std::string name) : name(std::move(name)) {}
    void accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::string getName() const;
};

class Literal : public Expr {
private:
    int value;

public:
    explicit Literal(int value) : value(value) {}
    void accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] int getValue() const;
};

class Unary : public Expr {
private:
    std::unique_ptr<Token> op;
    std::unique_ptr<Expr> right;

public:
    Unary(std::unique_ptr<Token> op, std::unique_ptr<Expr> right) : op(std::move(op)), right(std::move(right)) {}
    void accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::unique_ptr<Token> const& getOP() const;
    [[nodiscard]] std::unique_ptr<Expr> const& getRight() const;
};

#endif //SPA_EXPR_H
