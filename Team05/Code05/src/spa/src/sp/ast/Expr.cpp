//
// Created by Chua Bing Quan on 11/2/24.
//

#include <string>
#include "Expr.h"

void Binary::accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) {
    visitor.visitBinaryExpr(*this, parentInfo);
}

void Variable::accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) {
    visitor.visitVariableExpr(*this, parentInfo);
}

void Literal::accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) {
    visitor.visitLiteralExpr(*this, parentInfo);
}

void Unary::accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) {
    visitor.visitUnaryExpr(*this, parentInfo);
}

std::string Binary::toString() const {
    return "( " + this->left->toString() + " " + this->op->getLexeme() + " " + this->right->toString() + " )";
}

std::string Variable::toString() const {
    return this->name;
}

std::string Literal::toString() const {
    return std::to_string(this->value);
}

std::string Unary::toString() const {
    return "( " + this->op->getLexeme() + " " + this->right->toString() + " )";
}

std::shared_ptr<Expr> const& Binary::getLeft() const {
    return this->left;
}

std::shared_ptr<Token> const& Binary::getOP() const {
    return this->op;
}

std::shared_ptr<Expr> const& Binary::getRight() const {
    return this->right;
}

std::string Variable::getName() const {
    return name;
}

int Literal::getValue() const {
    return value;
}

std::shared_ptr<Token> const& Unary::getOP() const {
    return this->op;
}

std::shared_ptr<Expr> const& Unary::getRight() const {
    return this->right;
}