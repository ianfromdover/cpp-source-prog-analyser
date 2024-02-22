//
// Created by sjh_9 on 17/2/2024.
//

#include "IfExtractor.h"

void IfExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void IfExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void IfExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
   // Do Nothing
}

void IfExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& stmtList = stmt.getBody();
    for (auto& childStmt : *stmtList) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void IfExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
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
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void IfExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do nothing
}

void IfExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void IfExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addIf(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addIf(stmtNo, expr.getName());
    }
}

void IfExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void IfExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
