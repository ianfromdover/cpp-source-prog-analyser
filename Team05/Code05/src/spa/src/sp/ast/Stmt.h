//
// Created by Chua Bing Quan on 12/2/24.
//

#ifndef SPA_STMT_H
#define SPA_STMT_H

#include <vector>
#include "Expr.h"
#include "common/SpaTypes.h"

class Procedure;
class Read;
class Print;
class Call;
class While;
class If;
class Assign;

class Stmt {
private:
    StmtNo stmtNo;
public:
    explicit Stmt(StmtNo stmtNo) : stmtNo(stmtNo) {}
    virtual ~Stmt() = default;
    virtual void accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) = 0;
    [[nodiscard]] virtual std::string toString() const = 0;
    [[nodiscard]] std::string prefixStmtNo(std::string text) const;
    [[nodiscard]] StmtNo getStmtNo() const;
};

using StmtList = std::vector<std::shared_ptr<Stmt>>;

class Procedure {
private:
    std::string name;
    std::shared_ptr<StmtList> body;

public:
    Procedure(std::string name, std::shared_ptr<StmtList> body) : name(std::move(name)), body(std::move(body)) {}
    void accept(ProgramVisitor& visitor) const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::shared_ptr<StmtList> const& getBody() const;
    [[nodiscard]] std::string getName() const;
};

class Read : public Stmt {
private:
    std::shared_ptr<Variable> variable;

public:
    Read(StmtNo stmtNo, std::shared_ptr<Variable> variable) : Stmt(stmtNo), variable(std::move(variable)) {}
    void accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::shared_ptr<Variable> const& getVariable() const;
};

class Print : public Stmt {
private:
    std::shared_ptr<Variable> variable;

public:
    Print(StmtNo stmtNo, std::shared_ptr<Variable> variable) : Stmt(stmtNo), variable(std::move(variable)) {}
    void accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::shared_ptr<Variable> const& getVariable() const;
};

class Call : public Stmt {
private:
    std::string procName;

public:
    Call(StmtNo stmtNo, std::string procName) : Stmt(stmtNo), procName(std::move(procName)) {}
    void accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::string getProcName() const;
};

class While : public Stmt {
private:
    std::shared_ptr<Expr> condition;
    std::shared_ptr<StmtList> body;

public:
    While(StmtNo stmtNo, std::shared_ptr<Expr> condition, std::shared_ptr<StmtList> body)
        : Stmt(stmtNo), condition(std::move(condition)), body(std::move(body)) {}
    void accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::shared_ptr<Expr> const& getCondition() const;
    [[nodiscard]] std::shared_ptr<StmtList> const& getBody() const;
};

class If : public Stmt {
private:
    std::shared_ptr<Expr> condition;
    std::shared_ptr<StmtList> thenBranch;
    std::shared_ptr<StmtList> elseBranch;

public:
    If(StmtNo stmtNo, std::shared_ptr<Expr> condition,
       std::shared_ptr<StmtList> thenBranch, std::shared_ptr<StmtList> elseBranch)
            : Stmt(stmtNo),
              condition(std::move(condition)),
              thenBranch(std::move(thenBranch)),
              elseBranch(std::move(elseBranch)) {}
    void accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::shared_ptr<Expr> const& getCondition() const;
    [[nodiscard]] std::shared_ptr<StmtList> const& getThenBranch() const;
    [[nodiscard]] std::shared_ptr<StmtList> const& getElseBranch() const;
};

class Assign : public Stmt {
private:
    std::shared_ptr<Variable> variable;
    std::shared_ptr<Expr> value;

public:
    Assign(StmtNo stmtNo, std::shared_ptr<Variable> variable, std::shared_ptr<Expr> value)
        : Stmt(stmtNo), variable(std::move(variable)), value(std::move(value)) {}
    void accept(ProgramVisitor& visitor, shared_ptr<Accumulator>& parentInfo) override;
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] std::shared_ptr<Variable> const& getVariable() const;
    [[nodiscard]] std::shared_ptr<Expr> const& getValue() const;
};

#endif //SPA_STMT_H
