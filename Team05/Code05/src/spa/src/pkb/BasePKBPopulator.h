#pragma once
#define SPA_BASEPKBPOPULATOR_H

#include "utilSpa/SpaTypes.h"

class BasePKBPopulator {
public:
    virtual bool addRead(StmtNo sNum, VarName name) = 0;
    virtual bool addCallStmt(StmtNo sNum, ProcName name) = 0;
    virtual bool addIf(StmtNo sNum, VarName ctrlVarName) = 0;
    virtual bool addWhile(StmtNo sNum, VarName ctrlVarName) = 0;
    virtual bool addPrint(StmtNo s, VarName name) = 0;
    virtual bool addFinalStatementNo(StmtNo s) = 0;
    virtual bool addProcedure(Str procedureName) = 0; // future: should this have an associated StmtList?
    virtual bool addVar(StmtNo sNum, VarName name) = 0;
    virtual bool addConst(StmtNo sNum, ConstVal c) = 0;

    // -- Add Abstractions --
    virtual bool addFollows(StmtNo before, StmtNo after) = 0;
    virtual bool addFollowsT(StmtNo before, StmtNo after) = 0;
    virtual bool addParent(StmtNo parent, StmtNo child) = 0;
    virtual bool addParentT(StmtNo ancestor, StmtNo descendant) = 0;
    virtual bool addUses(StmtNo sNum, VarName name) = 0;
    virtual bool addUses(ProcName ProcedureName, VarName name) = 0;
    virtual bool addModifies(StmtNo sNum, VarName name) = 0;
    virtual bool addModifies(ProcName ProcedureName, VarName name) = 0;
    virtual bool addPatternAsgn(StmtNo sNum, VarName LhsVarName, Str RhsExpression) = 0;

    virtual ~BasePKBPopulator() = default; // Ensure there's a virtual destructor
};

