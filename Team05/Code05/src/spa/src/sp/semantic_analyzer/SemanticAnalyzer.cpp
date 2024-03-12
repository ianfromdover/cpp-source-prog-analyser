//
// Created by Chua Bing Quan on 21/2/24.
//

#include "SemanticAnalyzer.h"
#include "sp/exception/SemanticAnalysisException.h"

void SemanticAnalyzer::check(const std::shared_ptr<Program>& program) {
    this->setupCallGraph(program);
    this->populateCallGraph(program);
    this->detectCyclicCalls();
}

void SemanticAnalyzer::setupCallGraph(const std::shared_ptr<Program>& program) {
    for (const auto& procedure : *program->getProcedures()) {
        const auto name = procedure->getName();
        if (this->callGraph.find(name) != this->callGraph.end()) {
            const auto errMsg = "Repeated procedure names \"" + name + "\" is not allowed";
            throw SemanticAnalysisException(errMsg);
        }
        callGraph.insert(std::pair(name, std::vector<std::string>()));
    }
}

void SemanticAnalyzer::populateCallGraph(const std::shared_ptr<Program>& program) {
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*this);
    }
}

void SemanticAnalyzer::detectCyclicCalls() {
    if (this->isCyclic()) {
        const auto errMsg = "Recursive and cyclic calls are not allowed";
        throw SemanticAnalysisException(errMsg);
    }
}

bool SemanticAnalyzer::isCyclic() {
    std::unordered_set<std::string> visited;
    std::unordered_set<std::string> inPath;

    for (const auto& caller : this->callGraph) {
        if (visited.find(caller.first) == visited.end()) {
            if (this->isCyclicHelper(caller.first, visited, inPath)) {
                return true;
            }
        }
    }

    return false;
}

bool SemanticAnalyzer::isCyclicHelper(const std::string& caller, std::unordered_set<std::string>& visited,
                                      std::unordered_set<std::string>& inPath) {
    if (visited.find(caller) == visited.end()) {
        visited.insert(caller);
        inPath.insert(caller);

        for (const auto& callee : this->callGraph.at(caller)) {
            if (visited.find(callee) == visited.end() && this->isCyclicHelper(callee, visited, inPath)) {
                return true;
            } else if (inPath.find(callee) != inPath.end()) {
                return true;
            }
        }
    }

    inPath.erase(caller);
    return false;
}

void SemanticAnalyzer::visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& info) {
    this->currentProcedure = procedure.getName();
    for (const auto& stmt : *procedure.getBody()) {
        auto _ = std::make_shared<Accumulator>();
        stmt->accept(*this, _);
    }
    this->currentProcedure = "";
}

void SemanticAnalyzer::visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& a) {}

void SemanticAnalyzer::visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& a) {}

void SemanticAnalyzer::visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& a) {
    const auto name = stmt.getProcName();
    if (this->callGraph.find(name) == this->callGraph.end()) {
        const auto errMsg = "Calling of unknown procedure \"" + name + "\" is not allowed";
        throw SemanticAnalysisException(errMsg);
    }
    this->callGraph.at(this->currentProcedure).push_back(name);
}

void SemanticAnalyzer::visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& a) {
    for (const auto& bodyStmt : *stmt.getBody()) {
        auto _ = make_shared<Accumulator>();
        bodyStmt->accept(*this, _);
    }
}

void SemanticAnalyzer::visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& a) {
    for (const auto& bodyStmt : *stmt.getThenBranch()) {
        auto _ = make_shared<Accumulator>();
        bodyStmt->accept(*this, _);
    }
    for (const auto& bodyStmt : *stmt.getElseBranch()) {
        auto _ = make_shared<Accumulator>();
        bodyStmt->accept(*this, _);
    }
}

void SemanticAnalyzer::visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& a) {}

void SemanticAnalyzer::visitBinaryExpr(const Binary& expr, std::shared_ptr<Accumulator>& a) {}

void SemanticAnalyzer::visitVariableExpr(const Variable& expr, std::shared_ptr<Accumulator>& a) {}

void SemanticAnalyzer::visitLiteralExpr(const Literal& expr, std::shared_ptr<Accumulator>& a) {}

void SemanticAnalyzer::visitUnaryExpr(const Unary& expr, std::shared_ptr<Accumulator>& a) {}