//
// Created by Chua Bing Quan on 12/2/24.
//

#include "Stmt.h"

void Procedure::accept(RelationExtractor& extractor) {
    for (const auto& stmt : *this->body) {
        stmt->accept(extractor);
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

void Read::accept(RelationExtractor& extractor) {
    extractor.visitReadStmt(this);
}

void Print::accept(RelationExtractor& extractor) {
    extractor.visitPrintStmt(this);
}

void Call::accept(RelationExtractor& extractor) {
    extractor.visitCallStmt(this);
}

void While::accept(RelationExtractor& extractor) {
    extractor.visitWhileStmt(this);
}

void If::accept(RelationExtractor& extractor) {
    extractor.visitIfStmt(this);
}

void Assign::accept(RelationExtractor& extractor) {
    extractor.visitAssignStmt(this);
}

std::unique_ptr<StmtList> const& While::getBody() const {
    return this->body;
}

std::unique_ptr<StmtList> const& If::getThenBranch() const {
    return this->thenBranch;
}

std::unique_ptr<StmtList> const& If::getElseBranch() const {
    return this->elseBranch;
}

