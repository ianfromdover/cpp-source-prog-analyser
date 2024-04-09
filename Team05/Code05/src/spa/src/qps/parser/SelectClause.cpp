//
// Created by Alex on 16/2/2024.
//

#include "SelectClause.h"
#include "qps/tokenizer/QPSToken.h"
#include "qps/exceptions/QPSException.h"


void SelectClause::addSelect(const std::string &selectElement) {
    selectElements.push_back(selectElement);
}

std::vector<std::string> SelectClause::getAllSelect() {
    return this->selectElements;
}

std::vector<QPSToken> SelectClause::getAllSelectEntities() {
    return this->selectEntities;
}

std::vector<QPSToken> SelectClause::getAllSelectAttributes() {
    return this->selectAttributes;
}


void SelectClause::addSelectArgument(QPSToken &entity, QPSToken &attribute) {

}

QPSToken SelectClause::getSelectEntityAt(int i) {
    if (i < 0 || i >= selectEntities.size()){
        throw QPSException("invalid array access");
    }
    return this->selectEntities[i];
}

QPSToken SelectClause::getSelectAttributeAt(int i) {
    if (i < 0 || i >= selectAttributes.size()){
        throw QPSException("invalid array access");
    }
    return this->selectAttributes[i];
}





