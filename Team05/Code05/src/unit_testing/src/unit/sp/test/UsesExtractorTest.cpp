//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/relation_extractor/UsesExtractor.h"

// Test removed for now after new implementation for uses
/**
//Uses_TestZeroNestingLevel
using Procedures = std::vector<std::shared_ptr<Procedure>>;

TEST_CASE("Uses_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "y"},
            {"1", "3"},
            {"1", "1"},
            {"1", "y"},
            {"4", "u"},
    };
    auto procedure = AstProcedures::createAssignCallReadPrint();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Uses_TestSingleNestingLevel
TEST_CASE("Uses_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "y"},
            {"1", "3"},
            {"1", "1"},
            {"1", "y"},
            {"4", "u"},
            {"5", "x"},
            {"5", "y"},
            {"5", "y"},
            {"5", "u"},
            {"5", "y"},
            {"5", "u"},
            {"6", "y"},
            {"6", "y"},
            {"6", "1"},
            {"6", "3"},
            {"9", "u"},
            {"10", "y"},
            {"10", "3"},
            {"13", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "y"},
            {"4", "u"},
            {"5", "x"},
            {"5", "y"},
            {"5", "u"},
            {"5", "y"},
            {"5", "u"},
            {"6", "y"},
            {"9", "u"},
            {"10", "y"},
            {"13", "u"},
            {"14", "y"},
            {"17", "u"}
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "y"},
            {"9", "u"},
            {"10", "y"},
            {"13", "u"}
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "y"},
            {"4", "u"},
            {"5", "x"},
            {"5", "y"},
            {"5", "u"},
            {"6", "y"},
            {"9", "u"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "y"},
            {"4", "u"},
            {"5", "x"},
            {"5", "y"},
            {"5", "u"},
            {"6", "y"},
            {"9", "u"},
            {"10", "y"},
            {"13", "u"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "y"},
            {"9", "u"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Uses_TestDoubleNestingLevel

TEST_CASE("Uses_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "y"},
            {"6", "u"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
            {"15", "y"},
            {"18", "u"},
            {"19", "x"},
            {"19", "y"},
            {"19", "u"},
            {"19", "y"},
            {"19", "u"},
            {"20", "y"},
            {"23", "u"},
            {"24", "y"},
            {"27", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "u"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
            {"15", "y"},
            {"18", "u"},
            {"19", "y"},
            {"22", "u"},
            {"23", "x"},
            {"23", "y"},
            {"23", "u"},
            {"23", "y"},
            {"23", "u"},
            {"24", "y"},
            {"27", "u"},
            {"28", "y"},
            {"31", "u"},
            {"32", "y"},
            {"35", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "x"},
            {"2", "y"},
            {"2", "u"},
            {"2", "y"},
            {"2", "u"},
            {"3", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
            {"15", "x"},
            {"15", "y"},
            {"15", "u"},
            {"15", "y"},
            {"15", "u"},
            {"16", "y"},
            {"19", "u"},
            {"20", "y"},
            {"23", "u"},
            {"24", "y"},
            {"27", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
            {"15", "x"},
            {"15", "y"},
            {"15", "u"},
            {"16", "y"},
            {"19", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
            {"15", "y"},
            {"18", "u"},
            {"19", "x"},
            {"19", "y"},
            {"19", "u"},
            {"20", "y"},
            {"23", "u"},
            {"24", "y"},
            {"27", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "x"},
            {"2", "y"},
            {"2", "u"},
            {"3", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"11", "u"},
            {"12", "y"},
            {"15", "u"},
            {"16", "y"},
            {"19", "u"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "u"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "u"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
            {"15", "y"},
            {"18", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "x"},
            {"2", "y"},
            {"2", "u"},
            {"2", "y"},
            {"2", "u"},
            {"3", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "y"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
            {"11", "y"},
            {"14", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Uses_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "x"},
            {"1", "y"},
            {"1", "u"},
            {"1", "y"},
            {"1", "u"},
            {"2", "x"},
            {"2", "y"},
            {"2", "u"},
            {"3", "y"},
            {"6", "u"},
            {"7", "y"},
            {"10", "u"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto procedures = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<UsesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}
**/