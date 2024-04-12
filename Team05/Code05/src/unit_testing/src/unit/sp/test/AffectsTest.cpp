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

TEST_CASE("Affects_TestWithControlFlow") {}

TEST_CASE("Affects_TestMultipleProcedures") {}