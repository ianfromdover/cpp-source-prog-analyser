//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSSTRATEGYLIST_H
#define SPA_QPSSTRATEGYLIST_H

#include <vector>
#include <memory>
#include "QPSTokenStrategy.h"
#include "QPSSingleCharacterStrategy.h"
#include "QPSMultiCharacterStrategy.h"


class QPSStrategyList {
private:
    std::vector<std::shared_ptr<QPSTokenStrategy>> strategies;
public:
    QPSStrategyList();

    std::vector<std::shared_ptr<QPSTokenStrategy>> &getStrategies();
};


#endif //SPA_QPSSTRATEGYLIST_H
