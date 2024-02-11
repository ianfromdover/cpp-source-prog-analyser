#pragma once

#define SPA_PKB_H
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "utilSpa/SpaTypes.h"
#include "pkb/constraintTables/ParentTable.h"

using namespace std;

class PKB {
private:
public:
    PKB();
    // TODO: Add a fn to Instantiate all Tables here, then call in TestWrapper
    // TODO: Use Singleton pattern?

    shared_ptr<ParentTable> parentTable; // does this initialise?
};
