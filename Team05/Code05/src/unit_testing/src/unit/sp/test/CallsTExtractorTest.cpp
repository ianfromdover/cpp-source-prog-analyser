//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProgram.cpp"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/relation_extractor/CallsExtractor.h"
#include "sp/ast/Program.h"

TEST_CASE("CallsT_TestSequentialIfIfNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "IfElseWithStmtsBeforeAndInside"},
            {"AssignCallPrintRead", "IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
            {"IfElseWithStmtsBeforeAndInside", "IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"}
    };
    auto program = AstProgram::createSequentialIfIfNestingChain();
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
    };
    auto program = AstProgram::createSequentialIfWhileNestingChain();
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
    };
    auto program = AstProgram::createSequentialWhileIfNestingChain();
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
    };
    auto program = AstProgram::createSequentialWhileWhileNestingChain();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}