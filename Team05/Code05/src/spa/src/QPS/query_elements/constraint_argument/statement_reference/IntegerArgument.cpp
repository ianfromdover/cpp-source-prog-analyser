//
// Created by tohzh on 8/2/2024.
//

#include "IntegerArgument.h"

std::string IntegerArgument::getArgumentValue() {
    return RETURN_TYPE_INTEGER;
}

std::string IntegerArgument::getEntityType() {
    return RETURN_TYPE_INTEGER;
}

std::string IntegerArgument::toString() {
    return to_string(this->value) + " [INTEGER]";
}

