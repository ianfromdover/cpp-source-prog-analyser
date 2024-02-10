//
// Created by tohzh on 10/2/2024.
//

#include "TNode.h"

#include "catch.hpp"
using namespace std;

#include "qps/query_elements/constraint_argument/StatementEntity.h"
#include "qps/query_elements/constraint_argument/ReadEntity.h"
#include "qps/query_elements/constraint_argument/PrintEntity.h"
#include "qps/query_elements/constraint_argument/AssignEntity.h"
#include "qps/query_elements/constraint_argument/CallEntity.h"
#include "qps/query_elements/constraint_argument/IfEntity.h"
#include "qps/query_elements/constraint_argument/WhileEntity.h"
#include "qps/query_elements/constraint_argument/IntegerArgument.h."
#include "qps/query_elements/constraint_argument/WildCard.h"

//named in the form of [feature]_[scenario]_[result]

// ai-gen start(gpt, 0, e)
// prompt: https://chat.openai.com/share/1d6a042b-6280-4306-abaf-1ec120a9fef4
TEST_CASE("entity_statementEntityIsTypeStatement_stringStatement") {
    StatementEntity en = StatementEntity();
    REQUIRE(en.getEntityType() == RETURN_TYPE_STATEMENT);
}

TEST_CASE("entity_readEntityIsTypeStatement_stringRead") {
    ReadEntity en = ReadEntity();
    REQUIRE(en.getEntityType() == RETURN_TYPE_READ);
}

TEST_CASE("entity_printEntityIsTypePrint_stringPrint") {
    PrintEntity en = PrintEntity();
    REQUIRE(en.getEntityType() == RETURN_TYPE_PRINT);
}

TEST_CASE("entity_assignEntityIsTypeAssign_stringAssign") {
    AssignEntity en = AssignEntity();
    REQUIRE(en.getEntityType() == RETURN_TYPE_ASSIGN);
}

TEST_CASE("entity_callEntityIsTypeCall_stringCall") {
    CallEntity en = CallEntity();
    REQUIRE(en.getEntityType() == RETURN_TYPE_CALL);
}

TEST_CASE("entity_ifEntityIsTypeIf_stringIf") {
    IfEntity en = IfEntity();
    REQUIRE(en.getEntityType() == RETURN_TYPE_IF);
}

TEST_CASE("entity_whileEntityIsTypeWhile_stringWhile") {
    WhileEntity en = WhileEntity();
    REQUIRE(en.getEntityType() == RETURN_TYPE_WHILE);
}

TEST_CASE("entity_integerArgumentIsTypeInteger_stringInteger") {
    IntegerArgument en = IntegerArgument();
    REQUIRE(en.getEntityType() == RETURN_TYPE_INTEGER);
}

TEST_CASE("entity_wildCardIsTypeWildcard_stringWildcard") {
    WildCard en = WildCard();
    REQUIRE(en.getEntityType() == RETURN_TYPE_WILDCARD);
}

// ai-gen end

// ai-gen start(gpt, 0, e)
// prompt: https://chat.openai.com/share/79d15f08-fd88-453e-943a-261fbef441a6
TEST_CASE("Entity_setIdentifierAndGetIdentifier_Success") {
    // Arrange
    AssignEntity entity;
    std::string identifier = "test_identifier";

    // Act
    entity.setIdentifier(identifier);
    std::string retrievedIdentifier = entity.getIdentifier();

    // Assert
    REQUIRE(retrievedIdentifier == identifier);
}

TEST_CASE("Entity_setIdentifierAndGetIdentifier_EmptyString") {
    // Arrange
    AssignEntity entity;
    std::string identifier;

    // Act
    entity.setIdentifier(identifier);
    std::string retrievedIdentifier = entity.getIdentifier();

    // Assert
    REQUIRE(retrievedIdentifier == identifier);
}

TEST_CASE("Entity_setIdentifierAndGetIdentifier_AfterMultipleSets") {
    // Arrange
    AssignEntity entity;
    std::string identifier1 = "identifier1";
    std::string identifier2 = "identifier2";

    // Act
    entity.setIdentifier(identifier1);
    entity.setIdentifier(identifier2);
    std::string retrievedIdentifier = entity.getIdentifier();

    // Assert
    REQUIRE(retrievedIdentifier == identifier2);
}

//ai-gen end

// ai-gen start(gpt, 0 ,e)
// prompt: https://chat.openai.com/share/09e67ecb-4081-4912-bb8c-023c7e117580
TEST_CASE("inheritance_check_statementReference_ReadEntity") {
    ReadEntity readEntity;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&readEntity) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

TEST_CASE("inheritance_check_statementReference_PrintEntity") {
    PrintEntity printEntity;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&printEntity) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

TEST_CASE("inheritance_check_statementReference_AssignEntity") {
    AssignEntity assignEntity;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&assignEntity) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

TEST_CASE("inheritance_check_statementReference_CallEntity") {
    CallEntity callEntity;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&callEntity) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

TEST_CASE("inheritance_check_statementReference_IfEntity") {
    IfEntity ifEntity;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&ifEntity) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

TEST_CASE("inheritance_check_statementReference_WhileEntity") {
    WhileEntity whileEntity;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&whileEntity) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

TEST_CASE("inheritance_check_statementReference_IntegerArgument") {
    IntegerArgument integerArgument;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&integerArgument) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

TEST_CASE("inheritance_check_statementReference_WildCard") {
    WildCard wildCard;
    bool isInstanceOfStatementReference = dynamic_cast<StatementReference*>(&wildCard) != nullptr;
    REQUIRE(isInstanceOfStatementReference);
}

// ai-gen end


// ai-gen start(gpt, 0, e)
// prompt https://chat.openai.com/share/0b30db75-b64f-47a1-942b-1afdad17f2f3

TEST_CASE("StatementEntity_inheritanceCheck_isTrue") {
    REQUIRE(std::is_base_of<Entity, StatementEntity>::value);
}

TEST_CASE("ReadEntity_inheritanceCheck_isTrue") {
    REQUIRE(std::is_base_of<Entity, ReadEntity>::value);
}

TEST_CASE("PrintEntity_inheritanceCheck_isTrue") {
    REQUIRE(std::is_base_of<Entity, PrintEntity>::value);
}

TEST_CASE("AssignEntity_inheritanceCheck_isTrue") {
    REQUIRE(std::is_base_of<Entity, AssignEntity>::value);
}

TEST_CASE("CallEntity_inheritanceCheck_isTrue") {
    REQUIRE(std::is_base_of<Entity, CallEntity>::value);
}

TEST_CASE("IfEntity_inheritanceCheck_isTrue") {
    REQUIRE(std::is_base_of<Entity, IfEntity>::value);
}

TEST_CASE("WhileEntity_inheritanceCheck_isTrue") {
    REQUIRE(std::is_base_of<Entity, WhileEntity>::value);
}

TEST_CASE("IntegerArgument_inheritanceCheck_isFalse") {
    REQUIRE_FALSE(std::is_base_of<Entity, IntegerArgument>::value);
}

TEST_CASE("WildCard_inheritanceCheck_isFalse") {
    REQUIRE_FALSE(std::is_base_of<Entity, WildCard>::value);
}

// ai-gen end