//
// Created by Chua Bing Quan on 12/2/24.
//

#include <string>
#include "Stmt.h"

void Procedure::accept(RelationExtractor& extractor) {
    auto prevStmtInfo = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>();
    auto followsExtractor = dynamic_cast<FollowsExtractor*>(&extractor);
    if (followsExtractor != nullptr) {
        for (const auto& stmt : *this->body) {
            stmt->accept(extractor, prevStmtInfo);
            prevStmtInfo->emplace_back(stmt->getStmtNo());
        }
    } else {
        for (const auto& stmt : *this->body) {
            auto parentInfo = std::make_shared<std::vector<std::variant<StmtNo, std::string>>>();
            stmt->accept(extractor, parentInfo);
        }
    }
}

std::string Procedure::toString() const {
    std::string bodyStr;
    for (const auto& stmt : *this->body) {
        bodyStr += stmt->toString() + "\n";
    }
    return "procedure: {\n name: " + this->name + ",\n body: {\n" + bodyStr + "\n}\n}";
}

std::string Stmt::prefixStmtNo(std::string text) const {
    return std::to_string(this->stmtNo) + ". " + text;
}

StmtNo Stmt::getStmtNo() const {
    return this->stmtNo;
}

std::string Read::toString() const {
    return this->prefixStmtNo("Read: { variable: " + this->variable->toString() + " }");
};

std::string Print::toString() const {
    return this->prefixStmtNo("Print: { variable: " + this->variable->toString() + " }");
};

std::string Call::toString() const {
    return this->prefixStmtNo("Call: { procName: " + this->procName + " }");
};

std::string While::toString() const {
    std::string conditionStr = this->condition->toString();
    std::string bodyStr;
    for (const auto& stmt : *this->body) {
        bodyStr += stmt->toString() + "\n";
    }
    return this->prefixStmtNo("While: {\n condition: " + conditionStr + ",\n body: {\n" + bodyStr + "\n}\n}");
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
    std::string ifStr = "If: {\n condition: " + conditionStr + ", \n then: {\n" + thenBranchStr + "\n}\n, else: {\n"
            + elseBranchStr + "\n}\n}";
    return this->prefixStmtNo(ifStr);
};

std::string Assign::toString() const {
    return this->prefixStmtNo("Assign: {\n variable: " + this->variable->toString() + ",\n value: "
        + this->value->toString() + "\n}");
};

void Read::accept(RelationExtractor& extractor, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    extractor.visitReadStmt(*this, parentInfo);
}

void Print::accept(RelationExtractor& extractor, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    extractor.visitPrintStmt(*this, parentInfo);
}

void Call::accept(RelationExtractor& extractor, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    extractor.visitCallStmt(*this, parentInfo);
}

void While::accept(RelationExtractor& extractor, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    extractor.visitWhileStmt(*this, parentInfo);
}

void If::accept(RelationExtractor& extractor, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    extractor.visitIfStmt(*this, parentInfo);
}

void Assign::accept(RelationExtractor& extractor, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) {
    extractor.visitAssignStmt(*this, parentInfo);
}

std::unique_ptr<StmtList> const& Procedure::getBody() const {
    return this->body;
}

std::unique_ptr<Variable> const& Read::getVariable() const {
    return this->variable;
}

std::unique_ptr<Variable> const& Print::getVariable() const {
    return this->variable;
}

std::string Call::getProcName() const {
    return procName;
}

std::unique_ptr<Expr> const& While::getCondition() const {
    return this->condition;
}

std::unique_ptr<StmtList> const& While::getBody() const {
    return this->body;
}

std::unique_ptr<Expr> const& If::getCondition() const {
    return this->condition;
}

std::unique_ptr<StmtList> const& If::getThenBranch() const {
    return this->thenBranch;
}

std::unique_ptr<StmtList> const& If::getElseBranch() const {
    return this->elseBranch;
}

std::unique_ptr<Expr> const& Assign::getVariable() const {
    return this->variable;
}

std::unique_ptr<Expr> const& Assign::getValue() const {
    return this->value;
}
