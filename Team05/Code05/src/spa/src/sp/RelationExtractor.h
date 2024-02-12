//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_RELATIONEXTRACTOR_H
#define SPA_RELATIONEXTRACTOR_H
#include <iostream>
#include <vector>
#include "Stmt.h"

class RelationExtractor {
private:

public:
    virtual ~RelationExtractor() = default;
    // Statement Methods
    virtual void visitReadStmt(Read& stmt) = 0;
    virtual void visitPrintStmt(Print& stmt) = 0;
    virtual void visitCallStmt(Call& stmt)= 0;
    virtual void visitWhileStmt(While& stmt) = 0;
    virtual void visitIfStmt(If& stmt) = 0;
    virtual void visitAssignStmt(Assign& stmt) = 0;
    // Expression Methods
    virtual void visitBinaryExpr(Binary& expr) = 0;
    virtual void visitVariableExpr(Variable& expr) = 0;
    virtual void visitLiteralExpr(Literal& expr) = 0;
    virtual void visitUnaryExpr(Unary& expr) = 0;

};


#endif //SPA_RELATIONEXTRACTOR_H
