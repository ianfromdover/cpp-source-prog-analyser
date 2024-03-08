//
// Created by sjh_9 on 8/3/2024.
//

#include "CallsExtractor.h"

void CallsExtractor::visitProcedure(const Procedure &procedure) {
    // If procedure has been visited
    if (visitedProcedures.find(procedure.getName()) != visitedProcedures.end()) {
        // Do Nothing
    } else {
        visitedProcedures.insert(procedure.getName());
        for (const auto& stmt : *procedure.getBody()) {
            auto parentInfo = std::make_shared<Accumulator>();
            parentInfo->stringInfo.emplace_back(procedure.getName());
            stmt->accept(*this, parentInfo);
        }
    }
}

void CallsExtractor::visitCallStmt(const Call &stmt, shared_ptr<Accumulator> &parentInfo) {
    if (visitedProcedures.find(stmt.getProcName()) != visitedProcedures.end()) {
        // Do Nothing
    } else {
        for (auto& procName : parentInfo->stringInfo) {
            if (&procName == &parentInfo->stringInfo.back()) {
                //std::cout << "pkb.addCalls(" << procName << ", " << stmt.getProcName() << ");" << std::endl;
                pkb->addCalls(procName, stmt.getProcName());
            }
            std::cout << "pkb.addCallsT(" << procName << ", " << stmt.getProcName() << ");" << std::endl;
            pkb->addCallsT(procName, stmt.getProcName());
        }
        visitedProcedures.insert(stmt.getProcName());
        auto procedure = program->getProcedure(stmt.getProcName());
        parentInfo->stringInfo.emplace_back(stmt.getProcName());
        this->visitStmtList(procedure->getBody(), parentInfo);
    }
}
