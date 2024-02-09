//
// Created by Alex on 8/2/2024.
//

#include "SelectHandler.h"

std::shared_ptr<QueryComponent> SelectHandler::handle(std::string& str) {
    std::cout << "Select handler: " << str << std::endl;
    if (!true) {
        std::cout << "Handled by Select Handler: " << str << std::endl;
    } else {
        std::cout << "Select Handler unable to handle: " << str << std::endl;
        if (nextHandler) nextHandler->handle(str);
        else throw std::runtime_error("no handlers able to process!");
    }
    return nullptr;
}
