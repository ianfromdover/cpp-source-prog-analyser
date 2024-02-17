//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_STATEMENTREFWILDCARD_H
#define SPA_STATEMENTREFWILDCARD_H

#include "StatementReference.h"

class StatementRefWildCard : public StatementReference {
public:
    std::string getEntityType() override;
};



#endif //SPA_STATEMENTREFWILDCARD_H
