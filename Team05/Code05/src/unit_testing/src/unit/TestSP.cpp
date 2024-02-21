// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/e39e28d1-87dc-410f-918e-2fe030a34c82

#include "catch.hpp"
#include "sp/Scanner.h"
#include "sp/SingleCharacterStrategy.h"
#include "sp/DoubleCharacterStrategy.h"
#include "sp/MultiCharacterStrategy.h"
#include <sstream>

TEST_CASE("[TestSP] SingleCharacterStrategy tokenization", "[SingleCharacter]") {
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
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::UNKNOWN);
        REQUIRE(prevTokenIsKeyword == false);
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
        REQUIRE(strategy.tokenize(firstChar, stream, tokens, prevTokenIsKeyword) == true);
        REQUIRE(tokens->back()->getType() == TokenType::UNKNOWN);
        REQUIRE(prevTokenIsKeyword == false);
    }
}

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
