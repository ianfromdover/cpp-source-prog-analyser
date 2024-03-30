//
// Created by yewme on 27/3/2024.
//

#include "catch.hpp"
#include "qps/query_optimizer/concrete_optimizers/DuplicateRemovalOptimizer.h"
#include "qps/query_elements/constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"

TEST_CASE("Test duplicate remover") {
    IntegerArgument two(2);
    IntegerArgument three(3);
    FollowsConstraint fc = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                             std::make_shared<IntegerArgument>(three));
    FollowsConstraint fcCopy = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                                 std::make_shared<IntegerArgument>(three));
    FollowsConstraint fcCopyCopy = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                                     std::make_shared<IntegerArgument>(three));
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