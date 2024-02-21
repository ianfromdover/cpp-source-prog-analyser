//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_RELATIONEXTRACTOR_H
#define SPA_RELATIONEXTRACTOR_H

#include "ProgramVisitor.h"
#include "pkb/PopulatePKB.h"
#include "Stmt.h"

class RelationExtractor : public ProgramVisitor {
protected:
    PopulatePKB pkb;
public:
    explicit RelationExtractor(PopulatePKB& pkb) : pkb(pkb) {}
    virtual ~RelationExtractor() = default;
    void visitProcedure(const Procedure&) override;
};


#endif //SPA_RELATIONEXTRACTOR_H
