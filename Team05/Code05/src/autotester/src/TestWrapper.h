#ifndef TESTWRAPPER_H
#define TESTWRAPPER_H

#include <string>
#include <iostream>
#include <list>

// include your other headers here
#include "AbstractWrapper.h"
#include "sp/SourceProcessor.h"
#include "sp/RelationExtractor.h"
#include "pkb/apis/QueryPKB.h"
#include "qps/QPS.h"

class TestWrapper : public AbstractWrapper {
private:
    std::shared_ptr<PKBStorage> p=std::make_shared<PKBStorage>();
    std::shared_ptr<PopulatePKB> pkb = make_shared<PopulatePKB>(p);
    SourceProcessor sp = SourceProcessor(pkb);
    QueryPKB pkb1 = QueryPKB(p);
    QPS qps = QPS(std::make_shared<QueryPKB>(pkb1));

//    PKB pkb;
//    PopulatePKB popPkb;
//    QueryPKB queryPkb;
//    PKBStub pkb;
//    QPS qps;
public:
    // default constructor
    TestWrapper();

//        sp = SourceProcessor(nullptr);
//        pkb = PKB(1);
//        popPkb = PopulatePKB(1);
//        queryPkb = QueryPKB(1);
//        std::vector<std::string> ls = {"s1","s2"};
//        pkb = PKBStub(ls);
//        qps = QPS(pkb);

    // destructor
    ~TestWrapper();

    // method for parsing the SIMPLE source
    virtual void parse(std::string filename);

    // method for evaluating a query
    virtual void evaluate(std::string query, std::list<std::string>& results);
};

#endif