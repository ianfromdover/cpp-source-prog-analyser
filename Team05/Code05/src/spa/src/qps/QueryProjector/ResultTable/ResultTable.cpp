//
// Created by Alex on 7/2/2024.
//
//
//#include <algorithm>
//#include "ResultTable.h"
//
////void ResultTable::add(std::vector<Column<std::string>> input) {
//    if (input.size()==0) return;
//    if (this->columns.empty()) {
//        for (const auto& col : input) {
//            map[col.getHeader()] = col;
//            headers.push_back(col.getHeader());
//            this->columns.push_back(col);
//        }
//    }
//    else {
//        // need to join or cross
//        cross(input);
//    }
//}
//
//
//
//void ResultTable::join(std::vector<Column<std::string>> input) {
//    // find common headers
//    std::vector<std::string> headers1 = this->headers;
//    std::vector<std::string> headers2;
//    for (const auto& col : input) {
//        headers2.push_back(col.getHeader());
//    }
//    std::vector<std::string> commonHeaders;
//    std::set_intersection(headers1.begin(), headers1.end(), headers2.begin(), headers2.end(), std::back_inserter(commonHeaders));
//if (commonHeaders.empty()) {
//        // no common headers, perform cross product
//        cross(input);
//    }
//    else {
//        // find common elements in the common headers
//        std::vector<std::string> commonElements;
//        for (const auto& header : commonHeaders) {
//            Column<std::string>& col1 = map[header];
//            Column<std::string>& col2 = input[header];
//            std::vector<std::string> elements1 = col1.getAllElements();
//            std::vector<std::string> elements2 = col2.getAllElements();
//            std::vector<std::string> temp;
//            std::set_intersection(elements1.begin(), elements1.end(), elements2.begin(), elements2.end(), std::back_inserter(temp));
//            commonElements = temp;
//        }
//            
//        // using common headers, filter both tables
//        // perform cross product
//    }
//}
//
//void ResultTable::cross(std::vector<Column<std::string>> input) {
//    std::vector<Column<std::string>> tempTable;
//    // Perform Cartesian product
//    for (size_t i = 0; i < columns.size(); ++i) {
//        for (size_t j = 0; j < input.size(); ++j) {
//            Column<std::string>& col1 = columns[i];
//            Column<std::string>& col2 = input[j];
//
//            // Create a new column for the Cartesian product
//            Column<std::string> resultColumn;
//            resultColumn.setHeader(col1.getHeader() + "_" + col2.getHeader());
//
//            // Get all elements of both columns
//            const std::vector<std::string>& elements1 = col1.getAllElements();
//            const std::vector<std::string>& elements2 = col2.getAllElements();
//
//            // Perform Cartesian product for each pair of elements
//            for (const std::string& element1 : elements1) {
//                for (const std::string& element2 : elements2) {
//                    // Combine elements and add to the result column
//                    resultColumn.addElement(element1 + "_" + element2);
//                }
//            }
//
//            // Add the result column to the result table
//            tempTable.push_back(resultColumn);
//        }
//    }
//
//}
//
//void ResultTable::addSingleColumn(Column<std::string> column) {
//    if (columns.empty()){
//        map[column.getHeader()] = column;
//        this->columns.push_back(column);
//    }
//    else {
//        if (map.find(column.getHeader()) != map.end()) {
//            // synonym already exists
//            // need to join
//        }
//        else {
//            // need to cross
//        }
//    }
//
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

using table = vector<vector<string>>;

ostream& operator<<(ostream& o, const table& t) {
    for (const auto& row : t) {
        for (const auto& e : row)
            o << e << '\t';
        o << endl;
    }
    return o;
}

vector<string> findCommonHeaders(const table& a, const table& b) {
    vector<string> commonHeaders;
    for (const auto& headerA : a[0]) {
        for (const auto& headerB : b[0]) {
            if (headerA == headerB) {
                commonHeaders.push_back(headerA);
            }
        }
    }
    return commonHeaders;
}

size_t findColumnIndex(const table& table, const string& header) {
    for (size_t i = 0; i < table[0].size(); ++i) {
        if (table[0][i] == header) {
            return i;
        }
    }
    return string::npos; // Not found
}

table joinOrCrossProduct(const table& a, const table& b) {
    vector<string> commonHeaders = findCommonHeaders(a, b);

    if (!commonHeaders.empty()) {
        // Perform inner join on common headers
        table result;
        result.push_back({a[0].begin(), a[0].end()}); // Add header from table A
        result[0].insert(result[0].end(), b[0].begin(), b[0].end()); // Extend with header from table B

        size_t columnA = findColumnIndex(a, commonHeaders[0]);
        size_t columnB = findColumnIndex(b, commonHeaders[0]);

        for (size_t i = 1; i < a.size(); ++i) {
            for (size_t j = 1; j < b.size(); ++j) {
                if (a[i][columnA] == b[j][columnB]) {
                    vector<string> row(a[i].begin(), a[i].end());
                    row.insert(row.end(), b[j].begin(), b[j].end());
                    result.push_back(move(row));
                }
            }
        }
        return result;
    } else {
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
