//
// Created by Chua Bing Quan on 13/2/24.
//

#ifndef SPA_PRETTYPRINTER_H
#define SPA_PRETTYPRINTER_H


#include "Stmt.h"

class PrettyPrinter {
public:
    static std::string print(Program const& program);
};


#endif //SPA_PRETTYPRINTER_H
