//Ai Link: https://chat.openai.com/share/7135ca30-fc9b-47af-abee-8e458da2587a
//Ai Link: https://chat.openai.com/share/a8902a0c-5005-4d5a-a895-337aa882cedc
#include <iostream>
#include <set>
#include <pkb/BasePKBPopulator.h>
#include "utilSpa/SpaTypes.h"

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

    bool addUses(StmtNo sNum, VarName name) override {
        //std::cout << "addUses called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addUses(ProcName ProcedureName, VarName name) override {
        //std::cout << "addUses (ProcName) called" << std::endl;
        pairCalls.insert({ProcedureName, name});
        return true;
    }

    bool addModifies(StmtNo sNum, VarName name) override {
        //std::cout << "addModifies called" << std::endl;
        pairCalls.insert({std::to_string(sNum), name});
        return true;
    }

    bool addModifies(ProcName ProcedureName, VarName name) override {
        //std::cout << "addModifies (ProcName) called" << std::endl;
        pairCalls.insert({ProcedureName, name});
        return true;
    }

    bool addPatternAsgn(StmtNo sNum, Str lhs, Str rhsBracketed) override {
        //std::cout << "addPatternAsgn called" << std::endl;
        tupleCalls.insert({std::to_string(sNum), lhs, rhsBracketed});
        return true;
    }


    template<typename... T>
    bool checkAgainstResults(const std::multiset<T...>& given, const std::multiset<T...>& expect) {
        if (given.size() != expect.size()) {
            return false; // Early return if sizes don't match
        }

        auto itGiven = given.begin();
        auto itExpect = expect.begin();
        while (itGiven != given.end() && itExpect != expect.end()) {
            if (*itGiven != *itExpect) {
                return false; // Elements or their counts don't match
            }
            ++itGiven;
            ++itExpect;
        }

        return true; // All elements and their counts match
    }

    bool checkAgainstSingleResults(const std::multiset<std::string>& toCheck) {
        return checkAgainstResults<>(singleCalls, toCheck);
    }

    bool checkAgainstPairResults(const std::multiset<std::pair<std::string, std::string>> &toCheck) {
       return checkAgainstResults<>(pairCalls, toCheck);
    }

    bool checkAgainstPairTResults(const std::multiset<std::pair<std::string, std::string>> &toCheck) {
        return checkAgainstResults<>(pairCallsT, toCheck);
    }

    bool checkAgainstTupleResults(const std::multiset<std::tuple<std::string, std::string, std::string>> &toCheck) {
        return checkAgainstResults<>(tupleCalls, toCheck);
    }

    bool checkIfExistPair(const std::multiset<std::pair<std::string, std::string>>& pairVector) {
        // Iterate through each pair in pairVector
        for (const auto& pair : pairVector) {
            // Try to find the pair in pairCalls
            auto it = pairCalls.find(pair);
            if (it == pairCalls.end()) {
                // If the pair is not found, return false
                return false;
            } else {
                // If found, erase one instance of that pair from pairCalls
                pairCalls.erase(it);
            }
        }
        // If all pairs are found and removed, return true
        return pairCalls.empty();
    }

    bool checkIfExistPairT(const std::multiset<std::pair<std::string, std::string>>& pairVector) {
        // Iterate through each pair in pairVector
        for (const auto& pair : pairVector) {
            // Try to find the pair in pairCalls
            auto it = pairCallsT.find(pair);
            if (it == pairCallsT.end()) {
                // If the pair is not found, return false
                return false;
            } else {
                // If found, erase one instance of that pair from pairCalls
                pairCallsT.erase(it);
            }
        }
        // If all pairs are found and removed, return true
        return pairCallsT.empty();
    }

    bool checkIfExistSingle(const std::multiset<std::string>& stringVector) {
        // Iterate through each string in stringVector
        for (const auto& str : stringVector) {
            // Try to find the string in singleCalls
            auto it = singleCalls.find(str);
            if (it == singleCalls.end()) {
                // If the string is not found, return false
                return false;
            } else {
                // If found, erase one instance of that string from singleCalls
                singleCalls.erase(it);
            }
        }
        // If all strings are found and removed, return true
        return singleCalls.empty();
    }

    bool checkIfExistTuple(const std::multiset<std::tuple<std::string, std::string, std::string>>& tupleVector) {
        // Iterate through each tuple in tupleVector
        for (const auto& tuple : tupleVector) {
            // Try to find the tuple in tupleCalls
            auto it = tupleCalls.find(tuple);
            if (it == tupleCalls.end()) {
                // If the tuple is not found, return false
                return false;
            } else {
                // If found, erase one instance of that tuple from tupleCalls
                tupleCalls.erase(it);
            }
        }
        // If all tuples are found and removed, return true
        return tupleCalls.empty();
    }

};