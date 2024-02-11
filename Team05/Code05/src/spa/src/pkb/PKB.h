#pragma once

#define SPA_PKB_H
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "utilSpa/SpaTypes.h"
#include "pkb/constraintTables/ParentTable.h"

using namespace std;

class VarTable;  // no need to #include "VarTable.h" as all I need is pointer

class PKB {
private:
    shared_ptr<ParentTable> parentTable; // does this initialise?
public:
    PKB();
    // TODO: Add a fn to Instantiate all Tables here, then call in TestWrapper
	static VarTable* varTable;

};
