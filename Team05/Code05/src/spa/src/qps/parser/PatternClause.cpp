//
// Created by Alex on 16/2/2024.
//

#include <stdexcept>
#include "PatternClause.h"
#include "qps/exceptions/QPSException.h"


//std::string PatternClause::getSecondArgValue() {
//    if (secondArg != nullptr) {
//        return secondArg->getLexeme();
//    }
//    throw QPSException("Second argument is not set");
//}
//
//std::string PatternClause::getFirstArgValue() {
//    if (firstArg != nullptr) {
//        return firstArg->getLexeme();
//    }
//    throw QPSException("First argument is not set");
//}
//
//QPSTokenType::QPSTypeInfo PatternClause::getSecondArgType() {
//    if (secondArg != nullptr) {
//        return secondArg->getType().getInfo();
//    }
//    throw QPSException("Second argument is not set");
//}
//
//QPSTokenType::QPSTypeInfo PatternClause::getFirstArgType() {
//    if (firstArg != nullptr) {
//        return firstArg->getType().getInfo();
//    }
//    throw QPSException("First argument is not set");
//}

std::string PatternClause::getPatternSynonym() {
    return synonym;
}

//QPSTokenType::QPSTypeInfo PatternClause::getFirstReferenceType() {
//    return firstArgType;
//}
//
//QPSTokenType::QPSTypeInfo PatternClause::getSecondReferenceType() {
//    return secondArgType;
//}
//
//QPSToken &PatternClause::getFirstArg() {
//    if (firstArg != nullptr) {
//        return *firstArg;
//    }
//    throw QPSException("First argument is not set");
//}
//
//QPSToken &PatternClause::getSecondArg() {
//    if (secondArg != nullptr) {
//        return *secondArg;
//    }
//    throw QPSException("Second argument is not set");
//}

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
