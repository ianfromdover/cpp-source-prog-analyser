//
// Created by Alex on 23/2/2024.
//

#ifndef SPA_QPSEXCEPTION_H
#define SPA_QPSEXCEPTION_H

#include <string>
#include "utilSpa/base_exception/BaseException.h"

class QPSException : public BaseException {
public:
    QPSException(const std::string& message) : BaseException("QPS Error: " + message) {}
    const char* what() const noexcept override {
        return msg;
    }
private:
    const char* msg;
};

#endif //SPA_QPSEXCEPTION_H
