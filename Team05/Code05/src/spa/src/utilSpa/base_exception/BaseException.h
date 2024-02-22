//
// Created by yewme on 15/2/2024.
//

#ifndef SPA_BASEEXCEPTION_H
#define SPA_BASEEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class BaseException : public std::exception {
public:
    explicit BaseException(std::string message) : msg(message) {}

    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }
private:
    std::string msg;
};


#endif //SPA_BASEEXCEPTION_H
