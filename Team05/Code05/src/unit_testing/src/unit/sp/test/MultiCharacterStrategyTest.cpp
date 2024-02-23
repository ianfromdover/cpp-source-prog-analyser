//
// Created by sjh_9 on 23/2/2024.
//

#include "catch.hpp"
#include "sp/MultiCharacterStrategy.h"


TEST_CASE("[TestSP] MultiCharacterStrategy tokenization", "[MultiCharacter]") {
    MultiCharacterStrategy strategy;
    auto tokens = std::make_shared<std::vector<std::shared_ptr<Token>>>();
    bool prevTokenIsKeyword = false;
    std::stringstream stream;

    SECTION("Tokenize program as keyword") {
        stream.str("program");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::PROGRAM);
    }
    SECTION("Tokenize procedure as keyword") {
        stream.str("procedure");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::PROCEDURE);
    }
    SECTION("Tokenize read as keyword") {
        stream.str("read");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::READ);
    }
    SECTION("Tokenize while as keyword") {
        stream.str("while");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::WHILE);
    }
    SECTION("Tokenize if as keyword") {
        stream.str("if");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::IF);
    }

    SECTION("Tokenize then as keyword") {
        stream.str("then");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::THEN);
    }
    SECTION("Tokenize else as keyword") {
        stream.str("else");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::ELSE);
    }
    SECTION("Tokenize call as keyword") {
        stream.str("call");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::CALL);
    }

    SECTION("Tokenize program as name") {
        prevTokenIsKeyword = true;
        stream.str("program");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize procedure as name") {
        prevTokenIsKeyword = true;
        stream.str("procedure");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize read as name") {
        prevTokenIsKeyword = true;
        stream.str("read");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize while as name") {
        prevTokenIsKeyword = true;
        stream.str("while");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize if as name") {
        prevTokenIsKeyword = true;
        stream.str("if");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }

    SECTION("Tokenize then as name") {
        prevTokenIsKeyword = true;
        stream.str("then");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize else as name") {
        prevTokenIsKeyword = true;
        stream.str("else");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize call as name") {
        prevTokenIsKeyword = true;
        stream.str("call");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
    SECTION("Tokenize digits") {
        stream.str("13972");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::INTEGER);
        REQUIRE(prevTokenIsKeyword == false);
    }

    SECTION("Tokenize name") {
        stream.str("sad13972");
        char firstChar;
        stream.get(firstChar);
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::NAME);
        REQUIRE(prevTokenIsKeyword == false);
    }
}
