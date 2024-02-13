#include "PKBStorage.h"

PKBStorage::PKBStorage() {
    parentTable = std::make_unique<ParentTable>();
}
