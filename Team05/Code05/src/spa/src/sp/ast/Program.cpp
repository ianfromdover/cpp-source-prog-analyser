//
// Created by Chua Bing Quan on 6/3/24.
//

#include "Program.h"

Program::Program(const std::shared_ptr<Procedures>& procedures) {
    this->procedures = procedures;
    this->procedureMap = std::make_shared<ProcedureMap>();
    for (const auto& procedure : *procedures) {
        this->procedureMap->insert({ procedure->getName(), procedure });
    }
}

std::shared_ptr<Procedure> Program::getProcedure(std::string name) {
    return this->procedureMap->at(name);
}

std::shared_ptr<Procedures> Program::getProcedures() {
    return this->procedures;
}