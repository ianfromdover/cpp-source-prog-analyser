//
// Created by sjh_9 on 22/3/2024.
//

#include "NextExtractor.h"
#include "sp/cfg/CFG.h"


void NextExtractor::visitCFG(const CFG& cfg) {
    for (const auto& block : *cfg.getBlocks()) {
        this->processPredecessors(block);
        this->processBody(block);
        this->processSuccessors(block);
    }
}

void NextExtractor::addNextRelation(StmtNo from, StmtNo to) {
    if (from != to) {
        //std::cout << "pkb.addNext(" << from << ", " << to << ");" << std::endl;
        this->pkb->addNext(from, to);
    }
}

void NextExtractor::processPredecessors(const std::shared_ptr<Block>& block) {
    for (const auto& predBlock : *block->getPredecessors()) {
        if (predBlock->getRange() && block->getRange()) {
            addNextRelation(predBlock->getRange()->second, block->getRange()->first);
        }
    }
}

void NextExtractor::processSuccessors(const std::shared_ptr<Block>& block) {
    for (const auto& succBlock : *block->getSuccessors()) {
        if (succBlock->getRange() && block->getRange()) {
            addNextRelation(block->getRange()->second, succBlock->getRange()->first);
        }
    }
}

void NextExtractor::processBody(const std::shared_ptr<Block>& block) {
    if (block->getRange()) {
        const auto start = block->getRange()->first;
        const auto end = block->getRange()->second;
        for (StmtNo i = start; i < end; ++i) {
            addNextRelation(i, i + 1);
        }
        return;
    }
    for (const auto& succBlock : *block->getSuccessors()) {
        for (const auto& predBlock : *block->getPredecessors()) {
            if (predBlock->getRange() && succBlock->getRange()) {
                addNextRelation(predBlock->getRange()->second, succBlock->getRange()->first);
            }
        }
    }
}

