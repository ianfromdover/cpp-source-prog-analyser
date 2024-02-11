//
// Created by Alex on 8/2/2024.
//

#include "DeclarationHandler.h"
#include "utilSpa/StringUtils.h"
#include "DeclarationComponent.h"
#include "qps/Exceptions/SyntaxErrorException.h"
#include <regex>
#include <vector>


std::shared_ptr<QueryComponent> DeclarationHandler::handle(std::string& str) {

    std::shared_ptr<DeclarationComponent> component = std::make_shared<DeclarationComponent>();

    std::regex entityPattern(R"(^(stmt)\s+([a-zA-Z][a-zA-Z0-9]*)(?:,\s*([a-zA-Z][a-zA-Z0-9]*))*$)");

    std::sregex_iterator iterator(str.begin(), str.end(), entityPattern);
    std::sregex_iterator end;
    std::smatch matches;
    std::string entity;
    if (std::regex_search(str, matches, entityPattern)) {
        std::cout << "Handled by Declaration Handler: " << str << std::endl;
        if (matches[1].matched) {
            std::string entityType = matches[1];

            StringUtils::trimAll(str);
            StringUtils::removePrefix(str, entityType);
            StringUtils::trimAll(str);

            std::vector<std::string> synList = StringUtils::splitString(str, ',');
            for (const std::string& syn : synList){
                component->addDeclaration(entityType, syn);
            }

            return component;
        }

        else throw std::runtime_error("BUG::SelectHandler matching regex but not matching required groups");

    } else {
        if (nextHandler) return nextHandler->handle(str);
        else throw SyntaxErrorException(str.c_str());
    }
}
