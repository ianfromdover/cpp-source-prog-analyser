//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_RELATIONEXTRACTOR_H
#define SPA_RELATIONEXTRACTOR_H
#include <variant>
#include <iostream>
#include <vector>
#include "pkb/PopulatePKB.h"

class Read;
class Print;
class Call;
class While;
class If;
class Assign;
class Expr;
class Binary;
class Variable;
class Literal;
class Unary;


class RelationExtractor {
protected:
    PopulatePKB pkb;
public:
    RelationExtractor(PopulatePKB& pkb) : pkb(pkb) {}
    virtual ~RelationExtractor() = default;
    // Statement Methods
    virtual void visitReadStmt(const Read& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    virtual void visitPrintStmt(const Print& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    virtual void visitCallStmt(const Call& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo)= 0;
    virtual void visitWhileStmt(const While& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    virtual void visitIfStmt(const If& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    virtual void visitAssignStmt(const Assign& stmt, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    // Expression Methods
    virtual void visitBinaryExpr(const Binary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    virtual void visitVariableExpr(const Variable& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    virtual void visitLiteralExpr(const Literal& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;
    virtual void visitUnaryExpr(const Unary& expr, shared_ptr<std::vector<std::variant<StmtNo, std::string>>>& parentInfo) = 0;

};


#endif //SPA_RELATIONEXTRACTOR_H
