//
// Created by sjh_9 on 16/2/2024.
//

#include "FollowsExtractor.h"

//
// Created by sjh_9 on 10/2/2024.
//

#include "FollowsExtractor.h"

void FollowsExtractor::visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    for (const auto& val : *prevStmtInfo) {
        std::visit([&](const auto& actualValue) {
            if (&val == &prevStmtInfo->back()) {
                std::cout << "pkb.addFollow(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
            }
            std::cout << "pkb.addFollowT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
}

void FollowsExtractor::visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    for (const auto& val : *prevStmtInfo) {
        std::visit([&](const auto& actualValue) {
            if (&val == &prevStmtInfo->back()) {
                std::cout << "pkb.addFollow(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
            }
            std::cout << "pkb.addFollowT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
}

void FollowsExtractor::visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    for (const auto& val : *prevStmtInfo) {
        std::visit([&](const auto& actualValue) {
            if (&val == &prevStmtInfo->back()) {
                std::cout << "pkb.addFollow(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
            }
            std::cout << "pkb.addFollowT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
}

void FollowsExtractor::visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    for (const auto& val : *prevStmtInfo) {
        std::visit([&](const auto& actualValue) {
            if (&val == &prevStmtInfo->back()) {
                std::cout << "pkb.addFollow(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
            }
            std::cout << "pkb.addFollowT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
    auto newPrevStmtInfo = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>();
    for (const auto& stmtBody : *stmt.getBody()) {
        stmtBody->accept(*this, newPrevStmtInfo);
        newPrevStmtInfo->emplace_back(stmtBody->getStmtNo());
    }
}

void FollowsExtractor::visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    for (const auto& val : *prevStmtInfo) {
        std::visit([&](const auto& actualValue) {
            if (&val == &prevStmtInfo->back()) {
                std::cout << "pkb.addFollow(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
            }
            std::cout << "pkb.addFollowT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
    auto newPrevThenStmtInfo = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>();
    for (const auto& stmtThen : *stmt.getThenBranch()) {
        stmtThen->accept(*this, newPrevThenStmtInfo);
        newPrevThenStmtInfo->emplace_back(stmtThen->getStmtNo());
    }
    auto newPrevElseStmtInfo = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>();
    for (const auto& stmtThen : *stmt.getElseBranch()) {
        stmtThen->accept(*this, newPrevElseStmtInfo);
        newPrevElseStmtInfo->emplace_back(stmtThen->getStmtNo());
    }
}

void FollowsExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    for (const auto& val : *prevStmtInfo) {
        std::visit([&](const auto& actualValue) {
            if (&val == &prevStmtInfo->back()) {
                std::cout << "pkb.addFollow(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
            }
            std::cout << "pkb.addFollowT(" << actualValue << ", " << stmt.getStmtNo() << ");" << std::endl;
        }, val);
    }
}

void FollowsExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    // Do Nothing
}

void FollowsExtractor::visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    // Do Nothing
}

void FollowsExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    // Do Nothing
}

void FollowsExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) {
    // Do Nothing
}