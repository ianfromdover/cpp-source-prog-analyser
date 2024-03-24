//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/relation_extractor/FollowsExtractor.h"

inline AstTestProgramProducer astPrograms = AstTestProgramProducer();

//FollowsT_TestZeroNestingLevel

TEST_CASE("FollowsT_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"2", "3"},
            {"2", "4"},
            {"3", "4"},
    };
    auto program = astPrograms.createAssignCallPrintRead();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

//FollowsT_TestSingleNestingLevel

TEST_CASE("FollowsT_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"},
            {"1", "3"},
            {"1", "4"},
            {"1", "5"},
            {"2", "3"},
            {"2", "4"},
            {"2", "5"},
            {"3", "4"},
            {"3", "5"},
            {"4", "5"},

            {"6", "7"},
            {"6", "8"},
            {"6", "9"},
            {"7", "8"},
            {"7", "9"},
            {"8", "9"},

            {"10", "11"},
            {"10", "12"},
            {"10", "13"},
            {"11", "12"},
            {"11", "13"},
            {"12", "13"},
    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"}, {"1", "3"}, {"1", "4"}, {"1", "5"},
            {"1", "14"}, {"1", "15"},{"1", "16"}, {"1", "17"},
            {"2", "3"}, {"2", "4"}, {"2", "5"},
            {"2", "14"}, {"2", "15"},{"2", "16"}, {"2", "17"},
            {"3", "4"}, {"3", "5"},
            {"3", "14"}, {"3", "15"},{"3", "16"}, {"3", "17"},
            {"4", "5"},
            {"4", "14"}, {"4", "15"},{"4", "16"}, {"4", "17"},
            {"5", "14"}, {"5", "15"},{"5", "16"}, {"5", "17"},
            {"14", "15"}, {"14", "16"}, {"14", "17"},
            {"15", "16"}, {"15", "17"},
            {"16", "17"},

            {"6", "7"}, {"6", "8"}, {"6", "9"},
            {"7", "8"}, {"7", "9"},
            {"8", "9"},

            {"10", "11"}, {"10", "12"}, {"10", "13"},
            {"11", "12"}, {"11", "13"},
            {"12", "13"},

    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"}, {"2", "5"},
            {"3", "4"}, {"3", "5"},
            {"4", "5"},

            {"6", "7"}, {"6", "8"}, {"6", "9"},
            {"7", "8"}, {"7", "9"},
            {"8", "9"},

            {"1", "10"}, {"1", "11"}, {"1", "12"}, {"1", "13"},
            {"10", "11"}, {"10", "12"}, {"10", "13"},
            {"11", "12"}, {"11", "13"},
            {"12", "13"},
    };
    auto program = astPrograms.createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"}, {"1", "3"}, {"1", "4"}, {"1", "5"},

            {"2", "3"}, {"2", "4"}, {"2", "5"},
            {"3", "4"}, {"3", "5"},
            {"4", "5"},

            {"6", "7"}, {"6", "8"}, {"6", "9"},
            {"7", "8"}, {"7", "9"},
            {"8", "9"},

    };
    auto program = astPrograms.createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "2"}, {"1", "3"}, {"1", "4"}, {"1", "5"},
            {"1", "10"}, {"1", "11"}, {"1", "12"}, {"1", "13"},
            {"2", "3"}, {"2", "4"}, {"2", "5"},
            {"2", "10"}, {"2", "11"}, {"2", "12"}, {"2", "13"},
            {"3", "4"}, {"3", "5"},
            {"3", "10"}, {"3", "11"}, {"3", "12"}, {"3", "13"},
            {"4", "5"}, {"4", "10"}, {"4", "11"}, {"4", "12"}, {"4", "13"},
            {"5", "10"}, {"5", "11"}, {"5", "12"}, {"5", "13"},
            {"10", "11"}, {"10", "12"}, {"10", "13"},
            {"11", "12"}, {"11", "13"},
            {"12", "13"},

            {"6", "7"}, {"6", "8"}, {"6", "9"},
            {"7", "8"}, {"7", "9"},
            {"8", "9"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"}, {"2", "5"},
            {"3", "4"}, {"3", "5"},
            {"4", "5"},

            {"1", "6"}, {"1", "7"}, {"1", "8"}, {"1", "9"},
            {"6", "7"}, {"6", "8"}, {"6", "9"},
            {"7", "8"}, {"7", "9"},
            {"8", "9"},
    };
    auto program = astPrograms.createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

//FollowsT_TestDoubleNestingLevel

TEST_CASE("FollowsT_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"}, {"2", "5"}, {"2", "6"},
            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},

            {"15", "16"}, {"15", "17"}, {"15", "18"}, {"15", "19"},
            {"16", "17"}, {"16", "18"}, {"16", "19"},
            {"17", "18"}, {"17", "19"},
            {"18", "19"},

            {"20", "21"}, {"20", "22"}, {"20", "23"},
            {"21", "22"}, {"21", "23"},
            {"22", "23"},

            {"24", "25"}, {"24", "26"}, {"24", "27"},
            {"25", "26"}, {"25", "27"},
            {"26", "27"},
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"},{"2", "5"},{"2", "6"},
            {"2", "15"}, {"2", "16"}, {"2", "17"}, {"2", "18"},
            {"3", "4"},{"3", "5"},{"3", "6"},
            {"3", "15"}, {"3", "16"}, {"3", "17"}, {"3", "18"},
            {"4", "5"}, {"4", "6"},
            {"4", "15"}, {"4", "16"}, {"4", "17"}, {"4", "18"},
            {"5", "6"}, {"5", "15"}, {"5", "16"}, {"5", "17"}, {"5", "18"},
            {"6", "15"},  {"6", "16"}, {"6", "17"}, {"6", "18"},
            {"15", "16"}, {"15", "17"}, {"15", "18"},
            {"16", "17"}, {"16", "18"},
            {"17", "18"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},


            {"19", "20"}, {"19", "21"}, {"19", "22"}, {"19", "23"}, {"19", "32"},
            {"19", "33"}, {"19", "34"}, {"19", "35"},
            {"20", "21"}, {"20", "22"}, {"20", "23"}, {"20", "32"},
            {"20", "33"}, {"20", "34"}, {"20", "35"},
            {"21", "22"}, {"21", "23"}, {"21", "32"},
            {"21", "33"}, {"21", "34"}, {"21", "35"},
            {"22", "23"}, {"22", "32"},
            {"22", "33"}, {"22", "34"}, {"22", "35"},
            {"23", "32"}, {"23", "33"}, {"23", "34"}, {"23", "35"},
            {"32", "33"}, {"32", "34"}, {"32", "35"},
            {"33", "34"}, {"33", "35"},
            {"34", "35"},


            {"24", "25"}, {"24", "26"}, {"24", "27"},
            {"25", "26"}, {"25", "27"},
            {"26", "27"},

            {"28", "29"}, {"28", "30"}, {"28", "31"},
            {"29", "30"}, {"29", "31"},
            {"30", "31"},
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "11"}, {"2", "12"}, {"2", "13"}, {"2", "14"},
            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},

            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"15", "24"}, {"15", "25"}, {"15", "26"}, {"15", "27"},
            {"24", "25"}, {"24", "26"}, {"24", "27"},
            {"25", "26"}, {"25", "27"},
            {"26", "27"},

            {"16", "17"}, {"16", "18"}, {"16", "19"},
            {"17", "18"}, {"17", "19"},
            {"18", "19"},

            {"20", "21"}, {"20", "22"}, {"20", "23"},
            {"21", "22"}, {"21", "23"},
            {"22", "23"},

    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"}, {"2", "5"}, {"2", "6"},
            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"11", "12"}, {"11", "13"}, {"11", "14"}, {"11", "15"},
            {"12", "13"}, {"12", "14"}, {"12", "15"},
            {"13", "14"}, {"13", "15"},
            {"14", "15"},

            {"16", "17"}, {"16", "18"}, {"16", "19"},
            {"17", "18"}, {"17", "19"},
            {"18", "19"},

    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"}, {"2", "5"}, {"2", "6"},
            {"2", "11"}, {"2", "12"}, {"2", "13"}, {"2", "14"},
            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"3", "11"}, {"3", "12"}, {"3", "13"}, {"3", "14"},
            {"4", "5"}, {"4", "6"},
            {"4", "11"}, {"4", "12"}, {"4", "13"}, {"4", "14"},
            {"5", "6"}, {"5", "11"}, {"5", "12"}, {"5", "13"}, {"5", "14"},
            {"6", "11"}, {"6", "12"}, {"6", "13"}, {"6", "14"},
            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"15", "16"}, {"15", "17"}, {"15", "18"}, {"15", "19"},
            {"15", "24"}, {"15", "25"}, {"15", "26"}, {"15", "27"},
            {"16", "17"}, {"16", "18"}, {"16", "19"},
            {"16", "24"}, {"16", "25"}, {"16", "26"}, {"16", "27"},
            {"17", "18"}, {"17", "19"},
            {"17", "24"}, {"17", "25"}, {"17", "26"}, {"17", "27"},
            {"18", "19"}, {"18", "24"}, {"18", "25"}, {"18", "26"}, {"18", "27"},
            {"19", "24"}, {"19", "25"}, {"19", "26"}, {"19", "27"},
            {"24", "25"}, {"24", "26"}, {"24", "27"},
            {"25", "26"}, {"25", "27"},
            {"26", "27"},

            {"20", "21"}, {"20", "22"}, {"20", "23"},
            {"21", "22"}, {"21", "23"},
            {"22", "23"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "7"}, {"2", "8"}, {"2", "9"}, {"2", "10"},
            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"11", "16"}, {"11", "17"}, {"11", "18"}, {"11", "19"},
            {"16", "17"}, {"16", "18"}, {"16", "19"},
            {"17", "18"}, {"17", "19"},
            {"18", "19"},

            {"12", "13"}, {"12", "14"}, {"12", "15"},
            {"13", "14"}, {"13", "15"},
            {"14", "15"},

    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"}, {"2", "5"}, {"2", "6"},
            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

            {"2", "3"}, {"2", "4"}, {"2", "5"}, {"2", "6"},
            {"2", "15"}, {"2", "16"}, {"2", "17"}, {"2", "18"},
            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"3", "15"}, {"3", "16"}, {"3", "17"}, {"3", "18"},
            {"4", "5"}, {"4", "6"},
            {"4", "15"}, {"4", "16"}, {"4", "17"}, {"4", "18"},
            {"5", "6"}, {"5", "15"}, {"5", "16"}, {"5", "17"}, {"5", "18"},
            {"6", "15"}, {"6", "16"}, {"6", "17"}, {"6", "18"},
            {"15", "16"}, {"15", "17"}, {"15", "18"},
            {"16", "17"}, {"16", "18"},
            {"17", "18"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},

    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {

            {"2", "11"}, {"2", "12"}, {"2", "13"}, {"2", "14"},
            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},

            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"},  {"2", "5"}, {"2", "6"},
            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "3"}, {"2", "4"}, {"2", "5"}, {"2", "6"}, {"2", "11"},
            {"2", "12"}, {"2", "13"}, {"2", "14"},
            {"3", "4"}, {"3", "5"}, {"3", "6"}, {"3", "11"},
            {"3", "12"}, {"3", "13"}, {"3", "14"},
            {"4", "5"}, {"4", "6"}, {"4", "11"},
            {"4", "12"}, {"4", "13"}, {"4", "14"},
            {"5", "6"}, {"5", "11"},
            {"5", "12"}, {"5", "13"}, {"5", "14"},
            {"6", "11"}, {"6", "12"}, {"6", "13"}, {"6", "14"},
            {"11", "12"}, {"11", "13"}, {"11", "14"},
            {"12", "13"}, {"12", "14"},
            {"13", "14"},

            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},

    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}

TEST_CASE("FollowsT_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "4"}, {"3", "5"}, {"3", "6"},
            {"4", "5"}, {"4", "6"},
            {"5", "6"},

            {"2", "7"}, {"2", "8"}, {"2", "9"}, {"2", "10"},
            {"7", "8"}, {"7", "9"}, {"7", "10"},
            {"8", "9"}, {"8", "10"},
            {"9", "10"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<FollowsExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairTResults(resultsVector));
}