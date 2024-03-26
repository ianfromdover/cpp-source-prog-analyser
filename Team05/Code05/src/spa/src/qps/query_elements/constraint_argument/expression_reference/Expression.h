//
// Created by tohzh on 15/2/2024.
//

#ifndef SPA_EXPRESSION_H
#define SPA_EXPRESSION_H


#include "ExpressionReference.h"
#include "pkb/apis/QueryPKBVirtual.h"

class Expression : public ExpressionReference {
protected:
    std::string regularExpression;
public:
    explicit Expression(std::string);
    std::string getEntityType() override;
    std::string getArgumentValue() override;
    std::string toString() override;

    std::vector<std::vector<std::string>> getRawTable(QueryPKBVirtual & pkb) override;
    std::vector<std::vector<std::string>> getEntityTable(QueryPKBVirtual & pkb) override;
};


#endif //SPA_EXPRESSION_H
