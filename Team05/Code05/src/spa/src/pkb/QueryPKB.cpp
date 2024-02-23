#include "PKBStorage.h"
#include "QueryPKB.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"
#include "qps/query_elements/constraint_argument/statement_reference/IntegerArgument.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"

QueryPKB::QueryPKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

QueryPKB::~QueryPKB() {}


//bool QueryPKB::getFollows(StmtNo before, StmtNo after) {
//    return false;
//}
//bool QueryPKB::getParent(StmtNo parent, StmtNo child) {
//    return false;
//}

//vector<StmtNo> QueryPKB::getChildren(StmtNo parent) {
//    return pkb->parentTable->getChildren(parent);
//}
//
//StmtNo QueryPKB::getParent(StmtNo child) {
//    return pkb->parentTable->getParent(child);
//}

std::shared_ptr<QueryResult> QueryPKB::getResult(Returnable &r, Constraint &c) {
    if (r.getReturnType() == RETURN_TYPE_STATEMENT) {
        vector<shared_ptr<ConstraintArgument>> argList = c.getConstraintArguments();
        std::shared_ptr<QueryResult> finalResult;
        std::string type = c.getConstraintType();
        if (type == CONSTRAINT_TYPE_PARENT) {
            finalResult = queryParentTable(r, argList);
        } else if (type == CONSTRAINT_TYPE_PARENTT) {
            finalResult = queryParentTTable(argList);
        } else if (type == CONSTRAINT_TYPE_FOLLOWS) {
            finalResult = queryFollowsTable(argList);
        } else if (type == CONSTRAINT_TYPE_FOLLOWST) {
            finalResult = queryFollowsTTable(argList);
        } else if (type == CONSTRAINT_TYPE_USESS) {
            finalResult = queryUsesTable(argList);
        } else if (type == CONSTRAINT_TYPE_MODIFIESS) {
            finalResult = queryModifiesSTable(argList);
        } else if (type == CONSTRAINT_TYPE_MODIFIESP) {
            finalResult = queryModifiesPTable(argList);
        } else {
            finalResult = {};
        }
//        std::vector<int> converted;

//        for (auto k : results){
//            converted.push_back(static_cast<int>(k));
//        }
        return finalResult;
    }

    return {};
}

// TODO: refactor after MS1
// TODO: making it return the correct things
std::shared_ptr<QueryResult> QueryPKB::queryParentTable(Returnable &r, vector<shared_ptr<ConstraintArgument>> argList) {
    // this is assuming that Returnable is statement number
    if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
//        if (r.getReturnType() == bool) {
//            // does not work for now
//        }
        // finding children of line number
        std::vector<int> results;
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[0]);
        int i = newInt->value; //get value
        results = pkb->parentTable->getChildren(i);
        IntResult res(results);
        return std::make_shared<IntResult>(res);
    } else {
        // finding parent of line number
        std::vector<int> results;
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[1]);
        int i = newInt->value; //get value
        results.push_back(pkb->parentTable->getParent(i));
        IntResult res(results);
        return std::make_shared<IntResult>(res);
    }
}

std::shared_ptr<QueryResult> QueryPKB::queryParentTTable(vector<shared_ptr<ConstraintArgument>> argList) {
    std::vector<int> results;
    if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
        // finding childrenT of line number
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[0]);
        int i = newInt->value; //get value
        results = pkb->parentTTable->getChildrenT(i);
    } else {
        // finding parentsT of line number
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[1]);
        int i = newInt->value; //get value
        results = pkb->parentTTable->getParentsT(i);
    }
    IntResult res(results);
    return std::make_shared<IntResult>(res);
}

std::shared_ptr<QueryResult> QueryPKB::queryFollowsTable(vector<shared_ptr<ConstraintArgument>> argList) {
    std::vector<int> results;
    if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
        // finding the statement number which Follows argList[0]
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[0]);
        int i = newInt->value; //get value
        results.push_back(pkb->followsTable->getFollower(i));
    } else {
        // finding what statement is before argList[1]
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[1]);
        int i = newInt->value; //get value
        results.push_back(pkb->followsTable->getStmtBefore(i));
    }
    IntResult res(results);
    return std::make_shared<IntResult>(res);
}

std::shared_ptr<QueryResult> QueryPKB::queryFollowsTTable(vector<shared_ptr<ConstraintArgument>> argList) {
    std::vector<int> results;
    if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
        // finding the statement number which Follows argList[0]
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[0]);
        int i = newInt->value; //get value
        results = pkb->followsTTable->getFollowersT(i);
    } else {
        // finding what statement is before argList[1]
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[1]);
        int i = newInt->value; //get value
        results = pkb->followsTTable->getStmtsBefore(i);
    }
    IntResult res(results);
    return std::make_shared<IntResult>(res);
}

std::shared_ptr<QueryResult> QueryPKB::queryUsesTable(vector<shared_ptr<ConstraintArgument>> argList) {
    std::vector<int> results;
    if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
        // finding what variable(s) argList[0] uses
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[0]);
        int i = newInt->value; //get value
//        results = pkb->usesTable->getUses(i); // glue code //TODO
    } else {
        // finding what variable(s) argList[1] is used by
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[1]);
        int i = newInt->value; //get value
//        results.push_back(pkb->usesTable->getUsedBy(i)); // glue code //TODO
    }
    IntResult res(results);
    return std::make_shared<IntResult>(res);
}

std::shared_ptr<QueryResult> QueryPKB::queryModifiesSTable(vector<shared_ptr<ConstraintArgument>> argList) {

    // TODO: separate each different argument type and call the appropriate table inside modifiesTable class.
    // TODO: how to check diff combinations????

    if (argList[0]->getEntityType() == RETURN_TYPE_INTEGER) {
        std::vector<VarName> resultsV;
        // finding what variable(s) argList[0] modifies
        // assume this is for read statements
        std::shared_ptr<IntegerArgument> newInt = std::dynamic_pointer_cast<IntegerArgument>(argList[0]);
        int i = newInt->value; //get value
        resultsV = pkb->modifiesTable->getModifiedS(pkb->modifiesTable->getReadMap(), i);
        StringResult res(resultsV);
        return std::make_shared<StringResult>(res);
    } else {
        std::vector<StmtNo> resultsS;
        // finding what variable(s) argList[1] is modified by
        // assume this is for read statements
        std::shared_ptr<StatementEntity> newVar = std::dynamic_pointer_cast<StatementEntity>(argList[1]);
        VarName v = newVar->value;
        resultsS = pkb->modifiesTable->getModifiersS(pkb->modifiesTable->getReadMap(), v);
        IntResult res(resultsS);
        return std::make_shared<IntResult>(res);
    }
}

shared_ptr<QueryResult> QueryPKB::queryModifiesPTable(vector<shared_ptr<ConstraintArgument>> argList) {
    if (argList[0]->getEntityType() == RETURN_TYPE_WILDCARD) {
        std::vector<ProcName> resultsP;
        // finding what variable(s) argList[1] is modified by
        std::shared_ptr<StatementEntity> newVar = std::dynamic_pointer_cast<StatementEntity>(argList[1]);
        VarName v = newVar->value;
        resultsP = pkb->modifiesTable->getModifiersP(v);
        StringResult res(resultsP);
        return std::make_shared<StringResult>(res);
    } else {
        std::vector<VarName> resultsV;
        // finding what variable(s) argList[0] modifies
        std::shared_ptr<StatementEntity> newProc = std::dynamic_pointer_cast<StatementEntity>(argList[1]);
        ProcName p = newProc->value;
        resultsV = pkb->modifiesTable->getModifiedP(p);
        StringResult res(resultsV);
        return std::make_shared<StringResult>(res);
    }
}
