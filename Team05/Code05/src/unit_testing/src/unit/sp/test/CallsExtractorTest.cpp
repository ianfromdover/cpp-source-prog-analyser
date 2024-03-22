//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProgram.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/relation_extractor/CallsExtractor.h"
#include "sp/ast/Program.h"

TEST_CASE("Calls_TestSequentialIfIfNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "IfElseWithStmtsBeforeAndInside"},
            {"IfElseWithStmtsBeforeAndInside", "IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
    };
    auto program = AstProgram::createSequentialIfIfNestingChain();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Calls_TestSequentialIfWhileNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside"},
            {"IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
    };
    auto program = AstProgram::createSequentialIfWhileNestingChain();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Calls_TestSequentialWhileIfNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
            {"WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
    };
    auto program = AstProgram::createSequentialWhileIfNestingChain();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Calls_TestSequentialWhileWhileNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "WhileWithNestedWhilePlusNestedStmtsBeforeAndInside"},
            {"WhileWithNestedWhilePlusNestedStmtsBeforeAndInside", "WhileWithStmtsBeforeAndInside"},
    };
    auto program = AstProgram::createSequentialWhileWhileNestingChain();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}