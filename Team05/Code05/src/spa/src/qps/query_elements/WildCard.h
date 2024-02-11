//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_WILDCARD_H
#define SPA_WILDCARD_H

#include "StatementReference.h"

class WildCard : public StatementReference {
public:
    std::string getEntityType() override;
};


#endif //SPA_WILDCARD_H
