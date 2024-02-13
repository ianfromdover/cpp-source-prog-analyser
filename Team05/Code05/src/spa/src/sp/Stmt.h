//
// Created by Chua Bing Quan on 12/2/24.
//

#ifndef SPA_STMT_H
#define SPA_STMT_H

#include <memory>
#include <vector>
#include "Expr.h"
#include "RelationExtractor.h"
#include "utilSpa/SpaTypes.h"

class Procedure;
class Read;
class Print;
class Call;
class While;
class If;
class Assign;

//using StmtNo = unsigned long;

class Stmt {
private:
    StmtNo stmtNo;
public:
    explicit Stmt(StmtNo stmtNo) : stmtNo(stmtNo) {}
    virtual ~Stmt() = default;
    virtual void accept(RelationExtractor& extractor) = 0;
    virtual std::string toString() const = 0;
    std::string prefixStmtNo(std::string text) const;
    [[nodiscard]] StmtNo getStmtNo() const;
};

using Program = std::unique_ptr<std::vector<std::unique_ptr<Procedure>>>;
using StmtList = std::vector<std::unique_ptr<Stmt>>;

class Procedure {
private:
    std::string name;
    std::unique_ptr<StmtList> body;

public:
    Procedure(std::string name, std::unique_ptr<StmtList> body) : name(std::move(name)), body(std::move(body)) {}
    void accept(RelationExtractor& extractor);
    std::string toString() const;
};

class Read : public Stmt {
private:
    std::unique_ptr<Variable> variable;

public:
    Read(StmtNo stmtNo, std::unique_ptr<Variable> variable) : Stmt(stmtNo), variable(std::move(variable)) {}
    void accept(RelationExtractor& extractor) override;
    std::string toString() const override;
};

class Print : public Stmt {
private:
    std::unique_ptr<Variable> variable;

public:
    Print(StmtNo stmtNo, std::unique_ptr<Variable> variable) : Stmt(stmtNo), variable(std::move(variable)) {}
    void accept(RelationExtractor& extractor) override;
    std::string toString() const override;
};

class Call : public Stmt {
private:
    std::string procName;

public:
    Call(StmtNo stmtNo, std::string procName) : Stmt(stmtNo), procName(std::move(procName)) {}
    void accept(RelationExtractor& extractor) override;
    std::string toString() const override;
};

class While : public Stmt {
private:
    std::unique_ptr<Expr> condition;
    std::unique_ptr<StmtList> body;

public:
    While(StmtNo stmtNo, std::unique_ptr<Expr> condition, std::unique_ptr<StmtList> body)
        : Stmt(stmtNo), condition(std::move(condition)), body(std::move(body)) {}
    void accept(RelationExtractor& extractor) override;
    std::string toString() const override;
    std::unique_ptr<StmtList> const& getBody() const;
};

class If : public Stmt {
private:
    std::unique_ptr<Expr> condition;
    std::unique_ptr<StmtList> thenBranch;
    std::unique_ptr<StmtList> elseBranch;

public:
    If(StmtNo stmtNo, std::unique_ptr<Expr> condition,
       std::unique_ptr<StmtList> thenBranch, std::unique_ptr<StmtList> elseBranch)
            : Stmt(stmtNo),
              condition(std::move(condition)),
              thenBranch(std::move(thenBranch)),
              elseBranch(std::move(elseBranch)) {}
    void accept(RelationExtractor& extractor) override;
    std::string toString() const override;
    std::unique_ptr<StmtList> const& getThenBranch() const;
    std::unique_ptr<StmtList> const& getElseBranch() const;
};

class Assign : public Stmt {
private:
    std::unique_ptr<Expr> variable;
    std::unique_ptr<Expr> value;

public:
    Assign(StmtNo stmtNo, std::unique_ptr<Expr> variable, std::unique_ptr<Expr> value)
        : Stmt(stmtNo), variable(std::move(variable)), value(std::move(value)) {}
    void accept(RelationExtractor& extractor) override;
    std::string toString() const override;
};

#endif //SPA_STMT_H
