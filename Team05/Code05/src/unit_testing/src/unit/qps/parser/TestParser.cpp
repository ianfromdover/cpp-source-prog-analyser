//
// Created by Alex on 16/2/2024.
//

#include "catch.hpp"
#include "qps/parser/Parser.h"

using namespace qps;

static TokenList generateTokenList(std::initializer_list<std::pair<TokenType::TypeInfo,std::string>> tokenStream);

// Unit Tests for QPS
TEST_CASE("parse_validSyntax_noThrows") {
    SECTION("singleDeclaration_singleSelect") {
        TokenList tokens = generateTokenList({
            {TokenType::TypeInfo::STMT, "stmt"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::SEMICOLON, ";"},
            {TokenType::TypeInfo::SELECT, "Select"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("multipleDeclaration_singleSelect") {
        TokenList tokens = generateTokenList({
            {TokenType::TypeInfo::STMT, "stmt"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::COMMA, ","},
            {TokenType::TypeInfo::IDENTIFIER, "s1"},
            {TokenType::TypeInfo::SEMICOLON, ";"},
            {TokenType::TypeInfo::SELECT, "Select"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("singleDeclaration_singleSelect_singleRelationship") {
        TokenList tokens = generateTokenList({
            {TokenType::TypeInfo::STMT, "stmt"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::SEMICOLON, ";"},
            {TokenType::TypeInfo::SELECT, "Select"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::SUCH, "such"},
            {TokenType::TypeInfo::THAT, "that"},
            {TokenType::TypeInfo::PARENT, "Parent"},
            {TokenType::TypeInfo::LEFT_PAREN, "("},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::COMMA, ","},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::RIGHT_PAREN, ")"},
            {TokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }
    SECTION("singleDeclaration_singleSelect_singlePattern") {
        TokenList tokens = generateTokenList({
            {TokenType::TypeInfo::STMT, "stmt"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::SEMICOLON, ";"},
            {TokenType::TypeInfo::SELECT, "Select"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::PATTERN, "pattern"},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::LEFT_PAREN, "("},
            {TokenType::TypeInfo::IDENTIFIER, "s"},
            {TokenType::TypeInfo::COMMA, ","},
            {TokenType::TypeInfo::WILDCARD, "_"},
            {TokenType::TypeInfo::RIGHT_PAREN, ")"},
            {TokenType::TypeInfo::END_OF_FILE, ""},
            });
        Parser parser(tokens);
        REQUIRE_NOTHROW(parser.parse());
    }

}

static TokenList generateTokenList(std::initializer_list<std::pair<TokenType::TypeInfo,std::string>> tokenStream){
    TokenList tokens;
    for(auto& token : tokenStream){
        tokens.addToken(token.first, token.second);
    }
    return tokens;
}

