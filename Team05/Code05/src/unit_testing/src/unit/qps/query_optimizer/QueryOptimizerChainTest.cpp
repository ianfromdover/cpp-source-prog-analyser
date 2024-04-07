//
// Created by yewme on 29/3/2024.
//

#include "catch.hpp"
#include "qps/query_optimizer/QueryOptimizerChain.h"
#include "qps/query_optimizer/concrete_optimizers/DuplicateRemovalOptimizer.h"
#include "qps/query_optimizer/concrete_optimizers/ConstraintOrderOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/CallsConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "qps/query_elements/constraint_argument/entity_reference/ProcedureEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"

TEST_CASE("Test adding optimizer to chain and getOptimizers function") {

    QueryOptimizerChain chain;
    DuplicateRemovalOptimizer optimizer;

    REQUIRE(chain.getOptimizers().empty());
    chain.addOptimizer(std::make_unique<DuplicateRemovalOptimizer>(optimizer));
    REQUIRE(chain.getOptimizers().size() == 1);
}

TEST_CASE("Test remove function") {

    QueryOptimizerChain chain;
    DuplicateRemovalOptimizer optimizer;

    REQUIRE(chain.getOptimizers().empty());
    chain.addOptimizer(std::make_unique<DuplicateRemovalOptimizer>(optimizer));
    // Add more optimizers to test removing functionality
    REQUIRE(chain.getOptimizers().size() == 1);
    chain.removeOptimizer(0);
    REQUIRE(chain.getOptimizers().empty());
}

TEST_CASE("Test clear function") {

    QueryOptimizerChain chain;
    DuplicateRemovalOptimizer optimizer;

    REQUIRE(chain.getOptimizers().empty());
    chain.addOptimizer(std::make_unique<DuplicateRemovalOptimizer>(optimizer));
    // Add more optimizers to test clearing functionality
    REQUIRE(chain.getOptimizers().size() == 1);
    chain.clearOptimizers();
    REQUIRE(chain.getOptimizers().empty());
}

TEST_CASE("Test optimizer chain") {

    QueryObject qo = QueryObject();
    QueryOptimizerChain chain;
    DuplicateRemovalOptimizer duplicateRemovalOptimizer;
    ConstraintOrderOptimizer constraintOrderOptimizer;

    StatementEntity s1("s1");
    StatementEntity s2("s2");
    IntegerArgument two(2);
    IntegerArgument three(3);
    ProcedureEntity p1("proc1");
    ProcedureEntity p2("proc2");
    FollowsConstraint fc = FollowsConstraint(std::make_shared<IntegerArgument>(two),
            std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcCopy = FollowsConstraint(std::make_shared<IntegerArgument>(two),
            std::make_shared<StatementEntity>(s2));
    FollowsConstraint fcCopyCopy = FollowsConstraint(std::make_shared<IntegerArgument>(two),
            std::make_shared<StatementEntity>(s2));
    FollowsTConstraint ftc = FollowsTConstraint(std::make_shared<StatementEntity>(s1),
            std::make_shared<StatementEntity>(s2));
    FollowsTConstraint ftcCopy = FollowsTConstraint(std::make_shared<StatementEntity>(s1),
            std::make_shared<StatementEntity>(s2));
    // Add more constraints to test ConstraintOrderOptimizer
    FollowsConstraint fcConst = FollowsConstraint(std::make_shared<IntegerArgument>(two),
            std::make_shared<IntegerArgument>(three));
    CallsConstraint cc = CallsConstraint(std::make_shared<ProcedureEntity>(p1),
            std::make_shared<ProcedureEntity>(p2));
    shared_ptr<FollowsConstraint> firstConstraint = make_shared<FollowsConstraint>(fcConst);
    shared_ptr<FollowsConstraint> secondConstraint = make_shared<FollowsConstraint>(fc);
    shared_ptr<FollowsTConstraint> thirdConstraint = make_shared<FollowsTConstraint>(ftc);
    shared_ptr<CallsConstraint> fourthConstraint = make_shared<CallsConstraint>(cc);
    qo.addConstraint(fourthConstraint);
    qo.addConstraint(firstConstraint);
    qo.addConstraint(secondConstraint);
    qo.addConstraint(thirdConstraint);
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopy));
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopyCopy));
    qo.addConstraint(make_shared<FollowsTConstraint>(ftcCopy));
    REQUIRE(qo.getConstraints().size() == 7);

    chain.addOptimizer(std::make_unique<DuplicateRemovalOptimizer>(duplicateRemovalOptimizer));
    chain.addOptimizer(std::make_unique<ConstraintOrderOptimizer>(constraintOrderOptimizer));
    chain.optimize(qo);

    // Testing DuplicateRemovalOptimizer
    REQUIRE(qo.getConstraints().size() == 4);

    // Testing ConstraintOrderOptimizer
    REQUIRE(qo.getConstraints()[0] == firstConstraint);
    REQUIRE(qo.getConstraints()[1] == secondConstraint);
    REQUIRE(qo.getConstraints()[2] == thirdConstraint);
    REQUIRE(qo.getConstraints()[3] == fourthConstraint);

    // Test other optimizers here
}