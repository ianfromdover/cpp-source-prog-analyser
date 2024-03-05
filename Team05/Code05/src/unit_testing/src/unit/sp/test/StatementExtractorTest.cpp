//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/node_extractor/StatementExtractor.h"


//Statement_TestZeroNestingLevel

TEST_CASE("Statement_TestAssignCallPrintRead") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}
    };
    auto procedure = AstProcedures::createAssignCallReadPrint();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

//Statement_TestSingleNestingLevel

TEST_CASE("Statement_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
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
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
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
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}, {"20"}, {"21"}, {"22"}, {"23"}, {"24"},
            {"25"}, {"26"}, {"27"}
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}, {"20"}, {"21"}, {"22"}, {"23"}, {"24"},
            {"25"}, {"26"}, {"27"}
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}, {"19"}
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}, {"15"}, {"16"},
            {"17"}, {"18"}
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}, {"11"}, {"12"}, {"13"}, {"14"}
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}

TEST_CASE("Statement_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<std::string> resultsVector = {
            {"1"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"},
            {"9"}, {"10"}
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<StatementExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstSingleResults(resultsVector));
}