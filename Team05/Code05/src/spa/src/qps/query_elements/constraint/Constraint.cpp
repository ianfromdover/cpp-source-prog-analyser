//
// Created by tohzh on 20/2/2024.
//

#include "Constraint.h"

std::string Constraint::toString() {

    std::string str = getConstraintType() + "(" + this->getConstraintArguments()[0]->toString();

    if (this->getConstraintArguments().size() > 1) {
        str += ", " + this->getConstraintArguments()[1]->toString();
    }

    str += + ")";

    return str;
}

bool Constraint::isStatementSynonym(std::string type) {
    vector<std::string> statementVector = {
            TYPE_STATEMENT, TYPE_READ, TYPE_PRINT, TYPE_ASSIGN,
            TYPE_CALL, TYPE_WHILE, TYPE_IF
    };
    return std::find(statementVector.begin(), statementVector.end(), type) != statementVector.end();
}

bool Constraint::isEntitySynonym(std::string type) {
    vector<std::string> entityVector = {
            TYPE_PROCEDURE, TYPE_VARIABLE, TYPE_CONSTANT
    };
    return std::find(entityVector.begin(), entityVector.end(), type) != entityVector.end();
}

bool Constraint::isStatementOrEntitySynonym(std::string type) {
    return isEntitySynonym(type) || isStatementSynonym(type);
}

bool Constraint::getNot() {
    return this->isNot;
}

void Constraint::setNot(bool val) {
    this->isNot = val;
}

void Constraint::removeHeaders(std::vector<std::string> toRemove, shared_ptr<ResultTable> table) {
    for (std::string s : toRemove) {
        table->removeColumnByHeader(s);
    }
}

void Constraint::removeHeaders(shared_ptr<ResultTable> table) {
  for (std::string s : defaultHeaders) {
    table->removeColumnByHeader(s);
  }
}