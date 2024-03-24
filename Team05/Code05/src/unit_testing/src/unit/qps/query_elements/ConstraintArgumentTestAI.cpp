//
// Created by tohzh on 10/2/2024.
//

#include "catch.hpp"
using namespace std;

#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/ReadEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/PrintEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/AssignEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/CallEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/IfEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/WhileEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementRefWildcard.h"
#include "qps/query_elements/constraint_argument/ConstraintArgument.h"


// ai-gen start(gpt, 0, e)
// prompt: https://platform.openai.com/playground/p/iUhV1Vs18pHIoJq0lDbowAOl?model=gpt-3.5-turbo&mode=chat
TEST_CASE("StatementEntity_inherits_from_ConstraintArgument") {
    StatementEntity statement("z");
    REQUIRE(dynamic_cast<ConstraintArgument*>(&statement) != nullptr);
}

TEST_CASE("ReadEntity_inherits_from_ConstraintArgument") {
    ReadEntity read("a");
    REQUIRE(dynamic_cast<ConstraintArgument*>(&read) != nullptr);
}

TEST_CASE("PrintEntity_inherits_from_ConstraintArgument") {
    PrintEntity print("b");
    REQUIRE(dynamic_cast<ConstraintArgument*>(&print) != nullptr);
}

TEST_CASE("AssignEntity_inherits_from_ConstraintArgument") {
    AssignEntity assign("c");
    REQUIRE(dynamic_cast<ConstraintArgument*>(&assign) != nullptr);
}

TEST_CASE("CallEntity_inherits_from_ConstraintArgument") {
    CallEntity call("f");
    REQUIRE(dynamic_cast<ConstraintArgument*>(&call) != nullptr);
}

TEST_CASE("IfEntity_inherits_from_ConstraintArgument") {
    IfEntity ifEntity("a");
    REQUIRE(dynamic_cast<ConstraintArgument*>(&ifEntity) != nullptr);
}

TEST_CASE("WhileEntity_inherits_from_ConstraintArgument") {
    WhileEntity whileEntity("q");
    REQUIRE(dynamic_cast<ConstraintArgument*>(&whileEntity) != nullptr);
}

TEST_CASE("IntegerArgument_inherits_from_ConstraintArgument") {
    IntegerArgument integerArg;
    REQUIRE(dynamic_cast<ConstraintArgument*>(&integerArg) != nullptr);
}

TEST_CASE("StatementEntity_ReferenceType_StatementReference") {
    StatementEntity s("q");
    REQUIRE(s.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("ReadEntity_ReferenceType_StatementReference") {
    ReadEntity r("p");
    REQUIRE(r.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("PrintEntity_ReferenceType_StatementReference") {
    PrintEntity p("Q");
    REQUIRE(p.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("AssignEntity_ReferenceType_StatementReference") {
    AssignEntity a("p");
    REQUIRE(a.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("CallEntity_ReferenceType_StatementReference") {
    CallEntity c("i");
    REQUIRE(c.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("IfEntity_ReferenceType_StatementReference") {
    IfEntity i("g");
    REQUIRE(i.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("WhileEntity_ReferenceType_StatementReference") {
    WhileEntity w("v");
    REQUIRE(w.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("IntegerArgument_ReferenceType_StatementReference") {
    IntegerArgument ia;
    REQUIRE(ia.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

TEST_CASE("Wildcard_ReferenceType_StatementReference") {
    StatementRefWildcard wc;
    REQUIRE(wc.getReferenceType() == REFERENCE_TYPE_STATEMENT);
}

// ai-gen end