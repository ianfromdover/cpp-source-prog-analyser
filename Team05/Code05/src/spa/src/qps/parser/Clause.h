//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_CLAUSE_H
#define SPA_CLAUSE_H

#include <string>

class Clause {
public:
    enum ClauseType {
        DECLARATION,
        SELECT,
        RELATIONSHIP,
        PATTERN,
        WITH,
        UNDEFINED

    };
public:
    explicit Clause(ClauseType type) : type_(type) {}

    [[nodiscard]] ClauseType getType() const { return type_; }

    virtual ~Clause() = default;

    virtual std::string toString() = 0;

    void setNot(bool _notValue) {
      _not = _notValue;
    }

    bool isNot() { return _not; }

private:
    ClauseType type_;
    bool _not = false;
};


#endif //SPA_CLAUSE_H
