//
// Created by Alex on 8/2/2024.
//

#include "DeclarationHandler.h"
#include "Utils/Utils.h"
#include "DeclarationComponent.h"
#include "qps/query_elements/StatementEntity.h"
#include <regex>
#include <vector>


std::shared_ptr<QueryComponent> DeclarationHandler::handle(std::string& str) {
    std::cout << "Declaration handler: " << str << std::endl;

    parseDeclaration(str);
    std::shared_ptr<DeclarationComponent> component = createComponent();
    return component;
}

void DeclarationHandler::parseDeclaration(std::string& s) {
    std::regex entityPattern(R"(^(variable)\s+([a-zA-Z][a-zA-Z0-9]*)(?:,\s*([a-zA-Z][a-zA-Z0-9]*))*$)");

    std::sregex_iterator iterator(s.begin(), s.end(), entityPattern);
    std::sregex_iterator end;

    std::smatch matches;
    std::string entity;
    if (std::regex_search(s, matches, entityPattern)) {
        if (matches[1].matched) {
            entity = matches[1];
        }

    }

    Utils::trimAll(s);
    Utils::removePrefix(s, entity);
    Utils::trimAll(s);

    std::vector<std::string> synList = Utils::splitString(s, ',');
    for (const std::string& syn : synList){
        synonyms.push_back(syn);
    }
}

std::shared_ptr<DeclarationComponent> DeclarationHandler::createComponent() {
    std::shared_ptr<DeclarationComponent> component(new DeclarationComponent);
    for (const std::string& syn : synonyms){
        Declaration d;
        d.entityType = new StatementEntity();
        d.identifier = syn;
        component->addDeclaration(d);
    }
    return component;
}


