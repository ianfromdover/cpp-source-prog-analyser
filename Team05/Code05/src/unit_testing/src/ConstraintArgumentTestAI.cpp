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
#include "qps/query_elements/constraint_argument/ConstraintArgument.h"


// ai-gen start(gpt, 0, e)
// prompt: https://chat.openai.com/share/ec225b64-f0c0-4d04-a5c2-9645760d0401
TEST_CASE("StatementEntity_inherits_from_ConstraintArgument") {
    StatementEntity statement;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&statement) != nullptr);
}

TEST_CASE("ReadEntity_inherits_from_ConstraintArgument") {
    ReadEntity read;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&read) != nullptr);
}

TEST_CASE("PrintEntity_inherits_from_ConstraintArgument") {
    PrintEntity print;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&print) != nullptr);
}

TEST_CASE("AssignEntity_inherits_from_ConstraintArgument") {
    AssignEntity assign;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&assign) != nullptr);
}

TEST_CASE("CallEntity_inherits_from_ConstraintArgument") {
    CallEntity call;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&call) != nullptr);
}

TEST_CASE("IfEntity_inherits_from_ConstraintArgument") {
    IfEntity ifEntity;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&ifEntity) != nullptr);
}

TEST_CASE("WhileEntity_inherits_from_ConstraintArgument") {
    WhileEntity whileEntity;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&whileEntity) != nullptr);
}

TEST_CASE("IntegerArgument_inherits_from_ConstraintArgument") {
    IntegerArgument integerArg;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&integerArg) != nullptr);
}

TEST_CASE("WildCard_inherits_from_ConstraintArgument") {
    WildCard wildCard;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&wildCard) != nullptr);
}

// ai-gen end

// ai-gen start(gpt, 0, e)
// prompt:https://chat.openai.com/c/02a7fbcc-80e0-4cfe-be5f-2f2858ab9b47
TEST_CASE("StatementEntity_ReferenceType_StatementReference") {
    StatementEntity s;
    REQUIRE(s.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("ReadEntity_ReferenceType_StatementReference") {
    ReadEntity r;
    REQUIRE(r.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("PrintEntity_ReferenceType_StatementReference") {
    PrintEntity p;
    REQUIRE(p.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("AssignEntity_ReferenceType_StatementReference") {
    AssignEntity a;
    REQUIRE(a.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("CallEntity_ReferenceType_StatementReference") {
    CallEntity c;
    REQUIRE(c.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("IfEntity_ReferenceType_StatementReference") {
    IfEntity i;
    REQUIRE(i.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("WhileEntity_ReferenceType_StatementReference") {
    WhileEntity w;
    REQUIRE(w.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("IntegerArgument_ReferenceType_StatementReference") {
    IntegerArgument ia;
    REQUIRE(ia.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("WildCard_ReferenceType_StatementReference") {
    WildCard wc;
    REQUIRE(wc.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

// ai-gen end