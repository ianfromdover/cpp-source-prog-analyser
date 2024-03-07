//
// Created by sjh_9 on 18/2/2024.
//

#ifndef SPA_CONSTANTEXTRACTOR_H
#define SPA_CONSTANTEXTRACTOR_H

#include <utility>

#include "sp/extractor/RelationExtractor.h"

class ConstantExtractor: public RelationExtractor {
public:
    // Constructor
    explicit ConstantExtractor(shared_ptr<BasePKBPopulator> pkb) : RelationExtractor(std::move(pkb)) {}
    // Statement Methods
    void visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) override;
    // Expression Methods
    void visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) override;
    void visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) override;
    void visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) override;
};


#endif //SPA_CONSTANTEXTRACTOR_H
