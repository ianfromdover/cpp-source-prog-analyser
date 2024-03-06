//
// Created by Chua Bing Quan on 22/2/24.
//

#include "common/base_exception/BaseException.h"

#ifndef SPA_PARSEEXCEPTION_H
#define SPA_PARSEEXCEPTION_H

class ParseException : public BaseException {
public:
    explicit ParseException(std::string message) : BaseException(message) {}
};

#endif //SPA_PARSEEXCEPTION_H