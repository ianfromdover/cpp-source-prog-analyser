//
// Created by Chua Bing Quan on 15/3/24.
//

#ifndef SPA_BLOCK_H
#define SPA_BLOCK_H

#include "sp/ast/Stmt.h"

class Block;

using Blocks = std::vector<std::shared_ptr<Block>>;

class Block {
private:
    std::shared_ptr<StmtList> stmts;
    std::shared_ptr<Blocks> successors;
    std::shared_ptr<Blocks> predecessors;

public:
    Block(const std::shared_ptr<StmtList>& stmts);
    void addSuccessor(const std::shared_ptr<Block>& successor);
    void addPredecessor(const std::shared_ptr<Block>& predecessor);
    std::shared_ptr<Blocks> getSuccessors();
    std::shared_ptr<Blocks> getPredecessors();
};


#endif //SPA_BLOCK_H
