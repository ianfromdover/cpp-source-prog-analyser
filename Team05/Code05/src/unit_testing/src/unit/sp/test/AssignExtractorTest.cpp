//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstProcedures.cpp"
#include "../helper/PKBStubSP.cpp"
#include "sp/extractor/node_extractor/AssignExtractor.h"


//Assign_TestZeroNestingLevel

TEST_CASE("Assign_TestAssignCallPrintRead") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "t", "( ( ( 1 + y ) * 3 ) + y )"}
    };
    auto procedure = AstProcedures::createAssignCallReadPrint();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

//Assign_TestSingleNestingLevel

TEST_CASE("Assign_TestIfElseWithStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "( y + 3 )"},
            {"6", "t", "( ( ( 1 + y ) * 3 ) + y )"},
            {"10", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "( y + 3 )"},
            {"6", "x", "( y + 3 )"},
            {"10", "x", "( y + 3 )"},
            {"14", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}
/**
TEST_CASE("Assign_TestIfElseWithStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"6", "x", "( y + 3 )"},
            {"10", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}
**/
TEST_CASE("Assign_TestWhileWithStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "( y + 3 )"},
            {"6", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"1", "x", "( y + 3 )"},
            {"6", "x", "( y + 3 )"},
            {"10", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"6", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

//Assign_TestDoubleNestingLevel

TEST_CASE("Assign_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "t", "( ( ( 1 + y ) * 3 ) + y )"},
            {"11", "x", "( y + 3 )"},
            {"15", "x", "( y + 3 )"},
            {"20", "x", "( y + 3 )"},
            {"24", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
            {"15", "x", "( y + 3 )"},
            {"19", "x", "( y + 3 )"},
            {"24", "x", "( y + 3 )"},
            {"28", "x", "( y + 3 )"},
            {"32", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
            {"16", "x", "( y + 3 )"},
            {"20", "x", "( y + 3 )"},
            {"24", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
            {"16", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
            {"15", "x", "( y + 3 )"},
            {"20", "x", "( y + 3 )"},
            {"24", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"12", "x", "( y + 3 )"},
            {"16", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
            {"15", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"2", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
            {"11", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}

TEST_CASE("Assign_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    std::multiset<tuple<std::string, std::string, std::string>> resultsVector = {
            {"3", "x", "( y + 3 )"},
            {"7", "x", "( y + 3 )"},
    };
    auto procedure = AstProcedures::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    auto pkb = make_shared<PKBStubSP>();
    shared_ptr<ProgramVisitor> extractor = std::make_shared<AssignExtractor>(pkb);
    procedure->accept(*extractor);
    REQUIRE(pkb->checkAgainstTupleResults(resultsVector));
}