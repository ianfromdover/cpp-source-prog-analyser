//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_READENTITY_H
#define SPA_READENTITY_H


#include "StatementReference.h"

class ReadEntity : public StatementReference, public  Entity {
public:
    std::string getReturnType() override;
    std::string getEntityType() override;
};


#endif //SPA_READENTITY_H
