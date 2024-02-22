#pragma once
#define SPA_POPULATEPKB_H
#include <memory>
//#include "utilSpa/SpaTypes.h"
#include "pkb/PKBStorage.h"
#include "PKBApi.h"

using namespace std;

// The interface between PKB and SP
class PopulatePKB : public PKBApi {
private:
    shared_ptr<PKBStorage> pkb;
public:
    PopulatePKB(shared_ptr<PKBStorage> p);
    // Returns true if PKBStorage exists
    bool exists();
    // -- Add Entities --
    // relationships

    bool addRead(StmtNo sNum, VarName name) override;
    bool addCallStmt(StmtNo sNum, ProcName name) override;
    // implement using set
    bool addIf(StmtNo sNum, VarName ctrlVarName) override;
    // implement using set
    bool addWhile(StmtNo sNum, VarName ctrlVarName) override;
    bool addAssign(StmtNo sNum, VarName LhsVarName) override;
    bool addPrint(StmtNo s, VarName name) override;
    bool addFinalStatementNo(StmtNo s) override;
    bool addProcedure(Str procedureName) override; // future: should this have an associated StmtList?
    bool addVar(StmtNo sNum, VarName name) override;
    bool addConst(StmtNo sNum, ConstVal c) override;

    // -- Add Abstractions --
    // Adds a follows relationship to the follows table
    bool addFollows(StmtNo before, StmtNo after) override;
    bool addFollowsT(StmtNo before, StmtNo after) override;
    // Adds a parent relationship to the parent table
    bool addParent(StmtNo parent, StmtNo child) override; // parent is s1, child is s2
    bool addParentT(StmtNo ancestor, StmtNo descendant) override;
    // Adds a uses relationship to the uses table
    bool addUses(StmtNo sNum, VarName name) override;
    bool addUses(ProcName ProcedureName, VarName name) override;
    // Adds a modifies relationship to the modifies table
    bool addModifies(StmtNo sNum, VarName name) override;
    bool addModifies(ProcName ProcedureName, VarName name) override;
    bool addPatternAsgn(StmtNo sNum, Str lhs, Str rhsBracketed) override;

};
