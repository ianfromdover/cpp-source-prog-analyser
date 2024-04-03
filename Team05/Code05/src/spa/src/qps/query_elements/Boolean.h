//
// Created by tohzh on 21/3/2024.
//

#ifndef SPA_BOOLEAN_H
#define SPA_BOOLEAN_H


#include "Returnable.h"

class Boolean : public Returnable {
public:
    std::string getReturnType() override;
    std::string toString() override;
    std::vector<std::string> getArgumentValue() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPkbVirtual &pkb) override;
};

#endif //SPA_BOOLEAN_H
