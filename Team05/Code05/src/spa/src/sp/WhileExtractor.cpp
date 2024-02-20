//
// Created by sjh_9 on 17/2/2024.
//

#include "WhileExtractor.h"

void WhileExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void WhileExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void WhileExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void WhileExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& stmtList = stmt.getBody();
    for (auto& childStmt : *stmtList) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void WhileExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& thenStmtList = stmt.getThenBranch();
    auto& elseStmtList = stmt.getElseBranch();
    for (auto& childStmt : *thenStmtList) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (auto& childStmt : *elseStmtList) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void WhileExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do nothing
}

void WhileExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void WhileExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addWhile(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb.addWhile(stmtNo, expr.getName());
    }
}

void WhileExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void WhileExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
