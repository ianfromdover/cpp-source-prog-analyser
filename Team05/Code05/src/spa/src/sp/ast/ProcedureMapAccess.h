//
// Created by sjh_9 on 7/3/2024.
//

#ifndef SPA_PROCEDUREMAPACCESS_H
#define SPA_PROCEDUREMAPACCESS_H

#include <memory>
#include "Stmt.h"

using Procedures = std::vector<std::shared_ptr<Procedure>>;

class ProcedureMapAccess {
public:
    virtual std::shared_ptr<Procedure> getProcedure(std::string name) = 0;
    virtual std::shared_ptr<Procedures> getProcedures() = 0;
    virtual ~ProcedureMapAccess() = default;
};

#endif //SPA_PROCEDUREMAPACCESS_H
