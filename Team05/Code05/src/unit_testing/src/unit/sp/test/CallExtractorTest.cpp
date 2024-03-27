//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/node_extractor/CallExtractor.h"

inline AstTestProgramProducer astPrograms = AstTestProgramProducer();

//Call_TestZeroNestingLevel

TEST_CASE("Call_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "hello"}
    };
    auto program = astPrograms.createAssignCallPrintRead();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Call_TestSingleNestingLevel

TEST_CASE("Call_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "hello"},
            {"7", "hello"},
            {"11", "hello"},
    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "hello"},
            {"7", "hello"},
            {"11", "hello"},
            {"15", "hello"},
    };
    auto program = astPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"7", "hello"},
            {"11", "hello"},
    };
    auto program = astPrograms.createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "hello"},
            {"7", "hello"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"2", "hello"},
            {"7", "hello"},
            {"11", "hello"},
    };
    auto program = astPrograms.createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"7", "hello"},
    };
    auto program = astPrograms.createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Call_TestDoubleNestingLevel

TEST_CASE("Call_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
            {"12", "hello"},
            {"16", "hello"},
            {"21", "hello"},
            {"25", "hello"},
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
            {"12", "hello"},
            {"16", "hello"},
            {"20", "hello"},
            {"25", "hello"},
            {"29", "hello"},
            {"33", "hello"},
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "hello"},
            {"8", "hello"},
            {"12", "hello"},
            {"17", "hello"},
            {"21", "hello"},
            {"25", "hello"},
    };
    auto program = astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
            {"12", "hello"},
            {"17", "hello"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
            {"12", "hello"},
            {"16", "hello"},
            {"21", "hello"},
            {"25", "hello"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "hello"},
            {"8", "hello"},
            {"13", "hello"},
            {"17", "hello"},
    };
    auto program = astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
            {"12", "hello"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
            {"12", "hello"},
            {"16", "hello"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "hello"},
            {"8", "hello"},
            {"12", "hello"},
    };
    auto program = astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"3", "hello"},
            {"8", "hello"},
            {"12", "hello"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Call_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"4", "hello"},
            {"8", "hello"},
    };
    auto program = astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<CallExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}