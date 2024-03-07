//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_RESULTTABLE_H
#define SPA_RESULTTABLE_H


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "utilSpa/Column.h"

using table = std::vector<std::vector<std::string>>;

class ResultTable {
public:
    table _table;
    ResultTable(table& t): _table(removeDuplicateColumn(t)) {};
    ResultTable() = default;

    bool isEmpty(){
        return _table.empty();
    }

    void add(const table& a){
        if (_table.empty()){
            _table = removeDuplicateColumn(a);
        } else {
            _table = joinOrCrossProduct(removeDuplicateColumn(_table), a);
            removeDuplicateEntires(_table);
        }
    }

    bool hasEntries(){
        if (isEmpty()) return false;
        return _table.size() > 1;
    }

    bool hasDuplicatedHeaders(table& t){
        std::vector<std::string> headers = t[0];
        std::sort(headers.begin(), headers.end());
        auto last = std::unique(headers.begin(), headers.end());
        return last != headers.end();
    }

    table removeDuplicateColumn(table t){
        if (hasDuplicatedHeaders(t)){
            std::vector<std::string> headers = t[0];
            std::sort(headers.begin(), headers.end());
            auto last = std::unique(headers.begin(), headers.end());
            headers.erase(last, headers.end());
            table result;
            result.push_back(headers);
            for (size_t i = 1; i < t.size(); ++i) {
                std::vector<std::string> row;
                for (const auto& header: headers){
                    size_t index = findColumnIndex(t, header);
                    row.push_back(t[i][index]);
                }
                result.push_back(row);
            }
            return result;
        }
        return t;
    }

    void filterByColumnPartial(const string& header, const string& str) {
        table filteredTab; // Resulting table after filtering
        int columnNo = -1;

        // Find the column number based on the header name
        for (size_t i = 0; i < _table[0].size(); ++i) {
            if (_table[0][i] == header) {
                columnNo = i;
                break;
            }
        }

        if (columnNo == -1) {
            cout << "Header not found: " << header << endl;
            return; // Header not found
        }

        filteredTab.push_back(_table[0]); // Include headers in the filtered table

        for (size_t i = 1; i < _table.size(); ++i) { // Skip header row
            if (_table[i][columnNo].find(str) != string::npos) {
                filteredTab.push_back(_table[i]);
            }
        }

        _table = filteredTab; // Replace the original table with the filtered results
    }

    void filterByColumnValues(std::string& header, std::vector<std::string>& values) {
        // given a header and a list of values, filter the table to only include rows where the value in the header column is in the list of values

        table filteredTab; // Resulting table after filtering
        int columnNo = -1;

        // Find the column number based on the header name
        for (size_t i = 0; i < _table[0].size(); ++i) {
            if (_table[0][i] == header) {
                columnNo = i;
                break;
            }
        }

        if (columnNo == -1) {
            cout << "Header not found: " << header << endl;
            return; // Header not found
        }

        filteredTab.push_back(_table[0]); // Include headers in the filtered table

        for (size_t i = 1; i < _table.size(); ++i) { // Skip header row
            if (std::find(values.begin(), values.end(), _table[i][columnNo]) != values.end()) {
                filteredTab.push_back(_table[i]);
            }
        }

        _table = filteredTab; // Replace the original table with the filtered results
    }

    void removeColumn(std::string& header){
        size_t index = findColumnIndex(_table, header);
        if (index != 0){
            for (size_t i = 0; i < _table.size(); ++i) {
                _table[i].erase(_table[i].begin() + index);
            }
        }
    }

    void filterByColumnExact(const string& header, const string& str) {
        table filteredTab; // Resulting table after filtering
        int columnNo = -1;

        // Find the column number based on the header name
        for (size_t i = 0; i < _table[0].size(); ++i) {
            if (_table[0][i] == header) {
                columnNo = i;
                break;
            }
        }

        if (columnNo == -1) {
            cout << "Header not found: " << header << endl;
            return; // Header not found
        }

        filteredTab.push_back(_table[0]); // Include headers in the filtered table

        for (size_t i = 1; i < _table.size(); ++i) { // Skip header row
            if (_table[i][columnNo] == str) {
                filteredTab.push_back(_table[i]);
            }
        }

        _table = filteredTab; // Replace the original table with the filtered results
    }

    table getTable() {
        return _table;
    }

    std::vector<std::string> getDistinctColumn(std::string colName){
        try {
            if (_table.empty()) return {};
            std::vector<std::string> result;
            size_t index = findColumnIndex(_table, colName);
            for (size_t i = 1; i < _table.size(); ++i) {
                result.push_back(_table[i][index]);
            }
            std::sort(result.begin(), result.end());
            result.erase(std::unique(result.begin(), result.end()), result.end());
            return result;
        } catch (std::runtime_error& e){
            return {};
        }
    }

    static vector<string> findCommonHeaders(const table& a, const table& b) {
        try {
            vector<string> commonHeaders;
            for (const auto &headerA: a[0]) {
                for (const auto &headerB: b[0]) {
                    if (headerA == headerB) {
                        commonHeaders.push_back(headerA);
                    }
                }
            }
            return commonHeaders;
        } catch (std::runtime_error& e){
            return {};
        }
    }

    static size_t findColumnIndex(const table& table, const string& header) {
        for (size_t i = 0; i < table[0].size(); ++i) {
            if (table[0][i] == header) {
                return i;
            }
        }
        return 0; // Not found
    }

    static void removeDuplicateEntires(table& a){
        for (size_t i = 1; i < a.size(); ++i) {
            for (size_t j = i + 1; j < a.size(); ++j) {
                if (a[i] == a[j]){
                    a.erase(a.begin() + j);
                }
            }
        }
    }

    // Code snippet referenced from: https://www.geeksforgeeks.org/joining-tables-using-multimaps/
    static table joinOrCrossProduct(const table& a, const table& b) {
        vector<string> commonHeaders = findCommonHeaders(a, b);

        if (!commonHeaders.empty()) {
            table result;

            // Add header from table A
            result.push_back({a[0].begin(), a[0].end()});
            // Extend with header from table B, skipping common headers
            for (const auto& header : b[0]) {
                if (std::find(commonHeaders.begin(), commonHeaders.end(), header) == commonHeaders.end()) {
                    result[0].push_back(header);
                }
            }

            size_t columnA = findColumnIndex(a, commonHeaders[0]);
            size_t columnB = findColumnIndex(b, commonHeaders[0]);

            for (size_t i = 1; i < a.size(); ++i) {
                for (size_t j = 1; j < b.size(); ++j) {
                    if (a[i][columnA] == b[j][columnB]) {
                        vector<string> row(a[i].begin(), a[i].end());

                        // Insert elements from b[j], skipping common columns
                        for (size_t k = 0; k < b[j].size(); ++k) {
                            // Only add if the column is not common
                            if (std::find(commonHeaders.begin(), commonHeaders.end(), b[0][k]) == commonHeaders.end()) {
                                row.push_back(b[j][k]);
                            }
                        }

                        result.push_back(move(row));
                    }
                }
            }
            return result;
        }
        else {
            // Perform cross product
            table result;
            for (size_t i = 1; i < a.size(); ++i) {
                for (size_t j = 1; j < b.size(); ++j) {
                    vector<string> row(a[i].begin(), a[i].end());
                    row.insert(row.end(), b[j].begin(), b[j].end());
                    result.push_back(move(row));
                }
            }
            return result;
        }
    }

    ostream& operator<<(ostream& o) {
        for (const auto& row : _table) {
            for (const auto& e : row)
                o << e << '\t';
            o << endl;
        }
        return o;
    }


};


#endif //SPA_RESULTTABLE_H
