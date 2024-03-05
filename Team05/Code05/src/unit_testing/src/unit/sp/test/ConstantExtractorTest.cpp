//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/node_extractor/ConstantExtractor.h"


//Constant_TestZeroNestingLevel

TEST_CASE("Constant_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"1", "3"}
    };
    auto procedure = AstProcedures::createAssignCallReadPrint();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Constant_TestSingleNestingLevel

TEST_CASE("Constant_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "3"},
            {"5", "1"},
            {"6", "1"},
            {"6", "3"},
            {"10", "3"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "3"},
            {"5", "1"},
            {"6", "3"},
            {"10", "3"},
            {"14", "3"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "3"},
            {"10", "3"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "3"},
            {"5", "1"},
            {"6", "3"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "3"},
            {"5", "1"},
            {"6", "3"},
            {"10", "3"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "3"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Constant_TestDoubleNestingLevel

TEST_CASE("Constant_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
            {"7", "1"},
            {"11", "3"},
            {"15", "3"},
            {"19", "1"},
            {"20", "3"},
            {"24","3"}
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
            {"11", "3"},
            {"15", "3"},
            {"19", "3"},
            {"23", "1"},
            {"24", "3"},
            {"28", "3"},
            {"32", "3"}
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "1"},
            {"3", "3"},
            {"7", "3"},
            {"11", "3"},
            {"15", "1"},
            {"16", "3"},
            {"20", "3"},
            {"24", "3"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
            {"11", "3"},
            {"15", "1"},
            {"16", "3"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
            {"11", "3"},
            {"15", "3"},
            {"19", "1"},
            {"20", "3"},
            {"24", "3"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "1"},
            {"3", "3"},
            {"7", "3"},
            {"11", "1"},
            {"12", "3"},
            {"16", "3"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
            {"11", "3"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
            {"11", "3"},
            {"15", "3"},

    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "1"},
            {"3", "3"},
            {"7", "3"},
            {"11", "3"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
            {"11", "3"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "1"},
            {"3", "3"},
            {"7", "3"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}