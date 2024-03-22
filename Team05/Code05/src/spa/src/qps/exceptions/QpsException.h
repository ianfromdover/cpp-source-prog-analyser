//
// Created by Alex on 23/2/2024.
//

#ifndef SPA_QPSEXCEPTION_H
#define SPA_QPSEXCEPTION_H

#include <string>
#include "common/base_exception/BaseException.h"

class QpsException : public BaseException {
public:
    explicit QpsException(const std::string& message) : BaseException("QPS Error: " + message) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    std::string message_;
};

#endif //SPA_QPSEXCEPTION_H
