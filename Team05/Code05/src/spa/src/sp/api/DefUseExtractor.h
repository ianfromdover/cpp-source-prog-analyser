//
// Created by Chua Bing Quan on 27/3/24.
//

#ifndef SPA_DEFUSEEXTRACTOR_H
#define SPA_DEFUSEEXTRACTOR_H

#include "sp/cfg/CFG.h"
#include "sp/visitor/ProgramVisitor.h"
#include "VarPoint.h"

using Definitions = unordered_map<std::shared_ptr<Block>, std::unordered_set<VarPoint>>;
using Uses = Definitions;

class DefUseExtractor : private ProgramVisitor {
private:
    Definitions defs;
    Uses uses;
    std::shared_ptr<Block> currentBlock;
private:
    void addToDefinitions(const VarPoint& var);
    void addToUses(const VarPoint& var);
private:
    void visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) override;
    void visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) override;
    void visitBinaryExpr(const Binary& expr, std::shared_ptr<Accumulator>& acc) override;
    void visitVariableExpr(const Variable& expr, std::shared_ptr<Accumulator>& acc) override;
    void visitUnaryExpr(const Unary& expr, std::shared_ptr<Accumulator>& acc) override;
public:
    explicit DefUseExtractor() = default;
    std::pair<Definitions, Uses> extract(const std::shared_ptr<CFG>& cfg);
};


#endif //SPA_DEFUSEEXTRACTOR_H
