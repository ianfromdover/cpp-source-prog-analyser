//
// Created by Chua Bing Quan on 13/4/24.
//

#include "catch.hpp"
#include "pkb/apis/PopulatePkb.h"
#include "pkb/apis/QueryPkb.h"
#include "sp/SourceProcessor.h"

using Test = std::pair<std::pair<StmtNo, StmtNo>, bool>;

static std::shared_ptr<Affects> setupAffects(const std::string& source) {
    const auto& pkb = std::make_shared<PkbStorage>();
    auto populatePkb = std::make_shared<PopulatePkb>(pkb);
    auto queryPkb = std::make_shared<QueryPkb>(pkb);

    auto sp = SourceProcessor(populatePkb);
    const auto program = sp.parse(sp.scan(source));
    sp.validate(program);
    sp.extract(program);

    return std::make_shared<Affects>(std::make_shared<CFGCollection>(program), queryPkb);
}

static void testAffects(const std::shared_ptr<Affects>& affects, const std::vector<Test>& tests) {
    for (const auto& [input, expected] : tests) {
        REQUIRE(affects->get(input.first, input.second) == expected);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
    }

    SECTION("Later Definition Doesn't Affect Previous Use") {
        const std::string source = R"(
            procedure main {
                read x;
                y = x + 1;
                x = 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 3, 2 }, false),
        };

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
    }

    SECTION("Not Assignment Statement(s)") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                read z;
                print y;
                call other;
            }

            procedure other {
                print x;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
            Test({ 1, 4 }, false),
            Test({ 1, 5 }, false),
            Test({ 2, 3 }, false),
            Test({ 2, 4 }, false),
            Test({ 2, 5 }, false),
            Test({ 3, 4 }, false),
            Test({ 3, 5 }, false),
            Test({ 4, 5 }, false),
        };

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
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

        testAffects(setupAffects(source), tests);
    }

    SECTION("Definition Matches Use In While") {
        const std::string source = R"(
            procedure main {
                x = 10;
                while (x > 0) {
                    y = x + 1;
                }
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 3, 3 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Assignment In While Affects Itself") {
        const std::string source = R"(
            procedure main {
                x = 10;
                while (x > 0) {
                    print x;
                    x = x - 1;
                }
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, true),
            Test({ 4, 4 }, true),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Definition And Use Matches In While") {
        const std::string source = R"(
            procedure main {
                x = 10;
                while (x > 0) {
                    x = 1;
                    x = x + 1;
                    y = x;
                }
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, false),
            Test({ 1, 5 }, false),
            Test({ 3, 4 }, true),
            Test({ 3, 5 }, false),
            Test({ 4, 5 }, true),
            Test({ 4, 3 }, false),
            Test({ 4, 4 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Later Definition Affects Earlier Use In While") {
        const std::string source = R"(
            procedure main {
                x = 10;
                while (x > 0) {
                    x = x + 1;
                    print x;
                    x = x + 2;
                    print x;
                }
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
            Test({ 1, 5 }, false),
            Test({ 3, 5 }, true),
            Test({ 3, 3 }, false),
            Test({ 5, 3 }, true),
            Test({ 5, 5 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Read In While") {
        const std::string source = R"(
            procedure main {
                x = 0;
                while (x > 0) {
                    read x;
                    x = x + 1;
                }
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 4 }, false),
            Test({ 4, 4 }, false),
        };

        testAffects(setupAffects(source), tests);
    }
}

TEST_CASE("Affects_TestMultipleProcedures") {
    SECTION("Modified By Called Procedure") {
        const std::string source = R"(
            procedure main {
                x = 0;
                call other;
                y = x + 1;
            }

            procedure other {
                x = 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Not Modified By Called Procedure") {
        const std::string source = R"(
            procedure main {
                x = 0;
                call other;
                y = x + 1;
            }

            procedure other {
                z = 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Modified By Transitive Procedure Call") {
        const std::string source = R"(
            procedure main {
                x = 0;
                call other;
                y = x + 1;
            }

            procedure other {
                z = 1;
                call another;
            }

            procedure another {
                x = 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Not Modified By Transitive Procedure Call") {
        const std::string source = R"(
            procedure main {
                x = 0;
                call other;
                y = x + 1;
            }

            procedure other {
                z = 1;
                call another;
            }

            procedure another {
                z = 2;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Query Multiple Procedures") {
        const std::string source = R"(
            procedure main {
                x = 0;
                y = 1;
                if (x == 0) then {
                    call other;
                    x = x + 1;
                } else {
                    call another;
                    y = y + 1;
                }
                z = x + y;
            }

            procedure other {
                read z;
                while (x == 0) {
                    z = z * 2;
                    x = x + 1;
                    print z;
                }
            }

            procedure another {
                z = 0;
                if (y == 1) then {
                    z = z + 1;
                } else {
                    print y;
                }
                print z;
            }
        )";

        std::vector<Test> tests = {
            // Points of interest in "main".
            Test({ 1, 5 }, false),
            Test({ 1, 8 }, true),
            Test({ 2, 7 }, true),
            Test({ 2, 8 }, true),
            Test({ 5, 8 }, true),
            Test({ 7, 8 }, true),

            // Points of interest in "other".
            Test({ 11, 11 }, true),
            Test({ 12, 12 }, true),

            // Points of interest in "another".
            Test({ 14, 16 }, true),

            // Everything else in "main".
            Test({ 1, 1 }, false),
            Test({ 1, 2 }, false),
            Test({ 1, 3 }, false),
            Test({ 1, 4 }, false),
            Test({ 1, 6 }, false),
            Test({ 1, 7 }, false),
            Test({ 2, 1 }, false),
            Test({ 2, 2 }, false),
            Test({ 2, 3 }, false),
            Test({ 2, 4 }, false),
            Test({ 2, 5 }, false),
            Test({ 2, 6 }, false),
            Test({ 3, 1 }, false),
            Test({ 3, 2 }, false),
            Test({ 3, 3 }, false),
            Test({ 3, 4 }, false),
            Test({ 3, 5 }, false),
            Test({ 3, 6 }, false),
            Test({ 3, 7 }, false),
            Test({ 3, 8 }, false),
            Test({ 4, 1 }, false),
            Test({ 4, 2 }, false),
            Test({ 4, 3 }, false),
            Test({ 4, 4 }, false),
            Test({ 4, 5 }, false),
            Test({ 4, 6 }, false),
            Test({ 4, 7 }, false),
            Test({ 4, 8 }, false),
            Test({ 5, 1 }, false),
            Test({ 5, 2 }, false),
            Test({ 5, 3 }, false),
            Test({ 5, 4 }, false),
            Test({ 5, 5 }, false),
            Test({ 5, 6 }, false),
            Test({ 5, 7 }, false),
            Test({ 6, 1 }, false),
            Test({ 6, 2 }, false),
            Test({ 6, 3 }, false),
            Test({ 6, 4 }, false),
            Test({ 6, 5 }, false),
            Test({ 6, 6 }, false),
            Test({ 6, 7 }, false),
            Test({ 6, 8 }, false),
            Test({ 7, 1 }, false),
            Test({ 7, 2 }, false),
            Test({ 7, 3 }, false),
            Test({ 7, 4 }, false),
            Test({ 7, 5 }, false),
            Test({ 7, 6 }, false),
            Test({ 7, 7 }, false),
            Test({ 8, 1 }, false),
            Test({ 8, 2 }, false),
            Test({ 8, 3 }, false),
            Test({ 8, 4 }, false),
            Test({ 8, 5 }, false),
            Test({ 8, 6 }, false),
            Test({ 8, 7 }, false),
            Test({ 8, 8 }, false),

            // Everything else in "other".
            Test({ 9, 9 }, false),
            Test({ 9, 10 }, false),
            Test({ 9, 11 }, false),
            Test({ 9, 12 }, false),
            Test({ 9, 13 }, false),
            Test({ 10, 9 }, false),
            Test({ 10, 10 }, false),
            Test({ 10, 11 }, false),
            Test({ 10, 12 }, false),
            Test({ 10, 13 }, false),
            Test({ 11, 9 }, false),
            Test({ 11, 10 }, false),
            Test({ 11, 12 }, false),
            Test({ 11, 13 }, false),
            Test({ 12, 9 }, false),
            Test({ 12, 10 }, false),
            Test({ 12, 11 }, false),
            Test({ 12, 13 }, false),
            Test({ 13, 9 }, false),
            Test({ 13, 10 }, false),
            Test({ 13, 11 }, false),
            Test({ 13, 12 }, false),
            Test({ 13, 13 }, false),

            // Everything else in "another".
            Test({ 14, 14 }, false),
            Test({ 14, 15 }, false),
            Test({ 14, 17 }, false),
            Test({ 14, 18 }, false),
            Test({ 15, 14 }, false),
            Test({ 15, 15 }, false),
            Test({ 15, 16 }, false),
            Test({ 15, 17 }, false),
            Test({ 15, 18 }, false),
            Test({ 16, 14 }, false),
            Test({ 16, 15 }, false),
            Test({ 16, 16 }, false),
            Test({ 16, 17 }, false),
            Test({ 16, 18 }, false),
            Test({ 17, 14 }, false),
            Test({ 17, 15 }, false),
            Test({ 17, 16 }, false),
            Test({ 17, 17 }, false),
            Test({ 17, 18 }, false),
            Test({ 18, 14 }, false),
            Test({ 18, 15 }, false),
            Test({ 18, 16 }, false),
            Test({ 18, 17 }, false),
            Test({ 18, 18 }, false),

            // Invalid cross-procedure arguments.
            Test({ 1, 9 }, false),
            Test({ 1, 10 }, false),
            Test({ 1, 11 }, false),
            Test({ 1, 12 }, false),
            Test({ 1, 13 }, false),
            Test({ 2, 9 }, false),
            Test({ 2, 10 }, false),
            Test({ 2, 11 }, false),
            Test({ 2, 12 }, false),
            Test({ 2, 13 }, false),
            Test({ 3, 9 }, false),
            Test({ 3, 10 }, false),
            Test({ 3, 11 }, false),
            Test({ 3, 12 }, false),
            Test({ 3, 13 }, false),
            Test({ 4, 9 }, false),
            Test({ 4, 10 }, false),
            Test({ 4, 11 }, false),
            Test({ 4, 12 }, false),
            Test({ 4, 13 }, false),
            Test({ 5, 9 }, false),
            Test({ 5, 10 }, false),
            Test({ 5, 11 }, false),
            Test({ 5, 12 }, false),
            Test({ 5, 13 }, false),
            Test({ 6, 9 }, false),
            Test({ 6, 10 }, false),
            Test({ 6, 11 }, false),
            Test({ 6, 12 }, false),
            Test({ 6, 13 }, false),
            Test({ 7, 9 }, false),
            Test({ 7, 10 }, false),
            Test({ 7, 11 }, false),
            Test({ 7, 12 }, false),
            Test({ 7, 13 }, false),
            Test({ 8, 9 }, false),
            Test({ 8, 10 }, false),
            Test({ 8, 11 }, false),
            Test({ 8, 12 }, false),
            Test({ 8, 13 }, false),
            Test({ 1, 14 }, false),
            Test({ 1, 15 }, false),
            Test({ 1, 16 }, false),
            Test({ 1, 17 }, false),
            Test({ 1, 18 }, false),
            Test({ 2, 14 }, false),
            Test({ 2, 15 }, false),
            Test({ 2, 16 }, false),
            Test({ 2, 17 }, false),
            Test({ 2, 18 }, false),
            Test({ 3, 14 }, false),
            Test({ 3, 15 }, false),
            Test({ 3, 16 }, false),
            Test({ 3, 17 }, false),
            Test({ 3, 18 }, false),
            Test({ 4, 14 }, false),
            Test({ 4, 15 }, false),
            Test({ 4, 16 }, false),
            Test({ 4, 17 }, false),
            Test({ 4, 18 }, false),
            Test({ 5, 14 }, false),
            Test({ 5, 15 }, false),
            Test({ 5, 16 }, false),
            Test({ 5, 17 }, false),
            Test({ 5, 18 }, false),
            Test({ 6, 14 }, false),
            Test({ 6, 15 }, false),
            Test({ 6, 16 }, false),
            Test({ 6, 17 }, false),
            Test({ 6, 18 }, false),
            Test({ 7, 14 }, false),
            Test({ 7, 15 }, false),
            Test({ 7, 16 }, false),
            Test({ 7, 17 }, false),
            Test({ 7, 18 }, false),
            Test({ 8, 14 }, false),
            Test({ 8, 15 }, false),
            Test({ 8, 16 }, false),
            Test({ 8, 17 }, false),
            Test({ 8, 18 }, false),
            Test({ 9, 1 }, false),
            Test({ 9, 2 }, false),
            Test({ 9, 3 }, false),
            Test({ 9, 4 }, false),
            Test({ 9, 5 }, false),
            Test({ 9, 6 }, false),
            Test({ 9, 7 }, false),
            Test({ 9, 8 }, false),
            Test({ 10, 1 }, false),
            Test({ 10, 2 }, false),
            Test({ 10, 3 }, false),
            Test({ 10, 4 }, false),
            Test({ 10, 5 }, false),
            Test({ 10, 6 }, false),
            Test({ 10, 7 }, false),
            Test({ 10, 8 }, false),
            Test({ 11, 1 }, false),
            Test({ 11, 2 }, false),
            Test({ 11, 3 }, false),
            Test({ 11, 4 }, false),
            Test({ 11, 5 }, false),
            Test({ 11, 6 }, false),
            Test({ 11, 7 }, false),
            Test({ 11, 8 }, false),
            Test({ 12, 1 }, false),
            Test({ 12, 2 }, false),
            Test({ 12, 3 }, false),
            Test({ 12, 4 }, false),
            Test({ 12, 5 }, false),
            Test({ 12, 6 }, false),
            Test({ 12, 7 }, false),
            Test({ 12, 8 }, false),
            Test({ 13, 1 }, false),
            Test({ 13, 2 }, false),
            Test({ 13, 3 }, false),
            Test({ 13, 4 }, false),
            Test({ 13, 5 }, false),
            Test({ 13, 6 }, false),
            Test({ 13, 7 }, false),
            Test({ 13, 8 }, false),
            Test({ 9, 14 }, false),
            Test({ 9, 15 }, false),
            Test({ 9, 16 }, false),
            Test({ 9, 17 }, false),
            Test({ 9, 18 }, false),
            Test({ 10, 14 }, false),
            Test({ 10, 15 }, false),
            Test({ 10, 16 }, false),
            Test({ 10, 17 }, false),
            Test({ 10, 18 }, false),
            Test({ 11, 14 }, false),
            Test({ 11, 15 }, false),
            Test({ 11, 16 }, false),
            Test({ 11, 17 }, false),
            Test({ 11, 18 }, false),
            Test({ 12, 14 }, false),
            Test({ 12, 15 }, false),
            Test({ 12, 16 }, false),
            Test({ 12, 17 }, false),
            Test({ 12, 18 }, false),
            Test({ 13, 14 }, false),
            Test({ 13, 15 }, false),
            Test({ 13, 16 }, false),
            Test({ 13, 17 }, false),
            Test({ 13, 18 }, false),
            Test({ 14, 1 }, false),
            Test({ 14, 2 }, false),
            Test({ 14, 3 }, false),
            Test({ 14, 4 }, false),
            Test({ 14, 5 }, false),
            Test({ 14, 6 }, false),
            Test({ 14, 7 }, false),
            Test({ 14, 8 }, false),
            Test({ 15, 1 }, false),
            Test({ 15, 2 }, false),
            Test({ 15, 3 }, false),
            Test({ 15, 4 }, false),
            Test({ 15, 5 }, false),
            Test({ 15, 6 }, false),
            Test({ 15, 7 }, false),
            Test({ 15, 8 }, false),
            Test({ 16, 1 }, false),
            Test({ 16, 2 }, false),
            Test({ 16, 3 }, false),
            Test({ 16, 4 }, false),
            Test({ 16, 5 }, false),
            Test({ 16, 6 }, false),
            Test({ 16, 7 }, false),
            Test({ 16, 8 }, false),
            Test({ 17, 1 }, false),
            Test({ 17, 2 }, false),
            Test({ 17, 3 }, false),
            Test({ 17, 4 }, false),
            Test({ 17, 5 }, false),
            Test({ 17, 6 }, false),
            Test({ 17, 7 }, false),
            Test({ 17, 8 }, false),
            Test({ 18, 1 }, false),
            Test({ 18, 2 }, false),
            Test({ 18, 3 }, false),
            Test({ 18, 4 }, false),
            Test({ 18, 5 }, false),
            Test({ 18, 6 }, false),
            Test({ 18, 7 }, false),
            Test({ 18, 8 }, false),
            Test({ 14, 9 }, false),
            Test({ 14, 10 }, false),
            Test({ 14, 11 }, false),
            Test({ 14, 12 }, false),
            Test({ 14, 13 }, false),
            Test({ 15, 9 }, false),
            Test({ 15, 10 }, false),
            Test({ 15, 11 }, false),
            Test({ 15, 12 }, false),
            Test({ 15, 13 }, false),
            Test({ 16, 9 }, false),
            Test({ 16, 10 }, false),
            Test({ 16, 11 }, false),
            Test({ 16, 12 }, false),
            Test({ 16, 13 }, false),
            Test({ 17, 9 }, false),
            Test({ 17, 10 }, false),
            Test({ 17, 11 }, false),
            Test({ 17, 12 }, false),
            Test({ 17, 13 }, false),
            Test({ 18, 9 }, false),
            Test({ 18, 10 }, false),
            Test({ 18, 11 }, false),
            Test({ 18, 12 }, false),
            Test({ 18, 13 }, false),
        };

        SECTION("Without Flush") {
            const auto& affects = setupAffects(source);
            testAffects(affects, tests);
            testAffects(affects, tests);
        }

        SECTION("With Flush") {
            const auto& affects = setupAffects(source);
            testAffects(affects, tests);
            affects->flush();
            testAffects(affects, tests);
        }
    }
}

TEST_CASE("Affects_TestGivenExamples") {
    // Examples from https://nus-cs3203.github.io/course-website/contents/advanced-spa-requirements/design-abstractions.html#affects.
    SECTION("Code 6 Example") {
        const auto source = R"(
            procedure Second {
                x = 0;
                i = 5;
                while (i!=0) {
                    x = x + 2*y;
                    call Third;
                    i = i - 1;
                }
                if (x==1) then {
                    x = x+1;
                }
                else {
                    z = 1;
                }
                z = z + x + i;
                y = z + 2;
                x = x * y + z;
            }

            procedure Third {
                z = 5;
                v = z;
                print v;
            }
        )";

        std::vector<Test> tests = {
            Test({ 2, 6 }, true),
            Test({ 4, 8 }, true),
            Test({ 4, 10 }, true),
            Test({ 6, 6 }, true),
            Test({ 1, 4 }, true),
            Test({ 1, 8 }, true),
            Test({ 1, 10 }, true),
            Test({ 1, 12 }, true),
            Test({ 2, 10 }, true),
            Test({ 9, 10 }, true),
            Test({ 9, 11 }, false),
            Test({ 9, 12 }, false),
            Test({ 2, 3 }, false),
            Test({ 9, 6 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Code 7 Example") {
        const auto source = R"(
            procedure alpha {
                x = 1;
                if ( i != 2 ) then {
                    x = a + 1;
                }
                else {
                    a = b;
                }
                a = x;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 5 }, true),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Code 8 Example where Modifies('q', 'x') holds") {
        const auto source = R"(
            procedure p {
                x = a;
                call q;
                v = x;
            }

            procedure q {
                x = 5;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Code 8 Example where Modifies('q', 'x') does not hold") {
        const auto source = R"(
            procedure p {
                x = a;
                call q;
                v = x;
            }

            procedure q {
                print x;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, true),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Code 9 Example") {
        const auto source = R"(
            procedure p {
                x = 1;
                y = 2;
                z = y;
                call q;
                z = x + y + z;
            }

            procedure q {
                x = 5;
                t = 4;
                if ( z > 0 ) then {
                    t = x + 1;
                }
                else {
                    y = z + x;
                }
                x = t + 1;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 5 }, false),
            Test({ 2, 5 }, false),
            Test({ 3, 10 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Code 10 Example") {
        const auto source = R"(
            procedure alpha {
                x = 1;
                call beta;
                a = x;
            }

            procedure beta {
                if ( i != 2 ) then {
                    x = a + 1;
                }
                else {
                    a = b;
                }
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
        };

        testAffects(setupAffects(source), tests);
    }

    SECTION("Code 11 Example") {
        const auto source = R"(
            procedure p {
                x = a;
                read x;
                v = x;
            }
        )";

        std::vector<Test> tests = {
            Test({ 1, 3 }, false),
        };

        testAffects(setupAffects(source), tests);
    }
}