//
// Created by Chua Bing Quan on 15/3/24.
//

#ifndef SPA_CFGHELPER_H
#define SPA_CFGHELPER_H

#include "../../ast/Stmt.h"
#include "sp/visitor/ProgramVisitor.h"

class CFGHelper {
private:
    class IsWhile : private ProgramVisitor {
    private:
        bool result = false;
    private:
        void visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) override;
        void visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) override;
    public:
        bool check(std::shared_ptr<Stmt>& stmt);
    };
    class IsIf : private ProgramVisitor {
    private:
        bool result = false;
    private:
        void visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) override;
        void visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) override;
        void visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) override;
    public:
        bool check(std::shared_ptr<Stmt>& stmt);
    };
public:
    static bool isWhile(std::shared_ptr<Stmt>& stmt);
    static bool isIf(std::shared_ptr<Stmt>& stmt);
};


#endif //SPA_CFGHELPER_H
