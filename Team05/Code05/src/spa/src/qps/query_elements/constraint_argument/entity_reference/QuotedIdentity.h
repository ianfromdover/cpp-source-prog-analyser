//
// Created by tohzh on 21/2/2024.
//

#ifndef SPA_QUOTEDIDENTITY_H
#define SPA_QUOTEDIDENTITY_H

#include "EntityReference.h"
#include "pkb/apis/QueryPkbVirtual.h"

class QuotedIdentity : public EntityReference {
private:
    std::string val;
public:
    explicit QuotedIdentity(std::string&);
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;

    std::vector<std::vector<std::string>> getEntityTable(QueryPkbVirtual & pkb) override;
};


#endif //SPA_QUOTEDIDENTITY_H
