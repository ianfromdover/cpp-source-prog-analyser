#pragma once
#define SPA_PKB_EXCEPTION_H

#include <utility>
#include "common/base_exception/BaseException.h"

// Wraps exceptions that arise from PKB with this additional message
class PkbException : public BaseException {
public:
    explicit PkbException(std::string message) : BaseException("PKB Error: " + std::move(message)) {}
};
