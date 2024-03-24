//
// Created by Chua Bing Quan on 21/3/24.
//

#ifndef SPA_TOKENIZEDTESTPROGRAMPRODUCER_H
#define SPA_TOKENIZEDTESTPROGRAMPRODUCER_H

#include "TestProgramProducer.h"
#include "TokenFactory.h"

class TokenizedTestProgramProducer : public TestProgramProducer<TokenStream> {
public:
    // Zero Nesting Level
    std::shared_ptr<TokenStream> createAssignCallPrintRead() const override;

    // Single Nesting Level
    std::shared_ptr<TokenStream> createIfElseWithStmtsBeforeAndInside() const override;
    std::shared_ptr<TokenStream> createIfElseWithStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<TokenStream> createIfElseWithStmtsAfterAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithStmtsBeforeAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithStmtsAfterAndInside() const override;

    // Double Nesting Level
    std::shared_ptr<TokenStream> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<TokenStream> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<TokenStream> createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside() const override;
    std::shared_ptr<TokenStream> createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<TokenStream> createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<TokenStream> createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const override;
    std::shared_ptr<TokenStream> createWhileWithNestedWhilePlusNestedStmtsAfterAndInside() const override;

    // Multiple Procedures in a Program
    std::shared_ptr<TokenStream> createSequentialIfIfNestingChain() const override;
    std::shared_ptr<TokenStream> createSequentialWhileIfNestingChain() const override;
    std::shared_ptr<TokenStream> createSequentialIfWhileNestingChain() const override;
    std::shared_ptr<TokenStream> createSequentialWhileWhileNestingChain() const override;
};


#endif //SPA_TOKENIZEDTESTPROGRAMPRODUCER_H
