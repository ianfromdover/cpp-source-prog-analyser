//
// Created by sjh_9 on 17/2/2024.
//

#include "StatementExtractor.h"

void StatementExtractor::visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
}

void StatementExtractor::visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
}

void StatementExtractor::visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
}

void StatementExtractor::visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getBody()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void StatementExtractor::visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    for (const auto& childStmt: *stmt.getThenBranch()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
    for (const auto& childStmt: *stmt.getElseBranch()) {
        auto parentInfoCopy = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>(*parentInfo);
        childStmt->accept(*this, parentInfoCopy);
    }
}

void StatementExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
}

void StatementExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void StatementExtractor::visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void StatementExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}

void StatementExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    // Do Nothing
}