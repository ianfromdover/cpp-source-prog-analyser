#ifndef TESTWRAPPER_H
#define TESTWRAPPER_H

#include <string>
#include <iostream>
#include <list>

// include your other headers here
#include "AbstractWrapper.h"
#include "pkb/apis/PopulatePkb.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/QPS.h"
#include "sp/SourceProcessor.h"
#include "sp/api/affects/Affects.h"
#include "sp/api/nextt/NextT.h"

class TestWrapper : public AbstractWrapper {
private:
    std::shared_ptr<PkbStorage> pkb;
    std::shared_ptr<PopulatePkb> populatePkb;
    std::shared_ptr<QueryPkb> queryPkb;
    SourceProcessor sp;
    QPS qps;
    std::shared_ptr<Affects> affects;
    std::shared_ptr<NextT> nextT;

public:
    // default constructor
    TestWrapper()
        : pkb(std::make_shared<PkbStorage>()),
          populatePkb(std::make_shared<PopulatePkb>(pkb)),
          queryPkb(std::make_shared<QueryPkb>(pkb)),
          sp(populatePkb),
          qps(queryPkb) {}

    // destructor
    ~TestWrapper();

    // method for parsing the SIMPLE source
    virtual void parse(std::string filename);

    // method for evaluating a query
    virtual void evaluate(std::string query, std::list<std::string>& results);
};

#endif