
#include "sp/tokenizer/Scanner.cpp"
#include "sp/parser/Parser.h"
#include "sp/tokenizer/strategy/TokenStrategy.cpp"
#include "sp/SourceProcessor.h"
#include "catch.hpp"
#include "qps/QPS.h"
#include "sp/exception/SemanticAnalysisException.h"
#include "sp/api/formatter/ExprFormatter.h"
#include "sp/exception/FormatterException.h"
#include "sp/cfg/CFG.h"
#include "sp/api/Affects.h"

using namespace std;
void require(bool b) {
    REQUIRE(b);
}

TEST_CASE("Modifsies Handler - QPS") {
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";

    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("Select s such that Modifies(s, v)") {
        std::string query = "call s; Select s";
        std::vector<std::string> expected = {};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}

TEST_CASE("Tokenise sample program") {

    std::string codeSnippet = R"(
    procedure procedure {
        count = 1123;
        cenX = 0;
        cenY = 0;
        call call;
        read x1;
        while (while != 0) {
            count = count + 1;
            cenX = cenX + x;
            cenY = cenY + y;
            call readPoint;
        }
        if (count == 0) then {
            flag = 1;
        } else {
            cenX = cenX / count;
            cenY = cenY / count;
        }
        normSq = cenX * cenX + cenY * cenY;
    }
    )";
    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    auto tokens = sp.scan(codeSnippet);
//    for (auto& token: *tokens) {
//        std::cout << token->toString() << std::endl;
//    }
}

TEST_CASE("Parse complex while condition") {
    std::string codeSnippet = R"(
    procedure procedure {
        count = 1123*923/wq;
        cenX = 0;
        cenY = 0;
        call call;
        while ((while != 0) && (y != 0)) {
            count = count + 1;
            cenX = cenX + x;
            cenY = cenY + y;
            call readPoint;
        }
        if (count == 0) then {
            flag = 1;
        } else {
            cenX = cenX / count;
            cenY = cenY / count;

            while (((x * (2 + 1) == (3 * (2 - x))) || (x == 0)) && (!(y != 5))) {
                print x;
            }

            while (x == 0) {
                x = y + 2;
            }

            while (1>= 1%((0-1)) ) {
                read k;
            }

            while (! ((1==0) && (1==0))) {
                print i;
            }

            while (1>= 1%((1)) ) {
                print w;
            }

            while (x>=(0+0)) {
                read e;
            }
        }
        normSq = cenX * cenX + cenY * cenY;
    }
    )";

    auto sp = SourceProcessor(nullptr);
    auto tokens = sp.scan(codeSnippet);
    const auto parser = new Parser(tokens);
    const auto program = parser->parse();
//    for (const auto& procedures : *program->getProcedures()) {
//        std::cout << procedures->toString() << std::endl;
//    }

    require(true);
}

TEST_CASE("Parse sample program") {
    std::string codeSnippet = R"(
    procedure procedure {
        count = 1123*923/wq;
        cenX = 0;
        cenY = 0;
        call call;
        while ((while != 0) && (y != 0)) {
            count = count + 1;
            cenX = cenX + x;
            cenY = cenY + y;
            call readPoint;
        }
        if (count == 0) then {
            flag = 1;
        } else {
            cenX = cenX / count;
            cenY = cenY / count;
        }
        normSq = cenX * cenX + cenY * cenY;
    }
    )";

    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    auto tokens = sp.scan(codeSnippet);
    const auto parser = new Parser(tokens);
    const auto program = parser->parse();
//    for (const auto& procedures : *program->getProcedures()) {
//        std::cout << procedures->toString() << std::endl;
//    }

    require(true);
}

TEST_CASE("Print with parent extractor") {

    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);

//    std::string query1 = "assign a;variable v;Select v pattern a(_, _)";
    std::string query2 = "assign a;variable v;Select a pattern a(v, _)";
    std::vector<std::string> expected2  = {"2","3","4"};
    std::string query3 = "assign a;variable v;Select v pattern a(_, \"x\")";
    std::vector<std::string> expected3  = {};
    std::string query4 = "assign a;variable v;Select a pattern a(v, _\"x\"_)";
    std::vector<std::string> expected4  = {"4"};
    std::string query5 = "assign a;variable v;Select v pattern a(v, _\"x\"_)";
    std::vector<std::string> expected5  = {"z"};
    std::string query6 = "assign s; variable v; Select s such that Modifies(s, v)";
    std::vector<std::string> expected6  = {"3", "7", "8", "9"};

    std::vector<std::string> queries = {
            //query2,query3,query4, query5,
            query6};
    Table expected = {
//            expected2,expected3,expected4,expected5,
            expected6};

    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    for(int i=0;i<queries.size();i++){
        std::vector<std::string> ans = qps.evaluate(queries[i]);
//        std::cout<< queries[i]<<endl;
        REQUIRE(ans==expected[i]);
    }
}

TEST_CASE("Test SIMPLE semantic analysis") {
    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);

    std::string repeatedProcedureName = R"(
        procedure getInputs {
            read x;
        }

        procedure getInputs {
            read y;
        }
    )";

    REQUIRE_THROWS_WITH(sp.exec(repeatedProcedureName), "Repeated procedure names \"getInputs\" is not allowed");

    std::string unknownProcedureCall = R"(
        procedure main {
            call getInputs;
        }

        procedure getInput {
            read x;
        }
    )";

    REQUIRE_THROWS_WITH(sp.exec(unknownProcedureCall), "Calling of unknown procedure \"getInputs\" is not allowed");

    std::string recursiveCall = R"(
        procedure main {
            read x;
            y = x + 1;
            call main;
        }
    )";

    REQUIRE_THROWS_WITH(sp.exec(recursiveCall), "Recursive and cyclic calls are not allowed");

    std::string cyclicCalls1 = R"(
        procedure A {
            x = 1;
            call B;
        }

        procedure B {
            x = x + 1;
            call C;
        }

        procedure C {
            x = x + 2;
            call A;
        }
    )";

    REQUIRE_THROWS_WITH(sp.exec(cyclicCalls1), "Recursive and cyclic calls are not allowed");

    std::string cyclicCalls2 = R"(
        procedure A {
            x = 1;
            call B;
        }

        procedure B {
            x = x + 1;
            call C;
        }

        procedure C {
            x = x + 2;
            call B;
        }
    )";

    REQUIRE_THROWS_WITH(sp.exec(cyclicCalls2), "Recursive and cyclic calls are not allowed");

    std::string cyclicCalls3 = R"(
        procedure A {
            x = 1;
            call C;
        }

        procedure B {
            x = x + 1;
            call A;
        }

        procedure C {
            x = x + 2;
            call B;
        }
    )";

    REQUIRE_THROWS_WITH(sp.exec(cyclicCalls3), "Recursive and cyclic calls are not allowed");

    std::string cyclicCalls4 = R"(
        procedure A {
            x = 1;
            call B;
        }

        procedure B {
            x = x + 1;
            call C;
        }

        procedure C {
            x = x + 2;
            if (x == 0) then {
                call D;
            } else {
                call E;
            }
        }

        procedure D {
            x = x - 1;
            while (x == 0) {
                call E;
                call F;
            }
        }

        procedure E {
            print x;
        }

        procedure F {
            print y;
            call B;
        }
    )";

    REQUIRE_THROWS_WITH(sp.exec(cyclicCalls4), "Recursive and cyclic calls are not allowed");

    std::string noCyclicCall1 = R"(
        procedure A {
            x = 1;
            call B;
        }

        procedure B {
            x = x + 1;
            call C;
        }

        procedure C {
            x = x + 2;
            if (x == 0) then {
                call D;
            } else {
                print x;
            }
        }

        procedure D {
            x = x - 1;
            while (x == 0) {
                call E;
                call F;
            }
        }

        procedure E {
            print x;
        }

        procedure F {
            print y;
        }
    )";

    REQUIRE_NOTHROW(sp.exec(noCyclicCall1));
}

TEST_CASE("Modifies Handler - QPS") {
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";

    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("Select s such that Modifies(s, v)") {
        std::string query = "stmt s; variable v; Select s such that Modifies(s, v)";
        std::vector<std::string> expected  = {"2", "3", "5", "6", "7", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select v such that Modifies(s, v)") {
        std::string query = "stmt s; variable v; Select v such that Modifies(s, v)";
        std::vector<std::string> expected  = {"f", "x", "y", "z"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select a such that Modifies(s, v)") {
        std::string query = "assign a; variable v; Select a such that Modifies(a, v)";
        std::vector<std::string> expected  = {"3", "7", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select v such that Modifies(a, v)") {
        std::string query = "assign a; variable v; Select v such that Modifies(a, v)";
        std::vector<std::string> expected  = {"x", "y", "z"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select w such that Modifies(s, v)") {
        std::string query = "while w; variable v; Select w such that Modifies(w, v)";
        std::vector<std::string> expected  = {"6"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select v such that Modifies(w, v)") {
        std::string query = "while w; variable v; Select v such that Modifies(w, v)";
        std::vector<std::string> expected  = {"x"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select i such that Modifies(i, v)") {
        std::string query = "if i; variable v; Select i such that Modifies(i, v)";
        std::vector<std::string> expected  = {"2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select v such that Modifies(i, v)") {
        std::string query = "if i; variable v; Select v such that Modifies(i, v)";
        std::vector<std::string> expected  = {"f", "x", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select v such that Modifies(2, v)") {
        std::string query = "variable v; Select v such that Modifies(2, v)";
        std::vector<std::string> expected  = {"f", "x", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select s such that Modifies(s, \"x\")") {
        std::string query = "stmt s; Select s such that Modifies(s, \"x\")";
        std::vector<std::string> expected  = {"2", "6", "7", "9"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select s such that Modifies(s, _)") {
        std::string query = "stmt s; Select s such that Modifies(s, _)";
        std::vector<std::string> expected  = {"2", "3", "5", "6", "7", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }


    SECTION("Select Variable2 from Modifies(Statement, Variable1)") {
        std::string query = "stmt s1; variable v1; variable v2; Select v1 such that Modifies(s1, v2)";
        std::vector<std::string> expected = {"x", "hello", "y", "t", "f", "z"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select Statement1 from Modifies(Statement2, Variable1)") {
        std::string query = "stmt s1; stmt s2; variable v1; Select s1 such that Modifies(s2, v1)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6", "7", "8",
                                             "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

}

TEST_CASE("Uses Handler - QPS") {
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("Select s such that Uses(s, v)") {
        std::string query = "stmt s; variable v; Select s such that Uses(s, v)";
        std::vector<std::string> expected = {"1", "2", "4", "6", "8","11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select v such that Uses(s, v)") {
        std::string query = "stmt s; variable v; Select v such that Uses(s, v)";
        std::vector<std::string> expected = {"hello", "x", "t", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }


    SECTION("Select a such that Uses(a, v)") {
        std::string query = "assign a; variable v; Select a such that Uses(a, v)";
        std::vector<std::string> expected = {"11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select v such that Uses(a, v)") {
        std::string query = "assign a; variable v; Select v such that Uses(a, v)";
        std::vector<std::string> expected = {"x", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select w such that Uses(w, v)") {
        std::string query = "while w; variable v; Select w such that Uses(w, v)";
        std::vector<std::string> expected = {"6"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select v such that Uses(w, v)") {
        std::string query = "while w; variable v; Select v such that Uses(w, v)";
        std::vector<std::string> expected = {"x"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select i such that Uses(i, v)") {
        std::string query = "if i; variable v; Select i such that Uses(i, v)";
        std::vector<std::string> expected = {"2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select v such that Uses(i, v)") {
        std::string query = "if i; variable v; Select v such that Uses(i, v)";
        std::vector<std::string> expected = {"hello", "t", "x"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select v such that Uses(2, v)") {
        std::string query = "variable v; Select v such that Uses(2, v)";
        std::vector<std::string> expected = {"hello", "x", "t"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s such that Uses(s, \"x\")") {
        std::string query = "stmt s; Select s such that Uses(s, \"x\")";
        std::vector<std::string> expected = {"1", "2", "6", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s such that Uses(s, _)") {
        std::string query = "stmt s; Select s such that Uses(s, _)";
        std::vector<std::string> expected = { "1", "11", "2", "4", "6", "8" };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select v1 such that Uses(s1, v2)") {
        std::string query = "stmt s1; variable v1; variable v2; Select v1 such that Uses(s1, v2)";
        std::vector<std::string> expected = {"x", "hello", "y", "t", "f", "z"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Uses(s2, v)") {
        std::string query = "stmt s1; variable v; stmt s2; Select s1 such that Uses(s2, v)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6", "7", "8",
                                             "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}

TEST_CASE("Parent Handler - QPS") {
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                if (i == 1) then {
                    w = 0;
                } else {
                    g = 1;
                }
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("Select s1 such that Parent(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Parent(s1, s2)";
        std::vector<std::string> expected = {"2", "6", "7"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent(s1, s2)") {
        std::string query = "if i; stmt s2; Select s2 such that Parent(i, s2)";
        std::vector<std::string> expected = {"3", "4", "5", "6", "8", "9", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    /**Error when synonym is the same and I am selecting S2**/
    SECTION("Select s2 such that Parent(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Parent(s1, s2)";
        std::vector<std::string> expected = {"3", "4", "5", "6", "7", "8", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent(s1, 3)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Parent(s1, 3)";
        std::vector<std::string> expected = {"2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Parent(3, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Parent(3, s2)";
        std::vector<std::string> expected = {};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }


    SECTION("Select s1 such that Parent(s1, _)") {
        std::string query = "stmt s1; Select s1 such that Parent(s1, _)";
        std::vector<std::string> expected = {"2", "6", "7"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Parent(_, s2)") {
        std::string query = "stmt s2; Select s2 such that Parent(_, s2)";
        std::vector<std::string> expected = {"3", "4", "5", "6", "7", "8", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent(_, _)") {
        std::string query = "stmt s1; Select s1 such that Parent(_, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
              "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent(2, 3)") {
        std::string query = "stmt s1; Select s1 such that Parent(2, 3)";
          std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
              "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}

TEST_CASE("Parent* Handler - QPS") {
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                if (i == 1) then {
                    w = 0;
                } else {
                    g = 1;
                }
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("Select s1 such that Parent*(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Parent*(s1, s2)";
        std::vector<std::string> expected = {"2", "6", "7"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent*(s1, s2)") {
        std::string query = "if i; stmt s2; Select i such that Parent*(i, s2)";
        std::vector<std::string> expected = {"2", "7"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    /**Error when synonym is the same and I am selecting S2**/
    SECTION("Select s2 such that Parent*(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Parent*(s1, s2)";
        std::vector<std::string> expected = {"3", "4", "5", "6", "7", "8", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent*(s1, 3)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Parent*(s1, 3)";
        std::vector<std::string> expected = {"2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Parent*(3, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Parent*(2, s2)";
        std::vector<std::string> expected = {"3", "4", "5", "6", "7", "8", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent*(s1, _)") {
        std::string query = "stmt s1; Select s1 such that Parent*(s1, _)";
        std::vector<std::string> expected = {"2", "6", "7"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }


    SECTION("Select s2 such that Parent*(_, s2)") {
        std::string query = "stmt s2; Select s2 such that Parent*(_, s2)";
        std::vector<std::string> expected = {"3", "4", "5", "6", "7", "8", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

        SECTION("Select s1 such that Parent*(_, _)") {
        std::string query = "stmt s1; Select s1 such that Parent*(_, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
              "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Parent(2, 3)") {
        std::string query = "stmt s1; Select s1 such that Parent*(2, 3)";
          std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
              "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}


TEST_CASE("Follows Handler - QPS") {
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                if (i == 1) then {
                    w = 0;
                } else {
                    g = 1;
                }
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("Select s1 such that Follows(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Follows(s1, s2)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "7", "12", "13"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Follows(i, s2)") {
        std::string query = "if i; stmt s2; Select s2 such that Follows(i, s2)";
        std::vector<std::string> expected = {"10", "12"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    /** Error when synonym is the same and I am selecting S2**/
    SECTION("Select s2 such that Follows(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Follows(s1, s2)";
        std::vector<std::string> expected = { "10" ,"4", "5", "6" ,"2", "12" ,"13" ,"14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows(s1, 3)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Follows(s1, 3)";
        std::vector<std::string> expected = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Follows(3, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Follows(3, s2)";
        std::vector<std::string> expected = {"4"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows(s1, _)") {
        std::string query = "stmt s1; Select s1 such that Follows(s1, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "7", "12", "13"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Follows(_, s2)") {
        std::string query = "stmt s2; Select s2 such that Follows(_, s2)";
        std::vector<std::string> expected = {"2", "4", "5", "6", "10", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows(_, _)") {
        std::string query = "stmt s1; Select s1 such that Follows(_, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
              "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows(2, 3)") {
        std::string query = "stmt s1; Select s1 such that Follows(2, 3)";
          std::vector<std::string> expected = {};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows(2, 3)") {
        std::string query = "stmt s1; Select s1 such that Follows(3,4)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
                                             "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}

TEST_CASE("Follows* Handler - QPS") {
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                if (i == 1) then {
                    w = 0;
                } else {
                    g = 1;
                }
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    //    SECTION("Select s1 such that Follows*(s1, s2)") {
    //        std::string query = "stmt s1; stmt s2; Select s1 such that
    //        Follows*(s1, s2)"; std::vector<std::string> expected = {"1", "2",
    //        "3", "4", "5", "7", "12", "13"}; std::vector<std::string> ans =
    //        qps.evaluate(query); std::sort(ans.begin(), ans.end());
    //        std::sort(expected.begin(), expected.end());
    //        REQUIRE(ans == expected);
    //    }
    //
    //    SECTION("Select s2 such that Follows*(i, s2)") {
    //        std::string query = "if i; stmt s2; Select s2 such that
    //        Follows*(i, s2)"; std::vector<std::string> expected = {"10", "12",
    //        "13", "14"}; std::vector<std::string> ans = qps.evaluate(query);
    //        std::sort(ans.begin(), ans.end());
    //        std::sort(expected.begin(), expected.end());
    //        REQUIRE(ans == expected);
    //    }

    SECTION("Select s2 such that Follows*(s1, s2)") {
        std::string query = "assign s1; assign s2; Select s2 such that Follows*(s1, s2)";
        std::vector<std::string> expected = {"13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows*(s1, 3)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Follows*(s1, 3)";
        std::vector<std::string> expected = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Follows*(3, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Follows*(3, s2)";
        std::vector<std::string> expected = {"4", "5", "6"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows*(s1, _)") {
        std::string query = "stmt s1; Select s1 such that Follows*(s1, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "7", "12", "13"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Follows*(_, s2)") {
        std::string query = "stmt s2; Select s2 such that Follows*(_, s2)";
        std::vector<std::string> expected = {"2", "4", "5", "6", "10", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows*(_, _)") {
        std::string query = "stmt s1; Select s1 such that Follows*(_, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
              "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows*(2, 3)") {
        std::string query = "stmt s1; Select s1 such that Follows*(2, 3)";
          std::vector<std::string> expected = {};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Follows*(2, 3)") {
        std::string query = "stmt s1; Select s1 such that Follows*(3, 4)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6",
                                             "7", "8", "9", "10", "11", "12", "13", "14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}

TEST_CASE("Multi-clause"){
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                if (i == 1) then {
                    w = 0;
                } else {
                    g = 1;
                }
                x=x+1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("merging of multi clause with multiple common synonym") {
        std::string query = "assign a; variable v; Select v such that Uses(a, v) pattern a(v, _)";
        std::vector<std::string> expected = {"x"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
    SECTION("merging of multi clause with multiple common synonym1") {
        std::string query = "assign a; variable v; Select a such that Uses(a, v) pattern a(v, _)";
        std::vector<std::string> expected = {"10"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}

TEST_CASE("Calls relationship"){
    std::string codeSnippet = R"(
    procedure f {
        if (x==1) then {
            while (y==1) {
                call f1;
            }
        } else {
            y=3;
        }
    }

    procedure f1 {
        call f2;
    }

    procedure f2 {
        x=1;
    }
    )";

    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("procedure p; Select p such that Calls(_, _)") {
        std::string query = "procedure p; Select p such that Calls(_, _)";
        std::vector<std::string> expected  = {"f", "f1", "f2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
    SECTION("procedure p; Select p such that Calls(f, _)") {
        std::string query = "procedure p; Select p such that Calls(\"f\", p)";
        std::vector<std::string> expected  = {"f1"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
    SECTION("procedure p; Select p such that Calls(_, f1)") {
        std::string query = "procedure p; Select p such that Calls(p, \"f1\")";
        std::vector<std::string> expected  = {"f"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
    SECTION("procedure p; Select p such that Calls(f, f2)") {
        std::string query = "procedure p; Select p such that Calls(\"f\", \"f2\")";
        std::vector<std::string> expected  = {};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
    SECTION("procedure p; Select p such that Calls*(_, _)") {
        std::string query = "procedure p; Select p such that Calls*(_, _)";
        std::vector<std::string> expected  = {"f", "f1", "f2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
    SECTION("procedure p; Select p such that Calls*(_, _)") {
        std::string query = "procedure p; Select p such that Calls*(_, p)";
        std::vector<std::string> expected  = {"f1", "f2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
    SECTION("procedure p; Select p such that Calls*(f1, _)") {
        std::string query = "procedure p; Select p such that Calls*(p, _)";
        std::vector<std::string> expected  = {"f","f1"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
    SECTION("procedure p; Select p such that Calls*(_, f2)") {
        std::string query = "procedure p; Select p such that Calls*(p,\"f2\")";
        std::vector<std::string> expected  = {"f1","f"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
}

TEST_CASE("Next relationship") {
    std::string codeSnippet = R"(
    procedure f {
        if (x==1) then {
            while (y==1) {
                call f1;
                y = 1;
            }
        } else {
            y=3;
        }
        read y;
        print t;
        y = 2;
    }

    procedure f1 {
        call f2;
    }

    procedure f2 {
        x=1;
    }
    )";

    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("Select s1 such that Next(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Next(s1, s2)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6", "7"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Next(i, s2)") {
        std::string query = "if i; stmt s2; Select s2 such that Next(i, s2)";
        std::vector<std::string> expected = {"2", "5"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Next(s1, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Next(s1, s2)";
        std::vector<std::string> expected = { "2", "3", "4", "5", "6", "7", "8" };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Next(s1, 3)") {
        std::string query = "stmt s1; stmt s2; Select s1 such that Next(s1, 3)";
        std::vector<std::string> expected = { "2" };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Next(3, s2)") {
        std::string query = "stmt s1; stmt s2; Select s2 such that Next(3, s2)";
        std::vector<std::string> expected = {"4"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Next(s1, _)") {
        std::string query = "stmt s1; Select s1 such that Next(s1, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6", "7" };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s2 such that Next(_, s2)") {
        std::string query = "stmt s2; Select s2 such that Next(_, s2)";
        std::vector<std::string> expected = {"2", "3", "4", "5", "6", "7", "8"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Next(_, _)") {
        std::string query = "stmt s1; Select s1 such that Next(_, _)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Next(2, 3)") {
        std::string query = "stmt s1; Select s1 such that Next(2, 3)";
        std::vector<std::string> expected = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s1 such that Next(3, 2)") {
        std::string query = "stmt s1; Select s1 such that Next(3, 2)";
        std::vector<std::string> expected = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}

TEST_CASE("Test ExprFormatter API") {
    REQUIRE(ExprFormatter::format("x") == "x");
    REQUIRE(ExprFormatter::format("x + 1") == "(x+1)");
    REQUIRE(ExprFormatter::format("x + 1 * 2") == "(x+(1*2))");
    REQUIRE_THROWS_WITH(ExprFormatter::format(""), InvalidExprString::ERR_MSG);
    REQUIRE_THROWS_WITH(ExprFormatter::format(" "), InvalidExprString::ERR_MSG);
    REQUIRE_THROWS_WITH(ExprFormatter::format("()"), InvalidExprString::ERR_MSG);
    REQUIRE_THROWS_WITH(ExprFormatter::format("(x"), InvalidExprString::ERR_MSG);
    REQUIRE_THROWS_WITH(ExprFormatter::format(";"), InvalidExprString::ERR_MSG);
    REQUIRE_THROWS_WITH(ExprFormatter::format("x + 1;"), InvalidExprString::ERR_MSG);
    REQUIRE_THROWS_WITH(ExprFormatter::format("x + 1; y = x + 2;"), InvalidExprString::ERR_MSG);
    REQUIRE_THROWS_WITH(ExprFormatter::format("print x"), InvalidExprString::ERR_MSG);
}

TEST_CASE("Test Extractor") {
    std::string codeSnippet = R"(
procedure main {
            read x;
            read y;
            print x;
            print y;
            z = 3;

            if (x == 0) then {
                x = x + 1;
                y = y - 1;
                z = 2;
            } else {
                x = x + 2;
                y = y + 1;

                if (z != 3) then {
                    x = 0;
                    y = 0;
                    z = 0;
                } else {
                    x = 1;
                    z = x + y + 2;
                }
            }

            x = x + 1;
            z = y + x;

            while (x < 5) {
                print x;
                print y;
                while (y < 2) {
                    print z;
                    print y;
                }
                z = x - y;
                k = z + y;

                if (k > 0) then {
                    k = k - 1;
                } else {
                    k = k + 1;
                }

                print k;
            }

            print x;
            print y;
            print z;
        }
    )";

    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);

    require(true);
}

TEST_CASE("expression matching") {
  std::string codeSnippet = R"(
    procedure f {
        x=v+x*y+z*t;
        a=b/c+d%e;
    }
    )";
  std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
  auto pkb = make_shared<PopulatePkb>(p);
  auto sp = SourceProcessor(pkb);
  sp.exec(codeSnippet);
  QueryPkb pkb1(p);
  QPS qps(std::make_shared<QueryPkb>(pkb1));

  SECTION("match (_,_b/c_)") {
    std::string query = "assign a; Select a pattern a(_, _\"b/c\"_)";
    std::vector<std::string> expected = {"2"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_d%e_)") {
    std::string query = "assign a; Select a pattern a(_, _\"d%e\"_)";
    std::vector<std::string> expected = {"2"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_c+d_)") {
    std::string query = "assign a; Select a pattern a(_, _\"c+d\"_)";
    std::vector<std::string> expected = {};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_v+x*y_)") {
    std::string query = "assign a; Select a pattern a(_, _\"v+x*y\"_)";
    std::vector<std::string> expected = {"1"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (x,v+x*y+z*t)") {
    std::string query = "assign a; Select a pattern a(\"x\", \"v+x*y+z*t\")";
    std::vector<std::string> expected = {"1"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (x,v)") {
    std::string query = "assign a; Select a pattern a(\"x\", \"v\")";
    std::vector<std::string> expected = {};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_v_)") {
    std::string query = "assign a; Select a pattern a(_, _\"v\"_)";
    std::vector<std::string> expected = {"1"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_x*y_)") {
    std::string query = "assign a; Select a pattern a(_, _\"x*y\"_)";
    std::vector<std::string> expected = {"1"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_v+x_)") {
    std::string query = "assign a; Select a pattern a(_, _\"v+x\"_)";
    std::vector<std::string> expected = {};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_v+x*y_)") {
    std::string query = "assign a; Select a pattern a(_, _\"v+x*y\"_)";
    std::vector<std::string> expected = {"1"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_y+z*t_)") {
    std::string query = "assign a; Select a pattern a(_, _\"y+z*t\"_)";
    std::vector<std::string> expected = {};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_x*y+z*t_)") {
    std::string query = "assign a; Select a pattern a(_, _\"x * y + z * t\"_)";
    std::vector<std::string> expected = {};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
  SECTION("match (_,_v+x*y+z*t_)") {
    std::string query = "assign a; Select a pattern a(_, _\"v + x * y + z * t\"_)";
    std::vector<std::string> expected = {"1"};
    std::vector<std::string> ans = qps.evaluate(query);
    std::sort(ans.begin(), ans.end());
    std::sort(expected.begin(), expected.end());
    REQUIRE(ans == expected);
  }
}

TEST_CASE("AST to CFG") {
    std::string source = R"(
        procedure main {
            read x;
            read y;
            print x;
            print y;
            z = 3;

            if (x == 0) then {
                x = x + 1;
                y = y - 1;
                z = 2;
            } else {
                x = x + 2;
                y = y + 1;

                if (z != 3) then {
                    x = 0;
                    y = 0;
                    z = 0;
                } else {
                    x = 1;
                    z = x + y + 2;
                }
            }

            call home;
            x = x + 1;
            z = y + x;

            while (x < 5) {
                print x;
                print y;
                while (y < 2) {
                    print z;
                    print y;
                }
                z = x - y;
                k = z + y;

                if (k > 0) then {
                    k = k - 1;
                } else {
                    k = k + 1;
                }

                print k;
            }

            print x;
            print y;
            print z;
        }
    )";

    std::string expect = R"(CFG [main]: [
	Block[1 - 5]: [
		predecessors: [],
		successors: [6 - 6]
	],
	Block[6 - 6]: [
		predecessors: [1 - 5],
		successors: [7 - 9, 10 - 11]
	],
	Block[7 - 9]: [
		predecessors: [6 - 6],
		successors: [18 - 20]
	],
	Block[10 - 11]: [
		predecessors: [6 - 6],
		successors: [12 - 12]
	],
	Block[12 - 12]: [
		predecessors: [10 - 11],
		successors: [13 - 15, 16 - 17]
	],
	Block[13 - 15]: [
		predecessors: [12 - 12],
		successors: [Dummy]
	],
	Block[16 - 17]: [
		predecessors: [12 - 12],
		successors: [Dummy]
	],
	Block[Dummy]: [
		predecessors: [13 - 15, 16 - 17],
		successors: [18 - 20]
	],
	Block[18 - 20]: [
		predecessors: [7 - 9, Dummy],
		successors: [21 - 21]
	],
	Block[21 - 21]: [
		predecessors: [18 - 20, 32 - 32],
		successors: [22 - 23, 33 - 35]
	],
	Block[22 - 23]: [
		predecessors: [21 - 21],
		successors: [24 - 24]
	],
	Block[24 - 24]: [
		predecessors: [22 - 23, 25 - 26],
		successors: [25 - 26, 27 - 28]
	],
	Block[25 - 26]: [
		predecessors: [24 - 24],
		successors: [24 - 24]
	],
	Block[27 - 28]: [
		predecessors: [24 - 24],
		successors: [29 - 29]
	],
	Block[29 - 29]: [
		predecessors: [27 - 28],
		successors: [30 - 30, 31 - 31]
	],
	Block[30 - 30]: [
		predecessors: [29 - 29],
		successors: [32 - 32]
	],
	Block[31 - 31]: [
		predecessors: [29 - 29],
		successors: [32 - 32]
	],
	Block[32 - 32]: [
		predecessors: [30 - 30, 31 - 31],
		successors: [21 - 21]
	],
	Block[33 - 35]: [
		predecessors: [21 - 21],
		successors: []
	]
]
)";

    auto sp = SourceProcessor(nullptr);
    const auto& program = sp.parse(sp.scan(source));
    REQUIRE(CFGCollection(program).find("main").value()->toString() == expect);
}

TEST_CASE("test") {
    SECTION("test 1") {
        std::string codeSnippet = R"(
            procedure program1 {
                if ((x != 4 + y) || (k == 4 + u)) then {
                    x = x + 1;
                    y = y - 1 + z;
                    z = 2;
                } else {
                    if (z != 3) then {
                        call program2;
                        x = 0;
                        y = 0;
                        z = 0;
                    } else {
                        x = 1;
                        z = x + y + 2;
                    }
                }
                x = x + 1;
                z = y + x;
                read x;
                print y;
                read z;
            }

            procedure program2 {
                while ((x != 4 + y) && (k != 4 + u)) {
                    print x;
                    read y;
                    call program3;
                    while (y < 2) {
                        print z;
                        print y;
                        if (k > 0) then {
                            k = k * 1 + 10 * r + h;
                        } else {
                            k = k + 1;
                        }
                    }
                    z = x - y;
                    k = z + y / k * 1 + 10 * r + h;
                    print k;
                }
            }

            procedure program3 {
                    z = x - y;
                    k = z + y * k * r / h;
                    print t;
            }
        )";

        std::cout << "test 1" << std::endl;
        std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
        auto pkb = make_shared<PopulatePkb>(p);
        auto sp = SourceProcessor(pkb);
        sp.exec(codeSnippet);

        require(true);
    }
    SECTION("test 2") {
        std::string codeSnippet = R"(
            procedure program1 {
                while ((x != 4 + y) && (k != 4 + u)) {
                    if (z > 3) then {
                        x = z + y * k * r / h + 100;
                        y = 9 + 1 + y;
                        z = 10 + 7;
                    } else {
                        call program2;
                        x = 1;
                        z = x + y + 2;
                    }
                }
                x = x + 1;
                z = y + x;
                read x;
                print y;
                read z;
            }

            procedure program2 {
                if ((x != 4 + y) || (k <= 4 + u)) then {
                    while ((x != 4 + y) && (k >= 4 + u)) {
                        print x;
                        read y;
                        call program3;
                        print k;
                    }
                } else {
                    if (z != 3) then {
                        x = 0;
                        y = 0;
                        u = z / y / k * r / h + 100;
                    } else {
                        x = 1;
                        z = x + y + 2;
                    }
                }
                x = x + 1;
                z = y + x;
                read x;
                print y;
                read z;
            }

            procedure program3 {
                    z = x - y;
                    u = z / y - k * r / h + 100;
                    print t;
            }
        )";

        std::cout << "test 2" << std::endl;
        std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
        auto pkb = make_shared<PopulatePkb>(p);
        auto sp = SourceProcessor(pkb);
        sp.exec(codeSnippet);

        require(true);
    }
}


//TEST_CASE("Test Affects") {
//    const auto source = R"(
//        procedure main {
//            x = 0;
//            y = 1;
//            z = 2;
//
//            if (x == 0) then {
//                x = 3;
//            } else {
//                x = 4;
//            }
//        }
//    )";
//
//    const auto& pkb = std::make_shared<PkbStorage>();
//    auto populatePkb = std::make_shared<PopulatePkb>(pkb);
//    auto queryPkb = std::make_shared<QueryPkb>(pkb);
//
//    auto sp = SourceProcessor(populatePkb);
//    const auto& tokens = sp.scan(source);
//    const auto& program = sp.parse(tokens);
//    sp.validate(program);
//    sp.extract(program);
//
//    const auto& cfgCollection = std::make_shared<CFGCollection>(program);
//    auto affects = Affects(cfgCollection, queryPkb);
//    const auto [in, out] = affects.get(1, 2);
//
//    for (const auto& block : *cfgCollection->getCFGs()->at(0)->getBlocks()) {
//        std::cout << block->toString() << std::endl;
//        std::cout << "In: [" << std::endl;
//        for (const auto& var : in.at(block)) {
//            std::cout << "(" << var.getName() << ", " << std::to_string(var.getStmtNo()) << ")" << std::endl;
//        }
//        std::cout << "]" << std::endl;
//        std::cout << "Out: [" << std::endl;
//        for (const auto& var : out.at(block)) {
//            std::cout << "(" << var.getName() << ", " << std::to_string(var.getStmtNo()) << ")" << std::endl;
//        }
//        std::cout << "]" << std::endl;
//    }
//}