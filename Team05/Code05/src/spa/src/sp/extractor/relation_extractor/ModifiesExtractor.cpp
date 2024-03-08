//
// Created by sjh_9 on 16/2/2024.
//

#include "ModifiesExtractor.h"

void ModifiesExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void ModifiesExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ModifiesExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Pending Implementation for Sprint 2
}

void ModifiesExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& stmtList = stmt.getBody();
    for (auto& childStmt : *stmtList) {
        auto parentInfoCopy = std::make_shared<Accumulator>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void ModifiesExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
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
}

void ModifiesExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& lhsExpr = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    lhsExpr->accept(*this, parentInfo);
}

void ModifiesExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void ModifiesExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addModifiesS(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addModifiesS(stmtNo, expr.getName());
    }
}

void ModifiesExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addModifiesS(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addModifiesS(stmtNo, std::to_string(expr.getValue()));
    }

}

void ModifiesExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
