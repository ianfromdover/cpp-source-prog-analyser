//
// Created by sjh_9 on 23/2/2024.
//

#ifndef SPA_TOKENEXCEPTION_H
#define SPA_TOKENEXCEPTION_H

#include "utilSpa/base_exception/BaseException.h"


class TokenException : public BaseException {
public:
    explicit TokenException(std::string message) : BaseException(message) {}
};


#endif //SPA_TOKENEXCEPTION_H
