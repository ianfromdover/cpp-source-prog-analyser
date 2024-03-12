//
// Created by yewme on 15/2/2024.
//

#ifndef SPA_BASEEXCEPTION_H
#define SPA_BASEEXCEPTION_H

#include <exception>
#include <utility>
#include <string>

class BaseException : public std::exception {
public:
    explicit BaseException(std::string message) : message_(std::move(message)) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};


#endif //SPA_BASEEXCEPTION_H
