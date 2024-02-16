//
// Created by Alex on 16/2/2024.
//

#include "SelectClause.h"

namespace qps {
    void SelectClause::addSelect(const std::string &selectElement) {
        selectElements.push_back(selectElement);
    }

    std::vector<std::string> SelectClause::getAllSelect() {
        return this->selectElements;
    }
}