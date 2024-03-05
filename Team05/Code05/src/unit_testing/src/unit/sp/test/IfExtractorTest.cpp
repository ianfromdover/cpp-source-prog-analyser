//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/node_extractor/IfExtractor.h"

//If_TestZeroNestingLevel

TEST_CASE("If_TestAssignCallReadPrint") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createAssignCallReadPrint();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//If_TestSingleNestingLevel

TEST_CASE("If_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//If_TestDoubleNestingLevel

TEST_CASE("If_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"6", "x"},
            {"19", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"6", "x"},
            {"23", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"15", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "x"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "x"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "x"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("If_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<IfExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}