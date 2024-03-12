//
// Created by Chua Bing Quan on 21/2/24.
//

#include "RelationExtractor.h"

void RelationExtractor::visitProcedure(const Procedure& procedure, std::shared_ptr<Accumulator>& info) {
    for (const auto& stmt : *procedure.getBody()) {
        auto parentInfo = std::make_shared<Accumulator>();
        stmt->accept(*this, parentInfo);
    }
}