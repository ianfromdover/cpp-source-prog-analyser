//
// Created by Alex on 16/2/2024.
//

#include "catch.hpp"
#include "qps/tokenizer/Tokenizer.h"

using namespace qps;

static std::vector<std::shared_ptr<Token>> testHelper(const std::string& basicString);
static bool compareExpected(std::vector<std::shared_ptr<Token>> tokens, std::initializer_list<TokenType::TypeInfo> expectedTypes);

// Unit Tests for QPS
TEST_CASE("tokenize_validSyntax_noThrows") {
    SECTION("singleDeclaration_singleSelect") {
        std::string source = "stmt s; Select s";
        std::vector<std::shared_ptr<Token>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {TokenType::STMT, TokenType::IDENTIFIER, TokenType::SEMICOLON,
                                         TokenType::SELECT, TokenType::IDENTIFIER, TokenType::END_OF_FILE}));
    }
    SECTION("multipleDeclaration_singleSelect") {
        std::string source = "stmt s,s1; Select s";
        std::vector<std::shared_ptr<Token>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {TokenType::STMT, TokenType::IDENTIFIER,
                                         TokenType::COMMA, TokenType::IDENTIFIER, TokenType::SEMICOLON,
                                         TokenType::SELECT, TokenType::IDENTIFIER, TokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_invalidSyntax_noThrows") {
    SECTION("integerDeclaration_singleSelect") {
        std::string source = "stmt 1 ; Select s";
        std::vector<std::shared_ptr<Token>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {TokenType::STMT, TokenType::INTEGER,
                                         TokenType::SEMICOLON, TokenType::SELECT,
                                         TokenType::IDENTIFIER, TokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_declaration_declarationToken") {
    SECTION("stmt token") {
        std::string source = "stmt";
        std::vector<std::shared_ptr<Token>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {TokenType::STMT, TokenType::END_OF_FILE}));
    }
    // TODO: other declaration tokens
}

TEST_CASE("tokenize_select_selectToken") {

    SECTION("properSelect_selectToken") {
        std::string source = "Select";
        std::vector<std::shared_ptr<Token>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {TokenType::SELECT, TokenType::END_OF_FILE}));
    }
    SECTION("lowercaseSelect_identifierToken") {
        std::string source = "select";
        std::vector<std::shared_ptr<Token>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {TokenType::IDENTIFIER, TokenType::END_OF_FILE}));
    }
}

static std::vector<std::shared_ptr<Token>> testHelper(const std::string& source) {
    std::shared_ptr<StrategyList> strategies = std::make_shared<StrategyList>();
    std::shared_ptr<TokenList> tokens = std::make_shared<TokenList>();
    Tokenizer tokenizer(source, strategies, tokens);
    REQUIRE_NOTHROW(tokenizer.tokenize());
    return tokens->getTokens();
}

static bool compareExpected(std::vector<std::shared_ptr<Token>> tokens,
                            std::initializer_list<TokenType::TypeInfo> expectedTypes){
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
