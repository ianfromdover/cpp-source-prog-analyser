//
// Created by Alex on 16/2/2024.
//

#include "DeclarationClause.h"

namespace qps {
    void DeclarationClause::addDeclaration(const QPSTokenType &type, const std::string &synonym) {
        if (declarationMap.find(type) != declarationMap.end()) {
            declarationMap[type].push_back(synonym);
        } else {
            declarationMap[type] = std::vector<std::string>{synonym};
        }
    }

    std::vector<std::pair<QPSTokenType::QPSTypeInfo, std::string>> DeclarationClause::getAllDeclarations() {
        std::vector<std::pair<QPSTokenType::QPSTypeInfo, std::string>> result;
        for (const auto &pair: declarationMap) {
            for (const std::string &s: pair.second) {
                auto token = pair.first;
                QPSTokenType::QPSTypeInfo typeInfo = token.getInfo();
                result.push_back(std::make_pair(typeInfo, s));
            }
        }
        return result;
    }
}