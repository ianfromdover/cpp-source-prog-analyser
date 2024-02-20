//
// Created by Alex on 15/2/2024.
//

#include "QPSTokenType.h"

std::string QPSTokenType::toString() const {
    switch (info) {
        case INTEGER:
            return "INTEGER";
        case SEMICOLON:
            return "SEMICOLON";
        case LEFT_PAREN:
            return "LEFT_PAREN";
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
        case QUOTE:
            return "QUOTE";
        case ENT_REF:
            return "ENT_REF";
        case STMT_REF:
            return "STMT_REF";
        case QUOTED_IDENT:
            return "QUOTED_IDENT";
        case WILDCARD:
            return "WILDCARD";
        case PATTERN:
            return "PATTERN";
        case SUCH:
            return "SUCH";
        case THAT:
            return "THAT";
        case COMMA:
            return "COMMA";
        case PARENT:
            return "PARENT";
        case SELECT:
            return "SELECT";
        case IDENTIFIER:
            return "IDENTIFIER";
        case END_OF_FILE:
            return "EOF";
        case STMT1:
            return "STMT";
        case SYNONYM:
            return "SYNONYM";

        default:
            return "UNKNOWN";
    }
}

QPSTokenType::QPSTokenType(QPSTokenType::QPSTypeInfo info) : info(info) {}

QPSTokenType::QPSTypeInfo QPSTokenType::getInfo() {
    return this->info;
}

