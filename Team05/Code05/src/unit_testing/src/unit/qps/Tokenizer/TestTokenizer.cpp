//
// Created by Alex on 16/2/2024.
//

#include "catch.hpp"
#include "qps/tokenizer/Tokenizer.h"



static std::vector<std::shared_ptr<QPSToken>> testHelper(const std::string& basicString);
static bool compareExpected(std::vector<std::shared_ptr<QPSToken>> tokens,
                            std::initializer_list<QPSTokenType::QPSTypeInfo> expectedTypes);

TEST_CASE("scratch_pad") {
    std::string source = "stmt s; Select s such that Follows(1, s) pattern s(_, _\"x+y\"_)";
    std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();
    std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();
    Tokenizer tokenizer(source, strategies, tokens);

    REQUIRE_NOTHROW(tokenizer.tokenize());
    tokens->toString();

}

// Unit Tests for QPS
TEST_CASE("tokenize_validSyntax_noThrows") {
    SECTION("singleDeclaration_singleSelect") {
        std::string source = "stmt s; Select s";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::STMT1, QPSTokenType::IDENTIFIER, QPSTokenType::SEMICOLON,
                                         QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
    SECTION("multipleDeclaration_singleSelect") {
        std::string source = "stmt s,s1; Select s";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::STMT1, QPSTokenType::IDENTIFIER,
                                     QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::SEMICOLON,
                                     QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_invalidSyntax_noThrows") {
    SECTION("integerDeclaration_singleSelect") {
        std::string source = "stmt 1 ; Select s";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::STMT1, QPSTokenType::INTEGER,
                                         QPSTokenType::SEMICOLON, QPSTokenType::SELECT,
                                         QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_declaration_declarationToken") {
    SECTION("stmt token") {
        std::string source = "stmt";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::STMT1, QPSTokenType::END_OF_FILE}));
    }
    // TODO: other declaration tokens
}

TEST_CASE("tokenize_select_selectToken") {

    SECTION("properSelect_selectToken") {
        std::string source = "Select";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::END_OF_FILE}));
    }
    SECTION("lowercaseSelect_identifierToken") {
        std::string source = "select";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_suchThat_suchThatToken"){
    SECTION("suchThat_suchTokenThatToken") {
        std::string source = "such that";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::SUCH, QPSTokenType::THAT, QPSTokenType::END_OF_FILE}));
    }
    SECTION("such_identifierToken") {
        std::string source = "such";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
    SECTION("that_identifierToken") {
        std::string source = "that";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_pattern_patternToken") {
    SECTION("pattern_patternToken") {
        std::string source = "pattern";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PATTERN, QPSTokenType::END_OF_FILE}));
    }
    SECTION("uowercasePattern_identifierToken") {
        std::string source = "Pattern";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_relationship_relationshipToken") {
    SECTION("parent_parentToken") {
        std::string source = "Parent";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PARENT, QPSTokenType::END_OF_FILE}));
    }
    SECTION("lowercasePattern_identifierToken") {
        std::string source = "parent";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
    SECTION("parent*_parentTToken") {
        std::string source = "Parent*";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PARENT_T, QPSTokenType::END_OF_FILE}));
    }
    SECTION("lowercasePattern*_identifierToken") {
        std::string source = "parent*";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::STAR, QPSTokenType::END_OF_FILE}));
    }
    SECTION("modifies_modifiesToken") {
        std::string source = "Modifies";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::MODIFIES_S, QPSTokenType::END_OF_FILE}));
    }
    SECTION("lowercasePattern*_identifierToken") {
        std::string source = "modifies";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
}


static std::vector<std::shared_ptr<QPSToken>> testHelper(const std::string& source) {
    std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();
    std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();
    Tokenizer tokenizer(source, strategies, tokens);
    REQUIRE_NOTHROW(tokenizer.tokenize());
    return tokens->getTokens();
}

static bool compareExpected(std::vector<std::shared_ptr<QPSToken>> tokens,
                            std::initializer_list<QPSTokenType::QPSTypeInfo> expectedTypes){
    if (tokens.size() != expectedTypes.size()) {
        return false;
    }
    auto it = tokens.begin();
    for (auto expectedType : expectedTypes) {
        if ((*it)->getType().getInfo() != expectedType) {
            return false;
        }
        it++;
    }
    return true;
}
