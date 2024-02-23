//
// Created by sjh_9 on 23/2/2024.
//

#include "catch.hpp"
#include "sp/SingleCharacterStrategy.h"


TEST_CASE("[TestSP] SingleCharacterStrategy Tokenization", "[SingleCharacter]") {
    SingleCharacterStrategy strategy;
    auto tokens = std::make_shared<std::vector<std::shared_ptr<Token>>>();
    bool prevTokenIsKeyword = true;
    std::stringstream stream;

    SECTION("Tokenize '{' as LEFT_BRACE") {
        REQUIRE(strategy.tokenize('{', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::LEFT_BRACE);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '}' as RIGHT_BRACE") {
        REQUIRE(strategy.tokenize('}', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::RIGHT_BRACE);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize ';' as SEMICOLON") {
        REQUIRE(strategy.tokenize(';', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::SEMICOLON);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '(' as LEFT_PAREN") {
        REQUIRE(strategy.tokenize('(', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::LEFT_PAREN);
        REQUIRE(prevTokenIsKeyword == true);
    }
    SECTION("Tokenize ')' as RIGHT_PAREN") {
        REQUIRE(strategy.tokenize(')', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::RIGHT_PAREN);
        REQUIRE(prevTokenIsKeyword == true);
    }
    SECTION("Tokenize '+' as ADD") {
        REQUIRE(strategy.tokenize('+', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::ADD);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '-' as SUBTRACT") {
        REQUIRE(strategy.tokenize('-', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::SUBTRACT);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '*' as MULTIPLY") {
        REQUIRE(strategy.tokenize('*', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::MULTIPLY);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '%' as MOD") {
        REQUIRE(strategy.tokenize('%', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::MOD);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '/' as DIVIDE") {
        REQUIRE(strategy.tokenize('/', stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::DIVIDE);
        REQUIRE(prevTokenIsKeyword == false);
    }
}