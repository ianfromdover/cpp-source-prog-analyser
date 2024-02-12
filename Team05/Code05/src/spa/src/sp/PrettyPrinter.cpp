//
// Created by Chua Bing Quan on 13/2/24.
//

#include "PrettyPrinter.h"

std::string PrettyPrinter::print(Program const& program) {
    std::string result;
    for (const auto& procedure : *program) {
        result += procedure->toString() + "\n";
    }
    return result;
}
