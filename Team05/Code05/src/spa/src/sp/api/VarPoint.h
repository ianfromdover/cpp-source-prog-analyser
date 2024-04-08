//
// Created by Chua Bing Quan on 28/3/24.
//

#ifndef SPA_VARPOINT_H
#define SPA_VARPOINT_H

#include <string>
#include "common/SpaTypes.h"

class VarPoint {
private:
    std::string name;
    StmtNo stmtNo;
public:
    explicit VarPoint(std::string name, StmtNo stmtNo) : name(name), stmtNo(stmtNo) {}
    std::string getName() const;
    StmtNo getStmtNo() const;
    bool operator==(const VarPoint& other) const;
};

namespace std {
    template <>
    struct hash<VarPoint> {
        size_t operator()(const VarPoint& var) const {
            return hash<std::string>()(var.getName()) ^ hash<StmtNo>()(var.getStmtNo());
        }
    };
}


#endif //SPA_VARPOINT_H
