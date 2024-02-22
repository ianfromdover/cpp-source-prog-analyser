//
// Created by sjh_9 on 16/2/2024.
//

#include "FollowsExtractor.h"

void FollowsExtractor::visitProcedure(const Procedure &procedure) {
    auto prevStmtInfo = std::make_shared<Accumulator>();
    for (const auto& stmt : *procedure.getBody()) {
        stmt->accept(*this, prevStmtInfo);
        prevStmtInfo->info.emplace_back(stmt->getStmtNo());
    }
}

void FollowsExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& prevStmtInfo) {
    for (const auto& stmtNo : prevStmtInfo->info) {
        if (&stmtNo == &prevStmtInfo->info.back()) {
            //std::cout << "pkb.addFollows(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
            pkb->addFollows(stmtNo, stmt.getStmtNo());
        }
        //std::cout << "pkb.addFollowsT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addFollowsT(stmtNo, stmt.getStmtNo());
    }
}

void FollowsExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& prevStmtInfo) {
    for (const auto& stmtNo : prevStmtInfo->info) {
        if (&stmtNo == &prevStmtInfo->info.back()) {
            //std::cout << "pkb.addFollows(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
            pkb->addFollows(stmtNo, stmt.getStmtNo());
        }
        //std::cout << "pkb.addFollowsT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addFollowsT(stmtNo, stmt.getStmtNo());
    }
}

void FollowsExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& prevStmtInfo) {
    for (const auto& stmtNo : prevStmtInfo->info) {
        if (&stmtNo == &prevStmtInfo->info.back()) {
            //std::cout << "pkb.addFollows(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
            pkb->addFollows(stmtNo, stmt.getStmtNo());
        }
        //std::cout << "pkb.addFollowsT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addFollowsT(stmtNo, stmt.getStmtNo());
    }
}

void FollowsExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& prevStmtInfo) {
    for (const auto& stmtNo : prevStmtInfo->info) {
        if (&stmtNo == &prevStmtInfo->info.back()) {
            //std::cout << "pkb.addFollows(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
            pkb->addFollows(stmtNo, stmt.getStmtNo());
        }
        //std::cout << "pkb.addFollowsT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addFollowsT(stmtNo, stmt.getStmtNo());
    }
    auto newPrevStmtInfo = std::make_shared<Accumulator>();
    for (const auto& stmtBody : *stmt.getBody()) {
        stmtBody->accept(*this, newPrevStmtInfo);
        newPrevStmtInfo->info.emplace_back(stmtBody->getStmtNo());
    }
}

void FollowsExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& prevStmtInfo) {
    for (const auto& stmtNo : prevStmtInfo->info) {
        if (&stmtNo == &prevStmtInfo->info.back()) {
            //std::cout << "pkb.addFollows(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
            pkb->addFollows(stmtNo, stmt.getStmtNo());
        }
        //std::cout << "pkb.addFollowsT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addFollowsT(stmtNo, stmt.getStmtNo());
    }
    auto newPrevThenStmtInfo = std::make_shared<Accumulator>();
    for (const auto& stmtThen : *stmt.getThenBranch()) {
        stmtThen->accept(*this, newPrevThenStmtInfo);
        newPrevThenStmtInfo->info.emplace_back(stmtThen->getStmtNo());
    }
    auto newPrevElseStmtInfo = std::make_shared<Accumulator>();
    for (const auto& stmtThen : *stmt.getElseBranch()) {
        stmtThen->accept(*this, newPrevElseStmtInfo);
        newPrevElseStmtInfo->info.emplace_back(stmtThen->getStmtNo());
    }
}

void FollowsExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& prevStmtInfo) {
    for (const auto& stmtNo : prevStmtInfo->info) {
        if (&stmtNo == &prevStmtInfo->info.back()) {
            //std::cout << "pkb.addFollows(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
            pkb->addFollows(stmtNo, stmt.getStmtNo());
        }
        //std::cout << "pkb.addFollowsT(" << stmtNo << ", " << stmt.getStmtNo() << ");" << std::endl;
        pkb->addFollowsT(stmtNo, stmt.getStmtNo());
    }
}

void FollowsExtractor::visitBinaryExpr(const Binary& expr, shared_ptr<Accumulator>& prevStmtInfo) {
    // Do Nothing
}

void FollowsExtractor::visitVariableExpr(const Variable& expr, shared_ptr<Accumulator>& prevStmtInfo) {
    // Do Nothing
}

void FollowsExtractor::visitLiteralExpr(const Literal& expr, shared_ptr<Accumulator>& prevStmtInfo) {
    // Do Nothing
}

void FollowsExtractor::visitUnaryExpr(const Unary& expr, shared_ptr<Accumulator>& prevStmtInfo) {
    // Do Nothing
}