//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "PatternClause.h"

namespace qps {
    std::string PatternClause::getSecondArgValue() {
        if (secondArg != nullptr) {
            return secondArg->getLexeme();
        }
        throw std::runtime_error("Second argument is not set");
    }

    std::string PatternClause::getFirstArgValue() {
        if (firstArg != nullptr) {
            return firstArg->getLexeme();
        }
        throw std::runtime_error("First argument is not set");
    }

    TokenType::TypeInfo PatternClause::getSecondArgType() {
        if (secondArg != nullptr) {
            return secondArg->getType().getInfo();
        }
        throw std::runtime_error("Second argument is not set");
    }

    TokenType::TypeInfo PatternClause::getFirstArgType() {
        if (firstArg != nullptr) {
            return firstArg->getType().getInfo();
        }
        throw std::runtime_error("First argument is not set");
    }

    std::string PatternClause::getPatternSynonym() {
        return synonym;
    }
}