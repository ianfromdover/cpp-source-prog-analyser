//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_QPSTOKENSTRATEGY_H
#define SPA_QPSTOKENSTRATEGY_H

#include <sstream>
#include <functional>
#include "QPSTokenList.h"

class QPSTokenStrategy {
public:
    virtual ~QPSTokenStrategy() = default;

    virtual bool
    tokenize(char character, std::stringstream &stream, QPSTokenList &tokens, bool &prevTokenIsKeyword) = 0;
};


#endif //SPA_QPSTOKENSTRATEGY_H
