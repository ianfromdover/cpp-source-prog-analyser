
#include "TNode.h"
#include "sp/ScannerTemp.cpp"
#include "sp/Scanner.cpp"
#include "sp/TokenList.h"
#include "sp/StrategyList.h"
#include "sp/Token.cpp"
#include "sp/TokenType.cpp"
#include "catch.hpp"

using namespace std;
void require(bool b) {
    REQUIRE(b);
}

TEST_CASE("1st Test") {
    auto strategies = new StrategyList();
    auto tokens = new TokenList();

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

    auto scanner = new Scanner(codeSnippet, *strategies, *tokens);

    scanner->scanTokens();

    require(true);

}


