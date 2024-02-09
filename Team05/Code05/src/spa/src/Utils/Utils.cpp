//
// Created by Alex on 8/2/2024.
//

#include "Utils.h"
#include <iostream>

std::vector<std::string> Utils::splitString(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    std::size_t start = 0;
    std::size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }

    result.push_back(str.substr(start));

    return result;
}

void Utils::printStringVector(const std::vector<std::string> &stringVector) {
    std::cout << "[ ";
    for (int i = 0; i < stringVector.size(); i++){
        std::cout << stringVector[i];
        if (i != stringVector.size()-1){
            std::cout << " , ";
        }
    }
    std::cout << " ]";
    std::cout << std::endl;
}


void Utils::trimStart(std::string& str) {
    // Find the first non-whitespace character
    size_t start = str.find_first_not_of(" \t\n\r");

    // If the string is all whitespace, return an empty string
    if (start == std::string::npos) {
        str = "";
    }

    // Return the substring starting from the first non-whitespace character
    str = str.substr(start);
}

void Utils::trimTrailing(std::string& str) {
    // Find the index of the last non-whitespace character
    size_t end = str.find_last_not_of(" \t\n\r");
    if (end == std::string::npos) {
        // If the string is all whitespace, return an empty string
        str = "";
    }

    // Return the substring from the beginning to the last non-whitespace character
    str = str.substr(0, end + 1);
}

void Utils::removePrefix(std::string& str, const std::string& prefix) {
    // Check if the string starts with the prefix
    if (str.compare(0, prefix.length(), prefix) == 0) {
        // If it does, erase the prefix from the string
        str = str.substr(prefix.length());
    }

}

void Utils::trimAll(std::string &str) {
    trimStart(str);
    trimTrailing(str);
}
