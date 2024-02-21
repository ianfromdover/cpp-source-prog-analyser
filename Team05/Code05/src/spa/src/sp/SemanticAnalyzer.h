//
// Created by Chua Bing Quan on 21/2/24.
//

#ifndef SPA_SEMANTICANALYZER_H
#define SPA_SEMANTICANALYZER_H


#include "Stmt.h"

class SemanticAnalyzer : public ProgramVisitor {
private:
    unordered_map<std::string, std::vector<std::string>> callGraph;
    std::string currentProcedure;
    void preprocess(const Program& program);
    void populateCallGraph(const Program& program);
    void detectCyclicCalls();
    bool isCyclic();
    bool isCyclicHelper(const std::string& caller, std::unordered_set<std::string>& visited, std::unordered_set<std::string>& inPath);
public:
    void check(const Program& program);
    // Top-level Methods.
    void visitProcedure(const Procedure&) override;
    // Statement Methods
    void visitReadStmt(const Read&, std::shared_ptr<Accumulator>&) override;
    void visitPrintStmt(const Print&, std::shared_ptr<Accumulator>&) override;
    void visitCallStmt(const Call&, std::shared_ptr<Accumulator>&)override;
    void visitWhileStmt(const While&, std::shared_ptr<Accumulator>&) override;
    void visitIfStmt(const If&, std::shared_ptr<Accumulator>&) override;
    void visitAssignStmt(const Assign&, std::shared_ptr<Accumulator>&) override;
    // Expression Methods
    void visitBinaryExpr(const Binary&, std::shared_ptr<Accumulator>&) override;
    void visitVariableExpr(const Variable&, std::shared_ptr<Accumulator>&) override;
    void visitLiteralExpr(const Literal&, std::shared_ptr<Accumulator>&) override;
    void visitUnaryExpr(const Unary&, std::shared_ptr<Accumulator>&) override;
};


#endif //SPA_SEMANTICANALYZER_H
