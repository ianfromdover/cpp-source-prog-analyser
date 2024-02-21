//
// Created by Chua Bing Quan on 12/2/24.
//

#include <string>
#include "Stmt.h"

void Procedure::accept(RelationExtractor& extractor) {
    auto prevStmtInfo = std::make_shared<Accumulator>();
    auto followsExtractor = dynamic_cast<FollowsExtractor*>(&extractor);
    if (followsExtractor != nullptr) {
        for (const auto& stmt : *this->body) {
            stmt->accept(extractor, prevStmtInfo);
            prevStmtInfo->info.emplace_back(stmt->getStmtNo());
        }
    } else {
        for (const auto& stmt : *this->body) {
            auto parentInfo = std::make_shared<Accumulator>();
            stmt->accept(extractor, parentInfo);
        }
    }
}

std::string Procedure::toString() const {
    std::string bodyStr;
    for (const auto& stmt : *this->body) {
        bodyStr += stmt->toString() + "\n";
    }
    return "procedure(" + this->name + "): " + "[\n" + bodyStr + "]";
}

std::string Stmt::prefixStmtNo(std::string text) const {
    return std::to_string(this->stmtNo) + ". " + text;
}

StmtNo Stmt::getStmtNo() const {
    return this->stmtNo;
}

std::string Read::toString() const {
    return this->prefixStmtNo("read: " + this->variable->toString());
};

std::string Print::toString() const {
    return this->prefixStmtNo("print: " + this->variable->toString());
};

std::string Call::toString() const {
    return this->prefixStmtNo("call: " + this->procName);
};

std::string While::toString() const {
    std::string conditionStr = this->condition->toString();
    std::string bodyStr;
    for (const auto& stmt : *this->body) {
        bodyStr += stmt->toString() + "\n";
    }
    return this->prefixStmtNo("while(" + conditionStr + "): [\n" + bodyStr + "]");
};

std::string If::toString() const {
    std::string conditionStr = this->condition->toString();
    std::string thenBranchStr;
    for (const auto& stmt : *this->thenBranch) {
        thenBranchStr += stmt->toString() + "\n";
    }
    std::string elseBranchStr;
    for (const auto& stmt : *this->elseBranch) {
        elseBranchStr += stmt->toString() + "\n";
    }
    return this->prefixStmtNo("if(" + conditionStr + ") then: [\n" + thenBranchStr + "] else: [\n" + elseBranchStr + "]");
};

std::string Assign::toString() const {
    return this->prefixStmtNo("assign: " + this->variable->toString() + " = " + this->value->toString());
};

void Read::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitReadStmt(*this, parentInfo);
}

void Print::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitPrintStmt(*this, parentInfo);
}

void Call::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitCallStmt(*this, parentInfo);
}

void While::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitWhileStmt(*this, parentInfo);
}

void If::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitIfStmt(*this, parentInfo);
}

void Assign::accept(RelationExtractor& extractor, shared_ptr<Accumulator>& parentInfo) {
    extractor.visitAssignStmt(*this, parentInfo);
}

std::shared_ptr<StmtList> const& Procedure::getBody() const {
    return this->body;
}

std::string Procedure::getProcName() const {
    return this->name;
}

std::shared_ptr<Variable> const& Read::getVariable() const {
    return this->variable;
}

std::shared_ptr<Variable> const& Print::getVariable() const {
    return this->variable;
}

std::string Call::getProcName() const {
    return procName;
}

std::shared_ptr<Expr> const& While::getCondition() const {
    return this->condition;
}

std::shared_ptr<StmtList> const& While::getBody() const {
    return this->body;
}

std::shared_ptr<Expr> const& If::getCondition() const {
    return this->condition;
}

std::shared_ptr<StmtList> const& If::getThenBranch() const {
    return this->thenBranch;
}

std::shared_ptr<StmtList> const& If::getElseBranch() const {
    return this->elseBranch;
}

std::shared_ptr<Expr> const& Assign::getVariable() const {
    return this->variable;
}

std::shared_ptr<Expr> const& Assign::getValue() const {
    return this->value;
}
