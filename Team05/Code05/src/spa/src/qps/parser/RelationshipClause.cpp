//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "RelationshipClause.h"

namespace qps {
    void RelationshipClause::setFirstArg(Token &t1) {
        firstArg = std::make_shared<Token>(t1);
    }

    void RelationshipClause::setSecondArg(Token &t2) {
        secondArg = std::make_shared<Token>(t2);
    }

    std::string RelationshipClause::getSecondArgValue() {
        if (secondArg != nullptr) {
            return secondArg->getLexeme();
        }
        throw std::runtime_error("Second argument is not set");
    }

    std::string RelationshipClause::getFirstArgValue() {
        if (firstArg != nullptr) {
            return firstArg->getLexeme();
        }
        throw std::runtime_error("First argument is not set");
    }

    TokenType::TypeInfo RelationshipClause::getSecondArgType() {
        if (secondArg != nullptr) {
            return secondArg->getType().getInfo();
        }
        throw std::runtime_error("Second argument is not set");
    }

    TokenType::TypeInfo RelationshipClause::getFirstArgType() {
        if (firstArg != nullptr) {
            return firstArg->getType().getInfo();
        }
        throw std::runtime_error("First argument is not set");
    }
}
