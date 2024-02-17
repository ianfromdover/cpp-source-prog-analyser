#pragma once
#define SPA_POPULATEPKB_H
#include <memory>
//#include "utilSpa/SpaTypes.h"
#include "pkb/PKBStorage.h"

using namespace std;

// The interface between PKB and SP
class PopulatePKB {
private:
    shared_ptr<PKBStorage> pkb;
public:
    PopulatePKB(shared_ptr<PKBStorage> p);
    // Returns true if PKBStorage exists
    bool exists();
    // -- Add Entities --
    // relationships

    bool addRead(StmtNo sNum, VarName name);
    bool addCallStmt(StmtNo sNum, ProcName name);
    // implement using set
    bool addIf(StmtNo sNum, VarName ctrlVarName);
    // implement using set
    bool addWhile(StmtNo sNum, VarName ctrlVarName);
    bool addAssign(StmtNo sNum, VarName LhsVarName);
    bool addPrint(StmtNo s, VarName name);
    bool addFinalStatementNo(StmtNo s);
    bool addProcedure(StmtNo sNum, Str procedureName); // future: should this have an associated StmtList?
    bool addVar(StmtNo sNum, VarName name);
    bool addConst(StmtNo sNum, ConstVal c);

    // -- Add Abstractions --
    // Adds a follows relationship to the follows table
    bool addFollows(StmtNo before, StmtNo after);
    bool addFollowsT(StmtNo before, StmtNo after);
    // Adds a parent relationship to the parent table
    bool addParent(StmtNo parent, StmtNo child); // parent is s1, child is s2
    bool addParentT(StmtNo ancestor, StmtNo descendant);
    // Adds a uses relationship to the uses table
    bool addUses(StmtNo sNum, VarName name);
    bool addUses(ProcName ProcedureName, VarName name);
    // Adds a modifies relationship to the modifies table
    bool addModifies(StmtNo sNum, VarName name);
    bool addModifies(ProcName ProcedureName, VarName name);
    bool addPatternAsgn(StmtNo sNum, Str lhs, Str rhsBracketed);
};
