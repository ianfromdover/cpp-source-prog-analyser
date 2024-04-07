//
// Created by sjh_9 on 5/4/2024.
//

#ifndef SPA_AGGREGATOR_H
#define SPA_AGGREGATOR_H

#include "sp/cfg/block/Block.h"

class Aggregator {
public:
    std::unordered_set<std::shared_ptr<Block>> info;
    Aggregator() = default;

    Aggregator(const Aggregator& copy) {
        info = copy.info;
    }

    bool operator!=(const Aggregator& other) const {
        return this->info != other.info;
    }

    void merge(const Aggregator& other) {
        this->info.insert(other.info.begin(), other.info.end());
    }

};
#endif //SPA_AGGREGATOR_H
