//
// Created by tohzh on 20/3/2024.
//

#ifndef SPA_VARIABLEWITH_H
#define SPA_VARIABLEWITH_H

#include "WithReference.h"
#include "../../Entity.h"
#include "qps/tokenizer/QPSTokenType.h"
#include "qps/Exceptions/QPSException.h"

class VariableWith : public WithReference, public Entity {
private:
    std::shared_ptr<Entity> variable;
    std::string varName;
    QPSTokenType::QPSTypeInfo varAttribute;
    bool hasMoreThanOneColumn(std::vector<std::vector<std::string>>);
    std::vector<std::vector<std::string>> removeColumnByIndex(int, std::vector<std::vector<std::string>>);
public:
    VariableWith(std::string, QPSTokenType::QPSTypeInfo);
    std::string getReturnType() override;
    std::string getEntityType() override;
    std::string toString() override;
    std::string getArgumentValue() override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPKBVirtual & pkb) override;
    std::string getVarName();
    QPSTokenType::QPSTypeInfo getVarAttribute();
    std::vector<std::vector<std::string>> getRawTable(QueryPKBVirtual & pkb) override;
    void setVariable(std::shared_ptr<QueryObject>) override;
};

#endif //SPA_VARIABLEWITH_H
