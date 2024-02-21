//
// Created by tohzh on 21/2/2024.
//

#include "qps/query_builder/QueryObjectBuilder.h"
#include "qps/parser/IntermediateQuery.h"
#include "qps/parser/DeclarationClause.h"
#include "qps/parser/PatternClause.h"
#include "qps/parser/SelectClause.h"

#include "catch.hpp"
#include <iostream>
using namespace std;

TEST_CASE("queryObjectBuilder_onlyOneDeclaration_returnsQO") {
    QueryObjectBuilderTest builder;
    IntermediateQuery intQuery;
    std::shared_ptr<DeclarationClause> dec;
    dec->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "p");
    intQuery.addClause(dec);
    std::shared_ptr<QueryObject> qo = builder.build(std::make_shared<IntermediateQuery>(intQuery));
    std::cout << qo->toString();
}