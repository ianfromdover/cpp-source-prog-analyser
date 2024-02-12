//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_RELATIONEXTRACTOR_H
#define SPA_RELATIONEXTRACTOR_H
#include <iostream>
#include <vector>
#include "Stmt.h"

// TODO: THIS IS A STUB, REMOVE DURING INTEGRATION WITH PKB.
class PopulatePKB {};

class RelationExtractor {
private:
    PopulatePKB pkb;
public:
    RelationExtractor(PopulatePKB pkb) : pkb(pkb) {}
    virtual ~RelationExtractor() = default;
    // Statement Methods
    virtual void visitReadStmt(const Read& stmt) = 0;
    virtual void visitPrintStmt(const Print& stmt) = 0;
    virtual void visitCallStmt(const Call& stmt)= 0;
    virtual void visitWhileStmt(const While& stmt) = 0;
    virtual void visitIfStmt(const If& stmt) = 0;
    virtual void visitAssignStmt(const Assign& stmt) = 0;
    // Expression Methods
    virtual void visitBinaryExpr(const Binary& expr) = 0;
    virtual void visitVariableExpr(const Variable& expr) = 0;
    virtual void visitLiteralExpr(const Literal& expr) = 0;
    virtual void visitUnaryExpr(const Unary& expr) = 0;

};


#endif //SPA_RELATIONEXTRACTOR_H
