// include "sp/yourClass.h"
// include "sp/yourClass.cpp"

#include "catch.hpp"
#include "pkb/apis/PkbStorage.h"
#include "pkb/apis/PopulatePkb.h"
#include "pkb/apis/QueryPkb.h"
#include "sp/SourceProcessor.h"
#include "common/TableUtils.h"

using namespace std;

// Integration Tests Between SP and PKB
TEST_CASE("SP-PKB Integration Test - SIMPLE Program 1") {
    // Initialize Stub for PKB
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

    std::shared_ptr<PkbStorage> p = std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto pkb1 = QueryPkb(p);
    auto sp = SourceProcessor(pkb);
    const auto program = sp.parse(sp.scan(codeSnippet));
    sp.validate(program);
    sp.extract(program, std::make_shared<CFGCollection>(program));

    // Entity Tables

    SECTION("Check for Procedure Entries") {
        Table resultsVector = {
                {"program1"}, {"program2"}, {"program3"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getProcTable(), resultsVector));
    }

    SECTION("Check for Pattern Assign Entries") {
        Table resultsVector = {
                {"2", "x=(x+1)"}, {"3", "y=((y-1)+z)"},
                {"4", "z=2"}, {"7", "x=0"},
                {"8", "y=0"}, {"9", "z=0"},
                {"10", "x=1"}, {"11", "z=((x+y)+2)"},
                {"12", "x=(x+1)"}, {"13", "z=(y+x)"},
                {"25", "k=(((k*1)+(10*r))+h)"}, {"26", "k=(k+1)"},
                {"27", "z=(x-y)"}, {"28", "k=(((z+((y/k)*1))+(10*r))+h)"},
                {"30", "z=(x-y)"}, {"31", "k=(z+(((y*k)*r)/h))"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getPatternAsgnTable(), resultsVector));
    }

    SECTION("Check for Call Entries") {
        Table resultsVector = {
                {"6", "program2"},
                {"20", "program3"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getCallTable(), resultsVector));
    }

    SECTION("Check for Const Entries") {
        Table resultsVector = {
                {"2", "1"}, {"3", "1"}, {"4", "2"}, {"7", "0"}, {"8", "0"},
                {"9", "0"}, {"10", "1"}, {"11", "2"},
                {"5", "3"}, {"1", "4"}, {"12", "1"},
                {"25", "1"}, {"25", "10"}, {"26", "1"},
                {"24", "0"}, {"21", "2"}, {"28", "1"},
                {"28", "10"}, {"17", "4"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getConstTable(), resultsVector));
    }

    SECTION("Check for If Entries") {
        Table resultsVector = {
                {"5", "z"}, {"1", "x"},
                {"1", "y"}, {"1", "k"},
                {"1", "u"}, {"24", "k"},
                {"5", ""}, {"1", ""},
                {"1", ""}, {"1", ""},
                {"1", ""}, {"24", ""}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getPatternIfTable(), resultsVector));
    }

    SECTION("Check for Print Entries") {
        Table resultsVector = {
                {"15", "y"}, {"18", "x"},
                {"22", "z"}, {"23", "y"},
                {"29", "k"}, {"32", "t"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getPrintTable(), resultsVector));
    }

    SECTION("Check for Read Entries") {
        Table resultsVector = {
                {"14", "x"}, {"16", "z"}, {"19", "y"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getReadTable(), resultsVector));
    }

    SECTION("Check for Statement Entries") {
        Table resultsVector = {
                {"1"}, {"2"}, {"3"}, {"4"}, {"5"},
                {"6"}, {"7"}, {"8"}, {"9"}, {"10"},
                {"11"}, {"12"}, {"13"}, {"14"}, {"15"},
                {"16"}, {"17"}, {"18"}, {"19"}, {"20"},
                {"21"}, {"22"}, {"23"}, {"24"}, {"25"},
                {"26"}, {"27"}, {"28"}, {"29"}, {"30"},
                {"31"}, {"32"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getStmtTable(), resultsVector));
    }

    SECTION("Check for Variable Entries") {
        Table resultsVector = {
                {"2", "x"}, {"3", "y"}, {"3", "z"}, {"4", "z"},
                {"7", "x"}, {"8", "y"}, {"9", "z"}, {"10", "x"},
                {"11", "z"}, {"11", "x"}, {"11", "y"}, {"5", "z"},
                {"1", "x"}, {"1", "y"}, {"1", "k"}, {"1", "u"},
                {"12", "x"}, {"13", "z"}, {"13", "y"}, {"13", "x"},
                {"14", "x"}, {"15", "y"}, {"16", "z"}, {"18", "x"},
                {"19", "y"}, {"22", "z"}, {"23", "y"}, {"25", "k"},
                {"25", "r"}, {"25", "h"}, {"26", "k"}, {"24", "k"},
                {"21", "y"}, {"27", "z"}, {"27", "x"}, {"27", "y"},
                {"28", "z"}, {"28", "y"}, {"28", "k"}, {"28", "r"},
                {"28", "h"}, {"29", "k"},{"17", "x"}, {"17", "y"},
                {"17", "k"}, {"17", "u"}, {"30", "z"}, {"30", "x"},
                {"30", "y"}, {"31", "z"}, {"31", "y"}, {"31", "k"},
                {"31", "r"}, {"31", "h"}, {"32", "t"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getVarTable(), resultsVector));
    }

    SECTION("Check for While Entries") {
        Table resultsVector = {
                {"21", "y"}, {"17", "x"},
                {"17", "y"}, {"17", "k"},
                {"17", "u"},
                {"21", ""}, {"17", ""},
                {"17", ""}, {"17", ""},
                {"17", ""},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getPatternWhileTable(), resultsVector));
    }

    // Relations Table
    SECTION("Check for Calls Entries") {
        Table resultsVector = {
                {"program1", "program2"}, {"program2", "program3"},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getCallsTable(), resultsVector));
    }

    SECTION("Check for CallsT Entries") {
        Table resultsVector = {
                {"program1", "program2"}, {"program2", "program3"},
                {"program1", "program3"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getCallsTTable(), resultsVector));
    }

    SECTION("Check for Follows Entries") {
        Table resultsVector = {
                {"2", "3"}, {"3", "4"}, {"6", "7"},
                {"7", "8"}, {"8", "9"}, {"10", "11"},
                {"1", "12"}, {"12", "13"}, {"13", "14"},
                {"14", "15"}, {"15", "16"}, {"18", "19"},
                {"19", "20"}, {"20", "21"}, {"22", "23"},
                {"23", "24"}, {"21", "27"}, {"27", "28"},
                {"28", "29"}, {"30", "31"}, {"31", "32"}
        };
        REQUIRE(TableUtils::isPresent(pkb1.getFollowsTable(), resultsVector));
    }

    SECTION("Check for FollowsT Entries") {
        Table resultsVector = {
                {"2", "3"}, {"2", "4"}, {"3", "4"},
                {"6", "7"}, {"6", "8"}, {"7", "8"},
                {"6", "9"}, {"7", "9"}, {"8", "9"},
                {"10", "11"}, {"1", "12"}, {"1", "13"},
                {"12", "13"}, {"1", "14"}, {"12", "14"},
                {"13", "14"}, {"1", "15"}, {"12", "15"},
                {"13", "15"}, {"14", "15"}, {"1", "16"},
                {"12", "16"}, {"13", "16"}, {"14", "16"},
                {"15", "16"}, {"18", "19"}, {"18", "20"},
                {"19", "20"}, {"18", "21"}, {"19", "21"},
                {"20", "21"}, {"22", "23"}, {"22", "24"},
                {"23", "24"}, {"18", "27"}, {"19", "27"},
                {"20", "27"}, {"21", "27"}, {"18", "28"},
                {"19", "28"}, {"20", "28"}, {"21", "28"},
                {"27", "28"}, {"18", "29"}, {"19", "29"},
                {"20", "29"}, {"21", "29"}, {"27", "29"},
                {"28", "29"}, {"30", "31"}, {"30", "32"},
                {"31", "32"},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getFollowsTTable(), resultsVector));
    }

    SECTION("Check for ModifiesS Entries") {
        Table resultsVector = {
                {"2", "x"}, {"3", "y"}, {"4", "z"},
                {"6", "y"}, {"6", "z"}, {"1", "k"},
                {"5", "k"}, {"6", "k"}, {"7", "x"},
                {"1", "y"}, {"5", "y"}, {"8", "y"},
                {"9", "z"}, {"1", "x"}, {"5", "x"},
                {"10", "x"}, {"1", "z"}, {"5", "z"},
                {"11", "z"}, {"12", "x"}, {"13", "z"},
                {"14", "x"}, {"16", "z"}, {"17", "y"},
                {"19", "y"}, {"20", "z"}, {"20", "k"},
                {"25", "k"},{"21", "k"}, {"24", "k"},
                {"26", "k"}, {"17", "z"}, {"27", "z"},
                {"17", "k"}, {"28", "k"}, {"30", "z"},
                {"31", "k"},

        };
        REQUIRE(TableUtils::isPresent(pkb1.getModifiesSTable(), resultsVector));
    }

    SECTION("Check for ModifiesP Entries") {
        Table resultsVector = {
            {"program1", "k"}, {"program1", "y"},
            {"program1", "x"},{"program1", "z"},
            {"program2", "y"}, {"program2", "z"},
            {"program2", "k"}, {"program3", "z"},
            {"program3", "k"},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getModifiesPTable(), resultsVector));
    }

    SECTION("Check for Parent Entries") {
        Table resultsVector = {
                {"1", "2"}, {"1", "3"}, {"1", "4"},
                {"1", "5"}, {"5", "6"}, {"5", "7"},
                {"5", "8"}, {"5", "9"}, {"5", "10"},
                {"5", "11"}, {"17", "18"}, {"17", "19"},
                {"17", "20"}, {"17", "21"}, {"21", "22"},
                {"21", "23"}, {"21", "24"}, {"24", "25"},
                {"24", "26"}, {"17", "27"}, {"17", "28"},
                {"17", "29"},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getParentTable(), resultsVector));
    }

    SECTION("Check for ParentT Entries") {
        Table resultsVector = {
                {"1", "2"}, {"1", "3"}, {"1", "4"},
                {"1", "5"}, {"1", "6"}, {"5", "6"},
                {"1", "7"}, {"5", "7"}, {"1", "8"},
                {"5", "8"}, {"1", "9"}, {"5", "9"},
                {"1", "10"}, {"5", "10"}, {"1", "11"},
                {"5", "11"}, {"17", "18"}, {"17", "19"},
                {"17", "20"}, {"17", "21"}, {"17", "22"},
                {"21", "22"}, {"17", "23"}, {"21", "23"},
                {"17", "24"}, {"21", "24"}, {"17", "25"},
                {"21", "25"}, {"24", "25"}, {"17", "26"},
                {"21", "26"}, {"24", "26"}, {"17", "27"},
                {"17", "28"}, {"17", "29"},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getParentTTable(), resultsVector));
    }

    SECTION("Check for UsesS Entries") {
        Table resultsVector = {
                {"2", "x"}, {"3", "y"}, {"3", "z"},
                {"1", "u"}, {"5", "u"}, {"6", "u"},
                {"1", "t"}, {"5", "t"}, {"6", "t"},
                {"6", "x"}, {"1", "z"}, {"5", "z"},
                {"6", "z"}, {"6", "y"}, {"1", "r"},
                {"5", "r"}, {"6", "r"}, {"1", "h"},
                {"5", "h"}, {"6", "h"}, {"1", "k"},
                {"5", "k"}, {"6", "k"}, {"1", "x"},
                {"5", "x"}, {"11", "x"}, {"1", "y"},
                {"5", "y"}, {"11", "y"}, {"12", "x"},
                {"13", "y"}, {"13", "x"}, {"15", "y"},
                {"17", "u"}, {"18", "x"}, {"20", "x"},
                {"20", "z"}, {"20", "y"}, {"20", "k"},
                {"20", "r"}, {"20", "h"}, {"17", "t"},
                {"20", "t"}, {"21", "z"}, {"22", "z"},
                {"21", "y"}, {"23", "y"}, {"25", "k"},
                {"21", "r"}, {"24", "r"}, {"25", "r"},
                {"21", "h"}, {"24", "h"}, {"25", "h"},
                {"21", "k"}, {"24", "k"}, {"26", "k"},
                {"17", "x"}, {"27", "x"}, {"27", "y"},
                {"17", "z"}, {"28", "z"}, {"17", "y"},
                {"28", "y"}, {"28", "k"}, {"17", "r"},
                {"28", "r"}, {"17", "h"}, {"28", "h"},
                {"17", "k"}, {"29", "k"}, {"30", "x"},
                {"30", "y"}, {"31", "z"}, {"31", "y"},
                {"31", "k"}, {"31", "r"}, {"31", "h"},
                {"32", "t"},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getUsesSTable(), resultsVector));
    }

    SECTION("Check for UsesP Entries") {
        Table resultsVector = {
                {"program1", "u"}, {"program1", "t"},
                {"program1", "z"}, {"program1", "r"},
                {"program1", "h"}, {"program1", "k"},
                {"program1", "x"}, {"program1", "y"},
                {"program2", "u"}, {"program2", "t"},
                {"program2", "x"}, {"program2", "z"},
                {"program2", "y"}, {"program2", "r"},
                {"program2", "h"}, {"program2", "k"},
                {"program3", "x"}, {"program3", "z"},
                {"program3", "y"}, {"program3", "k"},
                {"program3", "r"}, {"program3", "h"},
                {"program3", "t"},
        };
        REQUIRE(TableUtils::isPresent(pkb1.getUsesPTable(), resultsVector));
    }
}
