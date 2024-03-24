//
// Created by sjh_9 on 17/2/2024.
//

#ifndef SPA_IFEXTRACTOR_H
#define SPA_IFEXTRACTOR_H

#include <utility>

#include "sp/extractor/RelationExtractor.h"

class IfExtractor: public RelationExtractor {
public:
    // Constructor
    explicit IfExtractor(shared_ptr<BasePkbPopulator> pkb) : RelationExtractor(std::move(pkb)) {}
    // Statement Methods
    void visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) override;
    // Expression Methods
    void visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) override;
    void visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) override;
    void visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) override;
};


#endif //SPA_IFEXTRACTOR_H
