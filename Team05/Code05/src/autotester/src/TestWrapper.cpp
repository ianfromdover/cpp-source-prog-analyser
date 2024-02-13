#include <fstream>
#include "TestWrapper.h"
#include "QPS/QPS.h"

// implementation code of WrapperFactory - do NOT modify the next 5 lines
AbstractWrapper* WrapperFactory::wrapper = 0;
AbstractWrapper* WrapperFactory::createWrapper() {
  if (wrapper == 0) wrapper = new TestWrapper;
  return wrapper;
}
// Do not modify the following line
volatile bool AbstractWrapper::GlobalStop = false;

// method for parsing the SIMPLE source
void TestWrapper::parse(std::string filename) {
	// call your parser to do the parsing
  // ...rest of your code...
    std::ifstream theFile;
    bool valid=false;
    theFile.open(filename);
    if (!theFile) {
        valid = false;
    }
    std::string input;
    std::string line;
    while (getline(theFile, line)) {
        input += line + "\n";
    }
    theFile.close();


    std::cout << input;
    sp.exec(input);
}

// method to evaluating a query
void TestWrapper::evaluate(std::string query, std::list<std::string>& results){
// call your evaluator to evaluate the query here
  // ...code to evaluate query...



  // store the answers to the query in the results list (it is initially empty)
  // each result must be a string.
//    std::vector<std::string> ans = this->qps.evaluate(query);
//    for(const auto s : ans){
//        results.push_back(s);
//    }
}

TestWrapper::TestWrapper() : pkb(std::shared_ptr<PKBStorage>()), sp(pkb)  {
    std::shared_ptr<PKBStorage> p;
    this->pkb = PopulatePKB(p);
    this->sp = SourceProcessor(this->pkb);
}


