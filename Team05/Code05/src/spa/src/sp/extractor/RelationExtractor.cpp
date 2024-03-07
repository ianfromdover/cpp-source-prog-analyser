//
// Created by Chua Bing Quan on 21/2/24.
//

#include "RelationExtractor.h"

void RelationExtractor::visitProcedure(const Procedure& procedure) {
    for (const auto& stmt : *procedure.getBody()) {
        auto parentInfo = std::make_shared<Accumulator>();
        stmt->accept(*this, parentInfo);
    }
}

void RelationExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    auto parentInfoLHSCopy = std::make_shared<Accumulator>(*parentInfo);
    auto parentInfoRHSCopy = std::make_shared<Accumulator>(*parentInfo);
    auto& lhs = stmt.getVariable();
    parentInfoLHSCopy->info.emplace_back(stmt.getStmtNo());
    lhs->accept(*this, parentInfoLHSCopy);
    auto& rhs = stmt.getValue();
    parentInfoRHSCopy->info.emplace_back(stmt.getStmtNo());
    rhs->accept(*this, parentInfoRHSCopy);
}

void RelationExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}