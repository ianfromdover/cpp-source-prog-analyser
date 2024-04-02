#include <fstream>
#include "TestWrapper.h"
#include "common/base_exception/BaseException.h"

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
    try {
        const auto tokens = sp.scan(input);
        const auto program = sp.parse(tokens);
        sp.validate(program);
        sp.extract(program);
        this->affects = std::make_shared<Affects>(CFG::compile(program), queryPkb);
    } catch (BaseException& exception) {
        // handle exception
        std::cerr << "Caught BaseException: " << exception.what() << std::endl;
        exit(1); // exit silently
    }
}

// method to evaluating a query
void TestWrapper::evaluate(std::string query, std::list<std::string>& results) {
// call your evaluator to evaluate the query here
  // ...code to evaluate query...
  // store the answers to the query in the results list (it is initially empty)
  // each result must be a string.
    try {
        std::vector<std::string> ans = this->qps.evaluate(query);
        for (const auto s: ans) {
            results.push_back(s);
        }
    } catch (const BaseException& exception) {
        // handle exception
        std::cerr << "Caught BaseException: " << exception.what() << std::endl;
        exit(1); // exit silently
    }
}


