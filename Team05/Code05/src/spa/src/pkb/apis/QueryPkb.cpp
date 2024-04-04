#include <utility>
#include "QueryPkb.h"
#include "common/TableUtils.h"
/**
 * TODO: implement
getPatternAsgnByStmt(StmtNo sNum) {
getPatternAsgnByLhs(VarName Lhs) {
getPatternAsgnByRhs(std::string Rhs) {
 */

QueryPkb::QueryPkb(std::shared_ptr<PkbStorage> p) {
    pkb = std::move(p);
}

// on-demand --------------------------------------------------------------
bool QueryPkb::checkAffects(StmtNo affector, StmtNo affected) {
    return false;
}
bool QueryPkb::checkNextT(StmtNo before, StmtNo after) {
    return false;
}
bool QueryPkb::resetAffects() {
    return false;
}
bool QueryPkb::resetNextT() {
    return false;
}

// entities --------------------------------------------------------------
Table QueryPkb::getCallTable() {
    return pkb->callTable->getAll();
}
Table QueryPkb::getCallAllStmts() {
    return pkb->callTable->getAllKeys();
}
Table QueryPkb::getCallAllProcs() {
    return pkb->callTable->getAllValues();
}
Table QueryPkb::getCallProcsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->callTable->getRelatedValues(sNum));
}
Table QueryPkb::getCallStmtsByProc(ProcName proc) {
    return TableUtils::toTable(pkb->callTable->getRelatedKeys(proc));
}

Table QueryPkb::getConstTable() {
    return pkb->constTable->getAll();
}
Table QueryPkb::getConstAllStmts() {
    return pkb->constTable->getAllKeys();
}
Table QueryPkb::getConstAllValues() {
    return pkb->constTable->getAllValues();
}
Table QueryPkb::getConstStmtsByVal(ConstVal val) {
    return TableUtils::toTable(pkb->constTable->getRelatedKeys(val));
}
Table QueryPkb::getConstValuesByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->constTable->getRelatedValues(sNum));
}

Table QueryPkb::getIfTable() {
    return pkb->patternIfTable->getAll();
}
Table QueryPkb::getIfAllStmts() {
    return pkb->patternIfTable->getAllKeys();
}
Table QueryPkb::getIfAllVars() {
    return pkb->patternIfTable->getAllValues();
}
Table QueryPkb::getIfVarsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->patternIfTable->getRelatedValues(sNum));
}
Table QueryPkb::getIfStmtsByVar(VarName var) {
    return TableUtils::toTable(pkb->patternIfTable->getRelatedKeys(var));
}

Table QueryPkb::getPrintTable() {
    return pkb->printTable->getAll();
}
Table QueryPkb::getPrintAllStmts() {
    return pkb->printTable->getAllKeys();
}
Table QueryPkb::getPrintAllVars() {
    return pkb->printTable->getAllValues();
}
Table QueryPkb::getPrintVarsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->printTable->getRelatedValues(sNum));
}
Table QueryPkb::getPrintStmtsByVar(VarName var) {
    return TableUtils::toTable(pkb->printTable->getRelatedKeys(var));
}

Table QueryPkb::getProcTable() {
    return pkb->procedureTable->getAll();
}
// should I add a containsProc method? for with clause

Table QueryPkb::getReadTable() {
    return pkb->readTable->getAll();
}
Table QueryPkb::getReadAllStmts() {
    return pkb->readTable->getAllKeys();
}
Table QueryPkb::getReadAllVars() {
    return pkb->readTable->getAllValues();
}
Table QueryPkb::getReadVarsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->readTable->getRelatedValues(sNum));
}
Table QueryPkb::getReadStmtsByVar(VarName var) {
    return TableUtils::toTable(pkb->readTable->getRelatedKeys(var));
}

Table QueryPkb::getStmtTable() {
    return pkb->statementTable->getAll();
}
// should i add a containsStmt method? for with clause

Table QueryPkb::getVarTable() {
    return pkb->varTable->getAll();
}
Table QueryPkb::getVarAllStmts() {
    return pkb->varTable->getAllKeys();
}
Table QueryPkb::getVarAllVars() {
    return pkb->varTable->getAllValues();
}
Table QueryPkb::getVarVarsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->varTable->getRelatedValues(sNum));
}
Table QueryPkb::getVarStmtsByVar(VarName var) {
    return TableUtils::toTable(pkb->varTable->getRelatedKeys(var));
}

Table QueryPkb::getWhileTable() {
    return pkb->patternWhileTable->getAll();
}
Table QueryPkb::getWhileAllStmts() {
    return pkb->patternWhileTable->getAllKeys();
}
Table QueryPkb::getWhileAllVars() {
    return pkb->patternWhileTable->getAllValues();
}
Table QueryPkb::getWhileVarsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->patternWhileTable->getRelatedValues(sNum));
}
Table QueryPkb::getWhileStmtsByVar(VarName var) {
    return TableUtils::toTable(pkb->patternWhileTable->getRelatedKeys(var));
}
// relations --------------------------------------------------------------

/*
// generated each query
Table QueryPkb::getAffectsTable() {
    return {{}}; // derive from the accepted affects object
}
Table QueryPkb::getAffectsAllAffectors() {
    return {{}}; // derive from the accepted affects object
}
Table QueryPkb::getAffectsAllAffected() {
    return {{}}; // derive from the accepted affects object
}
Table QueryPkb::getAffectsAffectedByAffector(StmtNo affector) {
    return {{}}; // derive from the accepted affects object
}
Table QueryPkb::getAffectsAffectorsByAffected(StmtNo affected) {
    return {{}}; // derive from the accepted affects object
}
 */

Table QueryPkb::getCallsTable() {
    return pkb->callsTable->getAll();
}
Table QueryPkb::getCallsAllCallers() {
    return pkb->callsTable->getAllKeys();
}
Table QueryPkb::getCallsAllCalled() {
    return pkb->callsTable->getAllValues();
}
Table QueryPkb::getCallsCalledByCaller(ProcName caller) {
    return TableUtils::toTable(pkb->callsTable->getRelatedValues(caller));
}
Table QueryPkb::getCallsCallerByCalled(ProcName called) {
    return TableUtils::toTable(pkb->callsTable->getRelatedKeys(called));
}

Table QueryPkb::getCallsTTable() {
    return pkb->callsTTable->getAll();
}
Table QueryPkb::getCallsTAllCallers() {
    return pkb->callsTTable->getAllKeys();
}
Table QueryPkb::getCallsTAllCalled() {
    return pkb->callsTTable->getAllValues();
}
Table QueryPkb::getCallsTCalledByCaller(ProcName caller) {
    return TableUtils::toTable(pkb->callsTTable->getRelatedValues(caller));
}
Table QueryPkb::getCallsTCallerByCalled(ProcName called) {
    return TableUtils::toTable(pkb->callsTTable->getRelatedKeys(called));
}

Table QueryPkb::getFollowsTable() {
    return pkb->followsTable->getAll();
}
Table QueryPkb::getFollowsAllBefore() {
    return pkb->followsTable->getAllKeys();
}
Table QueryPkb::getFollowsAllAfter() {
    return pkb->followsTable->getAllValues();
}
Table QueryPkb::getFollowsAfterByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->followsTable->getRelatedValues(before));
}
Table QueryPkb::getFollowsBeforeByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->followsTable->getRelatedKeys(after));
}

Table QueryPkb::getFollowsTTable() {
    return pkb->followsTTable->getAll();
}
Table QueryPkb::getFollowsTAllBefore() {
    return pkb->followsTTable->getAllKeys();
}
Table QueryPkb::getFollowsTAllAfter() {
    return pkb->followsTTable->getAllValues();
}
Table QueryPkb::getFollowsTAfterByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->followsTTable->getRelatedValues(before));
}
Table QueryPkb::getFollowsTBeforeByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->followsTTable->getRelatedKeys(after));
}

Table QueryPkb::getModifiesPTable() {
    return pkb->modifiesPTable->getAll();
}
Table QueryPkb::getModifiesPAllProcs() {
    return pkb->modifiesPTable->getAllKeys();
}
Table QueryPkb::getModifiesPAllVars() {
    return pkb->modifiesPTable->getAllValues();
}
Table QueryPkb::getModifiesPVarsByProc(ProcName modifier) {
    return TableUtils::toTable(pkb->modifiesPTable->getRelatedValues(modifier));
}
Table QueryPkb::getModifiesPProcsByVar(VarName modified) {
    return TableUtils::toTable(pkb->modifiesPTable->getRelatedKeys(modified));
}
bool QueryPkb::isModifiesP(ProcName p, VarName v) {
    return pkb->modifiesPTable->containsPair(p, v);
}

Table QueryPkb::getModifiesSTable() {
    return pkb->modifiesSTable->getAll();
}
Table QueryPkb::getModifiesSAllStmts() {
    return pkb->modifiesSTable->getAllKeys();
}
Table QueryPkb::getModifiesSAllVars() {
    return pkb->modifiesSTable->getAllValues();
}
Table QueryPkb::getModifiesSVarsByStmt(StmtNo modifier) {
    return TableUtils::toTable(pkb->modifiesSTable->getRelatedValues(modifier));
}
Table QueryPkb::getModifiesSStmtsByVar(VarName modified) {
    return TableUtils::toTable(pkb->modifiesSTable->getRelatedKeys(modified));
}

Table QueryPkb::getNextTable() {
    return pkb->nextTable->getAll();
}
Table QueryPkb::getNextAllBefore() {
    return pkb->nextTable->getAllKeys();
}
Table QueryPkb::getNextAllAfter() {
    return pkb->nextTable->getAllValues();
}
Table QueryPkb::getNextAfterByBefore(StmtNo before) {
    return TableUtils::toTable(pkb->nextTable->getRelatedValues(before));
}
Table QueryPkb::getNextBeforeByAfter(StmtNo after) {
    return TableUtils::toTable(pkb->nextTable->getRelatedKeys(after));
}

/*
// generated each query
Table QueryPkb::getNextTTable() {
    return {{}}; // derive from the accepted nextT object
}
Table QueryPkb::getNextTAllBefore() {
    return {{}}; // derive from the accepted nextT object
}
Table QueryPkb::getNextTAllAfter() {
    return {{}}; // derive from the accepted nextT object
}
Table QueryPkb::getNextTAfterByBefore(StmtNo before) {
    return {{}}; // derive from the accepted nextT object
}
Table QueryPkb::getNextTBeforeByAfter(StmtNo after) {
    return {{}}; // derive from the accepted nextT object
}
 */

Table QueryPkb::getParentTable() {
    return pkb->parentTable->getAll();
}
Table QueryPkb::getParentAllChildren() {
    return pkb->parentTable->getAllKeys();
}
Table QueryPkb::getParentAllParents() {
    return pkb->parentTable->getAllValues();
}
Table QueryPkb::getParentChildByParent(StmtNo parent) {
    return TableUtils::toTable(pkb->parentTable->getRelatedValues(parent));
}
Table QueryPkb::getParentParentByChild(StmtNo child) {
    return TableUtils::toTable(pkb->parentTable->getRelatedKeys(child));
}

Table QueryPkb::getParentTTable() {
    return pkb->parentTTable->getAll();
}
Table QueryPkb::getParentTAllChildren() {
    return pkb->parentTTable->getAllKeys();
}
Table QueryPkb::getParentTAllParents() {
    return pkb->parentTTable->getAllValues();
}
Table QueryPkb::getParentTChildByParent(StmtNo parent) {
    return TableUtils::toTable(pkb->parentTTable->getRelatedValues(parent));
}
Table QueryPkb::getParentTParentByChild(StmtNo child) {
    return TableUtils::toTable(pkb->parentTTable->getRelatedKeys(child));
}

Table QueryPkb::getPatternAsgnTable() {
    return pkb->patternAssignTable->getAllAsStrings();
}
Table QueryPkb::getPatternAsgnByStmt(StmtNo sNum) {
    // TODO: implement
    return {{}}; // 2-col map needed
}
Table QueryPkb::getPatternAsgnByLhs(VarName Lhs) {
    return {{}}; // 2-col map needed
}
Table QueryPkb::getPatternAsgnByRhs(std::string Rhs) {
    return {{}}; // 2-col map needed
}

Table QueryPkb::getPatternIfTable() {
    return pkb->patternIfTable->getAll();
}
Table QueryPkb::getPatternIfAllStmts() {
    return pkb->patternIfTable->getAllKeys();
}
Table QueryPkb::getPatternIfAllVars() {
    return pkb->patternIfTable->getAllValues();
}
Table QueryPkb::getPatternIfVarsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->patternIfTable->getRelatedValues(sNum));
}
Table QueryPkb::getPatternIfStmtsByVar(VarName var) {
    return TableUtils::toTable(pkb->patternIfTable->getRelatedKeys(var));
}

Table QueryPkb::getPatternWhileTable() {
    return pkb->patternWhileTable->getAll();
}
Table QueryPkb::getPatternWhileAllStmts() {
    return pkb->patternWhileTable->getAllKeys();
}
Table QueryPkb::getPatternWhileAllVars() {
    return pkb->patternWhileTable->getAllValues();
}
Table QueryPkb::getPatternWhileVarsByStmt(StmtNo sNum) {
    return TableUtils::toTable(pkb->patternWhileTable->getRelatedValues(sNum));
}
Table QueryPkb::getPatternWhileStmtsByVar(VarName var) {
    return TableUtils::toTable(pkb->patternWhileTable->getRelatedKeys(var));
}

Table QueryPkb::getUsesPTable() {
    return pkb->usesPTable->getAll();
}
Table QueryPkb::getUsesPAllProcs() {
    return pkb->usesPTable->getAllKeys();
}
Table QueryPkb::getUsesPAllVars() {
    return pkb->usesPTable->getAllValues();
}
Table QueryPkb::getUsesPVarsByProc(ProcName user) {
    return TableUtils::toTable(pkb->usesPTable->getRelatedValues(user));
}
Table QueryPkb::getUsesPProcsByVar(VarName used) {
    return TableUtils::toTable(pkb->usesPTable->getRelatedKeys(used));
}

Table QueryPkb::getUsesSTable() {
    return pkb->usesSTable->getAll();
}
Table QueryPkb::getUsesSAllStmts() {
    return pkb->usesSTable->getAllKeys();
}
Table QueryPkb::getUsesSAllVars() {
    return pkb->usesSTable->getAllValues();
}
Table QueryPkb::getUsesSVarsByStmt(StmtNo user) {
    return TableUtils::toTable(pkb->usesSTable->getRelatedValues(user));
}
Table QueryPkb::getUsesSStmtsByVar(VarName used) {
    return TableUtils::toTable(pkb->usesSTable->getRelatedKeys(used));
}
