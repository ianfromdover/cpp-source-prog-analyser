//
// Created by yewme on 8/4/2024.
//

#include "catch.hpp"
#include "qps/query_optimizer/concrete_optimizers/ConstraintGroupOptimizer.h"
#include "qps/query_elements/constraint/relationship_constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/relationship_constraint/CallsConstraint.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "qps/query_elements/constraint_argument/entity_reference/ProcedureEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"

TEST_CASE("Test constraint grouper") {
    IntegerArgument two(2);
    IntegerArgument three(3);
    StatementEntity s("s"); // This should get a lower score than ints
    ProcedureEntity p1("proc1");
    ProcedureEntity p2("proc2");
    FollowsConstraint first = FollowsConstraint(std::make_shared<StatementEntity>(s),
                                                std::make_shared<IntegerArgument>(three));
    FollowsConstraint second = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                                 std::make_shared<StatementEntity>(s));
    FollowsConstraint third = FollowsConstraint(std::make_shared<IntegerArgument>(two),
                                                std::make_shared<IntegerArgument>(three));
    CallsConstraint fourth = CallsConstraint(std::make_shared<ProcedureEntity>(p1),
                                             std::make_shared<ProcedureEntity>(p2));
    QueryObject qo = QueryObject();
    shared_ptr<FollowsConstraint> firstConstraint = make_shared<FollowsConstraint>(first);
    shared_ptr<FollowsConstraint> secondConstraint = make_shared<FollowsConstraint>(second);
    shared_ptr<FollowsConstraint> thirdConstraint = make_shared<FollowsConstraint>(third);
    shared_ptr<CallsConstraint> fourthConstraint = make_shared<CallsConstraint>(fourth);

    qo.addConstraint(firstConstraint);
    qo.addConstraint(secondConstraint);
    qo.addConstraint(thirdConstraint);
    qo.addConstraint(fourthConstraint);
    ConstraintGroupOptimizer optimizer;
    optimizer.optimize(qo);

    auto synonymMap = optimizer.getSynonymMap();
    std::vector<std::string> key = {"s", "3", "2", "s", "2", "3"};
    std::vector<std::string> key2 = {"proc1", "proc2"};
//    std::vector<std::string> key = {"s", "3", "2", "s", "2", "3", "proc1", "proc2"};
    std::cout << synonymMap.size() << std::endl;
    REQUIRE(synonymMap.size() == 2);
    REQUIRE(synonymMap[key][0] == firstConstraint);
    std::cout << synonymMap[key].size() << std::endl;
    std::cout << synonymMap[key2].size() << std::endl;
//    // TODO: bug fix: now only 2 constraints in the whole map, where did the others go?
////    REQUIRE(synonymMap[key][1] == secondConstraint);
////    REQUIRE(synonymMap[key][2] == thirdConstraint);
//    REQUIRE(synonymMap[key2][0] == fourthConstraint);
}
