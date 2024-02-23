//
// Created by tohzh on 21/2/2024.
//

#include "Formattable.h"

std::string Formattable::toString() {
    std::vector<std::string> vectorStr = this->format();
    if (vectorStr.empty()) {
        return "";
    } else {
        std::string result = vectorStr[0];
        for (int i = 1; i < vectorStr.size(); ++i) {
            result += ", " + vectorStr[i];
        }
        return result;
    }
}