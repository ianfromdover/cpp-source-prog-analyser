//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/node_extractor/WhileExtractor.h"

inline const auto& astPrograms = AstTestProgramProducer();

//While_TestZeroNestingLevel

TEST_CASE("While_TestAssignCallReadPrint") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createAssignCallPrintRead();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//While_TestSingleNestingLevel

TEST_CASE("While_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "x"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "x"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto program = astPrograms.createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//While_TestDoubleNestingLevel

TEST_CASE("While_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "x"},
            {"15", "x"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"6", "x"},
            {"19", "x"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "x"},
            {"11", "x"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"6", "x"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"6", "x"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("While_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<WhileExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}