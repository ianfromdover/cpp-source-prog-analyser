//
// Created by tohzh on 8/2/2024.
//

#ifndef SPA_WHILEENTITY_H
#define SPA_WHILEENTITY_H

#include "StatementReference.h"

class WhileEntity : public StatementReference, Entity {
public:
    std::string getReturnType() override;
    std::string getEntityType() override;
};



#endif //SPA_WHILEENTITY_H
