//
// Created by tohzh on 21/3/2024.
//

#include "Tuple.h"

void Tuple::addEntityVector(std::shared_ptr<Entity> e) {
    if (this->entityVector.empty()) {
        this->entityVector = std::vector<std::shared_ptr<Entity>>();
    }
    this->entityVector.push_back(e);
}

std::vector<std::vector<std::string>> Tuple::getEntityTable(QueryPkbVirtual &pkb) {
    std::vector<std::vector<std::string>> result;
    for (std::shared_ptr<Entity> ent : entityVector) {
        std::vector<std::vector<std::string>> table = ent->getEntityTable(pkb);
        result.push_back(table.at(0));
    }
    return result;
}

std::string Tuple::getArgumentValue() {
    std::string result;
    for (size_t i = 0; i < entityVector.size(); ++i) {
        result += entityVector.at(i)->getArgumentValue();
        if (i < entityVector.size() - 1) {
            result += ", ";
        }
    }
    return result;
}

std::string Tuple::toString() {
    std::string result;
    for (size_t i = 0; i < entityVector.size(); ++i) {
        result += entityVector.at(i)->toString();
        if (i < entityVector.size() - 1) {
            result += ", ";
        }
    }
    return result;
}

std::string Tuple::getReturnType() {
    std::string result;
    for (size_t i = 0; i < entityVector.size(); ++i) {
        result += entityVector.at(i)->getReturnType();
        if (i < entityVector.size() - 1) {
            result += ", ";
        }
    }
    return result;
}
