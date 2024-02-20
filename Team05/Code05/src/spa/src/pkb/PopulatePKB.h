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
    // ai-gen start (copilot, 2, e)
    // prompt: used copilot

    // -- Add Entities --
    /*
    // Adds a variable to the variable table
    bool addVar();

    // Adds a constant to the constant table
    bool addConst();

    // Adds a procedure to the procedure table
    bool addProcedure();

    // Adds a statement to the statement table
    bool addStmt(StmtNo stmtNo, Str stmtType, ProcId procIndex);

    // -- Add Abstractions --
    */
    // Adds a follows relationship to the follows table
    bool addFollows(StmtNo before, StmtNo after);

    // Adds a parent relationship to the parent table
    bool addParent(StmtNo parent, StmtNo child); // parent is s1, child is s2

    // Adds a uses relationship to the uses table
    /*
    bool addUses();

    // Adds a modifies relationship to the modifies table
    bool addModifies();
    // ai-gen end

    // -- Generate Transitive Closures --
    // use the populated Follows table to generate FollowsT table
    bool generateFollowsT(); // T stands for Transitive closure
    bool generateParentT();
    */
};
