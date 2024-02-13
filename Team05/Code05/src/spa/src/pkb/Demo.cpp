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

    std::shared_ptr<ConstraintArgument> a; // you somehow get a constraint argument

    if (a->getReferenceType() == REFERENCE_TYPE_STATEMENT) {
        //is a reference statement
        if (a->getEntityType() == RETURN_TYPE_STATEMENT) {
            // is a statement
            std::shared_ptr<StatementEntity> newStmt = std::dynamic_pointer_cast<StatementEntity>(a);
            std::string s1 = newStmt->getIdentifier(); // get declaration identifier
        } else if (a->getEntityType() == RETURN_TYPE_INTEGER) {
            // is a integer
            std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(a);
            int i = newInt->value; //get value
        }
    }

}
