//
// Created by sjh_9 on 17/2/2024.
//

#include "CallExtractor.h"

void CallExtractor::visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void CallExtractor::visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void CallExtractor::visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    std::string procName = stmt.getProcName();
    std::cout << "pkb.addCall(" << stmt.getStmtNo() << ", " << procName << ");" << std::endl;
}

void CallExtractor::visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getBody()) {
        childStmt->accept(*this, parentInfo);
    }
}

void CallExtractor::visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        childStmt->accept(*this, parentInfo);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        childStmt->accept(*this, parentInfo);
    }
}

void CallExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do nothing
}

void CallExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void CallExtractor::visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void CallExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void CallExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}