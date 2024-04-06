//
// Created by tohzh on 6/4/2024.
//

#ifndef SPA_WITHCONSTRAINTDIRECTOR_H
#define SPA_WITHCONSTRAINTDIRECTOR_H

#include "with_builders/WithConstraintBuilder.h"

class WithConstraintDirector {
public:
    static std::shared_ptr<Constraint> process(std::shared_ptr<WithClause>, shared_ptr<QueryObject>);
};


#endif //SPA_WITHCONSTRAINTDIRECTOR_H
