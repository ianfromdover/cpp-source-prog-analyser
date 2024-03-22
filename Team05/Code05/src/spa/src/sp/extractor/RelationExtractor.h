//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_RELATIONEXTRACTOR_H
#define SPA_RELATIONEXTRACTOR_H

#include <utility>

#include "sp/visitor/ProgramVisitor.h"
#include "pkb/apis/PopulatePkb.h"
#include "sp/ast/Stmt.h"

class RelationExtractor : public ProgramVisitor {
protected:
    shared_ptr<BasePkbPopulator> pkb;
public:
    explicit RelationExtractor(shared_ptr<BasePkbPopulator> pkb) : pkb(std::move(pkb)) {}
    virtual ~RelationExtractor() = default;
    void visitProcedure(const Procedure&, std::shared_ptr<Accumulator>&) override;
};


#endif //SPA_RELATIONEXTRACTOR_H
