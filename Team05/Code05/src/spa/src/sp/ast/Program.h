//
// Created by Chua Bing Quan on 6/3/24.
//

#ifndef SPA_PROGRAM_H
#define SPA_PROGRAM_H

#include <vector>
#include "ProcedureMapAccess.h"

using ProcedureMap = std::unordered_map<std::string, std::shared_ptr<Procedure>>;

class Program : public ProcedureMapAccess {
private:
    std::shared_ptr<Procedures> procedures;
    std::shared_ptr<ProcedureMap> procedureMap;
public:
    explicit Program(const std::shared_ptr<Procedures>& procedures);
    std::shared_ptr<Procedure> getProcedure(std::string name) override;
    std::shared_ptr<Procedures> getProcedures() override;
};


#endif //SPA_PROGRAM_H
