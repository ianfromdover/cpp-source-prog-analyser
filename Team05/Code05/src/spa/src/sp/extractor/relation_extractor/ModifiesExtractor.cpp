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
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void ModifiesExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void ModifiesExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& lhsExpr = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    lhsExpr->accept(*this, parentInfo);
}

void ModifiesExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addModifies(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addModifies(stmtNo, expr.getName());
    }
}

void ModifiesExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addModifies(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addModifies(stmtNo, std::to_string(expr.getValue()));
    }

}

void ModifiesExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
