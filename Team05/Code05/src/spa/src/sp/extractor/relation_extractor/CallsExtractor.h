//
// Created by sjh_9 on 8/3/2024.
//

#ifndef SPA_CALLSEXTRACTOR_H
#define SPA_CALLSEXTRACTOR_H

#include "sp/extractor/RelationExtractor.h"
#include "sp/ast/Program.h"

class CallsExtractor : public RelationExtractor {
private:
    std::unordered_set<std::string> visitedProcedures;
    std::shared_ptr<Program> program;
public:
    // Constructor
    explicit CallsExtractor(shared_ptr<BasePKBPopulator> pkb, shared_ptr<Program> program)
    : RelationExtractor(std::move(pkb)), program(std::move(program)) {}
    void visitProcedure(const Procedure &procedure, std::shared_ptr<Accumulator>& info) override;
    // Statement Methods
    void visitCallStmt(const Call& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitWhileStmt(const While &stmt, shared_ptr<Accumulator> &parentInfo) override;
    void visitIfStmt(const If &stmt, shared_ptr<Accumulator> &parentInfo) override;
};


#endif //SPA_CALLSEXTRACTOR_H
