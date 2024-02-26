
#include "sp/ScannerTemp.cpp"
#include "sp/Scanner.cpp"
#include "sp/Parser.h"
#include "sp/TokenStrategy.cpp"
#include "sp/PrettyPrinter.h"
#include "sp/SourceProcessor.h"
#include "catch.hpp"
#include "qps/QPS.h"
#include "sp/SemanticAnalysisException.h"
#include "catch.hpp"

using namespace std;
void require(bool b) {
    REQUIRE(b);
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
    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = make_shared<PopulatePKB>(p);
    auto sp = SourceProcessor(pkb);
    auto tokens = sp.scan(codeSnippet);
    for (auto& token: *tokens) {
        std::cout << token->toString() << std::endl;
    }
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
    for (const auto& procedures : *program) {
        std::cout << procedures->toString() << std::endl;
    }

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

    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = make_shared<PopulatePKB>(p);
    auto sp = SourceProcessor(pkb);
    auto tokens = sp.scan(codeSnippet);
    const auto parser = new Parser(tokens);
    const auto program = parser->parse();
    for (const auto& procedures : *program) {
        std::cout << procedures->toString() << std::endl;
    }

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
    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = make_shared<PopulatePKB>(p);
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
    std::vector<std::vector<std::string>> expected = {
//            expected2,expected3,expected4,expected5,
            expected6};

    QueryPKB pkb1(p);
    QPS qps(std::make_shared<QueryPKB>(pkb1));

    for(int i=0;i<queries.size();i++){
        std::vector<std::string> ans = qps.evaluate(queries[i]);
        std::cout<< queries[i]<<endl;
        REQUIRE(ans==expected[i]);
    }
}

TEST_CASE("Test SIMPLE semantic analysis") {
    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = make_shared<PopulatePKB>(p);
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
    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = make_shared<PopulatePKB>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPKB pkb1(p);
    QPS qps(std::make_shared<QueryPKB>(pkb1));

    SECTION("Select Statement from Modifies(Statement, Variable)") {
        std::string query = "stmt s; variable v; Select s such that Modifies(s, v)";
        std::vector<std::string> expected  = {"2", "3", "5", "6", "7", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select Variable from Modifies(Statement, Variable)") {
        std::string query = "stmt s; variable v; Select v such that Modifies(s, v)";
        std::vector<std::string> expected  = {"f", "x", "y", "z"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select Assign from Modifies(Assign, Variable)") {
        std::string query = "assign s; variable v; Select s such that Modifies(s, v)";
        std::vector<std::string> expected  = {"3", "7", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select Variable from Modifies(Assign, Variable)") {
        std::string query = "assign s; variable v; Select v such that Modifies(s, v)";
        std::vector<std::string> expected  = {"x", "y", "z"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select While from Modifies(While, Variable)") {
        std::string query = "while s; variable v; Select s such that Modifies(s, v)";
        std::vector<std::string> expected  = {"6"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select Variable from Modifies(While, Variable)") {
        std::string query = "while s; variable v; Select v such that Modifies(s, v)";
        std::vector<std::string> expected  = {"x"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select If from Modifies(If, Variable)") {
        std::string query = "if s; variable v; Select s such that Modifies(s, v)";
        std::vector<std::string> expected  = {"2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select Variable from Modifies(If, Variable)") {
        std::string query = "if s; variable v; Select v such that Modifies(s, v)";
        std::vector<std::string> expected  = {"f", "x", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select Variable from Modifies(2, Variable)") {
        std::string query = "variable v; Select v such that Modifies(2, v)";
        std::vector<std::string> expected  = {"f", "x", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select s from Modifies(2, quoted(x))") {
        std::string query = "stmt s; Select s such that Modifies(s, \"x\")";
        std::vector<std::string> expected  = {"2", "6", "7", "9"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Select s from Modifies(2, _)") {
        std::string query = "stmt s; Select s such that Modifies(s, _)";
        std::vector<std::string> expected  = {"2", "3", "5", "6", "7", "9", "10", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
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
    std::shared_ptr<PKBStorage> p = std::make_shared<PKBStorage>();
    auto pkb = make_shared<PopulatePKB>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);
    QueryPKB pkb1(p);
    QPS qps(std::make_shared<QueryPKB>(pkb1));


    SECTION("Select Statement from Uses(Statement, Variable)") {
        std::string query = "stmt s; variable v; Select s such that Uses(s, v)";
        std::vector<std::string> expected = {"1", "2", "4", "6", "8","11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select Variable from Uses(Statement, Variable)") {
        std::string query = "stmt s; variable v; Select v such that Uses(s, v)";
        std::vector<std::string> expected = {"hello", "x", "t", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }


    SECTION("Select Assign from Uses(Assign, Variable)") {
        std::string query = "assign s; variable v; Select s such that Uses(s, v)";
        std::vector<std::string> expected = {"11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select Variable from Uses(Assign, Variable)") {
        std::string query = "assign s; variable v; Select v such that Uses(s, v)";
        std::vector<std::string> expected = {"x", "y"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select While from Uses(While, Variable)") {
        std::string query = "while s; variable v; Select s such that Uses(s, v)";
        std::vector<std::string> expected = {"6"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select Variable from Uses(While, Variable)") {
        std::string query = "while s; variable v; Select v such that Uses(s, v)";
        std::vector<std::string> expected = {"x"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select If from Uses(If, Variable)") {
        std::string query = "if s; variable v; Select s such that Uses(s, v)";
        std::vector<std::string> expected = {"2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select Variable from Uses(If, Variable)") {
        std::string query = "if s; variable v; Select v such that Uses(s, v)";
        std::vector<std::string> expected = {"hello", "t", "x"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select Variable from Uses(2, Variable)") {
        std::string query = "variable v; Select v such that Uses(2, v)";
        std::vector<std::string> expected = {"hello", "x", "t"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s from Uses(2, quoted(x))") {
        std::string query = "stmt s; Select s such that Uses(s, \"x\")";
        std::vector<std::string> expected = {"1", "2", "6", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }

    SECTION("Select s from Uses(2, _)") {
        std::string query = "stmt s; Select s such that Uses(s, _)";
        std::vector<std::string> expected = {"1", "2", "4", "6", "8", "11"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans == expected);
    }
}
