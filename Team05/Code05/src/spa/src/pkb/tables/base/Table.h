//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_TABLE_H
#define SPA_TABLE_H

#include <iostream>
#include "utilSpa/StringColumn.h"


class Table {
protected:
    std::vector<std::vector<std::string>> table;
public:
    Table() = default;

    // Function to add record into the table
    bool addRecord(std::string key, std::string val) {
        std::vector<std::string> newRow = {key, val};
        table.push_back(newRow);
        return true;
    }

    std::vector<std::vector<std::string>> getTable() {
        return table;
    }



};

#endif //SPA_TABLE_H
