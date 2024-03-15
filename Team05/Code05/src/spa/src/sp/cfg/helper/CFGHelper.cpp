//
// Created by Chua Bing Quan on 15/3/24.
//

#include "CFGHelper.h"

void CFGHelper::IsWhile::visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) {
    // Do nothing.
}

void CFGHelper::IsWhile::visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsWhile::visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsWhile::visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsWhile::visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = true;
}

void CFGHelper::IsWhile::visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsWhile::visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

bool CFGHelper::IsWhile::check(std::shared_ptr<Stmt>& stmt) {
    auto _ = std::make_shared<Accumulator>();
    stmt->accept(*this, _);
    return this->result;
}

void CFGHelper::IsIf::visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& _) {
    // Do nothing.
}

void CFGHelper::IsIf::visitReadStmt(const Read& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsIf::visitPrintStmt(const Print& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsIf::visitCallStmt(const Call& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsIf::visitWhileStmt(const While& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

void CFGHelper::IsIf::visitIfStmt(const If& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = true;
}

void CFGHelper::IsIf::visitAssignStmt(const Assign& stmt, std::shared_ptr<Accumulator>& _) {
    this->result = false;
}

bool CFGHelper::IsIf::check(std::shared_ptr<Stmt>& stmt) {
    auto _ = std::make_shared<Accumulator>();
    stmt->accept(*this, _);
    return this->result;
}

bool CFGHelper::isWhile(std::shared_ptr<Stmt>& stmt) {
    return IsWhile().check(stmt);
}

bool CFGHelper::isIf(std::shared_ptr<Stmt>& stmt) {
    return IsIf().check(stmt);
}