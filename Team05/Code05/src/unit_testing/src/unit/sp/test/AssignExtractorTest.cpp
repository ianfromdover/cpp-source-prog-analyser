//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProgram.cpp"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/node_extractor/AssignExtractor.h"


//Assign_TestZeroNestingLevel

TEST_CASE("Assign_TestAssignCallPrintRead") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "t", "(((1+y)*3)+y)"}
    };
    auto program = AstProgram::createAssignCallPrintRead();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

//Assign_TestSingleNestingLevel

TEST_CASE("Assign_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "(y+3)"},
            {"6", "t", "(((1+y)*3)+y)"},
            {"10", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "(y+3)"},
            {"6", "x", "(y+3)"},
            {"10", "x", "(y+3)"},
            {"14", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"6", "x", "(y+3)"},
            {"10", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "(y+3)"},
            {"6", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "(y+3)"},
            {"6", "x", "(y+3)"},
            {"10", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"6", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

//Assign_TestDoubleNestingLevel

TEST_CASE("Assign_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "t", "(((1+y)*3)+y)"},
            {"11", "x", "(y+3)"},
            {"15", "x", "(y+3)"},
            {"20", "x", "(y+3)"},
            {"24", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
            {"15", "x", "(y+3)"},
            {"19", "x", "(y+3)"},
            {"24", "x", "(y+3)"},
            {"28", "x", "(y+3)"},
            {"32", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
            {"16", "x", "(y+3)"},
            {"20", "x", "(y+3)"},
            {"24", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
            {"16", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
            {"15", "x", "(y+3)"},
            {"20", "x", "(y+3)"},
            {"24", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"12", "x", "(y+3)"},
            {"16", "x", "(y+3)"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
            {"15", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
            {"11", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "(y+3)"},
            {"7", "x", "(y+3)"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}