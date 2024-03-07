//
// Created by sjh_9 on 16/2/2024.
//

#include "UsesExtractor.h"

void UsesExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void UsesExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Pending Implementation for Sprint 2
}

void UsesExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
    auto& stmtList = stmt.getBody();
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void UsesExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void UsesExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& rhsExpr = stmt.getValue();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    rhsExpr->accept(*this, parentInfo);
}

void UsesExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void UsesExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addUses(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addUses(stmtNo, expr.getName());
    }
}

void UsesExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addModifies(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addUses(stmtNo, std::to_string(expr.getValue()));
    }
}

void UsesExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}