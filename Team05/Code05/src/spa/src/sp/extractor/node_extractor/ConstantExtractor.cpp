//
// Created by sjh_9 on 18/2/2024.
//

#include "ConstantExtractor.h"

void ConstantExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void ConstantExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void ConstantExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ConstantExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& childStmt: *stmt.getBody()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void ConstantExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void ConstantExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto parentInfoLHSCopy = std::make_shared<Accumulator>(*parentInfo);
    auto parentInfoRHSCopy = std::make_shared<Accumulator>(*parentInfo);
    auto& lhs = stmt.getVariable();
    parentInfoLHSCopy->info.emplace_back(stmt.getStmtNo());
    lhs->accept(*this, parentInfoLHSCopy);
    auto& rhs = stmt.getValue();
    parentInfoRHSCopy->info.emplace_back(stmt.getStmtNo());
    rhs->accept(*this, parentInfoRHSCopy);
}

void ConstantExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void ConstantExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ConstantExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addConst(" << stmtNo << ", " << expr.getValue() << ");" << std::endl;
        pkb->addConst(stmtNo, expr.getValue());
    }
}

void ConstantExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}