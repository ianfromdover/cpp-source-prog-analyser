//
// Created by sjh_9 on 20/2/2024.
//

#ifndef SPA_ACCUMULATOR_H
#define SPA_ACCUMULATOR_H

#include <vector>
#include <iostream>
#include <memory>
#include "common/SpaTypes.h"

class Accumulator {
public:
    std::vector<StmtNo> info;
    Accumulator() = default;

    Accumulator(Accumulator& copy) {
        info = copy.info;
    }
};


#endif //SPA_ACCUMULATOR_H
