//
// Created by sjh_9 on 17/2/2024.
//

#ifndef SPA_PROCEDURE_H
#define SPA_PROCEDURE_H

#include "RelationExtractor.h"
#include "Stmt.h"

class VariableExtractor: public RelationExtractor {
public:
    // Constructor
    explicit VariableExtractor(PopulatePKB& pkb) : RelationExtractor(pkb) {}
    // Statement Methods
    void visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) override;
    // Expression Methods
    void visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) override;
    void visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) override;
    void visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) override;
    void visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) override;
};

#endif //SPA_PROCEDURE_H
