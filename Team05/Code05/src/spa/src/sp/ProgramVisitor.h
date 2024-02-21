//
// Created by Chua Bing Quan on 21/2/24.
//

#ifndef SPA_PROGRAMVISITOR_H
#define SPA_PROGRAMVISITOR_H

#include "Accumulator.h"

class Procedure;
class Read;
class Print;
class Call;
class While;
class If;
class Assign;
class Expr;
class Binary;
class Variable;
class Literal;
class Unary;

class ProgramVisitor {
public:
    // Top-level Methods.
    virtual void visitProcedure(const Procedure&) = 0;
    // Statement Methods
    virtual void visitReadStmt(const Read&, shared_ptr<Accumulator>&) = 0;
    virtual void visitPrintStmt(const Print&, shared_ptr<Accumulator>&) = 0;
    virtual void visitCallStmt(const Call&, shared_ptr<Accumulator>&)= 0;
    virtual void visitWhileStmt(const While&, shared_ptr<Accumulator>&) = 0;
    virtual void visitIfStmt(const If&, shared_ptr<Accumulator>&) = 0;
    virtual void visitAssignStmt(const Assign&, shared_ptr<Accumulator>&) = 0;
    // Expression Methods
    virtual void visitBinaryExpr(const Binary&, shared_ptr<Accumulator>&) = 0;
    virtual void visitVariableExpr(const Variable&, shared_ptr<Accumulator>&) = 0;
    virtual void visitLiteralExpr(const Literal&, shared_ptr<Accumulator>&) = 0;
    virtual void visitUnaryExpr(const Unary&, shared_ptr<Accumulator>&) = 0;
};


#endif //SPA_PROGRAMVISITOR_H
