//
// Created by tohzh on 20/3/2024.
//

#ifndef SPA_INTEGERWITH_H
#define SPA_INTEGERWITH_H

#include "WithReference.h"

class IntegerWith : public WithReference {
private:
    std::string value;
public:
    IntegerWith(std::string);
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPKBVirtual & pkb) override;
    std::vector<std::vector<std::string>> getRawTable(QueryPKBVirtual & pkb) override;
    void setVariable(std::shared_ptr<QueryObject>) override;
};


#endif //SPA_INTEGERWITH_H
