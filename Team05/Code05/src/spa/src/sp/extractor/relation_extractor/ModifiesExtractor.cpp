//
// Created by sjh_9 on 16/2/2024.
//

#include "ModifiesExtractor.h"

void ModifiesExtractor::visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& info) {
    if (this->visitedProcedures.find(procedure.getName()) == this->visitedProcedures.end()) {
        this->visitedProcedures.insert(procedure.getName());
        auto parentInfo = std::make_shared<Accumulator>(*info);
        parentInfo->stringInfo.emplace_back(procedure.getName());
        this->visitStmtList(procedure.getBody(), parentInfo);
    }
}

void ModifiesExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void ModifiesExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
    this->visitProcedure(*this->program->getProcedure(stmt.getProcName()), parentInfo);
}

void ModifiesExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    parentInfo->info.emplace_back(stmt.getStmtNo());
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
    for (const auto& procName : parentInfo->stringInfo) {
        //std::cout << "pkb.addModifiesP(" << procName << ", " << expr.getName() << ");" << std::endl;
        pkb->addModifiesP(procName, expr.getName());
    }
}

void ModifiesExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
