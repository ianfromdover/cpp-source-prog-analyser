//
// Created by yewme on 27/3/2024.
//

#include "catch.hpp"
#include "qps/query_optimizer/concrete_optimizers/DuplicateRemovalOptimizer.h"
#include "qps/query_elements/constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"

TEST_CASE("Test hash function for FollowsConstraint") {
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

TEST_CASE("Test duplicate remover") {
    StatementEntity s1("2");
    StatementEntity s2("3");
    FollowsConstraint fc = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                             std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcCopy = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                                 std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcCopyCopy = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                                    std::make_shared<StatementEntity>(s2));
    QueryObject qo = QueryObject();
    qo.addConstraint(make_shared<FollowsConstraint>(fc));
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopy));
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopyCopy));
    DuplicateRemovalOptimizer optimizer;
    REQUIRE(qo.getConstraints().size() == 3);
    shared_ptr<Constraint> fcElement = qo.getConstraints()[0];
    optimizer.optimize(qo);
    shared_ptr<Constraint> fcElementAfter = qo.getConstraints()[0];
    REQUIRE(qo.getConstraints().size() == 1);
    REQUIRE(fcElement == fcElementAfter);
}