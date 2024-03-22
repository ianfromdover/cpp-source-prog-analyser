//
// Created by sjh_9 on 17/2/2024.
//

#include "WhileExtractor.h"

void WhileExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void WhileExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void WhileExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void WhileExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addPatternWhile(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addPatternWhile(stmtNo, expr.getName());
    }
}

void WhileExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
