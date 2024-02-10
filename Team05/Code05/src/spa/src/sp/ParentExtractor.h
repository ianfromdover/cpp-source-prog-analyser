//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_PARENTEXTRACTOR_H
#define SPA_PARENTEXTRACTOR_H

#include "RelationExtractor.h"

class ParentExtractor: public RelationExtractor {
public:
    ParentExtractor() = default;
    void readNode() override;
    void assignNode() override;
    void ifNode() override;
    void whileNode() override;
};

#endif //SPA_PARENTEXTRACTOR_H
