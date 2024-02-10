//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_PRINTENTITY_H
#define SPA_PRINTENTITY_H


#include "StatementReference.h"

class PrintEntity : public StatementReference, public Entity {
public:
    std::string getReturnType() override;
    std::string getEntityType() override;
};


#endif //SPA_PRINTENTITY_H
