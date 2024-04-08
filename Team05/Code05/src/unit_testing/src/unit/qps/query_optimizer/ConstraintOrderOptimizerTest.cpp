//
// Created by yewme on 29/3/2024.
//

#include "catch.hpp"
#include "qps/query_optimizer/concrete_optimizers/ConstraintOrderOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/CallsConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "qps/query_elements/constraint_argument/entity_reference/ProcedureEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"


TEST_CASE("Test constraint orderer") {
    IntegerArgument two(2);
    IntegerArgument three(3);
    StatementEntity s("s"); // This should get a lower score than ints
    ProcedureEntity p1("proc1");
    ProcedureEntity p2("proc2");
    FollowsConstraint first = FollowsConstraint(std::make_shared<IntegerArgument>(two),
            std::make_shared<IntegerArgument>(three));
    FollowsConstraint second = FollowsConstraint(std::make_shared<IntegerArgument>(two),
            std::make_shared<StatementEntity>(s));
    FollowsConstraint third = FollowsConstraint(std::make_shared<StatementEntity>(s),
            std::make_shared<StatementEntity>(s));
    CallsConstraint fourth = CallsConstraint(std::make_shared<ProcedureEntity>(p1),
            std::make_shared<ProcedureEntity>(p2));
    QueryObject qo = QueryObject();
    shared_ptr<FollowsConstraint> firstConstraint = make_shared<FollowsConstraint>(first);
    shared_ptr<FollowsConstraint> secondConstraint = make_shared<FollowsConstraint>(second);
    shared_ptr<FollowsConstraint> thirdConstraint = make_shared<FollowsConstraint>(third);
    shared_ptr<CallsConstraint> fourthConstraint = make_shared<CallsConstraint>(fourth);

    // Add the constraints in wrong order to test the order optimizer
    qo.addConstraint(secondConstraint);
    qo.addConstraint(thirdConstraint);
    qo.addConstraint(fourthConstraint);
    qo.addConstraint(firstConstraint);
    ConstraintOrderOptimizer optimizer;
    optimizer.optimize(qo);
    REQUIRE(qo.getConstraints()[0] == firstConstraint);
    REQUIRE(qo.getConstraints()[1] == secondConstraint);
    REQUIRE(qo.getConstraints()[2] == thirdConstraint);
    REQUIRE(qo.getConstraints()[3] == fourthConstraint);
}