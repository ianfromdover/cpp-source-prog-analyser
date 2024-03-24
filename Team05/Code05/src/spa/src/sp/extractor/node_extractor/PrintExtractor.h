//
// Created by sjh_9 on 17/2/2024.
//

#ifndef SPA_PRINTEXTRACTOR_H
#define SPA_PRINTEXTRACTOR_H

#include <utility>

#include "sp/extractor/RelationExtractor.h"

class PrintExtractor: public RelationExtractor {
public:
    // Constructor
    explicit PrintExtractor(shared_ptr<BasePkbPopulator> pkb) : RelationExtractor(std::move(pkb)) {}
    // Statement Methods
    void visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) override;
    // Expression Methods
    void visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) override;
};

#endif //SPA_PRINTEXTRACTOR_H
