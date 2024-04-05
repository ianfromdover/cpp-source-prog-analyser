//
// Created by yewme on 27/3/2024.
//

#include "catch.hpp"
#include "qps/query_optimizer/concrete_optimizers/DuplicateRemovalOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/ParentConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/CallsConstraint.h"
#include "qps/query_elements/constraint_argument/entity_reference/ProcedureEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"

TEST_CASE("Test duplicate remover for the same constraint type") {
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

TEST_CASE("Test duplicate remover for different constraint types") {
    IntegerArgument two(2);
    IntegerArgument three(3);
    IntegerArgument four(4);
    FollowsConstraint fc = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                             std::make_shared<IntegerArgument>(three));
    FollowsTConstraint ftc = FollowsTConstraint(std::make_shared<IntegerArgument>(two),
                                                 std::make_shared<IntegerArgument>(three));
    ParentConstraint pc = ParentConstraint(std::make_shared<IntegerArgument>(three),
                                                     std::make_shared<IntegerArgument>(four));
    QueryObject qo = QueryObject();
    qo.addConstraint(make_shared<FollowsConstraint>(fc));
    qo.addConstraint(make_shared<FollowsTConstraint>(ftc));
    qo.addConstraint(make_shared<ParentConstraint>(pc));
    DuplicateRemovalOptimizer optimizer;
    REQUIRE(qo.getConstraints().size() == 3);
    shared_ptr<Constraint> fcElement = qo.getConstraints()[0];
    optimizer.optimize(qo);
    shared_ptr<Constraint> fcElementAfter = qo.getConstraints()[0];
    REQUIRE(qo.getConstraints().size() == 3);
    REQUIRE(fcElement == fcElementAfter);
}

TEST_CASE("Test duplicate remover for different constraint types with duplicates") {
    IntegerArgument two(2);
    IntegerArgument three(3);
    IntegerArgument four(4);
    FollowsConstraint fc = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                             std::make_shared<IntegerArgument>(three));
    FollowsConstraint fcCopy = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                                 std::make_shared<IntegerArgument>(three));
    FollowsConstraint fcCopyCopy = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                                     std::make_shared<IntegerArgument>(three));
    FollowsTConstraint ftc = FollowsTConstraint(std::make_shared<IntegerArgument>(two),
                                                std::make_shared<IntegerArgument>(three));
    ParentConstraint pc = ParentConstraint(std::make_shared<IntegerArgument>(three),
                                           std::make_shared<IntegerArgument>(four));
    QueryObject qo = QueryObject();
    qo.addConstraint(make_shared<FollowsConstraint>(fc));
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopy));
    qo.addConstraint(make_shared<FollowsConstraint>(fcCopyCopy));
    qo.addConstraint(make_shared<FollowsTConstraint>(ftc));
    qo.addConstraint(make_shared<ParentConstraint>(pc));
    DuplicateRemovalOptimizer optimizer;
    REQUIRE(qo.getConstraints().size() == 5);
    shared_ptr<Constraint> fcElement = qo.getConstraints()[0];
    optimizer.optimize(qo);
    shared_ptr<Constraint> fcElementAfter = qo.getConstraints()[0];
    REQUIRE(qo.getConstraints().size() == 3);
    REQUIRE(fcElement == fcElementAfter);
}

TEST_CASE("Test duplicate remover for expression types") {
    ProcedureEntity p1("proc1");
    ProcedureEntity p2("proc2");
    ProcedureEntity p3("proc3");
    CallsConstraint cc1 = CallsConstraint(std::make_shared<ProcedureEntity>(p1),
            std::make_shared<ProcedureEntity>(p2));
    CallsConstraint cc1Copy = CallsConstraint(std::make_shared<ProcedureEntity>(p1),
            std::make_shared<ProcedureEntity>(p2));
    CallsConstraint cc2 = CallsConstraint(std::make_shared<ProcedureEntity>(p2),
            std::make_shared<ProcedureEntity>(p3));
    QueryObject qo = QueryObject();
    qo.addConstraint(make_shared<CallsConstraint>(cc1));
    qo.addConstraint(make_shared<CallsConstraint>(cc1Copy));
    qo.addConstraint(make_shared<CallsConstraint>(cc2));
    DuplicateRemovalOptimizer optimizer;
    REQUIRE(qo.getConstraints().size() == 3);
    shared_ptr<Constraint> fcElement = qo.getConstraints()[0];
    optimizer.optimize(qo);
    shared_ptr<Constraint> fcElementAfter = qo.getConstraints()[0];
    REQUIRE(qo.getConstraints().size() == 2);
    REQUIRE(fcElement == fcElementAfter);
}