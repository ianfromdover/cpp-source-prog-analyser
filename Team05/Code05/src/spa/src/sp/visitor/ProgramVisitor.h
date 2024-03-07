//
// Created by Chua Bing Quan on 21/2/24.
//

#ifndef SPA_PROGRAMVISITOR_H
#define SPA_PROGRAMVISITOR_H

#include "sp/extractor/Accumulator.h"

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
class Stmt;

class ProgramVisitor {
protected:
    virtual void visitStmtList(const shared_ptr<vector<shared_ptr<Stmt>>> &stmts, shared_ptr<Accumulator>& info);
public:
    // Top-level Methods.
    virtual void visitProcedure(const Procedure&) = 0;
    // Statement Methods
    virtual void visitReadStmt(const Read&, std::shared_ptr<Accumulator>&);
    virtual void visitPrintStmt(const Print&, std::shared_ptr<Accumulator>&);
    virtual void visitCallStmt(const Call&, std::shared_ptr<Accumulator>&);
    virtual void visitWhileStmt(const While&, std::shared_ptr<Accumulator>&);
    virtual void visitIfStmt(const If&, std::shared_ptr<Accumulator>&);
    virtual void visitAssignStmt(const Assign&, std::shared_ptr<Accumulator>&);
    // Expression Methods
    virtual void visitBinaryExpr(const Binary&, std::shared_ptr<Accumulator>&);
    virtual void visitVariableExpr(const Variable&, std::shared_ptr<Accumulator>&);
    virtual void visitLiteralExpr(const Literal&, std::shared_ptr<Accumulator>&);
    virtual void visitUnaryExpr(const Unary&, std::shared_ptr<Accumulator>&);
};


#endif //SPA_PROGRAMVISITOR_H
