//
// Created by Chua Bing Quan on 28/3/24.
//

#ifndef SPA_VAROCCURRENCE_H
#define SPA_VAROCCURRENCE_H

#include <string>
#include <utility>
#include "common/SpaTypes.h"

class VarOccurrence {
private:
    std::string name;
    std::shared_ptr<std::vector<StmtNo>> occurrences;
public:
    explicit VarOccurrence(std::string name) : name(std::move(name)), occurrences(std::make_shared<std::vector<StmtNo>>()) {}
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::shared_ptr<std::vector<StmtNo>> getOccurrences() const;
    void addOccurrence(StmtNo stmtNo);
    bool operator==(const VarOccurrence& other) const;
};

#endif //SPA_VAROCCURRENCE_H
