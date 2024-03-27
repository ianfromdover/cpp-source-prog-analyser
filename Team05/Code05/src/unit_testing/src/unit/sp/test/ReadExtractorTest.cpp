//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/node_extractor/ReadExtractor.h"

inline AstTestProgramProducer astPrograms = AstTestProgramProducer();

//Read_TestZeroNestingLevel

TEST_CASE("Read_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"}
    };
    auto program = astPrograms.createAssignCallPrintRead();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Read_TestSingleNestingLevel

TEST_CASE("Read_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
            {"12", "t"},
    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
            {"12", "t"},
            {"16", "t"},
    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"8", "t"},
            {"12", "t"},
    };
    auto program = astPrograms.createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "t"},
            {"8", "t"},
            {"12", "t"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"8", "t"},
    };
    auto program = astPrograms.createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Read_TestDoubleNestingLevel

TEST_CASE("Read_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"17", "t"},
            {"22", "t"},
            {"26", "t"},
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
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
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
            {"13", "t"},
            {"18", "t"},
            {"22", "t"},
            {"26", "t"},
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"18", "t"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"17", "t"},
            {"22", "t"},
            {"26", "t"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
            {"14", "t"},
            {"18", "t"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
            {"17", "t"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
            {"13", "t"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "t"},
            {"9", "t"},
            {"13", "t"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Read_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"5", "t"},
            {"9", "t"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<ReadExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}