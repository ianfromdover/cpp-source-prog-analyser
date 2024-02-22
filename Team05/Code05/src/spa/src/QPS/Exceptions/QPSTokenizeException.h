//
// Created by Alex on 23/2/2024.
//

#ifndef SPA_QPSTOKENIZEEXCEPTION_H
#define SPA_QPSTOKENIZEEXCEPTION_H

#include <string>
#include "utilSpa/base_exception/BaseException.h"

class QPSTokenizeException : public BaseException {
public:
    QPSTokenizeException(const std::string& message) : BaseException("QPS Tokenize Error: " + message) {}
    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};

#endif //SPA_QPSTOKENIZEEXCEPTION_H
