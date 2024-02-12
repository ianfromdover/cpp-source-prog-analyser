#ifndef TESTWRAPPER_H
#define TESTWRAPPER_H

#include <string>
#include <iostream>
#include <list>

// include your other headers here
#include "AbstractWrapper.h"

class TestWrapper : public AbstractWrapper {
private:
    SourceProcessor sp;
    PKB pkb;
    PopulatePKB popPkb;
    QueryPKB queryPkb;
    PKBStub pkb;
    QPS qps;

public:
    // default constructor
    TestWrapper() {
        sp = SourceProcessor();
        pkb = PKB(1);
        popPkb = PopulatePKB(1);
        queryPkb = QueryPKB(1);
        std::vector<std::string> ls = {"s1","s2"};
        pkb = PKBStub(ls);
        qps = QPS(pkb);
    };

    // destructor
    ~TestWrapper();
  
    // method for parsing the SIMPLE source
    virtual void parse(std::string filename);
  
    // method for evaluating a query
    virtual void evaluate(std::string query, std::list<std::string>& results);
};

#endif
