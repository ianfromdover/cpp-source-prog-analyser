//
// Created by Alex on 16/2/2024.
//

#include "catch.hpp"
#include "qps/parser/Parser.h"
#include "qps/parser/Demo.h"

using namespace qps;

static QPSTokenList generateTokenList(std::initializer_list<std::pair<QPSTokenType::TypeInfo,std::string>> tokenStream);

TEST_CASE("scratch pad parser"){
    SECTION("singleDeclaration_singleSelect_singlePattern") {
QPSTokenList tokens = generateTokenList({
            {QPSTokenType::TypeInfo::STMT,        "stmt"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::TypeInfo::SELECT,      "Select"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::SUCH,        "such"},
            {QPSTokenType::TypeInfo::THAT,        "that"},
            {QPSTokenType::TypeInfo::USES_S,      "UsesS"},
            {QPSTokenType::TypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::TypeInfo::INTEGER,     "1"},
            {QPSTokenType::TypeInfo::COMMA,       ","},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::TypeInfo::PATTERN,     "pattern"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::TypeInfo::WILDCARD,    "_"},
            {QPSTokenType::TypeInfo::COMMA,       ","},
            {QPSTokenType::TypeInfo::WILDCARD,    "_"},
            {QPSTokenType::TypeInfo::QUOTE,       "\""},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "x"},
            {QPSTokenType::TypeInfo::PLUS,        "+"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "y"},
            {QPSTokenType::TypeInfo::QUOTE,       "\""},
            {QPSTokenType::TypeInfo::WILDCARD,    "_"},
            {QPSTokenType::TypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::TypeInfo::END_OF_FILE, ""},
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
            {QPSTokenType::TypeInfo::STMT,        "stmt"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::TypeInfo::SELECT,      "Select"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("multipleDeclaration_singleSelect") {
        QPSTokenList tokens = generateTokenList({
            {QPSTokenType::TypeInfo::STMT,        "stmt"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::COMMA,       ","},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s1"},
            {QPSTokenType::TypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::TypeInfo::SELECT,      "Select"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("singleDeclaration_singleSelect_singleRelationship") {
        QPSTokenList tokens = generateTokenList({
            {QPSTokenType::TypeInfo::STMT,        "stmt"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::TypeInfo::SELECT,      "Select"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::SUCH,        "such"},
            {QPSTokenType::TypeInfo::THAT,        "that"},
            {QPSTokenType::TypeInfo::PARENT,      "Parent"},
            {QPSTokenType::TypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::COMMA,       ","},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("singleDeclaration_singleSelect_singlePattern") {
        QPSTokenList tokens = generateTokenList({
            {QPSTokenType::TypeInfo::STMT,        "stmt"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::SEMICOLON,   ";"},
            {QPSTokenType::TypeInfo::SELECT,      "Select"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::PATTERN,     "pattern"},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::LEFT_PAREN,  "("},
            {QPSTokenType::TypeInfo::IDENTIFIER,  "s"},
            {QPSTokenType::TypeInfo::COMMA,       ","},
            {QPSTokenType::TypeInfo::WILDCARD,    "_"},
            {QPSTokenType::TypeInfo::RIGHT_PAREN, ")"},
            {QPSTokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

}

static QPSTokenList generateTokenList(std::initializer_list<std::pair<QPSTokenType::TypeInfo,std::string>> tokenStream){
    QPSTokenList tokens;
    for(auto& token : tokenStream){
        tokens.addToken(token.first, token.second);
    }
    return tokens;
}

