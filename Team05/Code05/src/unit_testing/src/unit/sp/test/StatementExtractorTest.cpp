//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/node_extractor/StatementExtractor.h"

inline const auto& astPrograms = AstTestProgramProducer();

//Statement_TestZeroNestingLevel

TEST_CASE("Statement_TestAssignCallPrintRead") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}
    };
    auto program = astPrograms.createAssignCallPrintRead();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

//Statement_TestSingleNestingLevel

TEST_CASE("Statement_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}
    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}
    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}
    };
    auto program = astPrograms.createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"},
    };
    auto program = astPrograms.createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

//Statement_TestDoubleNestingLevel

TEST_CASE("Statement_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}, {"20"}, {"21"}, {"22"}, {"23"}, {"24"},
            {"25"}, {"26"}, {"27"}
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}, {"20"}, {"21"}, {"22"}, {"23"}, {"24"},
            {"25"}, {"26"}, {"27"}, {"28"}, {"29"}, {"30"}, {"31"}, {"32"},
            {"33"}, {"34"}, {"35"}
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}, {"20"}, {"21"}, {"22"}, {"23"}, {"24"},
            {"25"}, {"26"}, {"27"}
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}, {"20"}, {"21"}, {"22"}, {"23"}, {"24"},
            {"25"}, {"26"}, {"27"}
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}