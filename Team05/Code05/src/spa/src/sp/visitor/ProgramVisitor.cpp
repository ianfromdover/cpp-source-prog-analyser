//
// Created by Chua Bing Quan on 21/2/24.
//

#include "ProgramVisitor.h"
#include "sp/ast/Stmt.h"

void ProgramVisitor::visitStmtList(const shared_ptr<vector<shared_ptr<Stmt>>>& stmts, shared_ptr<Accumulator> &info) {
    for (const auto& childStmt : *stmts) {
        auto infoCopy = std::make_shared<Accumulator>(*info);
        childStmt->accept(*this, infoCopy);
    }
}

void ProgramVisitor::visitReadStmt(const Read &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitPrintStmt(const Print &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitCallStmt(const Call &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitWhileStmt(const While &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitIfStmt(const If &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitAssignStmt(const Assign &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitBinaryExpr(const Binary &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitVariableExpr(const Variable &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitLiteralExpr(const Literal &, shared_ptr<Accumulator> &) {
    // Do Nothing
}

void ProgramVisitor::visitUnaryExpr(const Unary &, shared_ptr<Accumulator> &) {
    // Do Nothing
}
