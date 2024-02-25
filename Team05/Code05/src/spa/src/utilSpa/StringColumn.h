//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_STRINGCOLUMN_H
#define SPA_STRINGCOLUMN_H

#include <utility>
#include <vector>
#include <string>

class StringColumn {
private:
    std::vector<std::string> stringVector;
    std::string header;

public:
    StringColumn() = default;

    // Function to add string into vector
    void addString(const std::string& str) {
        stringVector.push_back(str);
    }

    // Function to search indices of a string
    std::vector<int> searchIndices(const std::string& str) {
        std::vector<int> indices;
        for (int i = 0; i < str.size(); ++i) {
            if (stringVector[i] == str) {
                indices.push_back(i);
            }
        }
        return indices;
    }

    // Function to get string vector by indices
    std::vector<std::string> getElementsByIndices(std::vector<int> indices) {
        std::vector<std::string> result;
        for (int index : indices) {
            if (index >= 0 && index < stringVector.size()) {
                result.push_back(stringVector[index]);
            }
        }
        return result;
    }

    // Function to get string by index
    std::string getStringByIndex(int index) {
        return stringVector[index];
    }

    // Function to get the entire string vector
    std::vector<std::string> getStringVector() {
        return stringVector;
    }

    // Function to get the header
    [[nodiscard]] const std::string &getHeader() const {
        return header;
    }

    // Function to set the header
    void setHeader(std::string info) {
        StringColumn::header = std::move(info);
    }

};

#endif //SPA_STRINGCOLUMN_H
