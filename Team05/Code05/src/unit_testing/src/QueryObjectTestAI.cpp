//
// Created by tohzh on 10/2/2024.
//

#include "TNode.h"

#include "catch.hpp"
using namespace std;

#include "qps/query_elements/constraint/Constraint.h"
#include "qps/query_elements/constraint/FollowsConstraint.h"

#include "qps/query_elements/constraint_argument/StatementEntity.h"
#include "qps/query_elements/constraint_argument/PrintEntity.h"
#include "qps/query_elements/constraint_argument/ReadEntity.h"

#include "qps/query_elements/QueryObject.h"

// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/ab543156-156c-4880-9673-2ea97ffd9182
TEST_CASE("QueryObject_GetReturnType_ReturnsCorrectValue") {
    QueryObject queryObj;
    std::shared_ptr<PrintEntity> returnType = std::make_shared<PrintEntity>("g");
    queryObj.setReturnType(returnType);
    REQUIRE(queryObj.getReturnType() == returnType);
}

TEST_CASE("QueryObject_SetReturnType_SetsCorrectValue") {
    QueryObject queryObj;
    std::shared_ptr<Returnable> returnType = std::make_shared<PrintEntity>("c");
    queryObj.setReturnType(returnType);
    REQUIRE(queryObj.getReturnType() == returnType);
}

TEST_CASE("QueryObject_GetConstraints_ReturnsCorrectVector") {
    QueryObject queryObj;
    auto* s = new StatementEntity("a");
    auto* r = new ReadEntity("z");
    FollowsConstraint follows_constraint(s, r);
    queryObj.addConstraint(follows_constraint);
    std::vector<Constraint*> constraints = queryObj.getConstraints();
    REQUIRE(constraints.size() == 1);
    // Check if the stored pointer is of type FollowsConstraint
    auto* storedConstraint = dynamic_cast<FollowsConstraint*>(constraints[0]);
    REQUIRE(storedConstraint != nullptr); // Ensure dynamic_cast succeeded
    REQUIRE(storedConstraint == &follows_constraint); // Address comparison
}

TEST_CASE("QueryObject_Add/GetConstraint_ReturnsCorrectValues") {
    QueryObject queryObj;
    auto* s = new StatementEntity("t");
    auto* r = new ReadEntity("f");
    FollowsConstraint follows_constraint(s, r);
    queryObj.addConstraint(follows_constraint);
    std::vector<Constraint*> constraints = queryObj.getConstraints();
    REQUIRE(constraints[0] == &follows_constraint); // Address comparison
}

TEST_CASE("QueryObject_Get/AddDeclarations_ReturnsCorrectValues") {
    QueryObject queryObj;
    PrintEntity declaration1("q"); // Using PrintEntity instead of Entity
    PrintEntity declaration2("h"); // Using PrintEntity instead of Entity
    queryObj.addDeclaration(declaration1);
    queryObj.addDeclaration(declaration2);
    std::vector<Entity*> declarations = queryObj.getDeclarations();
    REQUIRE(declarations.size() == 2);
    // Check if the stored pointers are of type PrintEntity
    auto* storedDeclaration1 = dynamic_cast<PrintEntity*>(declarations[0]);
    auto* storedDeclaration2 = dynamic_cast<PrintEntity*>(declarations[1]);
    REQUIRE(storedDeclaration1 != nullptr); // Ensure dynamic_cast succeeded
    REQUIRE(storedDeclaration2 != nullptr); // Ensure dynamic_cast succeeded
    // Address comparison
    REQUIRE(storedDeclaration1 == &declaration1);
    REQUIRE(storedDeclaration2 == &declaration2);
}

// ai-gen end