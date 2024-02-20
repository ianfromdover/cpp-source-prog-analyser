//
// Created by Chua Bing Quan on 11/2/24.
//

#include <string>
#include "Expr.h"

void Binary::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitBinaryExpr(*this, parentInfo);
}

void Variable::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitVariableExpr(*this, parentInfo);
}

void Literal::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitLiteralExpr(*this, parentInfo);
}

void Unary::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitUnaryExpr(*this, parentInfo);
}

std::string Binary::toString() const {
    return "Binary: {\n op: " + this->op->getLexeme() + ",\n left: " + this->left->toString() + ",\n right: "
        + this->right->toString() + "\n}";
}

std::string Variable::toString() const {
    return "Variable: { name: " + this->name + " }";
}

std::string Literal::toString() const {
    return "Literal: { value: " + std::to_string(this->value) + " }";
}

std::string Unary::toString() const {
    return "Unary: {\n op: " + this->op->getLexeme() + ",\n right: " + this->right->toString() + "\n}";
}

std::unique_ptr<Expr> const& Binary::getLeft() const {
    return this->left;
}

std::unique_ptr<Token> const& Binary::getOP() const {
    return this->op;
}

std::unique_ptr<Expr> const& Binary::getRight() const {
    return this->right;
}

std::string Variable::getName() const {
    return name;
}

int Literal::getValue() const {
    return value;
}

std::unique_ptr<Token> const& Unary::getOP() const {
    return this->op;
}

std::unique_ptr<Expr> const& Unary::getRight() const {
    return this->right;
}