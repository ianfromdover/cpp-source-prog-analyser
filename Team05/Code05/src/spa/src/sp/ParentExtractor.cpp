//
// Created by sjh_9 on 10/2/2024.
//

#include "ParentExtractor.h"

void ParentExtractor::visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&stmt, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
                pkb.addParentT(actualValue, stmt.getStmtNo());
            }
        }, val);
    }
}

void ParentExtractor::visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&stmt, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
                pkb.addParentT(actualValue, stmt.getStmtNo());
            }
        }, val);
    }
}

void ParentExtractor::visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&stmt, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
                pkb.addParentT(actualValue, stmt.getStmtNo());
            }
        }, val);
    }
}

void ParentExtractor::visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&stmt, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
                pkb.addParentT(actualValue, stmt.getStmtNo());
            }
        }, val);
    }
    parentInfo->emplace_back(stmt.getStmtNo());
    for (const auto& childStmt : *stmt.getBody()) {
        //std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
        pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void ParentExtractor::visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&stmt, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
                pkb.addParentT(actualValue, stmt.getStmtNo());
            }
        }, val);
    }
    parentInfo->emplace_back(stmt.getStmtNo());
    for (const auto& childStmt: *stmt.getThenBranch()) {
        //std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
        pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        //std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
        pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void ParentExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&stmt, this](auto&& actualValue) {
            using T = std::decay_t<decltype(actualValue)>;
            if constexpr (std::is_same_v<T, StmtNo>) {
                //std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
                pkb.addParentT(actualValue, stmt.getStmtNo());
            }
        }, val);
    }
}

void ParentExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void ParentExtractor::visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void ParentExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void ParentExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}