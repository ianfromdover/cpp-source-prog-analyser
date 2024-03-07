//
// Created by sjh_9 on 17/2/2024.
//

#include "VariableExtractor.h"

void VariableExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void VariableExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void VariableExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void VariableExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void VariableExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void VariableExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto parentInfoLHSCopy = std::make_shared<Accumulator>(*parentInfo);
    auto parentInfoRHSCopy = std::make_shared<Accumulator>(*parentInfo);
    auto& lhs = stmt.getVariable();
    parentInfoLHSCopy->info.emplace_back(stmt.getStmtNo());
    lhs->accept(*this, parentInfoLHSCopy);
    auto& rhs = stmt.getValue();
    parentInfoRHSCopy->info.emplace_back(stmt.getStmtNo());
    rhs->accept(*this, parentInfoRHSCopy);
}

void VariableExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void VariableExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addVar(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addVar(stmtNo, expr.getName());
    }
}

void VariableExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void VariableExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}