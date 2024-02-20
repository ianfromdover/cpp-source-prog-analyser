//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_CLAUSE_H
#define SPA_CLAUSE_H


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

private:
    ClauseType type_;
};


#endif //SPA_CLAUSE_H
