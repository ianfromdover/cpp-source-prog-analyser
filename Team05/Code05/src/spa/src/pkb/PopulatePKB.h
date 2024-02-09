#pragma once
#define SPA_POPULATEPKB_H
#include "utilSpa/SpaTypes.h"

using namespace std;

// The interface between PKB and SP
class PopulatePKB {
private:
public:
    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    static bool populateVarTable();
    static bool populateProcTable();
    static bool populateStmtTable();
    static bool populateFollows();
    static bool populateParent();
    static bool populateUses();
    static bool populateModifies();
    static bool populatePattern();
    static bool populateAST();
    static bool populateAll();
    // ai-gen end
    static bool generateFollowsT(); // use Follows table to generate FollowsT table
    static bool generateParentT();
};
