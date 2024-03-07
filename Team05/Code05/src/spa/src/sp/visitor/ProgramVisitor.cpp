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