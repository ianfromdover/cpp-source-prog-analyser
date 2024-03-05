//
// Created by Alex on 23/2/2024.
//

#ifndef SPA_QPSPARSEEXCEPTION_H
#define SPA_QPSPARSEEXCEPTION_H

#include <string>
#include "utilSpa/base_exception/BaseException.h"

class QPSParseException : public BaseException {
public:
    explicit QPSParseException(const std::string& message) : BaseException("QPS Parse Error: " + message) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    std::string message_;
};

#endif //SPA_QPSPARSEEXCEPTION_H
