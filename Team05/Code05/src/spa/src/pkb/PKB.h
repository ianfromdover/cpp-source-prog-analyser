#pragma once

#define SPA_PKB_H
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "utilSpa/SpaTypes.h"
#include "entityTables/StmtTable.h"
#include "entityTables/ParentTable.h"

using namespace std;

class TNode;

class VarTable;  // no need to #include "VarTable.h" as all I need is pointer

class PKB {
private:
    shared_ptr<StmtTable> stmtTable;
    shared_ptr<ParentTable> parentTable;
public:
    // TODO: Add a fn to Instantiate all Tables here, then call in TestWrapper
	static VarTable* varTable;

};