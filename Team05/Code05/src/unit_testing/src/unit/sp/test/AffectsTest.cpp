//
// Created by Chua Bing Quan on 13/4/24.
//

#include "catch.hpp"
#include "pkb/apis/PopulatePkb.h"
#include "pkb/apis/QueryPkb.h"
#include "sp/SourceProcessor.h"

using Test = std::pair<std::pair<StmtNo, StmtNo>, bool>;

static void testAffects(const std::string& source, const std::vector<Test>& tests) {
    const auto& pkb = std::make_shared<PkbStorage>();
    auto populatePkb = std::make_shared<PopulatePkb>(pkb);
    auto queryPkb = std::make_shared<QueryPkb>(pkb);

    auto sp = SourceProcessor(populatePkb);
    const auto program = sp.parse(sp.scan(source));
    sp.validate(program);
    sp.extract(program);

    auto affects = Affects(std::make_shared<CFGCollection>(program), queryPkb);

    for (const auto& [input, expected] : tests) {
        REQUIRE(affects.get(input.first, input.second) == expected);
    }
}

TEST_CASE("Affects_TestWithoutControlFlow") {
    SECTION("Definition Match Statement With Single Use") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 2 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Definition Match Statement With Multiple Use") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                z = x + y;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 2, 3 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Re-Definition By Read") {
        const std::string source = R"(
            procedure main {
                x = 0;
                x = x + 1;
                read x;
                x = x + 2;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 2 }, true),
            Test({ 1, 4 }, false),
            Test({ 2, 4 }, false),
        };

        testAffects(source, tests);
    }

    SECTION("Variable Shadowing") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                x = x + 1;
                z = x + y;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 1, 4 }, false),
            Test({ 3, 4 }, true),
            Test({ 2, 4 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Self Doesn't Affect Self") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 1 }, false),
            Test({ 2, 2 }, false),
        };

        testAffects(source, tests);
    }

    SECTION("Undefined Use Doesn't Affect Anything") {
        const std::string source = R"(
            procedure main {
                y = 1;
                z = x + y + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 2 }, true),
        };

        testAffects(source, tests);
    }
}

TEST_CASE("Affects_TestBadArguments") {
    SECTION("Definition Without Matching Use") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                z = y + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 2 }, false),
            Test({ 1, 3 }, false),
        };

        testAffects(source, tests);
    }

    SECTION("Not Assignment Statement(s)") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                read z;
                print y;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
            Test({ 1, 4 }, false),
            Test({ 2, 3 }, false),
            Test({ 2, 4 }, false),
            Test({ 3, 4 }, false),
        };

        testAffects(source, tests);
    }

    SECTION("Not Within Same Procedure") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                z = y + 1;
            }

            procedure other {
                w = 1;
                print w;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, false),
            Test({ 1, 5 }, false),
            Test({ 2, 4 }, false),
            Test({ 2, 5 }, false),
            Test({ 3, 4 }, false),
            Test({ 3, 5 }, false),
            Test({ 4, 1 }, false),
            Test({ 4, 2 }, false),
            Test({ 4, 3 }, false),
            Test({ 5, 1 }, false),
            Test({ 5, 2 }, false),
            Test({ 5, 3 }, false),
        };

        testAffects(source, tests);
    }

    SECTION("Statement(s) Doesn't Exist") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                z = y + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, false),
            Test({ 2, 4 }, false),
            Test({ 3, 4 }, false),
            Test({ 4, 5 }, false),
        };

        testAffects(source, tests);
    }
}

TEST_CASE("Affects_TestWithControlFlow") {
    SECTION("No Re-Definitions In If Statement") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    print x;
                } else {
                    y = 1;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 5 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Re-Definition In Then-Branch") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = 1;
                } else {
                    y = 1;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 5 }, true),
            Test({ 3, 5 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Re-Definition In Else-Branch") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    y = 1;
                } else {
                    x = 1;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 5 }, true),
            Test({ 4, 5 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Re-Definition In Both Branches") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = 1;
                } else {
                    x = 2;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 5 }, false),
            Test({ 3, 5 }, true),
            Test({ 4, 5 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Independence Of Branches") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = x + 1;
                } else {
                    x = x + 2;
                }
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 1, 4 }, true),
            Test({ 3, 4 }, false),
        };

        testAffects(source, tests);
    }

    SECTION("Shadowing In Branch") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = 1;
                    x = 2;
                } else {
                    x = 2;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 6 }, false),
            Test({ 3, 6 }, false),
            Test({ 4, 6 }, true),
            Test({ 5, 6 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Read In Then-Branch") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    read x;
                    x = x + 1;
                } else {
                    x = x + 2;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, false),
            Test({ 1, 5 }, true),
            Test({ 1, 6 }, false),
            Test({ 4, 6 }, true),
            Test({ 5, 6 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Read In Else-Branch") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = x + 1;
                } else {
                    read x;
                    x = x + 2;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 1, 5 }, false),
            Test({ 1, 6 }, false),
            Test({ 3, 6 }, true),
            Test({ 5, 6 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Read In Both Branches") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    read x;
                    x = x + 1;
                } else {
                    read x;
                    x = x + 2;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, false),
            Test({ 1, 6 }, false),
            Test({ 1, 7 }, false),
            Test({ 4, 7 }, true),
            Test({ 6, 7 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Definition Matches Use In Then-Branch") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = x + 1;
                } else {
                    y = 1;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 1, 5 }, true),
            Test({ 3, 5 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Definition Matches Use In Else-Branch") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    y = 1;
                } else {
                    x = x + 1;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, true),
            Test({ 1, 5 }, true),
            Test({ 4, 5 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Definition Matches Use In Both Branches") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = x + 1;
                } else {
                    x = x + 2;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 1, 4 }, true),
            Test({ 1, 5 }, false),
            Test({ 3, 5 }, true),
            Test({ 4, 5 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Definition Matches Use In Branch With Shadowing") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = x + 1;
                    x = x + 2;
                } else {
                    x = x + 3;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 1, 4 }, false),
            Test({ 1, 5 }, true),
            Test({ 1, 6 }, false),
            Test({ 3, 4 }, true),
            Test({ 3, 6 }, false),
            Test({ 4, 6 }, true),
            Test({ 5, 6 }, true),
        };

        testAffects(source, tests);
    }

    SECTION("Definition Doesn't Match Use In Branch With Shadowing") {
        const std::string source = R"(
            procedure main {
                x = 0;
                if (x == 0) then {
                    x = 1;
                    x = x + 2;
                } else {
                    x = x + 3;
                }
                x = x + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
            Test({ 1, 4 }, false),
            Test({ 1, 5 }, true),
            Test({ 1, 6 }, false),
            Test({ 3, 4 }, true),
            Test({ 3, 6 }, false),
            Test({ 4, 6 }, true),
            Test({ 5, 6 }, true),
        };

        testAffects(source, tests);
    }
}

TEST_CASE("Affects_TestMultipleProcedures") {}