//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/node_extractor/ConstantExtractor.h"

inline const auto& astPrograms = AstTestProgramProducer();

//Constant_TestZeroNestingLevel

TEST_CASE("Constant_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"1", "3"}
    };
    auto program = astPrograms.createAssignCallPrintRead();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "3"},
            {"10", "3"},
    };
    auto program = astPrograms.createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "3"},
            {"5", "1"},
            {"6", "3"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "3"},
            {"5", "1"},
            {"6", "3"},
            {"10", "3"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "3"},
    };
    auto program = astPrograms.createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "3"},
            {"6", "1"},
            {"7", "3"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
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
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Constant_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "1"},
            {"2", "1"},
            {"3", "3"},
            {"7", "3"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ConstantExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}