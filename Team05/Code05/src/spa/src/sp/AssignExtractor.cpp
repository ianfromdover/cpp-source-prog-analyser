//
// Created by sjh_9 on 17/2/2024.
//

#include "AssignExtractor.h"

void AssignExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& childStmt: *stmt.getBody()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void AssignExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void AssignExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void AssignExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addAssign(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb.addAssign(stmtNo, expr.getName());
    }
}

void AssignExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}