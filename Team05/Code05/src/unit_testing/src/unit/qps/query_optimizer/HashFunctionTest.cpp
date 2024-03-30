//
// Created by yewme on 29/3/2024.
//

#include "catch.hpp"
#include "qps/query_elements/constraint/relationship_constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"

TEST_CASE("Test hash function on FollowsConstraint and FollowsTConstraint") {
    StatementEntity s1("2");
    StatementEntity s2("3");
    FollowsConstraint fc = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                             std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcCopy = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                                 std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcSwitch = FollowsConstraint(std::make_shared<StatementEntity>(s2),
                                                   std::make_shared<StatementEntity>(s1));
    FollowsTConstraint ftc = FollowsTConstraint(std::make_shared<StatementEntity>(s1),
                                                std::make_shared<StatementEntity>(s2));
    REQUIRE(fc.hash() == fcCopy.hash());
    REQUIRE(fc.hash() != fcSwitch.hash());
    REQUIRE(fc.hash() != ftc.hash());
}