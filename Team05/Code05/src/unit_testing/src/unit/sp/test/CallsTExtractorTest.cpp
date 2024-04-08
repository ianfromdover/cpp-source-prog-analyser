//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/relation_extractor/CallsExtractor.h"
#include "sp/ast/Program.h"

inline AstTestProgramProducer astPrograms = AstTestProgramProducer();

TEST_CASE("CallsT_TestSequentialIfIfNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "IfElseWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
            {"IfElseWithStmtsBeforeAndInside", "IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
            {"IfElseWithStmtsBeforeAndInside", "IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
    };
    auto program = astPrograms.createSequentialIfIfNestingChain();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("CallsT_TestSequentialIfWhileNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
    };
    auto program = astPrograms.createSequentialIfWhileNestingChain();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("CallsT_TestSequentialWhileIfNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
    };
    auto program = astPrograms.createSequentialWhileIfNestingChain();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("CallsT_TestSequentialWhileWhileNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "WhileWithNestedWhilePlusNestedStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
            {"WhileWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
    };
    auto program = astPrograms.createSequentialWhileWhileNestingChain();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}