//
// Created by sjh_9 on 16/2/2024.
//

#ifndef SPA_MODIFIESEXTRACTOR_H
#define SPA_MODIFIESEXTRACTOR_H

#include "RelationExtractor.h"
#include "Stmt.h"

class ModifiesExtractor: public RelationExtractor {
public:
    // Constructor
    explicit ModifiesExtractor(PopulatePKB& pkb) : RelationExtractor(pkb) {}
    // Statement Methods
    void visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    // Expression Methods
    void visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
    void visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) override;
};

#endif //SPA_MODIFIESEXTRACTOR_H
