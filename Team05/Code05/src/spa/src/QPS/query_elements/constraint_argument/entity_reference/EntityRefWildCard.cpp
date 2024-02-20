//
// Created by tohzh on 8/2/2024.
//

#include "EntityRefWildCard.h"

std::string EntityRefWildCard::getEntityType() {
    return RETURN_TYPE_WILDCARD;
}

std::string EntityRefWildCard::toString() {
    return "_ [ENT WILDCARD]";
}
