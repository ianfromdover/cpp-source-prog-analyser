//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSTOKEN_H
#define SPA_QPSTOKEN_H


#include "QPSTokenType.h"


class QPSToken {
private:
    QPSTokenType type;
    std::string lexeme;

public:
    // Constructor
    QPSToken(QPSTokenType type, std::string lexeme);

    // Getter
    [[nodiscard]] QPSTokenType getType() const;

    [[nodiscard]] std::string getLexeme() const;

    [[nodiscard]] std::string toString() const;
};


#endif //SPA_QPSTOKEN_H
