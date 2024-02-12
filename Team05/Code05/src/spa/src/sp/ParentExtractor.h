//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_PARENTEXTRACTOR_H
#define SPA_PARENTEXTRACTOR_H

#include "RelationExtractor.h"

class ParentExtractor: public RelationExtractor {
public:
    ParentExtractor() = default;
    // Statement Methods
    void visitReadStmt(Read& stmt) override;
    void visitPrintStmt(Print& stmt) override;
    void visitCallStmt(Call& stmt) override;
    void visitWhileStmt(While& stmt) override;
    void visitIfStmt(If& stmt) override;
    void visitAssignStmt(Assign& stmt) override;
    // Expression Methods
    void visitBinaryExpr(Binary& expr) override;
    void visitVariableExpr(Variable& expr) override;
    void visitLiteralExpr(Literal& expr) override;
    void visitUnaryExpr(Unary& expr) override;
};

#endif //SPA_PARENTEXTRACTOR_H
