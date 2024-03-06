//
// Created by Chua Bing Quan on 5/3/24.
//

#ifndef SPA_FORMATTEREXCEPTION_H
#define SPA_FORMATTEREXCEPTION_H

#include <utility>

#include "utilSpa/base_exception/BaseException.h"

class FormatterException : public BaseException {
public:
    explicit FormatterException(std::string message) : BaseException(std::move(message)) {}
};

class InvalidExprString : public FormatterException {
public:
    static inline const std::string ERR_MSG = "Input is not a valid expression string";
    InvalidExprString() : FormatterException(InvalidExprString::ERR_MSG) {}
};

#endif //SPA_FORMATTEREXCEPTION_H
