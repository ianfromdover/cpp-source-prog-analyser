//
// Created by sjh_9 on 22/3/2024.
//

#include "NextExtractor.h"
#include "sp/cfg/block/Block.h"

// Created by sjh_9 on 22/3/2024.

#include "NextExtractor.h"
#include "sp/cfg/block/Block.h"


void NextExtractor::visitBlock(const Block& block) {
    processPredecessors(std::make_shared<Block>(block));
    processStatementList(std::make_shared<Block>(block));
    processSuccessors(std::make_shared<Block>(block));
    //std::cout << block.toString() << std::endl;
}

// Helper function to add a "Next" relation between two statements.
void NextExtractor::addNextRelation(const std::shared_ptr<Stmt>& fromStmt, const std::shared_ptr<Stmt>& toStmt) {
    if (fromStmt != nullptr && toStmt != nullptr) {
        //std::cout << "pkb.addNext(" << fromStmt->getStmtNo() << ", " << toStmt->getStmtNo() << ");" << std::endl;
        pkb->addNext(fromStmt->getStmtNo(), toStmt->getStmtNo());
    }
}

void NextExtractor::processPredecessors(const std::shared_ptr<Block>& block) {
    auto predecessors = block->getPredecessors();
    if (!predecessors->empty()) {
        for (const auto& predBlock : *predecessors) {
            addNextRelation(predBlock->getLastStmt(), block->getFirstStmt());
        }
    }
}

void NextExtractor::processSuccessors(const std::shared_ptr<Block>& block) {
    auto successors = block->getSuccessors();
    if (!successors->empty()) {
        for (const auto& succBlock : *successors) {
            addNextRelation(block->getLastStmt(), succBlock->getFirstStmt());
            if (visited.find(succBlock->toString()) == visited.end()) {
                visited.insert(succBlock->toString());
                succBlock->accept(*this);
            }
        }
    }
}

void NextExtractor::processStatementList(const std::shared_ptr<Block>& block) {
    auto stmts = block->getStmts();
    if (stmts && stmts->size() > 1) {
        for (size_t i = 0; i < stmts->size() - 1; ++i) {
            addNextRelation((*stmts)[i], (*stmts)[i + 1]);
        }
    }
    if (block->isDummy()) {
        auto successors = block->getSuccessors();
        auto predecessors = block->getPredecessors();
        for (const auto& succBlock : *successors) {
            for (const auto& predBlock : *predecessors) {
                addNextRelation(predBlock->getLastStmt(), succBlock->getFirstStmt());
            }
        }
    }

}

