//
// Created by Alex on 16/2/2024.
//

#include "catch.hpp"
#include "qps/parser/Parser.h"
#include "qps/parser/Demo.h"

using namespace qps;

static QPSTokenList generateTokenList(std::initializer_list<std::pair<QPSTokenType::QPSTypeInfo,std::string>> tokenStream);

TEST_CASE("scratch pad parser"){
    SECTION("singleDeclaration_singleSelect_singlePattern") {
QPSTokenList tokens = generateTokenList({
            {QPSTokenType::QPSTypeInfo::STMT1,        "stmt"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::QPSTypeInfo::SELECT,      "Select"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::SUCH,        "such"},
            {QPSTokenType::QPSTypeInfo::THAT,        "that"},
            {QPSTokenType::QPSTypeInfo::USES_S,      "UsesS"},
            {QPSTokenType::QPSTypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::QPSTypeInfo::INTEGER,     "1"},
            {QPSTokenType::QPSTypeInfo::COMMA,       ","},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::QPSTypeInfo::PATTERN,     "pattern"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::QPSTypeInfo::WILDCARD,    "_"},
            {QPSTokenType::QPSTypeInfo::COMMA,       ","},
            {QPSTokenType::QPSTypeInfo::WILDCARD,    "_"},
            {QPSTokenType::QPSTypeInfo::QUOTE,       "\""},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "x"},
            {QPSTokenType::QPSTypeInfo::PLUS,        "+"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "y"},
            {QPSTokenType::QPSTypeInfo::QUOTE,       "\""},
            {QPSTokenType::QPSTypeInfo::WILDCARD,    "_"},
            {QPSTokenType::QPSTypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::QPSTypeInfo::END_OF_FILE, ""},
        });

        Parser parser(tokens);
        std::shared_ptr<IntermediateQuery> query;
        REQUIRE_NOTHROW(query=parser.parse());
    }
}

// Unit Tests for QPS
TEST_CASE("parse_validSyntax_noThrows") {
    SECTION("singleDeclaration_singleSelect") {
        QPSTokenList tokens = generateTokenList({
            {QPSTokenType::QPSTypeInfo::STMT1,        "stmt"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::QPSTypeInfo::SELECT,      "Select"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("multipleDeclaration_singleSelect") {
        QPSTokenList tokens = generateTokenList({
            {QPSTokenType::QPSTypeInfo::STMT1,        "stmt"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::COMMA,       ","},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s1"},
            {QPSTokenType::QPSTypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::QPSTypeInfo::SELECT,      "Select"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("singleDeclaration_singleSelect_singleRelationship") {
        QPSTokenList tokens = generateTokenList({
            {QPSTokenType::QPSTypeInfo::STMT1,        "stmt"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::QPSTypeInfo::SELECT,      "Select"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::SUCH,        "such"},
            {QPSTokenType::QPSTypeInfo::THAT,        "that"},
            {QPSTokenType::QPSTypeInfo::PARENT,      "Parent"},
            {QPSTokenType::QPSTypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::COMMA,       ","},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::QPSTypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("singleDeclaration_singleSelect_singlePattern") {
        QPSTokenList tokens = generateTokenList({
            {QPSTokenType::QPSTypeInfo::STMT1,        "stmt"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::QPSTypeInfo::SELECT,      "Select"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::PATTERN,     "pattern"},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::QPSTypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::QPSTypeInfo::COMMA,       ","},
            {QPSTokenType::QPSTypeInfo::WILDCARD,    "_"},
            {QPSTokenType::QPSTypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::QPSTypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

}

static QPSTokenList generateTokenList(std::initializer_list<std::pair<QPSTokenType::QPSTypeInfo,std::string>> tokenStream){
    QPSTokenList tokens;
    for(auto& token : tokenStream){
        tokens.addToken(token.first, token.second);
    }
    return tokens;
}

