//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProgram.cpp"
#include "../helper/PkbStubSp.cpp"
#include "sp/extractor/node_extractor/VariableExtractor.h"


//Variable_TestZeroNestingLevel

TEST_CASE("Variable_TestAssignCallPrintRead") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "t"},
            {"1", "y"},
            {"1", "y"},
            {"3", "t"},
            {"4", "u"},
    };
    auto program = AstProgram::createAssignCallPrintRead();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Variable_TestSingleNestingLevel

TEST_CASE("Variable_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"3", "t"},
            {"4", "u"},
            {"5", "x"},
            {"6", "t"},
            {"6", "y"},
            {"6", "y"},
            {"8", "t"},
            {"9", "u"},
            {"10", "x"},
            {"10", "y"},
            {"12", "t"},
            {"13", "u"},
    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"3", "t"},
            {"4", "u"},
            {"5", "x"},
            {"6", "x"},
            {"6", "y"},
            {"8", "t"},
            {"9", "u"},
            {"10", "x"},
            {"10", "y"},
            {"12", "t"},
            {"13", "u"},
            {"14", "x"},
            {"14", "y"},
            {"16", "t"},
            {"17", "u"}
    };
    auto program = AstProgram::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"8", "t"},
            {"9", "u"},
            {"10", "x"},
            {"10", "y"},
            {"12", "t"},
            {"13", "u"}
    };
    auto program = AstProgram::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"3", "t"},
            {"4", "u"},
            {"5", "x"},
            {"6", "x"},
            {"6", "y"},
            {"8", "t"},
            {"9", "u"},
    };
    auto program = AstProgram::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"1", "y"},
            {"3", "t"},
            {"4", "u"},
            {"5", "x"},
            {"6", "x"},
            {"6", "y"},
            {"8", "t"},
            {"9", "u"},
            {"10", "x"},
            {"10", "y"},
            {"12", "t"},
            {"13", "u"},
    };
    auto program = AstProgram::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"6", "y"},
            {"8", "t"},
            {"9", "u"},
    };
    auto program = AstProgram::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

//Variable_TestDoubleNestingLevel

TEST_CASE("Variable_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "t"},
            {"7", "y"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
            {"15", "x"},
            {"15", "y"},
            {"17", "t"},
            {"18", "u"},
            {"19", "x"},
            {"20", "x"},
            {"20", "y"},
            {"22", "t"},
            {"23", "u"},
            {"24", "x"},
            {"24", "y"},
            {"26", "t"},
            {"27", "u"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
            {"15", "x"},
            {"15", "y"},
            {"17", "t"},
            {"18", "u"},
            {"19", "x"},
            {"19", "y"},
            {"21", "t"},
            {"22", "u"},
            {"23", "x"},
            {"24", "x"},
            {"24", "y"},
            {"26", "t"},
            {"27", "u"},
            {"28", "x"},
            {"28", "y"},
            {"30", "t"},
            {"31", "u"},
            {"32", "x"},
            {"32", "y"},
            {"34", "t"},
            {"35", "u"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"3", "x"},
            {"3", "y"},
            {"5", "t"},
            {"6", "u"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
            {"15", "x"},
            {"16", "x"},
            {"16", "y"},
            {"18", "t"},
            {"19", "u"},
            {"20", "x"},
            {"20", "y"},
            {"22", "t"},
            {"23", "u"},
            {"24", "x"},
            {"24", "y"},
            {"26", "t"},
            {"27", "u"},
    };
    auto program = AstProgram::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
            {"15", "x"},
            {"16", "x"},
            {"16", "y"},
            {"18", "t"},
            {"19", "u"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
            {"15", "x"},
            {"15", "y"},
            {"17", "t"},
            {"18", "u"},
            {"19", "x"},
            {"20", "x"},
            {"20", "y"},
            {"22", "t"},
            {"23", "u"},
            {"24", "x"},
            {"24", "y"},
            {"26", "t"},
            {"27", "u"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"3", "x"},
            {"3", "y"},
            {"5", "t"},
            {"6", "u"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"12", "x"},
            {"12", "y"},
            {"14", "t"},
            {"15", "u"},
            {"16", "x"},
            {"16", "y"},
            {"18", "t"},
            {"19", "u"},
    };
    auto program = AstProgram::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
            {"15", "x"},
            {"15", "y"},
            {"17", "t"},
            {"18", "u"},

    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"3", "x"},
            {"3", "y"},
            {"5", "t"},
            {"6", "u"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
    };
    auto program = AstProgram::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"2", "y"},
            {"4", "t"},
            {"5", "u"},
            {"6", "x"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
            {"11", "x"},
            {"11", "y"},
            {"13", "t"},
            {"14", "u"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}

TEST_CASE("Variable_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<pair<std::string, std::string>> resultsVector = {
            {"1", "x"},
            {"2", "x"},
            {"3", "x"},
            {"3", "y"},
            {"5", "t"},
            {"6", "u"},
            {"7", "x"},
            {"7", "y"},
            {"9", "t"},
            {"10", "u"},
    };
    auto program = AstProgram::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PkbStubSp>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<VariableExtractor>(pkb);
    for (const auto& procedure : *program->getProcedures()) {
        procedure->accept(*extractor);
    }
    REQUIRE(pkb->checkAgainstPairResults(resultsVector));
}