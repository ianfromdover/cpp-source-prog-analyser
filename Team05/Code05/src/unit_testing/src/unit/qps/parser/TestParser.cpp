//
// Created by Alex on 16/2/2024.
//

#include <iostream>
#include "catch.hpp"
#include "qps/parser/QPSParser.h"
#include "TokenListBuilder.h"
#include "IntermediateBuilder.h"


typedef QPSTokenType::QPSTypeInfo type;

static QPSTokenList
generateTokenList(std::initializer_list<std::pair<QPSTokenType::QPSTypeInfo, std::string>> tokenStream);


TEST_CASE("scratch pad parser") {
    SECTION("pattern_modifies"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleIfDeclaration().select().identifier().validIfPattern().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
}

// Unit Tests for QPS

TEST_CASE("singleDeclaration_singleSelect") {
    QPSTokenList tokens;
    tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().get();

    QPSParser parser(tokens);
    IntermediateQuery query;
    REQUIRE_NOTHROW(query = *parser.parse());
}

TEST_CASE("multipleDeclaration_singleSelect") {
    QPSTokenList tokens;
    tokens = TokenListBuilder().multiStmtDeclaration().select().identifier().get();

    QPSParser parser(tokens);
    REQUIRE_NOTHROW(parser.parse());
}

TEST_CASE("singleDeclaration_singleSelect_singleRelationship1") {

    SECTION("follows") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().identifier().comma().identifier().rightParen().get();


        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_synonym_wildcard") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().identifier().comma().wildcard().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
}

TEST_CASE("boolean_select"){
  SECTION("simple boolean select") {
    QPSTokenList tokens;
    tokens = TokenListBuilder().validBooleanSelect().get();

    QPSParser parser(tokens);
    REQUIRE_NOTHROW(parser.parse());
  }
  SECTION("single declaration and single boolean select") {
    QPSTokenList tokens;
    tokens = TokenListBuilder().singleStmtDeclaration().validBooleanSelect().get();

    QPSParser parser(tokens);
    REQUIRE_NOTHROW(parser.parse());
  }
}

TEST_CASE("tuple select"){
    SECTION("single tuple element"){
      QPSTokenList tokens;
      tokens = TokenListBuilder().validSingleTupleSelect().get();

      QPSParser parser(tokens);
      REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("multi tuple element"){
      QPSTokenList tokens;
      tokens = TokenListBuilder().validMultiTupleSelect().get();

      QPSParser parser(tokens);
      REQUIRE_NOTHROW(parser.parse());
    }
}

TEST_CASE("not parsing"){
    SECTION("single not pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat()._not().validParentWithoutSuchThat().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("multi not pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat()._not().validParentWithoutSuchThat().suchThat()._not().validParentWithoutSuchThat().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("multi not pattern with and"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat()._not().validParentWithoutSuchThat()._and()._not().validParentWithoutSuchThat().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
}

TEST_CASE("singleDeclaration_singleSelect_singlePattern") {

    SECTION("pattern_synonym_wildcard") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().identifier().comma().wildcard().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_wildcard_wildcard") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().wildcard().comma().wildcard().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_quotedIdent_wildcard") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().quotedIdent().comma().wildcard().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_quotedIdent_wildcardIdent") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().quotedIdent().comma().wildcardIdent().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_wildcard_wildcardIdent") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().wildcard().comma().wildcardIdent().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_synonym_wildcardIdent") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().identifier().comma().wildcardIdent().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_quotedIdent_wildcardConst") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().quotedIdent().comma().wildcardConst().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_wildcard_wildcardConst") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().wildcard().comma().wildcardConst().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

    SECTION("pattern_synonym_wildcardConst") {
        QPSTokenList tokens;
        tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().pattern().identifier().leftParen().identifier().comma().wildcardConst().rightParen().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
}

TEST_CASE("singleDeclaration_singleSelect_singleRelationship") {
    SECTION("parent") {
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().identifier().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().wildcard().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().integer().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parent().leftParen().integer().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
    }
    SECTION("parent*") {
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().identifier().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().wildcard().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().integer().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().parentStar().leftParen().integer().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
    }
    SECTION("follows") {
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().identifier().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().wildcard().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().integer().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().follows().leftParen().integer().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
    }
    SECTION("follows*") {
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonym_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().identifier().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("wildcard_integer") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().wildcard().comma().integer().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().integer().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("integer_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().followsStar().leftParen().integer().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
    }
    SECTION("uses") {
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("synonym_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("synonym_quotedIdent"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().identifier().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_quotedIdent"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().wildcard().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("integer_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().integer().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("integer_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().integer().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("integer_quotedIdent"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().uses().leftParen().integer().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
    }
    SECTION("modifies") {
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("synonyn_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }

        SECTION("synonyn_quotedIdent") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().identifier().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_quotedIdent"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().wildcard().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("integer_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().integer().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("integer_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().integer().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("integer_quotedIdent"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().modifies().leftParen().integer().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("quotedIdent_quotedIdent") {
          QPSTokenList tokens;
          tokens = TokenListBuilder()
                       .singleStmtDeclaration()
                       .select()
                       .identifier()
                       .suchThat()
                       .modifies()
                       .leftParen()
                       .quotedIdent()
                       .comma()
                       .quotedIdent()
                       .rightParen()
                       .get();

          QPSParser parser(tokens);
          REQUIRE_NOTHROW(parser.parse());
        }
    }
    SECTION("calls"){
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("synonyn_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("synonyn_quotedIdentifier") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().identifier().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_quotedIdentifier"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().wildcard().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("quotedIdentifier_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().quotedIdent().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("quotedIdentifier_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().quotedIdent().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("quotedIdentifier_quotedIdentifier"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().calls().leftParen().quotedIdent().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
    }
    SECTION("calls*"){
        SECTION("synonyn_synonym") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().identifier().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("synonyn_wildcard") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().identifier().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("synonyn_quotedIdentifier") {
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().identifier().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().wildcard().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().wildcard().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("wildcard_quotedIdentifier"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().wildcard().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("quotedIdentifier_synonym"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().quotedIdent().comma().identifier().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("quotedIdentifier_wildcard"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().quotedIdent().comma().wildcard().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
        SECTION("quotedIdentifier_quotedIdentifier"){
            QPSTokenList tokens;
            tokens = TokenListBuilder().singleStmtDeclaration().select().identifier().suchThat().callsStar().leftParen().quotedIdent().comma().quotedIdent().rightParen().get();

            QPSParser parser(tokens);
            REQUIRE_NOTHROW(parser.parse());
        }
    }
}

TEST_CASE("singleDeclaration_singleSelect_singlePattern_singleRelationship") {
    SECTION("pattern_parents"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiStmtDeclaration().select().identifier().validAssignPattern().validFollows().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("pattern_parentsStar"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiReadDeclaration().select().identifier().validAssignPattern().validParentStar().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("pattern_follows"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiPrintDeclaration().select().identifier().validAssignPattern().validFollows().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("pattern_followsStar"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiWhileDeclaration().select().identifier().validAssignPattern().validFollowsStar().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("pattern_uses"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiIfDeclaration().select().identifier().validAssignPattern().validFollows().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("pattern_modifies"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiAssignDeclaration().select().identifier().validAssignPattern().validFollows().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

}
TEST_CASE("singleDeclaration_singleSelect_singleRelationship_singlePattern") {
    SECTION("parents_pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiAssignDeclaration().select().identifier().validParent().validAssignPattern().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("parentsStar_pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiIfDeclaration().select().identifier().validParentStar().validAssignPattern().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("follows_pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiWhileDeclaration().select().identifier().validFollows().validAssignPattern().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("followsStar_pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiVariableDeclaration().select().identifier().validFollowsStar().validAssignPattern().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("uses_pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiConstantDeclaration().select().identifier().validUses().validAssignPattern().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("modifies_pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiProcedureDeclaration().select().identifier().validModifies().validAssignPattern().get();

        QPSParser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

}

TEST_CASE("invalid syntax"){
    SECTION("suchThat_pattern"){
        QPSTokenList tokens;
        tokens = TokenListBuilder().multiStmtDeclaration().select().identifier().suchThat().validAssignPattern().get();
        QPSParser parser(tokens);
        REQUIRE_THROWS(parser.parse());
    }
}
