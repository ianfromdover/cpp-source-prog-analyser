//
// Created by Chua Bing Quan on 20/3/24.
//

#ifndef SPA_TESTPROGRAMPRODUCER_H
#define SPA_TESTPROGRAMPRODUCER_H

#include <memory>

template <typename T>
class TestProgramProducer {
public:
    // Zero Nesting Level
    virtual std::shared_ptr<T> createAssignCallPrintRead() const;

    // Single Nesting Level
    virtual std::shared_ptr<T> createIfElseWithStmtsBeforeAndInside() const;
    virtual std::shared_ptr<T> createIfElseWithStmtsBeforeAfterAndInside() const;
    virtual std::shared_ptr<T> createIfElseWithStmtsAfterAndInside() const;
    virtual std::shared_ptr<T> createWhileWithStmtsBeforeAndInside() const;
    virtual std::shared_ptr<T> createWhileWithStmtsBeforeAfterAndInside() const;
    virtual std::shared_ptr<T> createWhileWithStmtsAfterAndInside() const;

    // Double Nesting Level
    virtual std::shared_ptr<T> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside() const;
    virtual std::shared_ptr<T> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const;
    virtual std::shared_ptr<T> createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside() const;
    virtual std::shared_ptr<T> createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside() const;
    virtual std::shared_ptr<T> createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const;
    virtual std::shared_ptr<T> createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside() const;
    virtual std::shared_ptr<T> createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside() const;
    virtual std::shared_ptr<T> createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const;
    virtual std::shared_ptr<T> createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside() const;
    virtual std::shared_ptr<T> createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside() const;
    virtual std::shared_ptr<T> createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const;
    virtual std::shared_ptr<T> createWhileWithNestedWhilePlusNestedStmtsAfterAndInside() const;

    // Multiple Procedures in a Program
    virtual std::shared_ptr<T> createSequentialNestingChain() const;
};

#endif //SPA_TESTPROGRAMPRODUCER_H
