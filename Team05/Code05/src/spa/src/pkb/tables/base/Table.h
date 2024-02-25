//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_TABLE_H
#define SPA_TABLE_H

#include <iostream>
#include "utilSpa/StringColumn.h"


class Table {
protected:
    std::pair<StringColumn, StringColumn> table;
public:
    Table() = default;

    // Function to add record into the table
    bool addRecord(std::string key, std::string val) {
        table.first.addString(key);
        table.second.addString(val);
        return true;
    }

    // Function to returns string vector of values that correspond to the given key
    std::vector<std::string> queryRHS(std::string key) {
        auto indices = table.first.searchIndices(key);
        auto results = table.second.getElementsByIndices(indices);
        return results;
    }

    // Function to returns string vector of keys that correspond to the given value
    std::vector<std::string> queryLHS(std::string val) {
        auto indices = table.second.searchIndices(val);
        auto results = table.first.getElementsByIndices(indices);
        return results;
    }

    // Function to get the entire string vector from LHS
    std::vector<std::string> getLHS() {
        return table.first.getStringVector();
    }

    // Function to get the entire string vector from RHS
    std::vector<std::string> getRHS() {
        return table.second.getStringVector();
    }

};

#endif //SPA_TABLE_H
