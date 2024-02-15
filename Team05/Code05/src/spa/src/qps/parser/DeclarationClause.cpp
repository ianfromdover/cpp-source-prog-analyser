//
// Created by Alex on 16/2/2024.
//

#include "DeclarationClause.h"

namespace qps {
    void DeclarationClause::addDeclaration(const TokenType &type, const std::string &synonym) {
        if (declarationMap.find(type) != declarationMap.end()) {
            declarationMap[type].push_back(synonym);
        } else {
            declarationMap[type] = std::vector<std::string>{synonym};
        }
    }

    std::vector<std::pair<TokenType, std::string>> DeclarationClause::getAllDeclarations() {
        std::vector<std::pair<TokenType, std::string>> result;
        for (const auto &pair: declarationMap) {
            for (const std::string &s: pair.second) {
                result.push_back(std::make_pair(pair.first, s));
            }
        }
        return result;
    }
}