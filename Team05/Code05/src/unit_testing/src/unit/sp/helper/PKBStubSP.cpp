#include <iostream>
#include <set>
#include "utilSpa/SpaTypes.h"

class PKBStubSP {
    std::multiset<std::tuple<std::string, std::string, std::string>> tupleCalls;
    std::multiset<std::pair<std::string, std::string>> pairCalls;
    std::multiset<std::string> singleCalls;

public:
    bool addRead(StmtNo sNum, VarName name) {
        std::cout << "addRead called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addCallStmt(StmtNo sNum, ProcName name) {
        std::cout << "addCallStmt called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addIf(StmtNo sNum, VarName ctrlVarName) {
        std::cout << "addIf called" << std::endl;
        pairCalls.insert({std::to_string(sNum), ctrlVarName});
        return true;
    }

    bool addWhile(StmtNo sNum, VarName ctrlVarName) {
        std::cout << "addWhile called" << std::endl;
        pairCalls.insert({std::to_string(sNum), ctrlVarName});
        return true;
    }

    bool addAssign(StmtNo sNum, VarName LhsVarName) {
        std::cout << "addAssign called" << std::endl;
        pairCalls.insert({std::to_string(sNum), LhsVarName});
        return true;
    }

    bool addPrint(StmtNo sNum, VarName name) {
        std::cout << "addPrint called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addFinalStatementNo(StmtNo sNum) {
        std::cout << "addFinalStatementNo called" << std::endl;
        singleCalls.insert(std::to_string(sNum));
        return true;
    }

    bool addProcedure(Str name) {
        std::cout << "addProcedure called" << std::endl;
        singleCalls.insert(name);
        return true;
    }

    bool addVar(StmtNo sNum, VarName name) {
        std::cout << "addVar called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addConst(StmtNo sNum, ConstVal c) {
        std::cout << "addConst called" << std::endl;
        pairCalls.insert({std::to_string(sNum), std::to_string(c)});
        return true;
    }

    bool addFollows(StmtNo before, StmtNo after) {
        std::cout << "addFollows called" << std::endl;
        pairCalls.insert({std::to_string(before), std::to_string(after)});
        return true;
    }

    bool addFollowsT(StmtNo before, StmtNo after) {
        std::cout << "addFollowsT called" << std::endl;
        pairCalls.insert({std::to_string(before), std::to_string(after)});
        return true;
    }

    bool addParent(StmtNo parent, StmtNo child) {
        std::cout << "addParent called" << std::endl;
        pairCalls.insert({std::to_string(parent), std::to_string(child)});
        return true;
    }

    bool addParentT(StmtNo ancestor, StmtNo descendant) {
        std::cout << "addParentT called" << std::endl;
        pairCalls.insert({std::to_string(ancestor), std::to_string(descendant)});
        return true;
    }

    bool addUses(StmtNo sNum, VarName name) {
        std::cout << "addUses called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addUses(ProcName ProcedureName, VarName name) {
        std::cout << "addUses (ProcName) called" << std::endl;
        pairCalls.insert({ProcedureName, name});
        return true;
    }

    bool addModifies(StmtNo sNum, VarName name) {
        std::cout << "addModifies called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addModifies(ProcName ProcedureName, VarName name) {
        std::cout << "addModifies (ProcName) called" << std::endl;
        pairCalls.insert({ProcedureName, name});
        return true;
    }

    bool addPatternAsgn(StmtNo sNum, Str lhs, Str rhsBracketed) {
        std::cout << "addPatternAsgn called" << std::endl;
        tupleCalls.insert({std::to_string(sNum), lhs, rhsBracketed});
        return true;
    }


};