//
// Created by tohzh on 21/2/2024.
//

#ifndef SPA_QUOTEDIDENTITY_H
#define SPA_QUOTEDIDENTITY_H

#include "EntityReference.h"

class QuotedIdentity : public EntityReference {
private:
    std::string val;
public:
    explicit QuotedIdentity(std::string&);
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;
};


#endif //SPA_QUOTEDIDENTITY_H
