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
#include <regex>
#include <map>
#include "common/Column.h"

using table = Table;

class ResultTable {
public:
    table _table;
    ResultTable(table& t){
        removeDuplicateEntires(t);
        _table = t;
    };
    ResultTable() = default;

    bool isEmpty(){
        return _table.empty();
    }

    void add(const table& a){
        if (_table.empty()){
            _table = removeDuplicateColumn(a); // TODO: remove 'removeDuplicateColumn' after pkb patch
        } else {
            _table = joinOrCrossProduct(removeDuplicateColumn(_table), a);
            removeDuplicateEntires(_table);
        }
    }

    std::vector<std::string> getHeaders(){
        if (isEmpty()) return {};
        return _table[0];
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

        return t;
    }

    void filterByColumnPartial(const string& header, const string& patternStr) {
        vector<vector<string>> filteredTab; // Resulting table after filtering
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

        // Compile the regular expression pattern
        regex pattern(patternStr);

        filteredTab.push_back(_table[0]); // Include headers in the filtered table

        // Iterate through each row of the table, starting from row 1 to skip header
        for (size_t i = 1; i < _table.size(); ++i) {
            smatch matches;

            // Use regex_search to find matches in the specified column
            if (regex_search(_table[i][columnNo], matches, pattern)) {
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

    bool hasHeader(std::string& header){
        return std::find(_table[0].begin(), _table[0].end(), header) != _table[0].end();
    }

    void removeColumnByHeader(std::string& header){
        if (hasHeader(header)) {
            size_t index = findColumnIndex(_table, header);
            removeColumnByIndex(index);
        }
    }

    void removeColumnByIndex(int i){
        if (i >= 0 && i < _table[0].size()) {
            for (int j = 0; j < _table.size(); ++j) {
                _table[j].erase(_table[j].begin() + i);
            }
        }
        removeDuplicateEntires(_table);
    }

    void removeAllColumnsExceptIndex(int i){
        for (int j = 0; j < _table[0].size(); ++j) {
            if (j != i){
                removeColumnByIndex(j);
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
        removeDuplicateEntires(_table);
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

    std::vector<std::vector<std::string>> getDistinctColumns(std::vector<std::string> colNames) {
        try {
            if (_table.empty()) return {{}};
            std::vector<std::vector<std::string>> result;
            for (std::string colName : colNames) {
                std::vector<std::string> oneCol = getDistinctColumn(colName);
                result.push_back(oneCol);
            }
            return result;
        } catch (std::runtime_error& e){
            return {};
        }
    }

    static vector<string> findCommonHeaders(const table& a, const table& b) {
      if (a.empty() || b.empty()) return {};
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

    static Table nestedLoopJoin(const table& tableA, const table& tableB) {
        // guaranteed to have common headers
        table result;

        map<string, size_t> headerIndex;
        vector<string> headers;

        for (size_t i = 0; i < tableA[0].size(); ++i) {
            headerIndex[tableA[0][i]] = i;
            headers.push_back(tableA[0][i]);
        }
        size_t offset = tableA[0].size();
        for (size_t i = 0; i < tableB[0].size(); ++i) {
            if (headerIndex.find(tableB[0][i]) == headerIndex.end()) {
                headerIndex[tableB[0][i]] = i + offset;
                headers.push_back(tableB[0][i]);
            }
        }

        // find common headers
        vector<string> commonHeaders = findCommonHeaders(tableA, tableB);

        map<string, size_t> headerMapA;
        map<string, size_t> headerMapB;

        for (size_t i = 0; i < commonHeaders.size(); ++i) {
            headerMapA[commonHeaders[i]] = findColumnIndex(tableA, commonHeaders[i]);
            headerMapB[commonHeaders[i]] = findColumnIndex(tableB, commonHeaders[i]);
        }

        // insert all headers
        result.push_back(headers);

        // iterate through table a
        for (size_t i = 1; i < tableA.size(); ++i) {
            // iterate through table b
            vector<string> entryA = tableA[i];
            for (size_t j = 1; j < tableB.size(); ++j) {
                vector<string> entryB = tableB[j];

                bool match = false;
                for (const auto& header: commonHeaders) {
                    if (entryA[headerMapA[header]] == entryB[headerMapB[header]]) {
                        match = true;
                    } else {
                        match = false;
                        break;
                    }
                }

                if (match){
                    // join records
                    vector<string> row;
                    for (const auto& e: entryA) {
                        row.push_back(e);
                    }
                    for (int i=0;i<entryB.size();i++){
                        string header = tableB[0][i];
                        if (std::find(commonHeaders.begin(), commonHeaders.end(), header) == commonHeaders.end()){
                            row.push_back(entryB[i]);
                        }
                    }
                    result.push_back(row);
                }
            }
        }

        return result;
    }

    // Code snippet referenced from: https://www.geeksforgeeks.org/joining-tables-using-multimaps/
    static table joinOrCrossProduct(const table& a, const table& b) {
        vector<string> commonHeaders = findCommonHeaders(a, b);

        if (!commonHeaders.empty()) {
            return nestedLoopJoin(a, b);
        }
        else {
            // Perform cross product
            table result;

            // Add header from table A
            result.push_back({a[0].begin(), a[0].end()});
            // Extend with header from table B
            for (const auto header : b[0]) {
                result[0].push_back(header);
            }

            for (size_t i = 1; i < a.size(); ++i) {
                for (size_t j = 1; j < b.size(); ++j) {
                    vector<string> row(a[i].begin(), a[i].end());
                    row.insert(row.end(), b[j].begin(), b[j].end());
                    result.push_back(std::move(row));
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

    std::string toString() {
        std::stringstream ss;
        for (const auto& row : _table) {
            for (const auto& e : row)
                ss << e << ' ';
            ss << std::endl;
        }
        return ss.str();
    }


};


#endif //SPA_RESULTTABLE_H
