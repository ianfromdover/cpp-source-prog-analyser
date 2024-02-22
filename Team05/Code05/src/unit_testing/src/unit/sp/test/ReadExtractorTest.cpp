//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/ReadExtractor.h"


//testZeroNestingLevel

TEST_CASE("testAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"}
    };
    auto procedure = AstProcedures::createAssignCallPrintRead();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

//testSingleNestingLevel

TEST_CASE("testIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
            {"12", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
            {"12", "t"},
            {"16", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"8", "t"},
            {"12", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
            {"12", "t"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"8", "t"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

//testDoubleNestingLevel

TEST_CASE("testIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"17", "t"},
            {"22", "t"},
            {"26", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"17", "t"},
            {"21", "t"},
            {"26", "t"},
            {"30", "t"},
            {"34", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
            {"13", "t"},
            {"18", "t"},
            {"22", "t"},
            {"26", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"18", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"17", "t"},
            {"22", "t"},
            {"26", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
            {"14", "t"},
            {"18", "t"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"17", "t"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
            {"13", "t"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}

TEST_CASE("testWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkIfExistPair(resultsVector));
}