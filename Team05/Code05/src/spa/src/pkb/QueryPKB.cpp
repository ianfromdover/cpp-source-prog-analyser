#include "PKBStorage.h"
#include "QueryPKB.h"
#include "constraintTables/ParentTable.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"

QueryPKB::QueryPKB() {}
QueryPKB::~QueryPKB() {}

PKBStorage pkb;
ParentTable pt;
ParentTConstraint ptc;

bool QueryPKB::getFollows(StmtNo before, StmtNo after) {
    return false;
}
bool QueryPKB::getParent(StmtNo parent, StmtNo child) {
    return false;
}

vector<StmtNo> QueryPKB::getChildren(StmtNo parent) {
    return pt.getChildren(parent);
}

StmtNo QueryPKB::getParent(StmtNo child) {
    return pt.getParent(child);
}

std::vector<ConstraintArgument *> QueryPKB::getContraintArgs()  {
    return ptc.getConstraintArguments();
}

std::shared_ptr<QueryResult> QueryPKB::getResult(Returnable &r, Constraint &c) {
    if (r.getReturnType() == RETURN_TYPE_STATEMENT
            && c.getConstraintType() == CONSTRAINT_TYPE_PARENT) {
        std::vector<ConstraintArgument*> argList = c.getConstraintArguments();
        std::vector<int> results;
        if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
            // finding children of line number
            results = pkb.parentTable->getChildren(argList[0]->getArgumentValue()); //TODO: fix after merge
        } else {
            // finding parent of line number
            results[0] = pkb.parentTable->getParent(argList[0]->getArgumentValue());
        }
        IntResult res(results);
        std::shared_ptr<QueryResult> result1 = std::make_shared<IntResult>(res);
        return result1;
    }

}
