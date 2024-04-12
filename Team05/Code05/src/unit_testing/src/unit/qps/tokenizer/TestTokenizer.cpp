//
// Created by Alex on 16/2/2024.
//

#include "catch.hpp"
#include "qps/tokenizer/Tokenizer.h"



static std::vector<std::shared_ptr<QPSToken>> testHelper(const std::string& basicString);
static bool compareExpected(std::vector<std::shared_ptr<QPSToken>> tokens,
                            std::initializer_list<QPSTokenType::QPSTypeInfo> expectedTypes);

TEST_CASE("scratch_pad") {
    std::string source = "assign a; variable v; Select a.stmt#";
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
    SECTION("read token") {
        std::string source = "read";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::READ, QPSTokenType::END_OF_FILE}));
    }
    SECTION("print token") {
        std::string source = "print";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PRINT, QPSTokenType::END_OF_FILE}));
    }
    SECTION("call token") {
        std::string source = "call";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::CALL, QPSTokenType::END_OF_FILE}));
    }
    SECTION("while token") {
        std::string source = "while";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::WHILE, QPSTokenType::END_OF_FILE}));
    }
    SECTION("if token") {
        std::string source = "if";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IF, QPSTokenType::END_OF_FILE}));
    }
    SECTION("assign token") {
        std::string source = "assign";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::ASSIGN, QPSTokenType::END_OF_FILE}));
    }
    SECTION("variable token") {
        std::string source = "variable";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::VARIABLE, QPSTokenType::END_OF_FILE}));
    }
    SECTION("constant token") {
        std::string source = "constant";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::CONSTANT, QPSTokenType::END_OF_FILE}));
    }
    SECTION("procedure token") {
        std::string source = "procedure";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PROCEDURE, QPSTokenType::END_OF_FILE}));
    }

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

TEST_CASE("tokenize_not"){
//    SECTION("simple not"){
//        std::string source = "not";
//        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
//        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
//    }
//    SECTION("select ident not pattern"){
//        std::string source = "Select s not pattern";
//        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
//        REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::NOT, QPSTokenType::PATTERN, QPSTokenType::END_OF_FILE}));
//    }
//    SECTION("select not as synonym"){
//        std::string source = "Select not not pattern";
//        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
//        REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::NOT, QPSTokenType::PATTERN, QPSTokenType::END_OF_FILE}));
//    }
//    SECTION("not as declaration synonym"){
//        std::string source = "stmt not; Select s";
//        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
//        REQUIRE(compareExpected(tokens, {QPSTokenType::STMT1, QPSTokenType::IDENTIFIER, QPSTokenType::SEMICOLON, QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
//    }
    SECTION("select not as synonym with and operator"){
        std::string source = "Select not such that not Follows(not,not) and not Follows(not,not)";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens,
             {QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::SUCH, QPSTokenType::THAT,
              QPSTokenType::NOT,
              QPSTokenType::FOLLOWS, QPSTokenType::LEFT_PAREN, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_PAREN,
              QPSTokenType::AND,
              QPSTokenType::NOT,
              QPSTokenType::FOLLOWS, QPSTokenType::LEFT_PAREN, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_PAREN,
              QPSTokenType::END_OF_FILE}));
    }
    SECTION("select not as synonym with pattern"){
      std::string source = "Select not such that not Follows(not,not) such that not Follows(not,not)";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens,
                              {QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::SUCH, QPSTokenType::THAT,
                               QPSTokenType::NOT,
                               QPSTokenType::FOLLOWS, QPSTokenType::LEFT_PAREN, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_PAREN,
                               QPSTokenType::SUCH, QPSTokenType::THAT,
                               QPSTokenType::NOT,
                               QPSTokenType::FOLLOWS, QPSTokenType::LEFT_PAREN, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_PAREN,
                               QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize with and not"){
  SECTION("with as synonym"){
    std::string source = "Select with with not not";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::WITH, QPSTokenType::NOT, QPSTokenType::IDENTIFIER,
                                     QPSTokenType::END_OF_FILE}));
  }
  SECTION("with as synonym"){
    std::string source = "Select <with> with not";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::LEFT_A_BRAC, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_A_BRAC, QPSTokenType::WITH, QPSTokenType::NOT,
                                     QPSTokenType::END_OF_FILE}));
  }
}

TEST_CASE("tokenize with attributes"){
    SECTION("procName"){
        std::string source = "with not.procName";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHPROCNAME, QPSTokenType::END_OF_FILE}));
    }
    SECTION("varName"){
      std::string source = "with not.varName";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHVARNAME, QPSTokenType::END_OF_FILE}));
    }
    SECTION("value"){
      std::string source = "with not.value";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHVALUE, QPSTokenType::END_OF_FILE}));
    }
    SECTION("stmt#"){
      std::string source = "with not.stmt#";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHSTMT, QPSTokenType::END_OF_FILE}));
    }
    SECTION("not procName"){
      std::string source = "with not not.procName";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::NOT, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHPROCNAME, QPSTokenType::END_OF_FILE}));
    }
    SECTION("not varName"){
      std::string source = "with not not.varName";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::NOT, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHVARNAME, QPSTokenType::END_OF_FILE}));
    }
    SECTION("not value"){
      std::string source = "with not not.value";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::NOT, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHVALUE, QPSTokenType::END_OF_FILE}));
    }
    SECTION("not stmt#"){
      std::string source = "with not not.stmt#";
      std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
      REQUIRE(compareExpected(tokens, {QPSTokenType::WITH, QPSTokenType::NOT, QPSTokenType::IDENTIFIER, QPSTokenType::DECIMAL, QPSTokenType::WITHSTMT, QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_with"){
  SECTION("with as synonym"){
    std::string source = "stmt with";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::STMT1, QPSTokenType::IDENTIFIER,
                                     QPSTokenType::END_OF_FILE}));
  }
  SECTION("with clause"){
    std::string source = "Select with with";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::WITH,
                                     QPSTokenType::END_OF_FILE}));
  }
  SECTION("with not clause"){
    std::string source = "Select with with not pattern";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::IDENTIFIER, QPSTokenType::WITH, QPSTokenType::NOT, QPSTokenType::IDENTIFIER,
                                     QPSTokenType::END_OF_FILE}));
  }
}

TEST_CASE("tokenize_boolean") {
  SECTION("boolean_identToken") {
    std::string source = "BOOLEAN";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER,
                                     QPSTokenType::END_OF_FILE}));
  }
  SECTION("selectBoolean_booleanToken") {
    std::string source = "Select BOOLEAN";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::SELECT, QPSTokenType::BOOLEAN,
                                     QPSTokenType::END_OF_FILE}));
  }
  SECTION("stmtBoolean_identToken") {
    std::string source = "stmt BOOLEAN";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::STMT1, QPSTokenType::IDENTIFIER,
                                     QPSTokenType::END_OF_FILE}));
  }
}

TEST_CASE("tokenize_tuple") {
  SECTION("openSynClose") {
    std::string source = "<a>";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::LEFT_A_BRAC, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_A_BRAC,
                                     QPSTokenType::END_OF_FILE}));
  }
  SECTION("openSynSynSynClose") {
    std::string source = "<a,b,c>";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::LEFT_A_BRAC, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_A_BRAC,
                                     QPSTokenType::END_OF_FILE}));
  }

}

TEST_CASE("tokenize_pattern_patternToken") {
    SECTION("pattern_patternToken") {
        std::string source = "pattern";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PATTERN, QPSTokenType::END_OF_FILE}));
    }
    SECTION("uppercasePattern_identifierToken") {
        std::string source = "Pattern";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
}

TEST_CASE("tokenize_and_andToken") {
  SECTION("and_identToken") {
    std::string source = "Uses(and,and)";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens, {QPSTokenType::USES, QPSTokenType::LEFT_PAREN, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_PAREN, QPSTokenType::END_OF_FILE}));
  }
  SECTION("and_andToken") {
    std::string source = "Uses(and,and) and Uses(and,and)";
    std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
    REQUIRE(compareExpected(tokens,
{QPSTokenType::USES, QPSTokenType::LEFT_PAREN, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_PAREN,
                             QPSTokenType::AND,
                             QPSTokenType::USES, QPSTokenType::LEFT_PAREN, QPSTokenType::IDENTIFIER, QPSTokenType::COMMA, QPSTokenType::IDENTIFIER, QPSTokenType::RIGHT_PAREN,
                             QPSTokenType::END_OF_FILE}));
  }

}

TEST_CASE("tokenize_relationship_relationshipToken") {
    SECTION("Parent_parentToken") {
        std::string source = "Parent";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PARENT, QPSTokenType::END_OF_FILE}));
    }
    SECTION("parent_identifierToken") {
        std::string source = "parent";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
    SECTION("Parent*_parentTToken") {
        std::string source = "Parent*";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::PARENT_T, QPSTokenType::END_OF_FILE}));
    }
    SECTION("parent*_identifierToken") {
        std::string source = "parent*";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::STAR, QPSTokenType::END_OF_FILE}));
    }
    SECTION("Modifies_modifiesToken") {
        std::string source = "Modifies";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(
            tokens, {QPSTokenType::MODIFIES, QPSTokenType::END_OF_FILE}));
    }
    SECTION("modifies_identifierToken") {
        std::string source = "modifies";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
    SECTION("Uses_usesToken") {
        std::string source = "Uses";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(
            tokens, {QPSTokenType::USES, QPSTokenType::END_OF_FILE}));
    }
    SECTION("uses_identifierToken") {
        std::string source = "uses";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
    SECTION("Calls_callsToken") {
        std::string source = "Calls";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::CALLS, QPSTokenType::END_OF_FILE}));
    }
    SECTION("calls_identifierToken") {
        std::string source = "calls";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::END_OF_FILE}));
    }
    SECTION("Calls*_callsToken") {
        std::string source = "Calls*";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::CALLS_T, QPSTokenType::END_OF_FILE}));
    }
    SECTION("calls*_identifierToken") {
        std::string source = "calls*";
        std::vector<std::shared_ptr<QPSToken>> tokens = testHelper(source);
        REQUIRE(compareExpected(tokens, {QPSTokenType::IDENTIFIER, QPSTokenType::STAR, QPSTokenType::END_OF_FILE}));
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
