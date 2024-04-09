//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_SELECTCLAUSE_H
#define SPA_SELECTCLAUSE_H

#include <vector>
#include <string>
#include "Clause.h"
#include "qps/tokenizer/QPSToken.h"


class SelectClause : public Clause {
public:
    SelectClause() : Clause(ClauseType::SELECT) {}

    void addSelect(const std::string &);

    void setSelectBool(){
        selectBool = true;
    }

    std::vector<std::string> getAllSelect();
    std::vector<std::string> selectElements;

    void addSelectArgument(QPSToken &entity, QPSToken &attribute);
    std::vector<QPSToken> getAllSelectEntities();
    std::vector<QPSToken> getAllSelectAttributes();
    std::vector<QPSToken> selectEntities;
    QPSToken getSelectEntityAt(int);
    std::vector<QPSToken> selectAttributes;
    QPSToken getSelectAttributeAt(int);

    bool isSelectBool() {
        return selectBool;
    }

    bool operator==(const SelectClause& other) const  {
        return selectElements == other.selectElements;
    }

    std::string toString() {
        std::string result = "Select: ";
        for (const auto &selectElement : selectElements) {
            result += selectElement + " ";
        }
        return result;
    }

  private:
    bool selectBool = false;


};


#endif //SPA_SELECTCLAUSE_H
