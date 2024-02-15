//
// Created by tohzh on 8/2/2024.
//

#include "WildCard.h"

std::string WildCard::getEntityType() {
    return RETURN_TYPE_WILDCARD;
}

std::string WildCard::getReferenceType() {
    return REFERENCE_TYPE_WILDCARD;
}

std::string WildCard::getArgumentValue() {
    return "";
}
