//
// Created by sjh_9 on 10/2/2024.
//

#include "ParentExtractor.h"

void ParentExtractor::visitReadStmt(Read& stmt) {
    // Do Nothing
}

void ParentExtractor::visitPrintStmt(Print& stmt) {
    // Do Nothing
}

void ParentExtractor::visitCallStmt(Call& stmt) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitWhileStmt(While& stmt) {
    for (auto& childStmt: stmt.getBody()) {
        //addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
    }
}

void ParentExtractor::visitIfStmt(If& stmt) {
    for (auto& childStmt: stmt.getThenBranch()) {
        //addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
    }
    for (auto& childStmt: stmt.getElseBranch()) {
        //addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
    }
}

void ParentExtractor::visitAssignStmt(Assign& stmt) {
    // Do Nothing
}

void ParentExtractor::visitBinaryExpr(Binary& expr) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitVariableExpr(Variable& expr) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitLiteralExpr(Literal& expr) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitUnaryExpr( Unary& expr) {
    // Pending Implementation for Sprint 2
}