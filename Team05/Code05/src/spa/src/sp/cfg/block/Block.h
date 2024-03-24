//
// Created by Chua Bing Quan on 15/3/24.
//

#ifndef SPA_BLOCK_H
#define SPA_BLOCK_H

#include <optional>
#include "sp/ast/Stmt.h"
#include "sp/extractor/CfgExtractor.h"

class Block;

using Blocks = std::vector<std::shared_ptr<Block>>;

class Block {
private:
    std::shared_ptr<StmtList> stmts;
    std::shared_ptr<Blocks> successors;
    std::shared_ptr<Blocks> predecessors;
private:
    static std::string rangeToString(const std::shared_ptr<Block>& block);
    static std::string rangesToString(const std::shared_ptr<Blocks>& blocks);
public:
    explicit Block();
    std::optional<std::pair<StmtNo, StmtNo>> getRange();
    void addStmt(const std::shared_ptr<Stmt>& stmt);
    void addSuccessor(const std::shared_ptr<Block>& successor);
    void addPredecessor(const std::shared_ptr<Block>& predecessor);
    bool isDummy();
    std::string toString() const;
    [[nodiscard]] std::shared_ptr<StmtList> getStmts() const;
    [[nodiscard]] std::shared_ptr<Blocks> getSuccessors() const;
    [[nodiscard]] std::shared_ptr<Blocks> getPredecessors() const;
};


#endif //SPA_BLOCK_H
