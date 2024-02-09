//
// Created by Alex on 8/2/2024.
//

#include "RelationshipConstraintHandler.h"

void RelationshipConstraintHandler::handle(std::string& str) {
    std::cout << "Relationship handler: " << str << std::endl;
    if (true) {
        std::cout << "Handled by Relationship Handler: " << str << std::endl;
    } else {
        std::cout << "Select Relationship unable to handle: " << str << std::endl;
        if (nextHandler) nextHandler->handle(str);
        else throw std::runtime_error("no handlers able to process!");
    }
}
