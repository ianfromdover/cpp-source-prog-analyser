//
// Created by sjh_9 on 16/2/2024.
//

#include "UsesExtractor.h"

void UsesExtractor::visitProcedure(const Procedure& procedure) {
    // If procedure has been visited
    if (visitedProcedures.find(procedure.getName()) != visitedProcedures.end()) {

    } else {
        visitedProcedures.insert(procedure.getName());
        for (const auto& stmt : *procedure.getBody()) {
            auto parentInfo = std::make_shared<Accumulator>();
            stmt->accept(*this, parentInfo);
        }
    }
}

void UsesExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void UsesExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    visitedProcedures.insert(stmt.getProcName());
    auto procedure = program->getProcedure(stmt.getProcName());
    parentInfo->info.emplace_back(stmt.getStmtNo());
    this->visitStmtList(procedure->getBody(), parentInfo);
}

void UsesExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void UsesExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void UsesExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& rhsExpr = stmt.getValue();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    rhsExpr->accept(*this, parentInfo);
}

void UsesExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void UsesExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addUsesS(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addUsesS(stmtNo, expr.getName());
    }
}

void UsesExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}