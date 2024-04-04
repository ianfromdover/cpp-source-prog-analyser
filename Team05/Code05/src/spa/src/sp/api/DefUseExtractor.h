//
// Created by Chua Bing Quan on 27/3/24.
//

#ifndef SPA_DEFUSEEXTRACTOR_H
#define SPA_DEFUSEEXTRACTOR_H

#include "sp/cfg/CFG.h"
#include "sp/visitor/ProgramVisitor.h"
#include "VarPoint.h"
#include "pkb/apis/QueryPkb.h"

using Definitions = unordered_map<std::shared_ptr<Block>, std::unordered_set<VarPoint>>;
using Uses = Definitions;

class DefUseExtractor : private ProgramVisitor {
private:
    Definitions defs;
    Uses uses;
    using Calls = Definitions;
    Calls calls;
    std::shared_ptr<Block> currentBlock;
    std::shared_ptr<QueryPkb> queryPkb;
private:
    void extractDefinitionsFromCalls();
    void addToDefinitions(const VarPoint& def);
    void addToUses(const VarPoint& use);
    void addToCalls(const VarPoint& call);
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
    explicit DefUseExtractor(const std::shared_ptr<QueryPkb>& queryPkb) : queryPkb(queryPkb) {}
    std::pair<Definitions, Uses> extract(const std::shared_ptr<CFG>& cfg);
};


#endif //SPA_DEFUSEEXTRACTOR_H
