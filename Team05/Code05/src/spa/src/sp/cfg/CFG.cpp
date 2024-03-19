//
// Created by Chua Bing Quan on 15/3/24.
//

#include "CFG.h"

CFG::CFG(const std::shared_ptr<Procedure>& procedure) {
    this->compile(procedure);
}

std::shared_ptr<Block> CFG::getEntryBlock() const {
    return this->blocks->front();
}

std::shared_ptr<Blocks> CFG::getBlocks() const {
    return this->blocks;
}

void CFG::compile(const std::shared_ptr<Procedure>& procedure) {
    procedure->accept(*this);
}

void CFG::addAndLinkBlock(const std::shared_ptr<Block>& block) {
    if (!this->blocks->empty()) {
        this->addEdge(this->blocks->back(), block);
    }
    this->addBlock(block);
}

void CFG::addBlock(const std::shared_ptr<Block>& block) {
    this->blocks->push_back(block);
}

void CFG::addEdge(const std::shared_ptr<Block>& predecessor, const std::shared_ptr<Block>& successor) {
    predecessor->addSuccessor(successor);
    successor->addPredecessor(predecessor);
}

void CFG::addStmtToBlock(const std::shared_ptr<Stmt>& stmt) {
    if (this->blocks->empty()) {
        this->addBlock(std::make_shared<Block>());
    }
    this->blocks->back()->addStmt(stmt);
}

void CFG::visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) {
    this->visitStmtList(procedure.getBody(), _);
}

void CFG::visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToBlock(std::make_shared<Read>(stmt));
}

void CFG::visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToBlock(std::make_shared<Print>(stmt));
}

void CFG::visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToBlock(std::make_shared<Call>(stmt));
}

void CFG::visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToBlock(std::make_shared<Assign>(stmt));
}

void CFG::visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) {
    const auto& whileBlock = std::make_shared<Block>();
    this->addAndLinkBlock(whileBlock);
    this->addStmtToBlock(std::make_shared<While>(stmt));

    const auto& bodyBlock = std::make_shared<Block>();
    this->addAndLinkBlock(bodyBlock);

    this->visitStmtList(stmt.getBody(), _);

    this->addEdge(this->blocks->back(), whileBlock);

    const auto& mergeBlock = std::make_shared<Block>();
    this->addEdge(whileBlock, mergeBlock);
    this->addBlock(mergeBlock);
}

void CFG::visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) {
    const auto& ifBlock = std::shared_ptr<Block>();
    this->addAndLinkBlock(ifBlock);
    this->addStmtToBlock(std::make_shared<If>(stmt));

    const auto& branches = std::vector<std::shared_ptr<StmtList>> {
        stmt.getThenBranch(),
        stmt.getElseBranch(),
    };
    const auto& mergeBlock = std::make_shared<Block>();

    for (const auto& branch : branches) {
        const auto& branchBlock = std::make_shared<Block>();
        this->addEdge(ifBlock, branchBlock);
        this->addBlock(branchBlock);
        this->visitStmtList(branch, _);
        this->addEdge(this->blocks->back(), mergeBlock);
    }

    this->addBlock(mergeBlock);
}

std::shared_ptr<CFGs> CFG::compile(const std::shared_ptr<Program>& program) {
    const auto& cfgs = std::make_shared<CFGs>();
    for (const auto& procedure : *program->getProcedures()) {
        cfgs->insert({ procedure->getName(), std::make_shared<CFG>(procedure) });
    }
    return cfgs;
}