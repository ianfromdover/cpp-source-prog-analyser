//
// Created by sjh_9 on 17/2/2024.
//

#include "PrintExtractor.h"

void PrintExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void PrintExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void PrintExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void PrintExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& childStmt: *stmt.getBody()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void PrintExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void PrintExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do nothing
}

void PrintExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void PrintExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addPrint(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addPrint(stmtNo, expr.getName());
    }
}

void PrintExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void PrintExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}