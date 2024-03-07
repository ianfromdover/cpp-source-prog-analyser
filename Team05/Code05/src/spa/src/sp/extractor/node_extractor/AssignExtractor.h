//
// Created by sjh_9 on 17/2/2024.
//

#ifndef SPA_ASSIGNEXTRACTOR_H
#define SPA_ASSIGNEXTRACTOR_H

#include <utility>

#include "sp/extractor/RelationExtractor.h"

class AssignExtractor: public RelationExtractor {
public:
    // Constructor
    explicit AssignExtractor(shared_ptr<BasePKBPopulator> pkb) : RelationExtractor(std::move(pkb)) {}
    // Statement Methods
    void visitWhileStmt(const While& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitIfStmt(const If& stmt, shared_ptr<Accumulator>& parentInfo) override;
    void visitAssignStmt(const Assign& stmt, shared_ptr<Accumulator>& parentInfo) override;
    // Expression Methods
};



#endif //SPA_ASSIGNEXTRACTOR_H
