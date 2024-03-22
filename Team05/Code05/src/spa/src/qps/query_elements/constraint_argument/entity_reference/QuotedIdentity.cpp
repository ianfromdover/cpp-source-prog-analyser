//
// Created by tohzh on 21/2/2024.
//

#include "QuotedIdentity.h"
#include "qps/Exceptions/QpsException.h"

std::string QuotedIdentity::getEntityType() {
    return TYPE_QUOTED_IDENT;
}

std::string QuotedIdentity::toString() {
    return this->val + " [QUOTED IDENT]";
}

QuotedIdentity::QuotedIdentity(std::string& s) {
    this->val = s;
}

std::string QuotedIdentity::getArgumentValue() {
    return this->val;
}

Table QuotedIdentity::getEntityTable(QueryPkbVirtual &pkb) {
    throw QpsException("Invalid QPS Query");
}

