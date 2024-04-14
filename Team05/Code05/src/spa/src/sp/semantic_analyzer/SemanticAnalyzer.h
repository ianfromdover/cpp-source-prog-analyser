//
// Created by Chua Bing Quan on 21/2/24.
//

#ifndef SPA_SEMANTICANALYZER_H
#define SPA_SEMANTICANALYZER_H

#include "sp/ast/Stmt.h"
#include "sp/ast/Program.h"

class SemanticAnalyzer : private ProgramVisitor {
private:
    unordered_map<std::string, std::vector<std::string>> callGraph;
    std::string currentProcedure;
private:
    void setupCallGraph(const std::shared_ptr<Program>& program);
    void populateCallGraph(const std::shared_ptr<Program>& program);
    void detectCyclicCalls();
    bool isCyclic();
    bool isCyclicHelper(const std::string& caller, std::unordered_set<std::string>& visited, std::unordered_set<std::string>& inPath);
private:
    void visitProcedure(const Procedure&, std::shared_ptr<Accumulator>&) override;
    void visitReadStmt(const Read&, std::shared_ptr<Accumulator>&) override;
    void visitPrintStmt(const Print&, std::shared_ptr<Accumulator>&) override;
    void visitCallStmt(const Call&, std::shared_ptr<Accumulator>&)override;
    void visitWhileStmt(const While&, std::shared_ptr<Accumulator>&) override;
    void visitIfStmt(const If&, std::shared_ptr<Accumulator>&) override;
    void visitAssignStmt(const Assign&, std::shared_ptr<Accumulator>&) override;
    void visitBinaryExpr(const Binary&, std::shared_ptr<Accumulator>&) override;
    void visitVariableExpr(const Variable&, std::shared_ptr<Accumulator>&) override;
    void visitLiteralExpr(const Literal&, std::shared_ptr<Accumulator>&) override;
    void visitUnaryExpr(const Unary&, std::shared_ptr<Accumulator>&) override;
public:
    void check(const std::shared_ptr<Program>& program);
};

#endif //SPA_SEMANTICANALYZER_H
