
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
        read x1;
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
        count = uer;
        cenX = 0;
        cenY = 0;
        call readPoint;
        while ((p != t) && (q != w)) {
            count = count + 1;
            cenX = cenX + x;
            while (t == 1) {
                x = y+1;
                while (k == 2) {
                    x = j+ 3;
                    print sk;
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
            if (meow >= 2) then {
              ad = sa;
              print usgdal;
            } else {
              sn = 2;
            }
            print hello;
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
