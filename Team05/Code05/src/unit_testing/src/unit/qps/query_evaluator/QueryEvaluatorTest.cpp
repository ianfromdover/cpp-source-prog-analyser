//
// Created by tohzh on 21/2/2024.
//

#include "qps/QueryEvaluator/QueryEvaluator.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
#include "qps/query_elements/QueryObject.h"
#include "qps/query_builder/ConstraintArgCreator.h"
#include "qps/query_elements/constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/ParentConstraint.h"
#include "qps/query_elements/constraint/ConcretePatternConstraint.h"
#include "stub/QueryPKBStub.h"
#include "catch.hpp"
#include <iostream>

using namespace std;


//TEST_CASE("QueryEvaluator_singleQuery_returnsResult") {
//    QueryObject qo;
//    std::shared_ptr<StatementEntity> s = ConstraintArgCreator::createStatementEntity("s");
//    std::shared_ptr<AssignEntity> a = ConstraintArgCreator::createAssignEntity("a");
//    qo.addDeclaration(s);
//    qo.addDeclaration(a);
//    std::shared_ptr<ParentConstraint> parentConst = make_shared<ParentConstraint>(s,a);
//    qo.addConstraint(parentConst);
//    QueryPKBStub stub;
//    auto eval = QueryEvaluator(stub);
//    shared_ptr<Formattable> formattable = eval.evaluate(qo);
//
//    REQUIRE(formattable->toString() == "a, b, c, f");
//}

//TEST_CASE("QueryEvaluator_oneConstraintOnePattern_returnsResult") {
//    QueryObject qo;
//    std::shared_ptr<StatementEntity> s = ConstraintArgCreator::createStatementEntity("s");
//    std::shared_ptr<AssignEntity> a = ConstraintArgCreator::createAssignEntity("a");
//    qo.addDeclaration(s);
//    qo.addDeclaration(a);
//    std::shared_ptr<ParentConstraint> parentConst = make_shared<ParentConstraint>(s,a);
//    qo.addConstraint(parentConst);
//
//    std::shared_ptr<ProcedureEntity> e = ConstraintArgCreator::createProcedureEntity("e");
//    std::shared_ptr<Expression> exp = ConstraintArgCreator::createExpression("five");
//    qo.addDeclaration(e);
//    std::shared_ptr<ConcretePatternConstraint> pattern = make_shared<ConcretePatternConstraint>(e, exp, a);
//    qo.addConstraint(pattern);
//
//    QueryPKBStub stub;
//    auto eval = QueryEvaluator(stub);
//    shared_ptr<Formattable> formattable = eval.evaluate(qo);
//
//    REQUIRE(formattable->toString() == "c, f");
//}