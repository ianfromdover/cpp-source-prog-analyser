//
// Created by Alex on 23/2/2024.
//

#ifndef SPA_QPSPARSEEXCEPTION_H
#define SPA_QPSPARSEEXCEPTION_H

#include <string>
#include "utilSpa/base_exception/BaseException.h"

class QPSParseException : public BaseException {
public:
    QPSParseException(const std::string& message) : BaseException("QPS Parse Error: " + message) {}
    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};

#endif //SPA_QPSPARSEEXCEPTION_H
