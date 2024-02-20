#include "PKBStorage.h"
#include "QueryPKB.h"
#include "constraintTables/ParentTable.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"

QueryPKB::QueryPKB(std::shared_ptr<PKBStorage> p) {
    pkb = p;
}

QueryPKB::~QueryPKB() {}

PKBStorage pkb;
ParentTable pt;

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

std::shared_ptr<QueryResult> QueryPKB::getResult(Returnable &r, Constraint &c) {
    if (r.getReturnType() == RETURN_TYPE_STATEMENT
            && c.getConstraintType() == CONSTRAINT_TYPE_PARENT) {
        vector<shared_ptr<ConstraintArgument>> argList = c.getConstraintArguments();
        std::vector<int > results;
        if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
            // finding children of line number
            std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[0]);
            int i = newInt->value; //get value
            results = pkb->parentTable->getChildren(i);
        } else {
            // finding parent of line number
            std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[1]);
            int i = newInt->value; //get value
            results.push_back(pkb->parentTable->getParent(i));
        }
//        std::vector<int> converted;

//        for (auto k : results){
//            converted.push_back(static_cast<int>(k));
//        }

        IntResult res(results);
        std::shared_ptr<QueryResult> result1 = std::make_shared<IntResult>(res);
        return result1;
    }

    return {};
}
