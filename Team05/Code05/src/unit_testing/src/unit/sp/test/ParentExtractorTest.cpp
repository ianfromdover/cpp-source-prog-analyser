//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/relation_extractor/ParentExtractor.h"

inline AstTestProgramProducer astPrograms = AstTestProgramProducer();

//Parent_TestZeroNestingLevel

TEST_CASE("Parent_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

    };
    auto program = astPrograms.createAssignCallPrintRead();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Parent_TestSingleNestingLevel

TEST_CASE("Parent_TestIfElseWithStmtsBeforeAndInside") {
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
    auto program = astPrograms.createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestIfElseWithStmtsBeforeAfterAndInside") {
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
    auto program = astPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestIfElseWithStmtsAfterAndInside") {
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
    auto program = astPrograms.createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "6"},
            {"5", "7"},
            {"5", "8"},
            {"5", "9"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "6"},
            {"5", "7"},
            {"5", "8"},
            {"5", "9"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
    };
    auto program = astPrograms.createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Parent_TestDoubleNestingLevel

TEST_CASE("Parent_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
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
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
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
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
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
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
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
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"15", "16"},
            {"15", "17"},
            {"15", "18"},
            {"15", "19"},

    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
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
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"19", "20"},
            {"19", "21"},
            {"19", "22"},
            {"19", "23"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
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

            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"2", "6"},

            {"11", "12"},
            {"11", "13"},
            {"11", "14"},
            {"11", "15"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"6", "11"},
            {"6", "12"},
            {"6", "13"},
            {"6", "14"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
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

            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
            {"6", "11"},
            {"6", "12"},
            {"6", "13"},
            {"6", "14"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "11"},
            {"1", "12"},
            {"1", "13"},
            {"1", "14"},

            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"2", "6"},

            {"2", "7"},
            {"2", "8"},
            {"2", "9"},
            {"2", "10"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"1", "6"},
            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
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

            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"6", "10"}
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Parent_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "7"},
            {"1", "8"},
            {"1", "9"},
            {"1", "10"},
            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"2", "6"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ParentExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}