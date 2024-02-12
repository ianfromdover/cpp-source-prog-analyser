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
    for (auto& childStmt: stmt.getBody()) {
        addParent(stmt.getStmtNo, childStmt.getStmtNo);
    }
}

void ParentExtractor::visitIfStmt(const If& stmt) {
    for (auto& childStmt: stmt.getThenBranch()) {
        addParent(stmt.getStmtNo, childStmt.getStmtNo);
    }
    for (auto& childStmt: stmt.getElseBranch()) {
        addParent(stmt.getStmtNo, childStmt.getStmtNo);
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