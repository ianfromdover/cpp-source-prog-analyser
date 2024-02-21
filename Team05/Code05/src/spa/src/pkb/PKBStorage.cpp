#include "PKBStorage.h"

PKBStorage::PKBStorage() {
    parentTable = std::make_unique<ParentTable>();
    followsTable = std::make_unique<FollowsTable>();
    followsTTable = std::make_unique<FollowsTTable>();
}
