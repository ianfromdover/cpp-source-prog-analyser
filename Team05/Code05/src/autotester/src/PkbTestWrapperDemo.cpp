//
// Demo for how to instantiate PKB classes
// Created by Ian on 12/2/24.
// Not meant to be run, just to show the code
// To copy and paste into actual TestWrapper.cpp
//
#include "TestWrapper.h"

// include these classes
#include "pkb/PKBStorage.h"
#include "pkb/PopulatePKB.h"
#include "pkb/QueryPKB.h"

TestWrapper::TestWrapper() {
    // instantiate in this order
    shared_ptr<PKBStorage> ps = make_shared<PKBStorage>();
    PopulatePKB pp(ps);
    QueryPKB pq; // TODO: yew meng probably needs a reference to the PKBStorage so this one might need to edit
}
