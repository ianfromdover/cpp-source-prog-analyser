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
private:
    std::optional<std::pair<StmtNo, StmtNo>> getRange();
    static std::string rangeToString(const std::shared_ptr<Block>& block);
    static std::string rangesToString(const std::shared_ptr<Blocks>& blocks);
public:
    explicit Block();
    void addStmt(const std::shared_ptr<Stmt>& stmt);
    void addSuccessor(const std::shared_ptr<Block>& successor);
    void addPredecessor(const std::shared_ptr<Block>& predecessor);
    std::string toString();
    [[nodiscard]] std::shared_ptr<StmtList> getStmts() const;
    [[nodiscard]] std::shared_ptr<Blocks> getSuccessors() const;
    [[nodiscard]] std::shared_ptr<Blocks> getPredecessors() const;
};


#endif //SPA_BLOCK_H
