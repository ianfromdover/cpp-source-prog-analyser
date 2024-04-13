//
// Created by Chua Bing Quan on 28/3/24.
//

#include "VarOccurrence.h"

std::string VarOccurrence::getName() const {
    return this->name;
}

std::shared_ptr<std::set<StmtNo>> VarOccurrence::getOccurrences() const {
    return this->occurrences;
}

void VarOccurrence::addOccurrence(StmtNo stmtNo) {
    this->occurrences->insert(stmtNo);
}

bool VarOccurrence::operator==(const VarOccurrence& other) const {
    return this->name == other.name && *(this->occurrences) == *(other.occurrences);
}