#include "catch.hpp"
#include "sp/PrettyPrinter.h"
#include "sp/SourceProcessor.h"
#include "qps/QPS.h"
#include "qps/parser/Demo.h"


using namespace std;
void require(bool b) {
    REQUIRE(b);
}

TEST_CASE("1st Test") {
    StrategyList strategies;
    TokenList tokens;

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
    auto scanner = new Scanner(codeSnippet, strategies, tokens);
    scanner->scanTokens();
    std::cout << tokens.toString() << std::endl;
    require(tokens.toString().find("UNKNOWN") == std::string::npos);

}

TEST_CASE("Parse sample program") {
    StrategyList strategies;
    TokenList tokens;

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

    const auto scanner = new Scanner(codeSnippet, strategies, tokens);
    scanner->scanTokens();
    const auto parser = new Parser(tokens);
    PrettyPrinter p;
    std::cout << p.print(parser->parse()) << std::endl;
    require(true);
}

TEST_CASE("Print with parent extractor") {
    std::string codeSnippet = R"(
    procedure main {
        flag = 0;
        call computeCentroid;
        call printResults;
    }
    procedure readPoint {
        read x;
        read y;
    }
    procedure printResults {
        print flag;
        print cenX;
        print cenY;
        print normSq;
    }
    procedure computeCentroid {
        count = 0;
        cenX = 0;
        cenY = 0;
        call readPoint;
        while ((x != 0) && (y != 0)) {
            count = count + 1;
            cenX = cenX + x;
            while (x == 1) {
                x = x+1;
                while (x == 2) {
                    x = x+ 3;
                }
            }
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
    procedure test {
        pass = 0;
        if (pass == 0) then {
            a = 0;
        } else {
            a = 1;
        }
    }
    )";
//    PopulatePKB stub;
//    SourceProcessor sp(stub);
//    sp.exec(codeSnippet);
//    require(true);
}

TEST_CASE("Print with parent extractoar") {
    std::string codeSnippet = R"(
    procedure main {
        flag = 0;
        call computeCentroid;
        call printResults;
    }
    procedure readPoint {
        read x;
        read y;
    }
    procedure printResults {
        print flag;
        print cenX;
        print cenY;
        print normSq;
    }
    procedure computeCentroid {
        count = 0;
        cenX = 0;
        cenY = 0;
        call readPoint;
        while ((x != 0) && (y != 0)) {
            count = count + 1;
            cenX = cenX + x;
            while (x == 1) {
                x = x+1;
                while (x == 2) {
                    x = x+ 3;
                }
            }
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
    procedure test {
        pass = 0;
        if (pass == 0) then {
            a = 0;
        } else {
            a = 1;
        }
    }
    )";

    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = PopulatePKB(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);

    std::string query = "stmt s;Select s such that Parent(s, 18)";

    QueryPKB pkb1(p);
    QPS qps(std::make_shared<QueryPKB>(pkb1));
    std::vector<std::string> ans = qps.evaluate(query);

    for (auto s:ans) {
        std::cout << s << std::endl;
    }





}