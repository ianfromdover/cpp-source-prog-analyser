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
    virtual void visitReadStmt(const Read&, std::shared_ptr<Accumulator>&) = 0;
    virtual void visitPrintStmt(const Print&, std::shared_ptr<Accumulator>&) = 0;
    virtual void visitCallStmt(const Call&, std::shared_ptr<Accumulator>&)= 0;
    virtual void visitWhileStmt(const While&, std::shared_ptr<Accumulator>&) = 0;
    virtual void visitIfStmt(const If&, std::shared_ptr<Accumulator>&) = 0;
    virtual void visitAssignStmt(const Assign&, std::shared_ptr<Accumulator>&) = 0;
    // Expression Methods
    virtual void visitBinaryExpr(const Binary&, std::shared_ptr<Accumulator>&) = 0;
    virtual void visitVariableExpr(const Variable&, std::shared_ptr<Accumulator>&) = 0;
    virtual void visitLiteralExpr(const Literal&, std::shared_ptr<Accumulator>&) = 0;
    virtual void visitUnaryExpr(const Unary&, std::shared_ptr<Accumulator>&) = 0;
};


#endif //SPA_PROGRAMVISITOR_H
