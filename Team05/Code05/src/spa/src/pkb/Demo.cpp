//
// Created by Alex on 12/2/2024.
//

#include "Demo.h"
#include "qps/query_elements/constraint_argument/IntegerArgument.h"
#include "qps/query_elements/constraint_argument/StatementEntity.h"
#include "qps/query_elements/constraint/ParentConstraint.h"

void Demo::demo() {
    //casting ConstraintArgument into intArgument, statementEntity
    //call IntegerArgument.value, StatementEntity.value

    IntegerArgument intArg(5);
    StatementEntity stmtEnt("s1");


    ParentConstraint c();

}
