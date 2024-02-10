//
// Created by sjh_9 on 10/2/2024.
//

#ifndef SPA_RELATIONEXTRACTOR_H
#define SPA_RELATIONEXTRACTOR_H
#include <iostream>
#include <vector>

class RelationExtractor {
private:

public:
    virtual ~RelationExtractor() = default;
    virtual void readNode();
    virtual void assignNode();
    virtual void ifNode();
    virtual void whileNode();
};


#endif //SPA_RELATIONEXTRACTOR_H
