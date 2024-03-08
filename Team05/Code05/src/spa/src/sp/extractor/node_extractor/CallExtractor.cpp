//
// Created by sjh_9 on 17/2/2024.
//

#include "CallExtractor.h"

void CallExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    std::string procName = stmt.getProcName();
    //std::cout << "pkb.addCallStmt(" << stmt.getStmtNo() << ", " << procName << ");" << std::endl;
    pkb->addCallStmt(stmt.getStmtNo(), procName );
}

void CallExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void CallExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}