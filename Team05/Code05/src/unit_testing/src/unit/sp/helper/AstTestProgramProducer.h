//
// Created by Chua Bing Quan on 21/3/24.
//

#ifndef SPA_ASTTESTPROGRAMPRODUCER_H
#define SPA_ASTTESTPROGRAMPRODUCER_H

#include "../helper/TestProgramProducer.h"
#include "sp/ast/Program.h"

class AstTestProgramProducer : TestProgramProducer<Program> {
public:
    // Zero Nesting Level
    std::shared_ptr<Program> createAssignCallPrintRead() const override;

    // Single Nesting Level
    std::shared_ptr<Program> createIfElseWithStmtsBeforeAndInside() const override;
    std::shared_ptr<Program> createIfElseWithStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<Program> createIfElseWithStmtsAfterAndInside() const override;
    std::shared_ptr<Program> createWhileWithStmtsBeforeAndInside() const override;
    std::shared_ptr<Program> createWhileWithStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<Program> createWhileWithStmtsAfterAndInside() const override;

    // Double Nesting Level
    std::shared_ptr<Program> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<Program> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<Program> createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside() const override;
    std::shared_ptr<Program> createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<Program> createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<Program> createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside() const override;
    std::shared_ptr<Program> createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<Program> createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<Program> createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside() const override;
    std::shared_ptr<Program> createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<Program> createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<Program> createWhileWithNestedWhilePlusNestedStmtsAfterAndInside() const override;

    // Multiple Procedures in a Program
    std::shared_ptr<Program> createSequentialNestingChain() const override;
};


#endif //SPA_ASTTESTPROGRAMPRODUCER_H
