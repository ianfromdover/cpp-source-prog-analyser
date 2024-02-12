//
// Created by Alex on 12/2/2024.
//

#include "Demo.h"
#include "qps/query_elements/constraint_argument/IntegerArgument.h"
#include "qps/query_elements/constraint_argument/StatementEntity.h"
#include "qps/query_elements/constraint/ParentConstraint.h"
#include "utilSpa/SpaTypes.h"

void Demo::demo() {
    //casting ConstraintArgument into intArgument, statementEntity
    //call IntegerArgument.value, StatementEntity.value

    IntegerArgument intArg(5);
    StatementEntity stmtEnt("s1");
    ParentConstraint c();

    ConstraintArgument a; // you somehow get a constraint argument

    if (a.getReferenceType() == REFERENCE_TYPE_STATEMENT) {
        //is a reference statement
        if (a.getEntityType() == RETURN_TYPE_STATEMENT) {
            // is a statement
            StatementEntity newStmt = dynamic_cast<StatementEntity>(a);
            newStmt.value; // get value
        } else if (a.getEntityType() == RETURN_TYPE_INTEGER) {
            // is a integer
            IntegerArgument newInt = dynamic_cast<IntegerArgument>(a);
            newInt.value; //get value
        }
    }

}
