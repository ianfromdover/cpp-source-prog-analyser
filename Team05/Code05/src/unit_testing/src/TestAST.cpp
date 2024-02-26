
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
    /**
    std::string codeSnippet = R"(
    procedure main {
        1 flag = 0;
        2 call computeCentroid;
        3 call printResults;
    }
    procedure readPoint {
        4 read x;
        5 read y;
    }
    procedure printResults {
        6 print flag;
        7 print cenX;
        8 print cenY;
        9 print normSq;
    }
    procedure computeCentroid {
        10 count = uer;
        11 cenX = 0;
        12 cenY = 0;
        13 call readPoint;
        Uses(14, x)
        Uses(14, y)
        Uses(14, t)
        Uses(14, w)
        14 while ((p != t) && (q != w)) {
            15 count = count + 1;
            16 cenX = cenX + x;
            17 while (t == 1) {
                18 x = y+1;
                19 while (k == 2) {
                    20 x = j+ 3;
                    21 print sk;
                }
            }
            22 cenY = cenY + y;
            23 call readPoint;
        }
        24 if (count == 0) then {
            25 flag = 1;
        } else {
            26 cenX = cenX / count;
            27 cenY = cenY / count;
        }
        28 normSq = cenX * cenX + cenY * cenY;
    }
    procedure test {
        29 pass = 0;
        30 if (pass == 0) then {
            31 a = 0;
        } else {
            32 if (meow >= 2) then {
              33 ad = sa;
              34 print usgdal;
            } else {
               35 sn = 2;
            }
            36 print hello;
        }
    }
    )";
**/
    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        x=0;
        y=1;
        z=x+y;
    }
    )";
    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = make_shared<PopulatePKB>(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);

    std::string query = "assign a;variable v;Select v pattern a(v, _\"x\"_)";

    QueryPKB pkb1(p);
    QPS qps(std::make_shared<QueryPKB>(pkb1));
    std::vector<std::string> ans = qps.evaluate(query);

    for (auto s:ans) {
        std::cout << s << std::endl;
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