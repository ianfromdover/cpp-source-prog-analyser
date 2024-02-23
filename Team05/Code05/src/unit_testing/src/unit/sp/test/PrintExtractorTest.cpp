//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/PrintExtractor.h"

//Print_TestZeroNestingLevel

TEST_CASE("Print_TestAssignCallReadPrint") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "u"}
    };
    auto procedure = AstProcedures::createAssignCallReadPrint();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Print_TestSingleNestingLevel

TEST_CASE("Print_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "u"},
            {"9", "u"},
            {"13", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "u"},
            {"9", "u"},
            {"13", "u"},
            {"17", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"9", "u"},
            {"13", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "u"},
            {"9", "u"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "u"},
            {"9", "u"},
            {"13", "u"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"9", "u"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Print_TestDoubleNestingLevel

TEST_CASE("Print_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
            {"14", "u"},
            {"18", "u"},
            {"23", "u"},
            {"27", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
            {"14", "u"},
            {"18", "u"},
            {"22", "u"},
            {"27", "u"},
            {"31", "u"},
            {"35", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "u"},
            {"10", "u"},
            {"14", "u"},
            {"19", "u"},
            {"23", "u"},
            {"27", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
            {"14", "u"},
            {"19", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
            {"14", "u"},
            {"18", "u"},
            {"23", "u"},
            {"27", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "u"},
            {"10", "u"},
            {"15", "u"},
            {"19", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
            {"14", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
            {"14", "u"},
            {"18", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "u"},
            {"10", "u"},
            {"14", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "u"},
            {"10", "u"},
            {"14", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Print_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "u"},
            {"10", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<PrintExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}