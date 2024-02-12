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

class Stmt {
public:
    int StmtNo;
    virtual ~Stmt() = default;
    virtual int getStmtNo();
};

using Program = std::unique_ptr<std::vector<std::unique_ptr<Procedure>>>;
using StmtList = std::vector<std::unique_ptr<Stmt>>;

class Procedure {
private:
    std::string name;
    std::unique_ptr<StmtList> body;

public:
    Procedure(std::string name, std::unique_ptr<StmtList> body) : name(std::move(name)), body(std::move(body)) {}
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
    std::unique_ptr<StmtList> body;

public:
    While(std::unique_ptr<Expr> condition, std::unique_ptr<StmtList> body) :
        condition(std::move(condition)), body(std::move(body)) {}
        std::unique_ptr<StmtList> getBody();
};

class If : public Stmt {
private:
    std::unique_ptr<Expr> condition;
    std::unique_ptr<StmtList> thenBranch;
    std::unique_ptr<StmtList> elseBranch;

public:
    If(std::unique_ptr<Expr> condition, std::unique_ptr<StmtList> thenBranch, std::unique_ptr<StmtList> elseBranch)
        : condition(std::move(condition)), thenBranch(std::move(thenBranch)), elseBranch(std::move(elseBranch)) {}
    std::unique_ptr<StmtList> getThenBranch();
    std::unique_ptr<StmtList> getElseBranch();
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
