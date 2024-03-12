//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProgram.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/relation_extractor/CallsExtractor.h"
#include "sp/ast/Program.h"

TEST_CASE("Calls_TestSequentialNestingChain") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"AssignCallPrintRead", "IfElseWithStmtsBeforeAndInside"},
            {"IfElseWithStmtsBeforeAndInside", "IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"},
    };
    auto program = AstProgram::createSequentialNestingChain();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallsExtractor>(pkb, program);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}