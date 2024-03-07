//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProgram.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/relation_extractor/ModifiesExtractor.h"
#include "sp/ast/Program.h"

// Test removed for now after new implementation for modifies
/**
using Procedures = std::vector<std::shared_ptr<Procedure>>;

//Modifies_TestZeroNestingLevel
TEST_CASE("Modifies_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "t"},
            {"3", "t"},
    };
    auto program = AstProgram::createAssignCallReadPrint();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Modifies_TestSingleNestingLevel

TEST_CASE("Modifies_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"3", "t"},
            {"5", "x"},
            {"5", "t"},
            {"5", "t"},
            {"5", "t"},
            {"6", "t"},
            {"8", "t"},
            {"10", "x"},
            {"12", "t"},
    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"3", "t"},
            {"5", "x"},
            {"5", "x"},
            {"5", "t"},
            {"5", "t"},
            {"6", "x"},
            {"8", "t"},
            {"10", "x"},
            {"12", "t"},
            {"14", "x"},
            {"16", "t"},
    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "x"},
            {"1", "t"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"8", "t"},
            {"10", "x"},
            {"12", "t"},

    };
    auto program = AstProgram::createIfElseWithStmtsAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"3", "t"},
            {"5", "x"},
            {"5", "t"},
            {"6", "x"},
            {"8", "t"},

    };
    auto program = AstProgram::createWhileWithStmtsBeforeAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"3", "t"},
            {"5", "x"},
            {"5", "t"},
            {"6", "x"},
            {"8", "t"},
            {"10", "x"},
            {"12", "t"},

    };
    auto program = AstProgram::createWhileWithStmtsBeforeAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"8", "t"},
    };
    auto program = AstProgram::createWhileWithStmtsAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Modifies_TestDoubleNestingLevel

TEST_CASE("Modifies_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "t"},
            {"1", "t"},
            {"1", "t"},
            {"1", "x"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "x"},
            {"1", "t"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "t"},
            {"6", "t"},
            {"6", "t"},
            {"6", "x"},
            {"7", "t"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
            {"15", "x"},
            {"17", "t"},
            {"19", "x"},
            {"19", "x"},
            {"19", "t"},
            {"19", "t"},
            {"20", "x"},
            {"22", "t"},
            {"24", "x"},
            {"26", "t"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "x"},
            {"1", "t"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "x"},
            {"1", "t"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"6", "x"},
            {"6", "t"},
            {"6", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
            {"15", "x"},
            {"17", "t"},
            {"19", "x"},
            {"21", "t"},
            {"23", "x"},
            {"23", "x"},
            {"23", "t"},
            {"23", "t"},
            {"24", "x"},
            {"26", "t"},
            {"28", "x"},
            {"30", "t"},
            {"32", "x"},
            {"34", "t"},

    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"2", "t"},
            {"2", "x"},
            {"2", "t"},
            {"3", "x"},
            {"5", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
            {"15", "x"},
            {"15", "t"},
            {"15", "x"},
            {"15", "t"},
            {"16", "x"},
            {"18", "t"},
            {"20", "x"},
            {"22", "t"},
            {"24", "x"},
            {"26", "t"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"6", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
            {"15", "x"},
            {"15", "t"},
            {"16", "x"},
            {"18", "t"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"6", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
            {"15", "x"},
            {"17", "t"},
            {"19", "x"},
            {"19", "t"},
            {"20", "x"},
            {"22", "t"},
            {"24", "x"},
            {"26", "t"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"2", "t"},
            {"3", "x"},
            {"5", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"11", "t"},
            {"12", "x"},
            {"14", "t"},
            {"16", "x"},
            {"18", "t"},

    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "x"},
            {"1", "t"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"6", "x"},
            {"6", "t"},
            {"6", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"6", "t"},
            {"6", "x"},
            {"6", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
            {"15", "x"},
            {"17", "t"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"2", "t"},
            {"2", "x"},
            {"2", "t"},
            {"3", "x"},
            {"5", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"6", "t"},
            {"7", "x"},
            {"9", "t"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"4", "t"},
            {"6", "x"},
            {"6", "t"},
            {"7", "x"},
            {"9", "t"},
            {"11", "x"},
            {"13", "t"},

    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Modifies_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "t"},
            {"1", "x"},
            {"1", "t"},
            {"2", "x"},
            {"2", "t"},
            {"3", "x"},
            {"5", "t"},
            {"7", "x"},
            {"9", "t"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto programs = std::make_shared<Procedures>();
    procedures->push_back(procedure);
    auto program = std::make_shared<Program>(procedures);
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ModifiesExtractor>(pkb, program);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}
 **/