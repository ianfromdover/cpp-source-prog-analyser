//
// Created by sjh_9 on 17/2/2024.
//

#include "IfExtractor.h"

void IfExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void IfExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
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

void IfExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
