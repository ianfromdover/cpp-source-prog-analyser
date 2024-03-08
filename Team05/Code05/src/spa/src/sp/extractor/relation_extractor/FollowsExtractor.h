//
// Created by sjh_9 on 16/2/2024.
//

#ifndef SPA_FOLLOWSEXTRACTOR_H
#define SPA_FOLLOWSEXTRACTOR_H

#include <utility>

#include "sp/extractor/RelationExtractor.h"

class FollowsExtractor: public RelationExtractor {
public:
    // Constructor
    explicit FollowsExtractor(shared_ptr<BasePKBPopulator> pkb) : RelationExtractor(std::move(pkb)) {}
    // Top-level Methods
    void visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>&) override;
    // Statement Methods
    void visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& prevStmtInfo) override;
    void visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& prevStmtInfo) override;
    void visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& prevStmtInfo) override;
    void visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& prevStmtInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<Accumulator>& prevStmtInfo) override;
    void visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& prevStmtInfo) override;
    void visitStmtList(const shared_ptr<vector<shared_ptr<Stmt>>> &stmts, shared_ptr<Accumulator> &info) override;
};


#endif //SPA_FOLLOWSEXTRACTOR_H
