//
// Created by Alex on 12/2/2024.
//

#ifndef SPA_SYNTAXERROREXCEPTION_H
#define SPA_SYNTAXERROREXCEPTION_H

#include <exception>
#include "../../common/base_exception/BaseException.h"

class SyntaxErrorException : public BaseException {
public:
    explicit SyntaxErrorException(const std::string& message) : BaseException("Syntax Error: " + message) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    std::string message_;
};
#endif //SPA_SYNTAXERROREXCEPTION_H
