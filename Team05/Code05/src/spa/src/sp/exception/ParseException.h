//
// Created by Chua Bing Quan on 22/2/24.
//

#ifndef SPA_PARSEEXCEPTION_H
#define SPA_PARSEEXCEPTION_H

#include <utility>
#include "common/base_exception/BaseException.h"

class ParseException : public BaseException {
public:
    explicit ParseException(std::string message) : BaseException(std::move(message)) {}
};

#endif //SPA_PARSEEXCEPTION_H