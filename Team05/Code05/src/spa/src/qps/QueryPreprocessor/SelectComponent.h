//
// Created by Alex on 10/2/2024.
//

#ifndef SPA_SELECTCOMPONENT_H
#define SPA_SELECTCOMPONENT_H


#include "QueryComponent.h"

class SelectComponent : public QueryComponent{
public:
    void acceptBuilder(std::shared_ptr<QueryBuilder>) override;
    void setSynonym(std::string string);
private:
    std::string selectedSyn;

};


#endif //SPA_SELECTCOMPONENT_H
