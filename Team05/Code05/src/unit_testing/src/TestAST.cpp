
#include "sp/ScannerTemp.cpp"
#include "sp/Scanner.cpp"
#include "sp/Parser.h"
#include "sp/TokenStrategy.cpp"
#include "sp/PrettyPrinter.h"
#include "sp/SourceProcessor.h"
#include "catch.hpp"
#include "qps/QPS.h"

using namespace std;
void require(bool b) {
    REQUIRE(b);
}

TEST_CASE("Tokenise sample program") {

    std::string codeSnippet = R"(
    procedure procedure {
        count = 1123*923/wq;
        cenX = 0;
        cenY = 0;
        call call;
        readx1;
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
    PopulatePKB pkb = PopulatePKB(p);;
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
    PopulatePKB pkb = PopulatePKB(p);;
    auto sp = SourceProcessor(pkb);
    auto tokens = sp.scan(codeSnippet);
    const auto parser = new Parser(tokens);
    PrettyPrinter pp;
    std::cout << pp.print(parser->parse()) << std::endl;
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

    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    auto pkb = PopulatePKB(p);
    auto sp = SourceProcessor(pkb);
    sp.exec(codeSnippet);

    std::string query = "stmt s;Select s such that Parent(s, 18)";

    QueryPKB pkb1(p);
    QPS qps(pkb1);
    std::vector<std::string> ans = qps.evaluate(query);

    for (auto s:ans) {
        std::cout << s << std::endl;
    }


}
