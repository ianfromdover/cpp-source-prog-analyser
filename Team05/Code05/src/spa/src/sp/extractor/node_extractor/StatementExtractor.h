//
// Created by sjh_9 on 17/2/2024.
//

#ifndef SPA_STATEMENTEXTRACTOR_H
#define SPA_STATEMENTEXTRACTOR_H

#include <utility>

#include "sp/extractor/RelationExtractor.h"

class StatementExtractor: public RelationExtractor {
public:
    // Constructor
    explicit StatementExtractor(shared_ptr<BasePkbPopulator> pkb) : RelationExtractor(std::move(pkb)) {}
    // Statement Methods
    void visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) override;
    // Expression Methods
};



#endif //SPA_STATEMENTEXTRACTOR_H
