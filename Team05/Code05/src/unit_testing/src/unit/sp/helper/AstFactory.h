//
// Created by Chua Bing Quan on 21/3/24.
//

#ifndef SPA_ASTFACTORY_H
#define SPA_ASTFACTORY_H

#include <memory>
#include "sp/ast/Expr.h"
#include "sp/ast/Stmt.h"
#include "sp/ast/Program.h"

class AstFactory {
public:
    // Helper creators
    static std::shared_ptr<Token> createTokens(TokenType tokenType, const std::string& lexeme);
    // Top-level creators
    static std::shared_ptr<Program> createProgram(const Procedures& procedures);
    static std::shared_ptr<Procedure> createProcedure(const std::string& name, std::shared_ptr<StmtList> body);
    // Expression creators
    static std::shared_ptr<Binary> createBinary(std::shared_ptr<Expr> left, std::shared_ptr<Token> op, std::shared_ptr<Expr> right);
    static std::shared_ptr<Variable> createVariable(const std::string& name);
    static std::shared_ptr<Literal> createLiteral(int value);
    static std::shared_ptr<Unary> createUnary(std::shared_ptr<Token> op, std::shared_ptr<Expr> right);
    // Statement creators
    static std::shared_ptr<Read> createRead(StmtNo stmtNo, std::shared_ptr<Variable> variable);
    static std::shared_ptr<Print> createPrint(StmtNo stmtNo, std::shared_ptr<Variable> variable);
    static std::shared_ptr<Call> createCall(StmtNo stmtNo, const std::string& procName);
    static std::shared_ptr<While> createWhile(StmtNo stmtNo, std::shared_ptr<Expr> condition, std::shared_ptr<StmtList> body);
    static std::shared_ptr<If> createIf(StmtNo stmtNo, std::shared_ptr<Expr> condition, std::shared_ptr<StmtList> thenBranch, std::shared_ptr<StmtList> elseBranch);
    static std::shared_ptr<Assign> createAssign(StmtNo stmtNo, std::shared_ptr<Variable> variable, std::shared_ptr<Expr> value);
    static std::shared_ptr<StmtList> createStmtList(std::vector<std::shared_ptr<Stmt>> stmts);
};

#endif //SPA_ASTFACTORY_H
