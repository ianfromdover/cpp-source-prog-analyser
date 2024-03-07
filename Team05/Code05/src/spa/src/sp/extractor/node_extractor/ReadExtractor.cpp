//
// Created by sjh_9 on 17/2/2024.
//

#include "ReadExtractor.h"

void ReadExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void ReadExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ReadExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ReadExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void ReadExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void ReadExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do nothing
}

void ReadExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ReadExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addRead(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addRead(stmtNo, expr.getName());
    }
}

void ReadExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ReadExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}