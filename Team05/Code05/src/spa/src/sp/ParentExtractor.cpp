//
// Created by sjh_9 on 10/2/2024.
//

#include "ParentExtractor.h"

void ParentExtractor::visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&](const auto& actualValue) {
            std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
}

void ParentExtractor::visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&](const auto& actualValue) {
            std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
}

void ParentExtractor::visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Pending Implementation for Sprint 2
}

void ParentExtractor::visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&](const auto& actualValue) {
            std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
    parentInfo->emplace_back(stmt.getStmtNo());
    for (const auto& childStmt : *stmt.getBody()) {
        //pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void ParentExtractor::visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&](const auto& actualValue) {
            std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
    parentInfo->emplace_back(stmt.getStmtNo());
    for (const auto& childStmt: *stmt.getThenBranch()) {
        //pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        //pkb.addParent(stmt.getStmtNo(), childStmt-> getStmtNo());
        std::cout << "pkb.addParent(" << stmt.getStmtNo() << ", " << childStmt->getStmtNo() << ");" << std::endl;
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void ParentExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& val : *parentInfo) {
        std::visit([&](const auto& actualValue) {
            std::cout << "pkb.addParentT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
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