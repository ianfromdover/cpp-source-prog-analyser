//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_PKBSTORAGE_H
#define SPA_PKBSTORAGE_H
#include "pkb/tables/entity/FollowsTable.h"
#include "pkb/tables/entity/ReadTable.h"

class PKBStorage {
public:
    PKBStorage() = default;

    FollowsTable followsTable;
    ReadTable readTable;


};


#endif //SPA_PKBSTORAGE_H
