//
// Created by sjh_9 on 25/2/2024.
//

#include "QueryPKB.h"

#include <utility>

QueryPKB::QueryPKB(std::shared_ptr<PKBStorage> p) {
    pkb = std::move(p);
}

pair<IntColumn, StringColumn> QueryPKB::getRead() {
    pkb->
}
