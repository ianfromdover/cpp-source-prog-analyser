//
// Created by Alex on 12/2/2024.
//

#include "catch.hpp"
#include "QPS/QueryPreprocessor/DeclarationHandler.h"
#include "QPS/QueryPreprocessor/DeclarationComponent.h"

using namespace std;


TEST_CASE("declaration_handler_valid_syntax") {

    DeclarationHandler handler;
    std::string clause = "stmt a,b";
    shared_ptr<QueryComponent> component;
    REQUIRE_NOTHROW(component = handler.handle(clause));

    shared_ptr<DeclarationComponent> expected = make_shared<DeclarationComponent>(DeclarationComponent());
    expected->addDeclaration("stmt","a");
    expected->addDeclaration("stmt","b");

    shared_ptr<DeclarationComponent> actual = dynamic_pointer_cast<DeclarationComponent>(component);
    REQUIRE(actual != nullptr);
}

TEST_CASE("declaration_handler_invalid_syntax_throws") {

    DeclarationHandler handler;
    std::string clause = "stmt a,12";
    shared_ptr<QueryComponent> component;
    REQUIRE_THROWS(component = handler.handle(clause));

}


