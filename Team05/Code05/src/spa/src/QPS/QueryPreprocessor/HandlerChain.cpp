//
// Created by Alex on 7/2/2024.
//

#include "HandlerChain.h"
#include "Utils/Utils.h"

void HandlerChain::handle(std::string str) {
    std::cout << "handler chain received " << str <<std::endl;
    char delimitter = ';';
    std::vector<std::string> splitStr = Utils::splitString(str,delimitter);
    for (std::string s : splitStr){
        if (s.empty()) continue;
        std::cout << "processing " << s <<std::endl;
        handlerChain->handle(s);
    }
}
