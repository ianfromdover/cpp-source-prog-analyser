//
// Created by Chua Bing Quan on 15/3/24.
//

#include "Block.h"

Block::Block(const std::shared_ptr<StmtList>& stmts) {
    this->stmts = stmts;
}

void Block::addSuccessor(const std::shared_ptr<Block>& successor) {
    this->successors->push_back(successor);
}

void Block::addPredecessor(const std::shared_ptr<Block>& predecessor) {
    this->predecessors->push_back(predecessor);
}

std::shared_ptr<Blocks> Block::getSuccessors() {
    return this->successors;
}

std::shared_ptr<Blocks> Block::getPredecessors() {
    return this->predecessors;
}