//
// Created by sjh_9 on 10/2/2024.
//

#include "ParentExtractor.h"

void ParentExtractor::visitReadStmt(const Read& stmt) {
    // Do Nothing
}

void ParentExtractor::visitPrintStmt(const Print& stmt) {
    // Do Nothing
}

void ParentExtractor::visitCallStmt(const Call& stmt) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitWhileStmt(const While& stmt) {
    for (const auto& childStmt : *stmt.getBody()) {
        // pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
    }
}

void ParentExtractor::visitIfStmt(const If& stmt) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        // pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        // pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
    }
}

void ParentExtractor::visitAssignStmt(const Assign& stmt) {
    // Do Nothing
}

void ParentExtractor::visitBinaryExpr(const Binary& expr) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitVariableExpr(const Variable& expr) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitLiteralExpr(const Literal& expr) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitUnaryExpr(const Unary& expr) {
    // Pending Implementation for Sprint 2
}