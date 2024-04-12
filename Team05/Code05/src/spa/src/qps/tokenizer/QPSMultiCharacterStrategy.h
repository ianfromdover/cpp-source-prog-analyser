//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSMULTICHARACTERSTRATEGY_H
#define SPA_QPSMULTICHARACTERSTRATEGY_H

#include "QPSTokenStrategy.h"
#include <map>
#include <unordered_set>


class QPSMultiCharacterStrategy : public QPSTokenStrategy {
public:
    bool tokenize(char character, std::stringstream &stream, QPSTokenList &tokens, bool &prevTokenIsKeyword) override;

    bool expectSynonymNext(const std::string &name, QPSTokenList &tokens);

private:
    std::string readWhile(std::stringstream &stream, const std::function<bool(char)> &condition);
    bool starAllowed(const std::string& );
    bool poundAllowed(const std::string& );
    bool isDeclarations(QPSTokenType::QPSTypeInfo type);
    bool isPunc(QPSTokenType::QPSTypeInfo type);

    static inline const std::unordered_set<QPSTokenType::QPSTypeInfo> tokenMap = {
        QPSTokenType::WITHSTMT,QPSTokenType::WITHVALUE, QPSTokenType::WITHPROCNAME, QPSTokenType::WITHVARNAME, QPSTokenType::WITH, QPSTokenType::AND
    };
    static inline const std::map<std::string, QPSTokenType::QPSTypeInfo> declarationKeywords = {
        // Design entities
        {"stmt",      QPSTokenType::STMT1},
        {"read",      QPSTokenType::READ},
        {"print",     QPSTokenType::PRINT},
        {"while",     QPSTokenType::WHILE},
        {"if",        QPSTokenType::IF},
        {"call",      QPSTokenType::CALL},
        {"assign",    QPSTokenType::ASSIGN},
        {"variable",  QPSTokenType::VARIABLE},
        {"constant",  QPSTokenType::CONSTANT},
        {"procedure", QPSTokenType::PROCEDURE},

        // Relations
        {"Follows",   QPSTokenType::FOLLOWS},
        {"Follows*",  QPSTokenType::FOLLOWS_T},
        {"Parent",    QPSTokenType::PARENT},
        {"Parent*",   QPSTokenType::PARENT_T},
        {"Modifies", QPSTokenType::MODIFIES},
        {"Uses", QPSTokenType::USES},
        {"Calls", QPSTokenType::CALLS},
        {"Calls*",    QPSTokenType::CALLS_T},
        {"Next",    QPSTokenType::NEXT},
        {"Next*",    QPSTokenType::NEXT_T},
        {"Affects",    QPSTokenType::AFFECTS},

        // With
        {"stmt#",   QPSTokenType::WITHSTMT},
        {"value",   QPSTokenType::WITHVALUE},
        {"procName",   QPSTokenType::WITHPROCNAME},
        {"varName",   QPSTokenType::WITHVARNAME},
        {"with",   QPSTokenType::WITH},

        {"Select",    QPSTokenType::SELECT},
        {"that",      QPSTokenType::THAT},
        {"pattern",   QPSTokenType::PATTERN},
        {"not",   QPSTokenType::NOT},

        {"and",   QPSTokenType::AND},
    };
};

#endif //SPA_QPSMULTICHARACTERSTRATEGY_H
