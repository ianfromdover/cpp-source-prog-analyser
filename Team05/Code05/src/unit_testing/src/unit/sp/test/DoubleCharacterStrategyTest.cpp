//
// Created by sjh_9 on 23/2/2024.
//

#include "catch.hpp"
#include "sp/tokenizer/strategy/DoubleCharacterStrategy.h"


TEST_CASE("DoubleCharacterStrategy tokenization", "[DoubleCharacter]") {
    DoubleCharacterStrategy strategy;
    auto tokens = std::make_shared<std::vector<std::shared_ptr<Token>>>();
    bool prevTokenIsKeyword = true;
    std::stringstream stream;

    SECTION("Tokenize '==' as EQUAL_EQUAL") {
        stream.str("==");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::EQUAL_EQUAL);
        REQUIRE(prevTokenIsKeyword == false);
    }

    SECTION("Tokenize '=' as ASSIGN") {
        stream.str("=");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::ASSIGN);
        REQUIRE(prevTokenIsKeyword == false);
    }

    SECTION("Tokenize '>=' as GREATER_EQUAL") {
        stream.str(">=");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::GREATER_EQUAL);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '>' as GREATER") {
        stream.str(">");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::GREATER);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '!=' as BANG_EQUAL") {
        stream.str("!=");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::BANG_EQUAL);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '!' as BANG") {
        stream.str("!");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::BANG);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '<=' as LESSER_EQUAL") {
        stream.str("<=");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::LESSER_EQUAL);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '<' as LESSER") {
        stream.str("<");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::LESSER);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '||' as OR") {
        stream.str("||");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::OR);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '|' as UNKNOWN") {
        stream.str("|");
        char firstChar;
        stream.get(firstChar);
        REQUIRE_THROWS_WITH(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword), "Invalid Token Type");
    }
    SECTION("Tokenize '&&' as AND") {
        stream.str("&&");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::AND);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize '&' as UNKNOWN") {
        stream.str("&");
        char firstChar;
        stream.get(firstChar);
        REQUIRE_THROWS_WITH(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword), "Invalid Token Type");
    }
}