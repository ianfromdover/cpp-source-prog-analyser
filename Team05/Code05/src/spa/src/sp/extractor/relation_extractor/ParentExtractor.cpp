//
// Created by sjh_9 on 10/2/2024.
//

#include "ParentExtractor.h"

void ParentExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addParentT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addParentT(stmtNo, stmt.getStmtNo());
    }
}

void ParentExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addParentT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addParentT(stmtNo, stmt.getStmtNo());
    }
}

void ParentExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addParentT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addParentT(stmtNo, stmt.getStmtNo());
    }
}

void ParentExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addParentT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addParentT(stmtNo, stmt.getStmtNo());
    }
    parentInfo->info.emplace_back(stmt.getStmtNo());
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void ParentExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addParentT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addParentT(stmtNo, stmt.getStmtNo());
    }
    parentInfo->info.emplace_back(stmt.getStmtNo());
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void ParentExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addParentT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addParentT(stmtNo, stmt.getStmtNo());
    }
}

void ParentExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ParentExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ParentExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void ParentExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}


void ParentExtractor::visitStmtList(const shared_ptr<vector<shared_ptr<Stmt>>>& stmts, shared_ptr<Accumulator> &info) {
    auto stmtNo = 0;
    if (!info->info.empty()) {
        stmtNo = info->info.back();
    }
    for (const auto& childStmt : *stmts) {
        pkb->addParent(stmtNo, childStmt->getStmtNo());
        auto infoCopy = std::make_shared<Accumulator>(*info);
        childStmt->accept(*this, infoCopy);
    }
}