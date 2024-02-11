//
// Created by Chua Bing Quan on 12/2/24.
//

#ifndef SPA_STMT_H
#define SPA_STMT_H

#include <memory>
#include <vector>
#include "Expr.h"

class Procedure;
class Read;
class Print;
class Call;
class While;
class If;
class Assign;

template <typename T>
class StmtVisitor {
public:
    virtual T visitReadStmt(const Read& stmt);
    virtual T visitPrintStmt(const Print& stmt);
    virtual T visitCallStmt(const Call& stmt);
    virtual T visitWhileStmt(const While& stmt);
    virtual T visitIfStmt(const If& stmt);
    virtual T visitAssignStmt(const Assign& stmt);
};

class Stmt {
    virtual ~Stmt() = default;
//    template <typename T>
//    T accept(Visitor<T> visitor);
};

using Program = std::unique_ptr<std::vector<std::unique_ptr<Procedure>>>;

class Procedure {
private:
    std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> stmtList;

public:
    Procedure(std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> stmtList) : stmtList(std::move(stmtList)) {}
};

class Read : public Stmt {
private:
    std::unique_ptr<Variable> variable;

public:
    Read(std::unique_ptr<Variable> variable) : variable(std::move(variable)) {}
};

class Print : public Stmt {
private:
    std::unique_ptr<Variable> variable;

public:
    Print(std::unique_ptr<Variable> variable) : variable(std::move(variable)) {}
};

class Call : public Stmt {
private:
    std::string procName;

public:
    Call(std::string procName) : procName(std::move(procName)) {}
};

class While : public Stmt {
private:
    std::unique_ptr<Expr> condition;
    std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> body;

public:
    While(std::unique_ptr<Expr> condition, std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> body) :
        condition(std::move(condition)), body(std::move(body)) {}
};

class If : public Stmt {
private:
    std::unique_ptr<Expr> condition;
    std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> then_branch;
    std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> else_branch;

public:
    If(std::unique_ptr<Expr> condition, std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> then_branch,
       std::unique_ptr<std::vector<std::unique_ptr<Stmt>>> else_branch) : condition(std::move(condition)),
       then_branch(std::move(then_branch)), else_branch(std::move(else_branch)) {}
};

class Assign : public Stmt {
private:
    std::unique_ptr<Expr> variable;
    std::unique_ptr<Expr> value;

public:
    Assign(std::unique_ptr<Expr> variable, std::unique_ptr<Expr> value)
        : variable(std::move(variable)), value(std::move(value)) {}
};

#endif //SPA_STMT_H
