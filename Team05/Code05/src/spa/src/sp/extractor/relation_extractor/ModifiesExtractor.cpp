//
// Created by sjh_9 on 16/2/2024.
//

#include "ModifiesExtractor.h"

void ModifiesExtractor::visitProcedure(const Procedure& procedure) {
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

void ModifiesExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->info.emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void ModifiesExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    visitedProcedures.insert(stmt.getProcName());
    auto procedure = program->getProcedure(stmt.getProcName());
    parentInfo->info.emplace_back(stmt.getStmtNo());
    this->visitStmtList(procedure->getBody(), parentInfo);
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
        //std::cout << "pkb.addModifies(" << stmtNo << ", " << expr.getName() << ");" << std::endl;
        pkb->addModifies(stmtNo, expr.getName());
    }
}

void ModifiesExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& parentInfo) {
    for (const auto& stmtNo : parentInfo->info) {
        //std::cout << "pkb.addModifies(" << stmtNo << ", " << expr.getValue() << ");" << std::endl;
        pkb->addModifies(stmtNo, std::to_string(expr.getValue()));
    }

}

void ModifiesExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}
