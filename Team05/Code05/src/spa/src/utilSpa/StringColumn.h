//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_STRINGCOLUMN_H
#define SPA_STRINGCOLUMN_H

#include <vector>
#include <string>

class StringColumn {
private:
    std::vector<std::string> stringVector;
public:
    StringColumn() = default;

    void addString(const std::string& str);
    std::string getStringByIndex(int index);
    std::vector<std::string> getStringVector();
};


#endif //SPA_STRINGCOLUMN_H
