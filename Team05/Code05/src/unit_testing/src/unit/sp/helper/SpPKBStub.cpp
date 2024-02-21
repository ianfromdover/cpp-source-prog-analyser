
// ai-gen start(gpt, 2, e)
// prompt: https://chat.openai.com/share/940ebdda-42de-413e-a802-ac3c1ded8bc5

#include <set>
#include <string>
#include <utility> // For std::pair

using namespace std;

#include "utilSpa/SpaTypes.h"
#include "pkb/PopulatePKB.h"

class SpPKBStub : public PopulatePKB {
private:
//    set<pair<StmtNo, StmtNo>> follows, followsT, parents, parentsT;
//    set<pair<StmtNo, VarName>> read, call, ifStmt, whileStmt, assign, print, uses, modifies;
//    set<StmtNo> finalStatementNo;
//    set<Str> procedure;
//    set<pair<StmtNo, ConstVal>> cons;

public:
    set<pair<StmtNo, StmtNo>> follows, followsT, parents, parentsT;
    set<pair<StmtNo, VarName>> read, call, ifStmt, whileStmt, assign, print, uses, modifies;
    set<StmtNo> finalStatementNo;
    set<Str> procedure;
    set<pair<StmtNo, ConstVal>> cons;
    explicit SpPKBStub(shared_ptr<PKBStorage> p) : PopulatePKB(p) {

    }

    bool addRead(StmtNo sNum, const VarName& name)  {
        std::cout <<"ss" <<std::endl;
        return read.insert({sNum, name}).second;
    }

    bool addCallStmt(StmtNo sNum, const ProcName& name) {
        return call.insert({sNum, name}).second;
    }

    bool addIf(StmtNo sNum, const VarName& ctrlVarName) {
        return ifStmt.insert({sNum, ctrlVarName}).second;
    }

    bool addWhile(StmtNo sNum, const VarName& ctrlVarName) {
        return whileStmt.insert({sNum, ctrlVarName}).second;
    }

    bool addAssign(StmtNo sNum, const VarName& LhsVarName) {
        return assign.insert({sNum, LhsVarName}).second;
    }

    bool addPrint(StmtNo s, const VarName& name) {
        return print.insert({s, name}).second;
    }

    bool addFinalStatementNo(StmtNo s) {
        return finalStatementNo.insert(s).second;
    }

    bool addProcedure(const Str& procedureName) {
        return procedure.insert(procedureName).second;
    }

    bool addVar(StmtNo sNum, const VarName& name) {
        return uses.insert({sNum, name}).second; // Assuming uses for simplicity; adjust as necessary.
    }

    bool addConst(StmtNo sNum, ConstVal c) {
        return cons.insert({sNum, c}).second;
    }

    bool addFollows(StmtNo before, StmtNo after) {
        return follows.insert({before, after}).second;
    }

    bool addFollowsT(StmtNo before, StmtNo after) {
        return followsT.insert({before, after}).second;
    }

    bool addParent(StmtNo parent, StmtNo child) {
        return parents.insert({parent, child}).second;
    }

    bool addParentT(StmtNo ancestor, StmtNo descendant){
        return parentsT.insert({ancestor, descendant}).second;
    }

    bool addUses(StmtNo sNum, const VarName& name) {
        return uses.insert({sNum, name}).second;
    }

    bool addModifies(StmtNo sNum, const VarName& name) {
        return modifies.insert({sNum, name}).second;
    }

    // Verification methods
    template<typename T>
    bool checkContains(const set<T>& dataSet, const T& value) const {
        return dataSet.find(value) != dataSet.end();
    }

};
