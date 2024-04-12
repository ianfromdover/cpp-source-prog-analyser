//
// Created by Chua Bing Quan on 27/3/24.
//

#include "DefUseExtractor.h"
#include "pkb/apis/QueryPkb.h"
#include <cassert>

std::pair<Definitions, Uses> DefUseExtractor::extract(const std::shared_ptr<CFG> &cfg) {
    this->defs = BlockVarOccurrencesMap();
    this->uses = BlockVarOccurrencesMap();
    this->calls = BlockVarOccurrencesMap();

    for (const auto& block : *cfg->getBlocks()) {
        this->currentBlock = block;
        this->defs.insert({ this->currentBlock, std::unordered_map<std::string, std::shared_ptr<VarOccurrence>>() });
        this->uses.insert({ this->currentBlock, std::unordered_map<std::string, std::shared_ptr<VarOccurrence>>() });
        auto _ = std::make_shared<Accumulator>();
        this->visitStmtList(block->getStmts(), _);
    }

    this->extractDefinitionsFromCalls();

    return std::move(this->generateDefUsePair(cfg));
}

void DefUseExtractor::extractDefinitionsFromCalls() {
    std::unordered_set<std::string> defNames;
    for (const auto& [_, blockDefs] : this->defs) {
        for (const auto& [defName, _] : blockDefs) {
            defNames.insert(defName);
        }
    }

    for (const auto& [block, blockCalls] : this->calls) {
        this->currentBlock = block;
        for (const auto& [_, call] : blockCalls) {
            for (const auto& defName : defNames) {
                if (this->queryPkb->isModifiesP(call->getName(), defName)) {
                    for (const auto stmtNo : *call->getOccurrences()) {
                        this->addToDefs(defName, stmtNo);
                    }
                }
            }
        }
    }
}

std::pair<Definitions, Uses> DefUseExtractor::generateDefUsePair(const std::shared_ptr<CFG> &cfg) {
    Definitions finalDefs = Definitions();
    Uses finalUses = Uses();

    for (const auto& block : *cfg->getBlocks()) {
        auto& defsSet = finalDefs[block];
        auto& usesSet = finalUses[block];

        for (const auto& [_, occurrence] : this->defs.at(block)) {
            defsSet.insert(occurrence);
        }
        for (const auto& [_, occurrence] : this->uses.at(block)) {
            usesSet.insert(occurrence);
        }
    }

    return { std::move(finalDefs), std::move(finalUses) };
}

void DefUseExtractor::addToBlockVarOccurrencesMap(BlockVarOccurrencesMap& map, const std::string& name, StmtNo stmtNo) {
    auto& blockMap = map[this->currentBlock];
    auto result = blockMap.emplace(name, std::make_shared<VarOccurrence>(name));
    result.first->second->addOccurrence(stmtNo);
}

void DefUseExtractor::addToDefs(const std::string& varName, StmtNo stmtNo) {
    this->addToBlockVarOccurrencesMap(this->defs, varName, stmtNo);
}

void DefUseExtractor::addToUses(const std::string& varName, StmtNo stmtNo) {
    this->addToBlockVarOccurrencesMap(this->uses, varName, stmtNo);
}

void DefUseExtractor::addToCalls(const std::string& procName, StmtNo stmtNo) {
    this->addToBlockVarOccurrencesMap(this->calls, procName, stmtNo);
}

void DefUseExtractor::visitProcedure(const Procedure &procedure, std::shared_ptr<Accumulator> &_) {
    // Do nothing.
}

void DefUseExtractor::visitReadStmt(const Read &stmt, std::shared_ptr<Accumulator>& _) {
    this->addToDefs(stmt.getVariable()->getName(), stmt.getStmtNo());
}

void DefUseExtractor::visitPrintStmt(const Print &stmt, std::shared_ptr<Accumulator>& _) {
    this->addToUses(stmt.getVariable()->getName(), stmt.getStmtNo());
}

void DefUseExtractor::visitCallStmt(const Call &stmt, std::shared_ptr<Accumulator>& _) {
    this->addToCalls(stmt.getProcName(), stmt.getStmtNo());
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
    this->addToDefs(stmt.getVariable()->getName(), stmt.getStmtNo());
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
    this->addToUses(expr.getName(), acc->info.front());
}

void DefUseExtractor::visitUnaryExpr(const Unary& expr, std::shared_ptr<Accumulator>& acc) {
    expr.getRight()->accept(*this, acc);
}