//
// Created by Chua Bing Quan on 15/3/24.
//

#include "Block.h"

Block::Block() {
    this->stmts = std::make_shared<StmtList>();
    this->successors = std::make_shared<Blocks>();
    this->predecessors = std::make_shared<Blocks>();
}

void Block::addStmt(const std::shared_ptr<Stmt>& stmt) {
    this->stmts->push_back(stmt);
}

void Block::addSuccessor(const std::shared_ptr<Block>& successor) {
    this->successors->push_back(successor);
}

void Block::addPredecessor(const std::shared_ptr<Block>& predecessor) {
    this->predecessors->push_back(predecessor);
}

std::shared_ptr<StmtList> Block::getStmts() const {
    return this->stmts;
}

std::shared_ptr<Blocks> Block::getSuccessors() const {
    return this->successors;
}

std::shared_ptr<Blocks> Block::getPredecessors() const {
    return this->predecessors;
}