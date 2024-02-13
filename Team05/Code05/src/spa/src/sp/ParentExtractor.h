//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_PARENTEXTRACTOR_H
#define SPA_PARENTEXTRACTOR_H

#include "RelationExtractor.h"
#include "Stmt.h"

class ParentExtractor: public RelationExtractor {
public:
    // Constructor
    explicit ParentExtractor(PopulatePKB& pkb) : RelationExtractor(pkb) {}
    // Statement Methods
    void visitReadStmt(const Read& stmt) override;
    void visitPrintStmt(const Print& stmt) override;
    void visitCallStmt(const Call& stmt) override;
    void visitWhileStmt(const While& stmt) override;
    void visitIfStmt(const If& stmt) override;
    void visitAssignStmt(const Assign& stmt) override;
    // Expression Methods
    void visitBinaryExpr(const Binary& expr) override;
    void visitVariableExpr(const Variable& expr) override;
    void visitLiteralExpr(const Literal& expr) override;
    void visitUnaryExpr(const Unary& expr) override;
};

#endif //SPA_PARENTEXTRACTOR_H
