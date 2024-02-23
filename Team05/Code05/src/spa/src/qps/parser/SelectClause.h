//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_SELECTCLAUSE_H
#define SPA_SELECTCLAUSE_H

#include <vector>
#include <string>
#include "Clause.h"


class SelectClause : public Clause {
public:
    SelectClause() : Clause(ClauseType::SELECT) {}

    void addSelect(const std::string &);

    std::vector<std::string> getAllSelect();

    std::vector<std::string> selectElements;

    bool operator==(const SelectClause& other) const  {
        return selectElements == other.selectElements;
    }

    std::string toString() {
        std::string result = "Select: ";
        for (const auto &selectElement : selectElements) {
            result += selectElement + " ";
        }
        return result;
    }

};


#endif //SPA_SELECTCLAUSE_H
