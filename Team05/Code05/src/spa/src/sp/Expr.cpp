//
// Created by Chua Bing Quan on 11/2/24.
//

#include "Expr.h"

void Binary::accept(RelationExtractor& extractor) {
    extractor.visitBinaryExpr(*this);
}

void Variable::accept(RelationExtractor& extractor) {
    extractor.visitVariableExpr(*this);
}

void Literal::accept(RelationExtractor& extractor) {
    extractor.visitLiteralExpr(*this);
}

void Unary::accept(RelationExtractor& extractor) {
    extractor.visitUnaryExpr(*this);
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