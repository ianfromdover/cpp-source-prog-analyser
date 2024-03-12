//
// Created by sjh_9 on 8/3/2024.
//

#include "CallsExtractor.h"

void CallsExtractor::visitProcedure(const Procedure &procedure, std::shared_ptr<Accumulator>& info) {
    if (this->visitedProcedures.find(procedure.getName()) == this->visitedProcedures.end()) {
        this->visitedProcedures.insert(procedure.getName());
        auto parentInfo = std::make_shared<Accumulator>(*info);
        parentInfo->stringInfo.emplace_back(procedure.getName());
        this->visitStmtList(procedure.getBody(), parentInfo);
    }
}

void CallsExtractor::visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getBody(), parentInfo);
}

void CallsExtractor::visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) {
    this->visitStmtList(stmt.getThenBranch(), parentInfo);
    this->visitStmtList(stmt.getElseBranch(), parentInfo);
}


void CallsExtractor::visitCallStmt(const Call &stmt, shared_ptr<Accumulator> &parentInfo) {
    if (this->visitedProcedures.find(stmt.getProcName()) == this->visitedProcedures.end()) {
        for (auto& procName : parentInfo->stringInfo) {
            if (&procName == &parentInfo->stringInfo.back()) {
                //std::cout << "pkb.addCalls(" << procName << ", " << stmt.getProcName() << ");" << std::endl;
                pkb->addCalls(procName, stmt.getProcName());
            }
            //std::cout << "pkb.addCallsT(" << procName << ", " << stmt.getProcName() << ");" << std::endl;
            pkb->addCallsT(procName, stmt.getProcName());
        }
        this->visitProcedure(*this->program->getProcedure(stmt.getProcName()), parentInfo);
    }
}
