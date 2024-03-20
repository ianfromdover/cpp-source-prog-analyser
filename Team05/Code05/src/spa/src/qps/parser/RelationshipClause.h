//
// Created by Alex on 16/2/2024.
//

#ifndef SPA_RELATIONSHIPCLAUSE_H
#define SPA_RELATIONSHIPCLAUSE_H

#include <memory>
#include "Clause.h"
#include "qps/tokenizer/QPSToken.h"


class RelationshipClause : public Clause {
public:
    RelationshipClause(QPSTokenType::QPSTypeInfo type, QPSToken &t1, QPSTokenType::QPSTypeInfo type1, QPSToken &t2,
                       QPSTokenType::QPSTypeInfo type2) : Clause(ClauseType::RELATIONSHIP) {
        relationshipType = type;

        firstArg = std::make_shared<QPSToken>(t1);
        firstArgRefType = type1;
        secondArg = std::make_shared<QPSToken>(t2);
        secondArgRefType = type2;
    }

    QPSTokenType::QPSTypeInfo getRelationshipType();

    QPSTokenType::QPSTypeInfo getFirstArgType();

    QPSTokenType::QPSTypeInfo getFirstReferenceType();

    QPSToken &getFirstArg();

    QPSTokenType::QPSTypeInfo getSecondArgType();

    QPSTokenType::QPSTypeInfo getSecondReferenceType();

    QPSToken &getSecondArg();

    void setRelationshipType(QPSTokenType::QPSTypeInfo &type);
    void setFirstReferenceType(QPSTokenType::QPSTypeInfo &type);

    bool operator==(const RelationshipClause &other) const {
        return relationshipType == other.relationshipType &&
        *firstArg == *other.firstArg &&
        firstArgRefType == other.firstArgRefType &&
        *secondArg == *other.secondArg &&
        secondArgRefType == other.secondArgRefType;
    }

    std::string toString() {
        return "Relationship: []";
    }

private:
    QPSTokenType::QPSTypeInfo relationshipType;

    std::shared_ptr<QPSToken> firstArg;
    QPSTokenType::QPSTypeInfo firstArgRefType;

    std::shared_ptr<QPSToken> secondArg;
    QPSTokenType::QPSTypeInfo secondArgRefType;
};


#endif //SPA_RELATIONSHIPCLAUSE_H
