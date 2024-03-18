//
// Created by tohzh on 20/2/2024.
//

#include <iostream>

#include "catch.hpp"
#include "qps/parser/IntermediateQuery.h"
#include "qps/parser/QPSParser.h"
#include "qps/query_builder/QueryObjectBuilder.h"
#include "qps/query_validator/QueryValidator.h"
#include "qps/tokenizer/QPSStrategyList.h"
#include "qps/tokenizer/Tokenizer.h"

using namespace std;

// this testHelper takes in a query in string and returns the query object string representation.
std::string testHelper1(std::string source);

TEST_CASE("OneDeclaration_TokenizertoQOBuilder_ReturnsOneSelectClause") {
    std::string source = "stmt s;"
                         "Select s";
    std::string processed = testHelper1(source);
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
    std::string processed = testHelper1(source);
    std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], c [CONST], cal [CALL], ifs [IF], p [PROCEDURE], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]";
    REQUIRE(processed == output);
    cout << processed;
}


TEST_CASE("commasInDeclaration_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1 ";
    std::string processed = testHelper1(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}



TEST_CASE("singleFollowsConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "stmt s;"
                         "read r; "
                         "print pr; "
                         "while w; "
                         "if ifs; "
                         "assign a; "
                         "Select pr ";
    SECTION("stmt-read") {
        std::string input = source + "such that Follows(s, r)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(s [STMT], r [READ])";
        REQUIRE(processed == output);
    }

    SECTION("read-stmt") {
        std::string input = source + "such that Follows(r, s)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(r [READ], s [STMT])";
        REQUIRE(processed == output);
    }

    SECTION("print-assign") {
        std::string input = source + "such that Follows(pr, a)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(pr [PRINT], a [ASSIGN])";
        REQUIRE(processed == output);
    }

    SECTION("assign-print") {
        std::string input = source + "such that Follows(a, pr)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(a [ASSIGN], pr [PRINT])";
        REQUIRE(processed == output);
    }

    SECTION("while-if") {
        std::string input = source + "such that Follows(w, ifs)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(w [WHILE], ifs [IF])";
        REQUIRE(processed == output);
    }

    SECTION("if-while") {
        std::string input = source + "such that Follows(ifs, w)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(ifs [IF], w [WHILE])";
        REQUIRE(processed == output);
    }

    SECTION("int-wildcard") {
        std::string input = source + "such that Follows(5, _)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(5 [INTEGER], _ [STMT WILDCARD])";
        REQUIRE(processed == output);
    }

    SECTION("wildcard-int") {
        std::string input = source + "such that Follows(_, 7)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Follows(_ [STMT WILDCARD], 7 [INTEGER])";
        REQUIRE(processed == output);
    }

}

TEST_CASE("singleFollowsTConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "stmt s;"
                         "read r; "
                         "print pr; "
                         "while w; "
                         "if ifs; "
                         "assign a; "
                         "Select pr ";
    SECTION("stmt-read") {
        std::string input = source + "such that Follows*(s, r)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(s [STMT], r [READ])";
        REQUIRE(processed == output);
    }

    SECTION("read-stmt") {
        std::string input = source + "such that Follows*(r, s)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(r [READ], s [STMT])";
        REQUIRE(processed == output);
    }

    SECTION("print-assign") {
        std::string input = source + "such that Follows*(pr, a)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(pr [PRINT], a [ASSIGN])";
        REQUIRE(processed == output);
    }

    SECTION("assign-print") {
        std::string input = source + "such that Follows*(a, pr)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(a [ASSIGN], pr [PRINT])";
        REQUIRE(processed == output);
    }

    SECTION("while-if") {
        std::string input = source + "such that Follows*(w, ifs)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(w [WHILE], ifs [IF])";
        REQUIRE(processed == output);
    }

    SECTION("if-while") {
        std::string input = source + "such that Follows*(ifs, w)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(ifs [IF], w [WHILE])";
        REQUIRE(processed == output);
    }

    SECTION("int-wildcard") {
        std::string input = source + "such that Follows*(5, _)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(5 [INTEGER], _ [STMT WILDCARD])";
        REQUIRE(processed == output);
    }

    SECTION("wildcard-int") {
        std::string input = source + "such that Follows*(_, 7)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: FollowsT(_ [STMT WILDCARD], 7 [INTEGER])";
        REQUIRE(processed == output);
    }
}

TEST_CASE("singleParentConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "stmt s;"
                         "read r; "
                         "print pr; "
                         "while w; "
                         "if ifs; "
                         "assign a; "
                         "Select pr ";
    SECTION("stmt-read") {
        std::string input = source + "such that Parent(s, r)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(s [STMT], r [READ])";
        REQUIRE(processed == output);
    }

    SECTION("read-stmt") {
        std::string input = source + "such that Parent(r, s)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(r [READ], s [STMT])";
        REQUIRE(processed == output);
    }

    SECTION("print-assign") {
        std::string input = source + "such that Parent(pr, a)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(pr [PRINT], a [ASSIGN])";
        REQUIRE(processed == output);
    }

    SECTION("assign-print") {
        std::string input = source + "such that Parent(a, pr)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(a [ASSIGN], pr [PRINT])";
        REQUIRE(processed == output);
    }

    SECTION("while-if") {
        std::string input = source + "such that Parent(w, ifs)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(w [WHILE], ifs [IF])";
        REQUIRE(processed == output);
    }

    SECTION("if-while") {
        std::string input = source + "such that Parent(ifs, w)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(ifs [IF], w [WHILE])";
        REQUIRE(processed == output);
    }

    SECTION("int-wildcard") {
        std::string input = source + "such that Parent(5, _)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(5 [INTEGER], _ [STMT WILDCARD])";
        REQUIRE(processed == output);
    }

    SECTION("wildcard-int") {
        std::string input = source + "such that Parent(_, 7)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: Parent(_ [STMT WILDCARD], 7 [INTEGER])";
        REQUIRE(processed == output);
    }
}

TEST_CASE("singleParentTConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "stmt s;"
                         "read r; "
                         "print pr; "
                         "while w; "
                         "if ifs; "
                         "assign a; "
                         "Select pr ";
    SECTION("stmt-read") {
        std::string input = source + "such that Parent*(s, r)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(s [STMT], r [READ])";
        REQUIRE(processed == output);
    }

    SECTION("read-stmt") {
        std::string input = source + "such that Parent*(r, s)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(r [READ], s [STMT])";
        REQUIRE(processed == output);
    }

    SECTION("print-assign") {
        std::string input = source + "such that Parent*(pr, a)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(pr [PRINT], a [ASSIGN])";
        REQUIRE(processed == output);
    }

    SECTION("assign-print") {
        std::string input = source + "such that Parent*(a, pr)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(a [ASSIGN], pr [PRINT])";
        REQUIRE(processed == output);
    }

    SECTION("while-if") {
        std::string input = source + "such that Parent*(w, ifs)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(w [WHILE], ifs [IF])";
        REQUIRE(processed == output);
    }

    SECTION("if-while") {
        std::string input = source + "such that Parent*(ifs, w)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(ifs [IF], w [WHILE])";
        REQUIRE(processed == output);
    }

    SECTION("int-wildcard") {
        std::string input = source + "such that Parent*(5, _)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(5 [INTEGER], _ [STMT WILDCARD])";
        REQUIRE(processed == output);
    }

    SECTION("wildcard-int") {
        std::string input = source + "such that Parent*(_, 7)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], w [WHILE]\n{CONSTRAINTS}: ParentT(_ [STMT WILDCARD], 7 [INTEGER])";
        REQUIRE(processed == output);
    }
}

TEST_CASE("singleUsesSConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source =  "stmt s;"
                          "read r; "
                          "print pr; "
                          "while w; "
                          "if ifs; "
                          "assign a; "
                          "variable v;"
                          "Select pr ";
    SECTION("if-var") {
        std::string input = source += "such that Uses(ifs, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(ifs [IF], v [VARIABLE])";
        REQUIRE(processed == output);
    }

    SECTION("assign-var") {
        std::string input = source += "such that Uses(a, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(a [ASSIGN], v [VARIABLE])";
        REQUIRE(processed == output);
    }

    SECTION("print-var") {
        std::string input = source += "such that Uses(pr, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(pr [PRINT], v [VARIABLE])";
        REQUIRE(processed == output);
    }

    SECTION("while-var") {
        std::string input = source += "such that Uses(w, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(w [WHILE], v [VARIABLE])";
        REQUIRE(processed == output);
    }

//    Not in milestone 1 (procedure)
//    SECTION("procedure-var") {
//        std::string input = source += "such that Uses(p, v)";
//        std::string processed = testHelper1(input);
//        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesP(p [PROCEDURE], v [VARIABLE])";
//        REQUIRE(processed == output);
//    }

//      Not in milestone 1 (call)
//    SECTION("call-var") {
//        std::string input = source += "such that Uses(cal, v)";
//        std::string processed = testHelper1(input);
//        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(a [ASSIGN], v [VARIABLE])";
//        REQUIRE(processed == output);
//    }

    SECTION("wild-wild") {
        std::string input = source += "such that Uses(_, _)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(_ [STMT WILDCARD], _ [ENT WILDCARD])";
        REQUIRE(processed == output);
    }

    SECTION("wild-var") {
        std::string input = source += "such that Uses(_, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(_ [STMT WILDCARD], v [VARIABLE])";
        REQUIRE(processed == output);
    }

    SECTION("assign-wild") {
        std::string input = source += "such that Uses(a, _)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: pr [PRINT]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: UsesS(a [ASSIGN], _ [ENT WILDCARD])";
        REQUIRE(processed == output);
    }

}


TEST_CASE("singleModifiesSConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "stmt s;"
                         "read r; "
                         "print pr; "
                         "while w; "
                         "if ifs; "
                         "assign a; "
                         "variable v;"
      "procedure p;"
      "call c;"
      "Select v ";

    SECTION("assign-var") {
        std::string input = source + "such that Modifies(a, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: ModifiesS(a [ASSIGN], v [VARIABLE])";
        REQUIRE(processed == output);
    }

    SECTION("read-var") {
        std::string input = source + "such that Modifies(r, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: ModifiesS(r [READ], v [VARIABLE])";
        REQUIRE(processed == output);
    }

    SECTION("if-var") {
        std::string input = source + "such that Modifies(ifs, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: ModifiesS(ifs [IF], v [VARIABLE])";
        REQUIRE(processed == output);
    }

    SECTION("while-var") {
        std::string input = source + "such that Modifies(w, v)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: ModifiesS(w [WHILE], v [VARIABLE])";
        REQUIRE(processed == output);
    }

//    Not in milestone 1
    SECTION("procedure-var") {
      std::string input = source + "such that Modifies(p, v)";
      std::string processed = testHelper1(input);
      std::string output =
          "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr "
          "[PRINT], r [READ], s [STMT], v [VARIABLE], w "
          "[WHILE]\n{CONSTRAINTS}: ModifiesS(a [ASSIGN], v [VARIABLE])";
      REQUIRE(processed == output);
    }

    SECTION("procedureCall-var") {
      std::string input = source + "such that Modifies(c, v)";
      std::string processed = testHelper1(input);
      std::string output =
          "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr "
          "[PRINT], r [READ], s [STMT], v [VARIABLE], w "
          "[WHILE]\n{CONSTRAINTS}: ModifiesS(a [ASSIGN], v [VARIABLE])";
      REQUIRE(processed == output);
    }

    // Invalid Test case, modifies should not take wildcard as 1st argument
    //    SECTION("wild-var") {
    //        std::string input = source + "such that Modifies(_, v)";
    //        std::string processed = testHelper1(input);
    //        std::string output = "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a
    //        [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE],
    //        w [WHILE]\n{CONSTRAINTS}: ModifiesS(_ [STMT WILDCARD], v
    //        [VARIABLE])"; REQUIRE(processed == output);
    //    }

    SECTION("assign-wild") {
        std::string input = source + "such that Modifies(a, _)";
        std::string processed = testHelper1(input);
        std::string output = "{RETURN}: v [VARIABLE]\n{DECLARATIONS}: a [ASSIGN], ifs [IF], pr [PRINT], r [READ], s [STMT], v [VARIABLE], w [WHILE]\n{CONSTRAINTS}: ModifiesS(a [ASSIGN], _ [ENT WILDCARD])";
        REQUIRE(processed == output);
    }
}

// Not in milestone 1
//TEST_CASE("singleModifiesPConstraint_TokenizertoQOBuilder_returnsCorrect") {
//    std::string source = "procedure p;"
//                         "variable v; "
//                         "Select p "
//                         "such that Modifies(p, v)";
//    std::string processed = testHelper1(source);
//    std::string output = "{RETURN}: p [PROCEDURE]\n{DECLARATIONS}: p [PROCEDURE], v [VARIABLE]\n{CONSTRAINTS}: ModifiesP(p [PROCEDURE], v [VARIABLE])";
//    REQUIRE(processed == output);
//    cout << processed;
//}

TEST_CASE("SingleConcretePatternConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "assign a;"
                         "Select a "
                         " pattern a (\"someExpr\", _\"wildcardExpr\"_)";
    std::string processed = testHelper1(source);
    std::string output = "{RETURN}: a [ASSIGN]\n{DECLARATIONS}: a [ASSIGN]\n{CONSTRAINTS}: Pattern(\"someExpr\" [QUOTED IDENT], \"wildcardExpr\" [EXPR WITH WILDCARD])";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("expressionWildcard_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "assign a;"
                         "Select a "
                         " pattern a (_, _\"wildcardExpr\"_)";
    std::string processed = testHelper1(source);
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
//    std::string processed = testHelper1(source);
//    std::string output = "{RETURN}: p [PROCEDURE]\n{DECLARATIONS}: p [PROCEDURE], v [VARIABLE]\n{CONSTRAINTS}: ModifiesP(p [PROCEDURE], _ [ENT WILDCARD])";
//    REQUIRE(processed == output);
//    cout << processed;
//}

TEST_CASE("StatementWildcard_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "if f;"
                         "read r; "
                         "Select r "
                         "such that Parent(_, r)";
    std::string processed = testHelper1(source);
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
    std::string processed = testHelper1(source);
    std::string output = "{RETURN}: r [READ]\n{DECLARATIONS}: a [ASSIGN], f [IF], r [READ]\n{CONSTRAINTS}: Parent(_ [STMT WILDCARD], r [READ]), Pattern(_ [ENT WILDCARD], \"wildcardExpr\" [EXPR WITH WILDCARD])";
    REQUIRE(processed == output);
    cout << processed;
}

std::string testHelper1(std::string source) {
    std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();
    std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();
    Tokenizer tokenizer(source, strategies, tokens);
    tokenizer.tokenize();
    QPSParser parser(*tokens);

    std::shared_ptr<IntermediateQuery> intermediateQuery = parser.parse();
    QueryValidator validator;
    validator.validateQuery(*intermediateQuery);
    // intermediateQuery->processDeclarations();

    QueryObjectBuilder builder;
    std::shared_ptr<QueryObject> qo = builder.build(intermediateQuery);
    return qo->toString();
}