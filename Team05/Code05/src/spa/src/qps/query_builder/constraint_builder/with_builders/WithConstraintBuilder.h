//
// Created by tohzh on 5/4/2024.
//

#ifndef SPA_WITHCONSTRAINTBUILDER_H
#define SPA_WITHCONSTRAINTBUILDER_H

#include "WithConstraintBuilderTemplate.h"

class WithConstraintBuilder : public WithConstraintBuilderTemplate {
private:
    shared_ptr<WithReference> arg1;
    shared_ptr<WithReference> arg2;
    void addPatternClause(std::shared_ptr<WithClause>, shared_ptr<QueryObject>);
    shared_ptr<WithReference> createWithArgument(QPSToken, QPSTokenType::QPSTypeInfo,
                                                                        QPSTokenType::QPSTypeInfo, shared_ptr<QueryObject>);
public:
    void addConstraintClause(shared_ptr<WithClause>, shared_ptr<QueryObject>);
};


#endif //SPA_WITHCONSTRAINTBUILDER_H
