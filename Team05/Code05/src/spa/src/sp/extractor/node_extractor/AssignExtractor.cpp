//
// Created by sjh_9 on 17/2/2024.
//

#include "AssignExtractor.h"

void AssignExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void AssignExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}

void AssignExtractor::visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) {
    //std::cout << "pkb.addPatternAsgn(" << stmt.getStmtNo() << ", " << stmt.getVariable()->toString() << ", " << stmt.getValue()->toString() << ");" << std::endl;
    pkb->addPatternAsgn(stmt.getStmtNo(), stmt.getVariable()->toString(), stmt.getValue()->toString());
}