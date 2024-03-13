//Ai Link: https://chat.openai.com/share/7135ca30-fc9b-47af-abee-8e458da2587a
//Ai Link: https://chat.openai.com/share/a8902a0c-5005-4d5a-a895-337aa882cedc
#include <iostream>
#include <set>
#include "pkb/apis/BasePKBPopulator.h"
#include "common/SpaTypes.h"

class PKBStubSP : public BasePKBPopulator {
    std::multiset<std::tuple<std::string, std::string, std::string>> tupleCalls;
    std::multiset<std::pair<std::string, std::string>> pairCalls;
    std::multiset<std::pair<std::string, std::string>> pairCallsT;
    std::multiset<std::string> singleCalls;

public:
    bool addRead(StmtNo sNum, VarName name) override {
        //std::cout << "addRead called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addCallStmt(StmtNo sNum, ProcName name) override {
        //std::cout << "addCallStmt called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addIf(StmtNo sNum, VarName ctrlVarName) override {
        //std::cout << "addIf called" << std::endl;
        pairCalls.insert({std::to_string(sNum), ctrlVarName});
        return true;
    }

    bool addWhile(StmtNo sNum, VarName ctrlVarName) override {
        //std::cout << "addWhile called" << std::endl;
        pairCalls.insert({std::to_string(sNum), ctrlVarName});
        return true;
    }

    bool addPrint(StmtNo sNum, VarName name) override {
        //std::cout << "addPrint called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addFinalStatementNo(StmtNo sNum) override {
        //std::cout << "addFinalStatementNo called" << std::endl;
        singleCalls.insert(std::to_string(sNum));
        return true;
    }

    bool addProcedure(Str name) override {
        //std::cout << "addProcedure called" << std::endl;
        singleCalls.insert(name);
        return true;
    }

    bool addVar(StmtNo sNum, VarName name) override {
        //std::cout << "addVar called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addConst(StmtNo sNum, ConstVal c) override {
        //std::cout << "addConst called" << std::endl;
        pairCalls.insert({std::to_string(sNum), std::to_string(c)});
        return true;
    }

    bool addFollows(StmtNo before, StmtNo after) override {
        //std::cout << "addFollows called" << std::endl;
        pairCalls.insert({std::to_string(before), std::to_string(after)});
        return true;
    }

    bool addFollowsT(StmtNo before, StmtNo after) override {
        //std::cout << "addFollowsT called" << std::endl;
        pairCallsT.insert({std::to_string(before), std::to_string(after)});
        return true;
    }

    bool addParent(StmtNo parent, StmtNo child) override {
        //std::cout << "addParent called" << std::endl;
        pairCalls.insert({std::to_string(parent), std::to_string(child)});
        return true;
    }

    bool addParentT(StmtNo ancestor, StmtNo descendant) override {
        //std::cout << "addParentT called" << std::endl;
        pairCallsT.insert({std::to_string(ancestor), std::to_string(descendant)});
        return true;
    }

    bool addUsesS(StmtNo sNum, VarName name) override {
        //std::cout << "addUsesS called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addUsesP(ProcName procName, VarName name) override {
        //std::cout << "addUsesP called" << std::endl;
        pairCalls.insert({procName, name});
        return true;
    }

    bool addModifiesS(StmtNo sNum, VarName name) override {
        //std::cout << "addModifiesS called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addModifiesP(ProcName procName, VarName name) override {
        //std::cout << "addModifiesP called" << std::endl;
        pairCalls.insert({procName, name});
        return true;
    }

    bool addPatternAsgn(StmtNo sNum, Str lhs, Str rhsBracketed) override {
        //std::cout << "addPatternAsgn called" << std::endl;
        tupleCalls.insert({std::to_string(sNum), lhs, rhsBracketed});
        return true;
    }

    bool addCalls(ProcName caller, ProcName called) override {
        //std::cout << "addCalls called" << std::endl;
        pairCalls.insert({caller, called});
        return true;
    }

    bool addCallsT(ProcName caller, ProcName called) override {
        //std::cout << "addCallsT called" << std::endl;
        pairCallsT.insert({caller, called});
        return true;
    }

    // TODO: check again, now is just to make it compile

    bool addAffects(int before, int after) override {
        //std::cout << "addAffects called" << std::endl;
        pairCalls.insert({std::to_string(before), std::to_string(after)});
        return true;
    }

    bool addNext(int before, int after) override {
        //std::cout << "addAffects called" << std::endl;
        pairCalls.insert({std::to_string(before), std::to_string(after)});
        return true;
    }

    bool addNextT(int before, int after) override {
        //std::cout << "addAffects called" << std::endl;
        pairCallsT.insert({std::to_string(before), std::to_string(after)});
        return true;
    }

    bool addPatternIf(int stmtNo, std::string name) override {
        //std::cout << "addPatternAsgn called" << std::endl;
        pairCalls.insert({std::to_string(stmtNo), name});
        return true;
    }

    bool addPatternWhile(int stmtNo, std::string name) override {
        //std::cout << "addPatternAsgn called" << std::endl;
        pairCalls.insert({std::to_string(stmtNo), name});
        return true;
    }

    // TODO: do for rest of the missing stuff

    template<typename... T>
    bool checkAgainstResults(std::multiset<T...>& given, std::multiset<T...>& expect) {
        // Iterate through each element in the given multiset
        for (const auto& element : given) {
            // Try to find the element in expect
            auto it = expect.find(element);
            if (it == expect.end()) {
                // If the element is not found, return false
                return false;
            } else {
                // If found, erase one instance of that element from expect
                expect.erase(it);
            }
        }
        // If all elements are found and removed, return true if expect is now empty
        return expect.empty();
    }

    bool checkAgainstSingleResults(std::multiset<std::string>& toCheck) {
        return checkAgainstResults<>(toCheck, singleCalls);
    }

    bool checkAgainstPairResults(std::multiset<std::pair<std::string, std::string>> &toCheck) {
       return checkAgainstResults<>(toCheck, pairCalls);
    }

    bool checkAgainstPairTResults(std::multiset<std::pair<std::string, std::string>> &toCheck) {
        return checkAgainstResults<>(toCheck, pairCallsT);
    }

    bool checkAgainstTupleResults(std::multiset<std::tuple<std::string, std::string, std::string>> &toCheck) {
        return checkAgainstResults<>(toCheck, tupleCalls);
    }

};