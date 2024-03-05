//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_RELATIONEXTRACTOR_H
#define SPA_RELATIONEXTRACTOR_H

#include <utility>

#include "sp/visitor/ProgramVisitor.h"
#include "pkb/apis/PopulatePKB.h"
#include "sp/parser/ast/Stmt.h"

class RelationExtractor : public ProgramVisitor {
protected:
    shared_ptr<BasePKBPopulator> pkb;
public:
    explicit RelationExtractor(shared_ptr<BasePKBPopulator> pkb) : pkb(std::move(pkb)) {}
    virtual ~RelationExtractor() = default;
    void visitProcedure(const Procedure&) override;
};


#endif //SPA_RELATIONEXTRACTOR_H
