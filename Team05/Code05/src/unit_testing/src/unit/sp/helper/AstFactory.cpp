//
// Created by sjh_9 on 21/2/2024.
//

// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/367b948e-5198-4955-ab4d-f81ff1b1f3c8

#include "AstFactory.h"

std::shared_ptr<Token> AstFactory::createTokens(TokenType tokenType, const std::string& lexeme) {
    return std::make_shared<Token>(tokenType, lexeme);
}

std::shared_ptr<Program> AstFactory::createProgram(const Procedures& procedures) {
    return std::make_shared<Program>(std::make_shared<Procedures>(procedures));
}

std::shared_ptr<Procedure> AstFactory::createProcedure(const std::string& name, std::shared_ptr<StmtList> body) {
    return std::make_shared<Procedure>(name, std::move(body));
}

std::shared_ptr<Binary> AstFactory::createBinary(std::shared_ptr<Expr> left, std::shared_ptr<Token> op,
                                                 std::shared_ptr<Expr> right) {
    return std::make_shared<Binary>(std::move(left), std::move(op), std::move(right));
}

std::shared_ptr<Variable> AstFactory::createVariable(const std::string& name) {
    return std::make_shared<Variable>(name);
}

std::shared_ptr<Literal> AstFactory::createLiteral(int value) {
    return std::make_shared<Literal>(value);
}

std::shared_ptr<Unary> AstFactory::createUnary(std::shared_ptr<Token> op, std::shared_ptr<Expr> right) {
    return std::make_shared<Unary>(std::move(op), std::move(right));
}

std::shared_ptr<Read> AstFactory::createRead(StmtNo stmtNo, std::shared_ptr<Variable> variable) {
    return std::make_shared<Read>(stmtNo, std::move(variable));
}

std::shared_ptr<Print> AstFactory::createPrint(StmtNo stmtNo, std::shared_ptr<Variable> variable) {
    return std::make_shared<Print>(stmtNo, std::move(variable));
}

std::shared_ptr<Call> AstFactory::createCall(StmtNo stmtNo, const std::string& procName) {
    return std::make_shared<Call>(stmtNo, procName);
}

std::shared_ptr<While> AstFactory::createWhile(StmtNo stmtNo, std::shared_ptr<Expr> condition,
                                               std::shared_ptr<StmtList> body) {
    return std::make_shared<While>(stmtNo, std::move(condition), std::move(body));
}

std::shared_ptr<If> AstFactory::createIf(StmtNo stmtNo, std::shared_ptr<Expr> condition,
                                         std::shared_ptr<StmtList> thenBranch, std::shared_ptr<StmtList> elseBranch) {
    return std::make_shared<If>(stmtNo, std::move(condition), std::move(thenBranch), std::move(elseBranch));
}

std::shared_ptr<Assign> AstFactory::createAssign(StmtNo stmtNo, std::shared_ptr<Variable> variable,
                                                 std::shared_ptr<Expr> value) {
    return std::make_shared<Assign>(stmtNo, std::move(variable), std::move(value));
}

std::shared_ptr<StmtList> AstFactory::createStmtList(std::vector<std::shared_ptr<Stmt>> stmts) {
    auto stmtList = std::make_shared<StmtList>();
    for (auto& stmt : stmts) {
        stmtList->push_back(std::move(stmt));
    }
    return stmtList;
}

// ai-gen end
