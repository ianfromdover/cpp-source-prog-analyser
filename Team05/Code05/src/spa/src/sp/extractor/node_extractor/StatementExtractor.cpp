//
// Created by sjh_9 on 17/2/2024.
//

#include "StatementExtractor.h"

void StatementExtractor::visitReadStmt(const Read& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
    pkb->addFinalStatementNo(stmt.getStmtNo());
}

void StatementExtractor::visitPrintStmt(const Print& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
    pkb->addFinalStatementNo(stmt.getStmtNo());
}

void StatementExtractor::visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
    pkb->addFinalStatementNo(stmt.getStmtNo());
}

void StatementExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
    pkb->addFinalStatementNo(stmt.getStmtNo());
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void StatementExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
    pkb->addFinalStatementNo(stmt.getStmtNo());
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void StatementExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addFinalStatementNo(" << stmt.getStmtNo() << ");" << std::endl;
    pkb->addFinalStatementNo(stmt.getStmtNo());
}