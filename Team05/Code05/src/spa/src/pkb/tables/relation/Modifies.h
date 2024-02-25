//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_MODIFIES_H
#define SPA_MODIFIES_H


#include "RelationTable.h"

class ModifiesTable : public Table {
public:
    ModifiesTable() = default;

    std::pair<StringColumn, StringColumn> handleRelation(std::string entTypeL, std::string entTypeR,
        std::unordered_map<std::string, std::shared_ptr<Table>>& entityTableMap) override {
        std::pair<StringColumn, StringColumn> tableCopy;
        handleLHS(entTypeL, tableCopy, entityTableMap);
        handleRHS(entTypeR, tableCopy, entityTableMap);
    }

    void handleLHS(std::string entTypeL, std::pair<StringColumn, StringColumn>& tableCopy,
                        std::unordered_map<std::string, std::shared_ptr<Table>>& entityTableMap) override {
        if (isLHSSynonym(entTypeL)) {
            auto entityIter = entityTableMap.find(entTypeL);

            if (entityIter != entityTableMap.end()) {
                // Get relevant entity tables
                auto &entity = entityIter->second;

                // Get relevant columns for matching
                auto entityLHS = entity->getLHS();
                auto relationLHS = table.first.getStringVector();

                // Find vector of matched strings
                auto commonString = findCommon(entityLHS, relationLHS);

                // Find valid rows by indices from the relation table
                std::vector<int> indices;
                for (auto key : commonString) {
                    auto indicesFound = table.first.searchIndices(key);
                    indices.insert(indices.end(), indicesFound.begin(), indicesFound.end());
                }

                for (auto index: indices) {
                    tableCopy.first.addString(table.first.getStringByIndex(index));
                    tableCopy.second.addString(table.second.getStringByIndex(index));
                }

            } else if (entTypeL == TYPE_WILDCARD) {
                // Do nothing
            } else {
                // Handle Integer Cases
                auto indicesFound = table.first.searchIndices(entTypeL);

                for (auto index: indicesFound) {
                    tableCopy.first.addString(table.first.getStringByIndex(index));
                    tableCopy.second.addString(table.second.getStringByIndex(index));
                }
            }
        }
    }

    void handleRHS(std::string entTypeR, std::pair<StringColumn, StringColumn>& tableCopy,
                   std::unordered_map<std::string, std::shared_ptr<Table>>& entityTableMap) override {
        if (isRHSSynonym(entTypeR)) {
            auto entityIter = entityTableMap.find(entTypeR);

            if (entityIter != entityTableMap.end()) {
                // Get relevant entity tables
                auto &entity = entityIter->second;

                // Get relevant columns for matching
                auto entityRHS = entity->getRHS();
                auto relationRHS = tableCopy.second.getStringVector();

                // Find vector of matched strings
                auto commonString = findCommon(entityRHS, relationRHS);

                // Find valid rows by indices from the relation table
                std::vector<int> indices;
                for (auto key : commonString) {
                    auto indicesFound = tableCopy.second.searchIndices(key);
                    indices.insert(indices.end(), indicesFound.begin(), indicesFound.end());
                }

                for (auto index: indices) {
                    tableCopy.first.addString(table.first.getStringByIndex(index));
                    tableCopy.second.addString(table.second.getStringByIndex(index));
                }

            } else if (entTypeR == TYPE_WILDCARD) {
                // Do nothing
            } else {
                // Handle quoted Cases
                auto indicesFound = table.second.searchIndices(entTypeR);

                for (auto index: indicesFound) {
                    tableCopy.first.addString(table.first.getStringByIndex(index));
                    tableCopy.second.addString(table.second.getStringByIndex(index));
                }
            }
        }

    }


    bool isLHSSynonym(std::string entType) override {
        std::vector<std::string> synonymList = {
                TYPE_STATEMENT, TYPE_READ, TYPE_PRINT, TYPE_ASSIGN,
                TYPE_CALL, TYPE_IF, TYPE_WHILE, TYPE_PROCEDURE
        };
        return std::find(synonymList.begin(), synonymList.end(), entType) != synonymList.end();
    }

    bool isRHSSynonym(std::string entType) override {
        std::vector<std::string> synonymList = {
                TYPE_VARIABLE
        };
        return std::find(synonymList.begin(), synonymList.end(), entType) != synonymList.end();
    }
};

#endif //SPA_MODIFIES_H
