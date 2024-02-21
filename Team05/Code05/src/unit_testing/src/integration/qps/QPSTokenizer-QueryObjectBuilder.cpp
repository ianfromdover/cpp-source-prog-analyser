//
// Created by tohzh on 20/2/2024.
//

#include "qps/query_builder/QueryObjectBuilder.h"
#include "qps/parser/IntermediateQuery.h"
#include "catch.hpp"
#include "qps/tokenizer/QPSStrategyList.h"
#include "qps/tokenizer/Tokenizer.h"
#include "qps/parser/QPSParser.h"
#include <iostream>

using namespace std;

// this testHelper takes in a query in string and returns the query object string representation.
std::string testHelper(std::string source) {
    std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();
    std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();
    Tokenizer tokenizer(source, strategies, tokens);
    tokenizer.tokenize();
    QPSParser parser(*tokens);

    std::shared_ptr<IntermediateQuery> intermediateQuery = parser.parse();
    intermediateQuery->processDeclarations();

    QueryObjectBuilderTest builder;
    std::shared_ptr<QueryObject> qo = builder.build(intermediateQuery);
    return qo->toString();
}

TEST_CASE("OneDeclaration_TokenizertoQOBuilder_ReturnsOneSelectClause") {
    std::string source = "stmt s;"
                         "Select s";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: s [STMT]\n{DECLARATIONS}: s [STMT]";
    REQUIRE(processed == output);
}

TEST_CASE("MultipleDeclaration_TokenizertoQOBuilder_ReturnsAllDeclaration") {
    std::string source = "stmt s;"
                         "variable v; "
                         "call cal; "
                         "read r; "
                         "print pr; "
                         "while w; "
                         "if ifs; "
                         "assign a; "
                         "constant c; "
                         "procedure p; "
                         "Select pr ";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], c [CONST], cal [CALL], ifs [IF], p [PROCEDURE], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]";
    REQUIRE(processed == output);
    cout << processed;
}


TEST_CASE("commasInDeclaration_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1 ";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}



TEST_CASE("singleFollowsConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "if f;"
                         "while w;"
                         "Select w "
                         "such that Follows(f, w)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: w [WHILE]\n{DECLARATIONS}: f [IF], w [WHILE]\n{CONSTRAINTS}: Follows(f [IF], w [WHILE])";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleFollowsTConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "print a;"
                         "stmt w;"
                         "Select w "
                         "such that Follows*(a, w)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: w [STMT]\n{DECLARATIONS}: a [PRINT], w [STMT]\n{CONSTRAINTS}: FollowsT(a [PRINT], w [STMT])";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleParentConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "if f;"
                         "read r; "
                         "Select r "
                         "such that Parent(f, r)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: r [READ]\n{DECLARATIONS}: f [IF], r [READ]\n{CONSTRAINTS}: Parent(f [IF], r [READ])";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleParentTConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "while w;"
                         "read r; "
                         "Select r "
                         "such that Parent*(w, r)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: r [READ]\n{DECLARATIONS}: w [WHILE], r [READ]\n{CONSTRAINTS}: ParentT(w [WHILE], r [READ])";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleUsesSConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read r;"
                         "constant c; "
                         "Select c "
                         "such that Uses(r, c)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: c [CONST]\n{DECLARATIONS}: c [CONST], r [READ]\n{CONSTRAINTS}: UsesS(r [READ], c [CONST])";
    REQUIRE(processed == output);
    cout << processed;
}

// Not in milestone 1 (procedure)
//TEST_CASE("singleUsesPConstraint_TokenizertoQOBuilder_returnsCorrect") {
//    std::string source = "variable v;"
//                         "procedure p; "
//                         "Select v "
//                         "such that Uses(p, v)";
//    std::string processed = testHelper(source);
//    std::string output = "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: v [VARIABLE], p [PROCEDURE]\n{CONSTRAINTS}: UsesP(p [PROCEDURE], v [VARIABLE])";
//    REQUIRE(processed == output);
//    cout << processed;
//}

TEST_CASE("singleModifiesSConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "assign a;"
                         "variable v; "
                         "Select a "
                         "such that Modifies(a, v)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: a [ASSIGN]\n{DECLARATIONS}: a [ASSIGN], v [VARIABLE]\n{CONSTRAINTS}: ModifiesS(a [ASSIGN], v [VARIABLE])";
    REQUIRE(processed == output);
    cout << processed;
}

// Not in milestone 1
//TEST_CASE("singleModifiesPConstraint_TokenizertoQOBuilder_returnsCorrect") {
//    std::string source = "procedure p;"
//                         "variable v; "
//                         "Select p "
//                         "such that Modifies(p, v)";
//    std::string processed = testHelper(source);
//    std::string output = "{RETURN}: p [PROCEDURE]\n{DECLARATIONS}: p [PROCEDURE], v [VARIABLE]\n{CONSTRAINTS}: ModifiesP(p [PROCEDURE], v [VARIABLE])";
//    REQUIRE(processed == output);
//    cout << processed;
//}

TEST_CASE("SingleConcretePatternConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "assign a;"
                         "Select a "
                         " pattern a (\"someExpr\", _\"wildcardExpr\"_)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: a [ASSIGN]\n{DECLARATIONS}: a [ASSIGN]\n{CONSTRAINTS}: Pattern(\"someExpr\" [QUOTED IDENT], \"wildcardExpr\" [EXPR WITH WILDCARD])";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("expressionWildcard_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "assign a;"
                         "Select a "
                         " pattern a (_, _\"wildcardExpr\"_)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: a [ASSIGN]\n{DECLARATIONS}: a [ASSIGN]\n{CONSTRAINTS}: Pattern(_ [ENT WILDCARD], \"wildcardExpr\" [EXPR WITH WILDCARD])";
    REQUIRE(processed == output);
    cout << processed;
}

// Not in milestone 1 scope (procedures)
//TEST_CASE("EntityWildcard_TokenizertoQOBuilder_returnsCorrect") {
//    std::string source = "procedure p;"
//                         "variable v; "
//                         "Select p "
//                         "such that Modifies(p, _)";
//    std::string processed = testHelper(source);
//    std::string output = "{RETURN}: p [PROCEDURE]\n{DECLARATIONS}: p [PROCEDURE], v [VARIABLE]\n{CONSTRAINTS}: ModifiesP(p [PROCEDURE], _ [ENT WILDCARD])";
//    REQUIRE(processed == output);
//    cout << processed;
//}

TEST_CASE("StatementWildcard_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "if f;"
                         "read r; "
                         "Select r "
                         "such that Parent(_, r)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: r [READ]\n{DECLARATIONS}: f [IF], r [READ]\n{CONSTRAINTS}: Parent(_ [STMT WILDCARD], r [READ])";
    REQUIRE(processed == output);
    cout << processed;
}


TEST_CASE("1ConstraintWithPattern_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "if f;"
                         "assign a;"
                         "read r; "
                         "Select r "
                         "such that Parent(_, r) "
                         " pattern a (_, _\"wildcardExpr\"_)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: r [READ]\n{DECLARATIONS}: a [ASSIGN], f [IF], r [READ]\n{CONSTRAINTS}: Parent(_ [STMT WILDCARD], r [READ]), Pattern(_ [ENT WILDCARD], \"wildcardExpr\" [EXPR WITH WILDCARD])";
    REQUIRE(processed == output);
    cout << processed;
}