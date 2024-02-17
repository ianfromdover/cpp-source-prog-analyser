//
// Created by sjh_9 on 16/2/2024.
//

#ifndef SPA_FOLLOWSEXTRACTOR_H
#define SPA_FOLLOWSEXTRACTOR_H

#include "RelationExtractor.h"
#include "Stmt.h"

class FollowsExtractor: public RelationExtractor {
public:
    // Constructor
    explicit FollowsExtractor(PopulatePKB& pkb) : RelationExtractor(pkb) {}
    // Statement Methods
    void visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    // Expression Methods
    void visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
    void visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& prevStmtInfo) override;
};


#endif //SPA_FOLLOWSEXTRACTOR_H
