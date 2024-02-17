//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSTOKENLIST_H
#define SPA_QPSTOKENLIST_H


#include <memory>
#include <vector>
#include "QPSToken.h"
#include "QPSTokenType.h"


class QPSTokenList {
private:
    std::vector<std::shared_ptr<QPSToken>> tokens;
public:
    QPSTokenList() = default;

    void addToken(QPSTokenType::TypeInfo typeInfo, const std::string &lexeme);

    std::vector<std::shared_ptr<QPSToken>> &getTokens();

    std::string toString();
};


#endif //SPA_QPSTOKENLIST_H
