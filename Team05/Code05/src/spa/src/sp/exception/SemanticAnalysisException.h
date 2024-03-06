//
// Created by Chua Bing Quan on 21/2/24.
//

#ifndef SPA_SEMANTICANALYSISEXCEPTION_H
#define SPA_SEMANTICANALYSISEXCEPTION_H

#include "common/base_exception/BaseException.h"

class SemanticAnalysisException : public BaseException {
public:
    explicit SemanticAnalysisException(std::string message) : BaseException(message) {}
};

#endif //SPA_SEMANTICANALYSISEXCEPTION_H
