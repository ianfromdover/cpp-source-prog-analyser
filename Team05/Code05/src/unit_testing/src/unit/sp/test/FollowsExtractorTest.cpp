//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProgram.cpp"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/relation_extractor/FollowsExtractor.h"


//Follows_TestZeroNestingLevel

TEST_CASE("Follows_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"2", "3"},
            {"3", "4"},
    };
    auto program = AstProgram::createAssignCallPrintRead();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Follows_TestSingleNestingLevel

TEST_CASE("Follows_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"6", "7"},
            {"7", "8"},
            {"8", "9"},
            {"10", "11"},
            {"11", "12"},
            {"12", "13"},
    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"6", "7"},
            {"7", "8"},
            {"8", "9"},
            {"10", "11"},
            {"11", "12"},
            {"12", "13"},
            {"14", "15"},
            {"15", "16"},
            {"16", "17"},
            {"5", "14"},

    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"6", "7"},
            {"7", "8"},
            {"8", "9"},
            {"10", "11"},
            {"11", "12"},
            {"12", "13"},
            {"1", "10"},
    };
    auto program = AstProgram::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"6", "7"},
            {"7", "8"},
            {"8", "9"},

    };
    auto program = AstProgram::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"6", "7"},
            {"7", "8"},
            {"8", "9"},
            {"10", "11"},
            {"11", "12"},
            {"12", "13"},
            {"5", "10"}
    };
    auto program = AstProgram::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},

            {"6", "7"},
            {"7", "8"},
            {"8", "9"},
            {"1", "6"},
    };
    auto program = AstProgram::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Follows_TestDoubleNestingLevel

TEST_CASE("Follows_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},

            {"15", "16"},
            {"16", "17"},
            {"17", "18"},
            {"18", "19"},

            {"20", "21"},
            {"21", "22"},
            {"22", "23"},

            {"24", "25"},
            {"25", "26"},
            {"26", "27"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},

            {"15", "16"},
            {"16", "17"},
            {"17", "18"},

            {"19", "20"},
            {"20", "21"},
            {"21", "22"},
            {"22", "23"},

            {"24", "25"},
            {"25", "26"},
            {"26", "27"},

            {"28", "29"},
            {"29", "30"},
            {"30", "31"},

            {"32", "33"},
            {"33", "34"},
            {"34", "35"},
            {"6", "15"},
            {"23", "32"}
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},

            {"16", "17"},
            {"17", "18"},
            {"18", "19"},

            {"20", "21"},
            {"21", "22"},
            {"22", "23"},

            {"24", "25"},
            {"25", "26"},
            {"26", "27"},

            {"2", "11"},
            {"15", "24"},

    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},
            {"14", "15"},

            {"16", "17"},
            {"17", "18"},
            {"18", "19"},

    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},

            {"15", "16"},
            {"16", "17"},
            {"17", "18"},
            {"18", "19"},

            {"20", "21"},
            {"21", "22"},
            {"22", "23"},

            {"24", "25"},
            {"25", "26"},
            {"26", "27"},

            {"6", "11"},
            {"19", "24"}
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"12", "13"},
            {"13", "14"},
            {"14", "15"},

            {"16", "17"},
            {"17", "18"},
            {"18", "19"},

            {"2", "7"},
            {"11", "16"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},

            {"15", "16"},
            {"16", "17"},
            {"17", "18"},

            {"6", "15"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},

            {"2", "11"}
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"},
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"11", "12"},
            {"12", "13"},
            {"13", "14"},

            {"6", "11"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Follows_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "4"},
            {"4", "5"},
            {"5", "6"},

            {"7", "8"},
            {"8", "9"},
            {"9", "10"},

            {"2", "7"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}