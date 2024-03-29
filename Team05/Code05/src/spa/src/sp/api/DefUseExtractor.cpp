//
// Created by Chua Bing Quan on 27/3/24.
//

#include "DefUseExtractor.h"
#include <cassert>

std::pair<Definitions, Uses> DefUseExtractor::extract(const std::shared_ptr<CFG> &cfg) {
    this->defs = Definitions();
    this->uses = Uses();

    for (const auto& block : *cfg->getBlocks()) {
        this->currentBlock = block;
        this->defs[this->currentBlock] = std::unordered_set<VarPoint>();
        this->uses[this->currentBlock] = std::unordered_set<VarPoint>();
        auto _ = std::make_shared<Accumulator>();
        this->visitStmtList(block->getStmts(), _);
    }

    return { std::move(this->defs), std::move(this->uses) };
}

void DefUseExtractor::addToDefinitions(const VarPoint &def) {
    this->defs.at(this->currentBlock).insert(def);
}

void DefUseExtractor::addToUses(const VarPoint &use) {
    this->uses.at(this->currentBlock).insert(use);
}

void DefUseExtractor::visitProcedure(const Procedure &procedure, std::shared_ptr<Accumulator> &_) {
    // Do nothing.
}

void DefUseExtractor::visitReadStmt(const Read &stmt, std::shared_ptr<Accumulator>& _) {
    const auto& def = VarPoint(stmt.getVariable()->getName(), stmt.getStmtNo());
    this->addToDefinitions(def);
}

void DefUseExtractor::visitPrintStmt(const Print &stmt, std::shared_ptr<Accumulator>& _) {
    const auto use = VarPoint(stmt.getVariable()->getName(), stmt.getStmtNo());
    this->addToUses(use);
}

void DefUseExtractor::visitCallStmt(const Call &stmt, std::shared_ptr<Accumulator>& _) {
    // TODO: Figure out how to handle this.
}

void DefUseExtractor::visitWhileStmt(const While &stmt, std::shared_ptr<Accumulator>& _) {
    // Since the body of the `While` statement spans subsequent blocks, we only need to process its condition.
    auto acc = std::make_shared<Accumulator>();
    acc->info.push_back(stmt.getStmtNo());
    stmt.getCondition()->accept(*this, acc);
}

void DefUseExtractor::visitIfStmt(const If &stmt, std::shared_ptr<Accumulator>& _) {
    // Since the branches of the `If` statement spans subsequent blocks, we only need to process its condition.
    auto acc = std::make_shared<Accumulator>();
    acc->info.push_back(stmt.getStmtNo());
    stmt.getCondition()->accept(*this, acc);
}

void DefUseExtractor::visitAssignStmt(const Assign &stmt, std::shared_ptr<Accumulator>& _) {
    const auto def = VarPoint(stmt.getVariable()->getName(), stmt.getStmtNo());
    this->addToDefinitions(def);
    auto acc = std::make_shared<Accumulator>();
    acc->info.push_back(stmt.getStmtNo());
    stmt.getValue()->accept(*this, acc);
}

void DefUseExtractor::visitBinaryExpr(const Binary& expr, std::shared_ptr<Accumulator>& acc) {
    expr.getLeft()->accept(*this, acc);
    expr.getRight()->accept(*this, acc);
}

void DefUseExtractor::visitVariableExpr(const Variable& expr, std::shared_ptr<Accumulator>& acc) {
    assert(acc->info.size() == 1);
    const auto use = VarPoint(expr.getName(), acc->info.front());
    this->addToUses(use);
}

void DefUseExtractor::visitUnaryExpr(const Unary& expr, std::shared_ptr<Accumulator>& acc) {
    expr.getRight()->accept(*this, acc);
}