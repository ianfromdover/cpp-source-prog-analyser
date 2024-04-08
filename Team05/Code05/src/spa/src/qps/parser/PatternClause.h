//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_PATTERNCLAUSE_H
#define SPA_PATTERNCLAUSE_H

#include <memory>
#include <utility>
#include <vector>
#include <string>
#include "Clause.h"
#include "qps/tokenizer/QPSToken.h"


class PatternClause : public Clause {
public:
    PatternClause(std::string syn, QPSToken &t1, QPSTokenType::QPSTypeInfo type1, QPSToken &t2,
                  QPSTokenType::QPSTypeInfo type2) : Clause(ClauseType::PATTERN) {
        synonym = std::move(syn);
        args.push_back(std::make_shared<QPSToken>(t1));
        args.push_back(std::make_shared<QPSToken>(t2));
        argRefTypes.push_back(type1);
        argRefTypes.push_back(type2);
    }

    explicit PatternClause(std::string syn) : Clause(ClauseType::PATTERN){
        synonym = std::move(syn);
        args = std::vector<std::shared_ptr<QPSToken>>();
        argRefTypes = std::vector<QPSTokenType::QPSTypeInfo>();
    };

    std::string getPatternSynonym();

    QPSTokenType::QPSTypeInfo getArgTypeAtIndex(int i);
    QPSTokenType::QPSTypeInfo getReferenceTypeAtIndex(int i);
    std::string getArgValueAtIndex(int i);
    QPSToken &getArgAtIndex(int i);

     [[nodiscard]] int getArgCount() const{
        return argCount+1;
    };

    void addArg(QPSToken &t1, QPSTokenType::QPSTypeInfo type1){
        args.push_back(std::make_shared<QPSToken>(t1));
        argRefTypes.push_back(type1);
        argCount++;
    };

    bool operator==(const PatternClause& other) const{
        return
        synonym == other.synonym;
    }

    std::string toString() {
        return "Pattern: []";
    }

private:
    std::string synonym;

    std::vector<std::shared_ptr<QPSToken>> args;
    std::vector<QPSTokenType::QPSTypeInfo> argRefTypes;
    int argCount=-1;
};


#endif //SPA_PATTERNCLAUSE_H
