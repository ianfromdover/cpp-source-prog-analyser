//
// Created by tohzh on 20/3/2024.
//

#ifndef SPA_LITERALWITH_H
#define SPA_LITERALWITH_H

#include "WithReference.h"

class LiteralWith : public WithReference {
private:
    std::string value;
public:
    LiteralWith(std::string);
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPKBVirtual & pkb) override;
    std::vector<std::vector<std::string>> getRawTable(QueryPKBVirtual & pkb) override;
    void setVariable(std::shared_ptr<QueryObject>) override;
};


#endif //SPA_LITERALWITH_H
