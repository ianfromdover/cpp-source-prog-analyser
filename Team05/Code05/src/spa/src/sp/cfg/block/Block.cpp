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

std::optional<std::pair<StmtNo, StmtNo>> Block::getRange() {
    if (this->stmts->empty()) {
        return std::nullopt;
    }
    return {{ this->stmts->front()->getStmtNo(), this->stmts->back()->getStmtNo() }};
}

std::string Block::rangeToString(const std::shared_ptr<Block>& block) {
    const auto& range = block->getRange();
    return range ? std::to_string(range->first) + " - " + std::to_string(range->second) : "Dummy";
}

std::string Block::rangesToString(const std::shared_ptr<Blocks>& blocks) {
    std::string str = "[";
    for (size_t i = 0; i < blocks->size(); i++) {
        str += Block::rangeToString(blocks->at(i));
        if (i < blocks->size() - 1) {
            str += ", ";
        }
    }
    str += "]";
    return str;
}

std::string Block::toString() const {
    const auto& self = std::make_shared<Blocks>();
    self->push_back(std::make_shared<Block>(*this));
    std::string str = "\tBlock" + Block::rangesToString(self) + ": [\n\t\tpredecessors: ";
    str += Block::rangesToString(this->predecessors) + ",\n\t\tsuccessors: ";
    str += Block::rangesToString(this->successors) + "\n\t]";
    return str;
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

bool Block::isDummy() {
    return this->stmts->empty();
}

