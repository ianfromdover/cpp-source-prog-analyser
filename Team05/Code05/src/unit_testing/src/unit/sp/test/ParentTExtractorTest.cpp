//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/relation_extractor/ParentExtractor.h"


//ParentT_TestZeroNestingLevel

TEST_CASE("ParentT_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto procedure = AstProcedures::createAssignCallReadPrint();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

//ParentT_TestSingleNestingLevel

TEST_CASE("ParentT_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "6"},
            {"5", "7"},
            {"5", "8"},
            {"5", "9"},
            {"5", "10"},
            {"5", "11"},
            {"5", "12"},
            {"5", "13"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "6"},
            {"5", "7"},
            {"5", "8"},
            {"5", "9"},
            {"5", "10"},
            {"5", "11"},
            {"5", "12"},
            {"5", "13"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "6"},
            {"5", "7"},
            {"5", "8"},
            {"5", "9"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "6"},
            {"5", "7"},
            {"5", "8"},
            {"5", "9"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

//ParentT_TestDoubleNestingLevel

TEST_CASE("ParentT_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "15"},
            {"1", "16"},
            {"1", "17"},
            {"1", "18"},
            {"1", "19"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "20"},
            {"1", "21"},
            {"1", "22"},
            {"1", "23"},
            {"1", "24"},
            {"1", "25"},
            {"1", "26"},
            {"1", "27"},

            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"6", "11"},
            {"6", "12"},
            {"6", "13"},
            {"6", "14"},

            {"19", "20"},
            {"19", "21"},
            {"19", "22"},
            {"19", "23"},
            {"19", "24"},
            {"19", "25"},
            {"19", "26"},
            {"19", "27"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "15"},
            {"1", "16"},
            {"1", "17"},
            {"1", "18"},
            {"1", "19"},
            {"1", "20"},
            {"1", "21"},
            {"1", "22"},
            {"1", "23"},
            {"1", "32"},
            {"1", "33"},
            {"1", "34"},
            {"1", "35"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "24"},
            {"1", "25"},
            {"1", "26"},
            {"1", "27"},
            {"1", "28"},
            {"1", "29"},
            {"1", "30"},
            {"1", "31"},


            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"6", "11"},
            {"6", "12"},
            {"6", "13"},
            {"6", "14"},

            {"23", "24"},
            {"23", "25"},
            {"23", "26"},
            {"23", "27"},
            {"23", "28"},
            {"23", "29"},
            {"23", "30"},
            {"23", "31"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "15"},
            {"1", "24"},
            {"1", "25"},
            {"1", "26"},
            {"1", "27"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},

            {"1", "16"},
            {"1", "17"},
            {"1", "18"},
            {"1", "19"},
            {"1", "20"},
            {"1", "21"},
            {"1", "22"},
            {"1", "23"},

            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"2", "6"},
            {"2", "7"},
            {"2", "8"},
            {"2", "9"},
            {"2", "10"},

            {"15", "16"},
            {"15", "17"},
            {"15", "18"},
            {"15", "19"},
            {"15", "20"},
            {"15", "21"},
            {"15", "22"},
            {"15", "23"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "15"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "16"},
            {"1", "17"},
            {"1", "18"},
            {"1", "19"},
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"15", "16"},
            {"15", "17"},
            {"15", "18"},
            {"15", "19"},

    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "15"},
            {"1", "16"},
            {"1", "17"},
            {"1", "18"},
            {"1", "19"},
            {"1", "24"},
            {"1", "25"},
            {"1", "26"},
            {"1", "27"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "20"},
            {"1", "21"},
            {"1", "22"},
            {"1", "23"},
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"19", "20"},
            {"19", "21"},
            {"19", "22"},
            {"19", "23"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "11"},
            {"1", "16"},
            {"1", "17"},
            {"1", "18"},
            {"1", "19"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "15"},
            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"2", "6"},

            {"11", "12"},
            {"11", "13"},
            {"11", "14"},
            {"11", "15"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"6", "11"},
            {"6", "12"},
            {"6", "13"},
            {"6", "14"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "15"},
            {"1", "16"},
            {"1", "17"},
            {"1", "18"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},

            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"6", "11"},
            {"6", "12"},
            {"6", "13"},
            {"6", "14"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},

            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"2", "6"},

            {"2", "7"},
            {"2", "8"},
            {"2", "9"},
            {"2", "10"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"}
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("ParentT_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"2", "6"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}