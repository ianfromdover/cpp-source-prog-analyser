//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_INTCOLUMN_H
#define SPA_INTCOLUMN_H

#include <vector>
#include <string>

class IntColumn {
private:
    std::vector<int> intVector;
public:
    IntColumn() = default;

    void addInt(int val);
    int getIntByIndex(int index);
    std::vector<int> getIntVector();
};


#endif //SPA_INTCOLUMN_H
