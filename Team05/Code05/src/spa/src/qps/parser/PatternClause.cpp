//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "PatternClause.h"
#include "qps/exceptions/QPSException.h"

std::string PatternClause::getPatternSynonym() {
    return synonym;
}

QPSTokenType::QPSTypeInfo PatternClause::getArgTypeAtIndex(int i) {
    if (argCount < i || i < 0) {
        throw QPSException("Index out of bounds");
    }
    return args[i]->getType().getInfo();
}

QPSTokenType::QPSTypeInfo PatternClause::getReferenceTypeAtIndex(int i) {
    if (argCount < i || i < 0) {
        throw QPSException("Index out of bounds");
    }
    return argRefTypes[i];
}

std::string PatternClause::getArgValueAtIndex(int i) {
    if (argCount < i || i < 0) {
        throw QPSException("Index out of bounds");
    }
    return args[i]->getLexeme();
}

QPSToken &PatternClause::getArgAtIndex(int i) {
    if (argCount < i || i < 0) {
        throw QPSException("Index out of bounds");
    }
    return *args[i];
}
