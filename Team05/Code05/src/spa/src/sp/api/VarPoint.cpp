//
// Created by Chua Bing Quan on 28/3/24.
//

#include "VarPoint.h"

std::string VarPoint::getName() const {
    return this->name;
}

StmtNo VarPoint::getStmtNo() const {
    return this->stmtNo;
}

bool VarPoint::operator==(const VarPoint &other) const {
    return name == other.name && stmtNo == other.stmtNo;
}