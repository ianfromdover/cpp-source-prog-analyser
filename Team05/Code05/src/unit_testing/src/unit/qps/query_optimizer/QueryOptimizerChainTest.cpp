//
// Created by yewme on 29/3/2024.
//

#include "catch.hpp"
#include "qps/query_optimizer/QueryOptimizerChain.h"
#include "qps/query_optimizer/concrete_optimizers/DuplicateRemovalOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"

TEST_CASE("Test optimizer chain") {

    QueryObject qo = QueryObject();
    QueryOptimizerChain chain;
    DuplicateRemovalOptimizer optimizer;

    StatementEntity s1("2");
    StatementEntity s2("3");
    FollowsConstraint fc = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                             std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcCopy = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                                 std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcCopyCopy = FollowsConstraint(std::make_shared<StatementEntity>(s1),
                                                     std::make_shared<StatementEntity>(s2));
    FollowsTConstraint ftc = FollowsTConstraint(std::make_shared<StatementEntity>(s1),
                                             std::make_shared<StatementEntity>(s2));
    FollowsTConstraint ftcCopy = FollowsTConstraint(std::make_shared<StatementEntity>(s1),
                                                 std::make_shared<StatementEntity>(s2));
    qo.addConstraint(make_shared<FollowsConstraint>(fc));
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopy));
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopyCopy));
    qo.addConstraint(make_shared<FollowsTConstraint>(ftc));
    qo.addConstraint(make_shared<FollowsTConstraint>(ftcCopy));
    REQUIRE(qo.getConstraints().size() == 5);
    shared_ptr<Constraint> fcElement = qo.getConstraints()[0];

    chain.addOptimizer(std::make_unique<DuplicateRemovalOptimizer>(optimizer));
    // TODO: add more optimizers to the chain here
    chain.optimize(qo);

    shared_ptr<Constraint> fcElementAfter = qo.getConstraints()[0];
    REQUIRE(qo.getConstraints().size() == 2);
    REQUIRE(fcElement == fcElementAfter);
}