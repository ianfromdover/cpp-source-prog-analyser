//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_IFENTITY_H
#define SPA_IFENTITY_H


#include "StatementReference.h"

class IfEntity : public StatementReference, Entity {
public:
    std::string getReturnType() override;
    std::string getEntityType() override;
};



#endif //SPA_IFENTITY_H
