#pragma once
#define SPA_POPULATEPKB_H
#include "utilSpa/SpaTypes.h"

using namespace std;

// The interface between PKB and SP
class PopulatePKB {
private:
public:
    // ai-gen start (copilot, 2, e)
    // prompt: used copilot

    // -- Add Entities --
    // Adds a variable to the variable table
    static bool addVar();

    // Adds a constant to the constant table
    static bool addConst();

    // Adds a procedure to the procedure table
    static bool addProcedure();

    // Adds a statement to the statement table
    static bool addStmt(StmtNo stmtNo, Str stmtType, ProcId procIndex);

    // -- Add Abstractions --
    // Adds a follows relationship to the follows table
    static bool addFollows();

    // Adds a parent relationship to the parent table
    static bool addParent(StmtNo parent, StmtNo child); // parent is s1, child is s2

    // Adds a uses relationship to the uses table
    static bool addUses();

    // Adds a modifies relationship to the modifies table
    static bool addModifies();
    // ai-gen end

    // -- Generate Transitive Closures --
    // use the populated Follows table to generate FollowsT table
    static bool generateFollowsT(); // T stands for Transitive closure
    static bool generateParentT();

};
