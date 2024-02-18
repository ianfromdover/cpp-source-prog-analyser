//
// Created by sjh_9 on 17/2/2024.
//

#include "AssignExtractor.h"

void AssignExtractor::visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getBody()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void AssignExtractor::visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void AssignExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    auto& var = stmt.getVariable();
    parentInfo->emplace_back(stmt.getStmtNo());
    var->accept(*this, parentInfo);
}

void AssignExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&expr, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addAssign(" << actualValue << ", " << expr.getName() << ");" << std::endl;
                pkb.addAssign(actualValue, expr.getName());
            }
        }, val);
    }
}

void AssignExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void AssignExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}