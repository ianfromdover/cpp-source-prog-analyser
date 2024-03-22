//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "PatternClause.h"
#include "qps/Exceptions/QpsException.h"


std::string PatternClause::getSecondArgValue() {
    if (secondArg != nullptr) {
        return secondArg->getLexeme();
    }
    throw QpsException("Second argument is not set");
}

std::string PatternClause::getFirstArgValue() {
    if (firstArg != nullptr) {
        return firstArg->getLexeme();
    }
    throw QpsException("First argument is not set");
}

QPSTokenType::QPSTypeInfo PatternClause::getSecondArgType() {
    if (secondArg != nullptr) {
        return secondArg->getType().getInfo();
    }
    throw QpsException("Second argument is not set");
}

QPSTokenType::QPSTypeInfo PatternClause::getFirstArgType() {
    if (firstArg != nullptr) {
        return firstArg->getType().getInfo();
    }
    throw QpsException("First argument is not set");
}

std::string PatternClause::getPatternSynonym() {
    return synonym;
}

QPSTokenType::QPSTypeInfo PatternClause::getFirstReferenceType() {
    return firstArgType;
}

QPSTokenType::QPSTypeInfo PatternClause::getSecondReferenceType() {
    return secondArgType;
}

QPSToken &PatternClause::getFirstArg() {
    if (firstArg != nullptr) {
        return *firstArg;
    }
    throw QpsException("First argument is not set");
}

QPSToken &PatternClause::getSecondArg() {
    if (secondArg != nullptr) {
        return *secondArg;
    }
    throw QpsException("Second argument is not set");
}
