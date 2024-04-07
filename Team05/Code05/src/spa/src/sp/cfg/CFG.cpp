//
// Created by Chua Bing Quan on 15/3/24.
//

#include "CFG.h"
#include "sp/extractor/CfgExtractor.h"

CFG::CFG(const std::shared_ptr<Procedure>& procedure) {
    this->procedureName = procedure->getName();
    this->blocks = std::make_shared<Blocks>();
    this->compile(procedure);
}

std::shared_ptr<Block> CFG::getEntryBlock() const {
    return this->blocks->front();
}

std::shared_ptr<Blocks> CFG::getBlocks() const {
    return this->blocks;
}

std::string CFG::getProcedureName() const {
    return this->procedureName;
}

std::pair<StmtNo, StmtNo> CFG::getRange() const {
    auto start = -1;
    auto end = -1;

    for (const auto& block : *this->blocks) {
        const auto range = block->getRange();
        if (range) {
            start = range->first;
            break;
        }
    }

    for (auto it = this->blocks->rbegin(); it != this->blocks->rend(); ++it) {
        const auto range = (*it)->getRange();
        if (range) {
            end = range->second;
            break;
        }
    }

    return { start, end };
}

bool CFG::containsStmtNo(StmtNo stmtNo) const {
    const auto range = this->getRange();
    return range.first <= stmtNo && stmtNo <= range.second;
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

void CFG::addStmtToLastBlock(const std::shared_ptr<Stmt>& stmt) {
    if (this->blocks->empty()) {
        this->addBlock(std::make_shared<Block>());
    }
    this->blocks->back()->addStmt(stmt);
}

bool CFG::isLastBlockEmpty() {
    return !this->blocks->empty() && this->blocks->back()->getStmts()->empty();
}

void CFG::visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) {
    this->visitStmtList(procedure.getBody(), _);
}

void CFG::visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToLastBlock(std::make_shared<Read>(stmt));
}

void CFG::visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToLastBlock(std::make_shared<Print>(stmt));
}

void CFG::visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToLastBlock(std::make_shared<Call>(stmt));
}

void CFG::visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) {
    this->addStmtToLastBlock(std::make_shared<Assign>(stmt));
}

void CFG::visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) {
    std::shared_ptr<Block> whileBlock;
    if (this->isLastBlockEmpty()) {
        whileBlock = this->blocks->back();
    } else {
        whileBlock = std::make_shared<Block>();
        this->addAndLinkBlock(whileBlock);
    }
    this->addStmtToLastBlock(std::make_shared<While>(stmt));

    const auto& bodyBlock = std::make_shared<Block>();
    this->addAndLinkBlock(bodyBlock);

    this->visitStmtList(stmt.getBody(), _);

    this->addEdge(this->blocks->back(), whileBlock);

    const auto& mergeBlock = std::make_shared<Block>();
    this->addEdge(whileBlock, mergeBlock);
    this->addBlock(mergeBlock);
}

void CFG::visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) {
    std::shared_ptr<Block> ifBlock;
    if (this->isLastBlockEmpty()) {
        ifBlock = this->blocks->back();
    } else {
        ifBlock = std::make_shared<Block>();
        this->addAndLinkBlock(ifBlock);
    }
    this->addStmtToLastBlock(std::make_shared<If>(stmt));

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

std::string CFG::toString() {
    std::string str = "CFG [" + this->procedureName + "]: [\n";
    for (size_t i = 0; i < this->blocks->size(); i++) {
        str += blocks->at(i)->toString();
        if (i < this->blocks->size() - 1) {
            str += ",";
        }
        str += "\n";
    }
    str += "]\n";
    return str;
}

void CFG::accept(CfgExtractor &visitor) const {
    visitor.visitCFG(*this);
}

std::optional<std::shared_ptr<Block>> CFG::find(int index) {
    for (const auto& block : *blocks) {
        auto front = block->getRange()->first;
        auto back = block->getRange()->second;
        if (index >= front && index <= back) {
            return block;
        }
    }
    return nullopt;
}


