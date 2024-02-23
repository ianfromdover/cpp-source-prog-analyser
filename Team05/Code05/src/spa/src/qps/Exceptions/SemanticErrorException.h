//
// Created by Alex on 12/2/2024.
//

#ifndef SPA_SEMANTICERROREXCEPTION_H
#define SPA_SEMANTICERROREXCEPTION_H

#include <exception>
#include "../../utilSpa/base_exception/BaseException.h"

class SemanticErrorException : public BaseException {
public:
    explicit SemanticErrorException(const std::string& message) : BaseException("Semantic Error: " + message) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message_.c_str();
    }
private:
    std::string message_;
};
#endif //SPA_SEMANTICERROREXCEPTION_H
