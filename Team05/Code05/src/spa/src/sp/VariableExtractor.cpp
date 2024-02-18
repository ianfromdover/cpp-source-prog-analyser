//
// Created by sjh_9 on 17/2/2024.
//

#include "VariableExtractor.h"

void VariableExtractor::visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void VariableExtractor::visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void VariableExtractor::visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void VariableExtractor::visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getBody()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    parentInfo->emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void VariableExtractor::visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    parentInfo->emplace_back(stmt.getStmtNo());
    auto& condition = stmt.getCondition();
    condition->accept(*this, parentInfo);
}

void VariableExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    auto parentInfoLHSCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
    auto parentInfoRHSCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
    auto& lhs = stmt.getVariable();
    parentInfoLHSCopy->emplace_back(stmt.getStmtNo());
    lhs->accept(*this, parentInfoLHSCopy);
    auto& rhs = stmt.getValue();
    parentInfoRHSCopy->emplace_back(stmt.getStmtNo());
    rhs->accept(*this, parentInfoRHSCopy);
}

void VariableExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    auto& leftExpr = expr.getLeft();
    auto& rightExpr = expr.getRight();
    leftExpr->accept(*this, parentInfo);
    rightExpr->accept(*this, parentInfo);
}

void VariableExtractor::visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&expr, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addVar(" << actualValue << ", " << expr.getName() << ");" << std::endl;
                pkb.addVar(actualValue, expr.getName());
            }
        }, val);
    }
}

void VariableExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void VariableExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    auto& rightExpr = expr.getRight();
    rightExpr->accept(*this, parentInfo);
}