//
// Created by Chua Bing Quan on 15/3/24.
//

#ifndef SPA_CFG_H
#define SPA_CFG_H

#include <vector>
#include "sp/ast/Program.h"
#include "sp/cfg/block/Block.h"

class CFG;

using CFGs = std::unordered_map<std::string, std::shared_ptr<CFG>>;

class CFG : private ProgramVisitor {
private:
    std::string procedureName;
    std::shared_ptr<Blocks> blocks;
private:
    void compile(const std::shared_ptr<Procedure>& procedure);
    void addAndLinkBlock(const std::shared_ptr<Block>& block);
    void addBlock(const std::shared_ptr<Block>& block);
    void addEdge(const std::shared_ptr<Block>& predecessor, const std::shared_ptr<Block>& successor);
    void addStmtToLastBlock(const std::shared_ptr<Stmt>& stmt);
    bool isLastBlockEmpty();
private:
    void visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) override;
    void visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) override;
public:
    explicit CFG(const std::shared_ptr<Procedure>& procedure);
    void accept(CfgExtractor& visitor) const;
    [[nodiscard]] std::shared_ptr<Block> getEntryBlock() const;
    [[nodiscard]] std::shared_ptr<Blocks> getBlocks() const;
    std::string toString();
    static std::shared_ptr<CFGs> compile(const std::shared_ptr<Program>& program);
};


#endif //SPA_CFG_H
