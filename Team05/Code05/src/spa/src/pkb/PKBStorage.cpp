#include "PKBStorage.h"

PKBStorage::PKBStorage() {
    parentTable = std::make_unique<ParentTable>();
    parentTTable = std::make_unique<ParentTTable>();
    followsTable = std::make_unique<FollowsTable>();
    followsTTable = std::make_unique<FollowsTTable>();
}
