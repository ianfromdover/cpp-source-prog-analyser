//
// Created by sjh_9 on 17/2/2024.
//

#include "PrintExtractor.h"

void PrintExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void PrintExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void PrintExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void PrintExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addPrint(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addPrint(stmtNo, expr.getName());
    }
}