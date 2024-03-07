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
    this->visitStmtList(stmt.getBody(), prevStmtInfo);
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
    this->visitStmtList(stmt.getThenBranch(), prevStmtInfo);
    this->visitStmtList(stmt.getElseBranch(), prevStmtInfo);
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

void FollowsExtractor::visitStmtList(const shared_ptr<vector<shared_ptr<Stmt>>>& stmts, shared_ptr<Accumulator> &info) {
    auto newStmtInfo = std::make_shared<Accumulator>();
    for (const auto& childStmt : *stmts) {
        childStmt->accept(*this, newStmtInfo);
        newStmtInfo->info.emplace_back(childStmt->getStmtNo());
    }
}