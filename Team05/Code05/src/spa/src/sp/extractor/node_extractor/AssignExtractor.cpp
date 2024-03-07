//
// Created by sjh_9 on 17/2/2024.
//

#include "AssignExtractor.h"

void AssignExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void AssignExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void AssignExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addPatternAsgn(" << stmt.getStmtNo() << ", " << stmt.getVariable()->toString() << ", " << stmt.getValue()->toString() << ");" << std::endl;
    pkb->addPatternAsgn(stmt.getStmtNo(), stmt.getVariable()->toString(), stmt.getValue()->toString());
    //    auto& var = stmt.getVariable();
    //    parentInfo->info.emplace_back(stmt.getStmtNo());
    //    var->accept(*this, parentInfo);
}

void AssignExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    // Do Nothing
}