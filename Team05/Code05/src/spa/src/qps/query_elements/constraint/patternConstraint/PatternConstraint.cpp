//
// Created by tohzh on 10/2/2024.
//

#include "PatternConstraint.h"
#include "pkb/apis/QueryPKB.h"


std::string PatternConstraint::getConstraintClass() {
    return CONSTRAINT_CLASS_PATTERN;
}

std::string& PatternConstraint::stripCharacters(std::string& str, const std::string& chars) {
    // Find the first character position after excluding leading characters
    std::size_t first = str.find_first_not_of(chars);
    if (first == std::string::npos) {
        // If there are no characters other than the ones to strip, return an empty string
        return str = "";
    }

    // Find the position of the last character not matching the strip characters
    std::size_t last = str.find_last_not_of(chars);

    // Erase the leading and trailing characters
    str = str.substr(first, (last - first + 1));

    return str;
}

Table PatternConstraint::getFullTable(QueryPkbVirtual &pkb){
    std::vector<std::shared_ptr<ConstraintArgument>> args = getConstraintArguments();
    std::string lhsEntityType = args[0] -> getEntityType();
    std::string rhsEntityType = TYPE_NONE;
    if (args.size() > 1) {
        rhsEntityType = args[1] -> getEntityType();
    }
    ResultTable rt;
    rt.add(getPatternConstraintIdentifier()->getEntityTable(pkb));
    if (getPatternConstraintIdentifier()->getEntityType()==TYPE_ASSIGN) {
      Table temp = rt.getTable();
      temp.erase(temp.begin()); // erase header
      Table temp1;
      for (const auto &entry : temp) {
        std::string stmtNo = entry[0];
        std::string lhs = entry[1].substr(0, entry[1].find('='));
        std::string rhs = entry[1].substr(entry[1].find('=') + 1);
        temp1.push_back({stmtNo, lhs, rhs});
      }
      temp1.insert(temp1.begin(),
                   {getPatternConstraintIdentifier()->getIdentifier(),
                    HEADER_ASSIGNLHS, HEADER_ASSIGNRHS});
      rt = ResultTable(temp1);
    }
    rt.removeAllColumnsExceptIndex(0);

    if (isStatementOrEntitySynonym(lhsEntityType) || isStatementOrEntitySynonym(rhsEntityType)) {

        if (isStatementOrEntitySynonym(lhsEntityType)) {
          rt.replaceHeader(1,args[0]->getArgumentValue()[0]);
          rt.add(args[0]->getEntityTable(pkb));
        }
        if (isStatementOrEntitySynonym(rhsEntityType)) {
            rt.add(args[1]->getEntityTable(pkb));
        }
        return rt.getTable();;
    } else {
        return getTableWithDefaultHeadersFromPkb(pkb);
    }
}

bool PatternConstraint::isDefaultHeaders(std::vector<std::string> header) {
    return header == this->getDefaultHeaders();
}

Table PatternConstraint::getRelationshipTable(QueryPkbVirtual & pkb) {
    if (this->getNot()) {
        Table wholeSet = getFullTable(pkb);
        Table subSet = getTable(pkb);
        if (!subSet.empty() && isDefaultHeaders(subSet[0])) {
            // if is default header, constraint is 2 non-synonyms
            if (subSet.size() > 1) {
                // if there exist some entry in subset
                // not [TRUE] = [no result]
                return {{}};
            } else {
                // there exist no entry in subset
                // not [FALSE] = [all result]
                return {{HEADER_SPECIAL_ALL_RESULTS}};
            }
        }
        Table result = ResultTable::minusTable(wholeSet, subSet);
        return result;
    } else {
        return getTable(pkb);
    }
}