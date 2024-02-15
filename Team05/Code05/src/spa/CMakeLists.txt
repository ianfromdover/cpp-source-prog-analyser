file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/qps/query_elements/constraint_argument/expression_reference/ExpressionReference.cpp
        src/qps/query_elements/constraint_argument/expression_reference/ExpressionReference.h
        src/qps/query_elements/constraint_argument/expression_reference/ExpressionSpec.cpp
        src/qps/query_elements/constraint_argument/expression_reference/ExpressionSpec.h
        src/qps/query_elements/constraint/UsesSConstraint.cpp
        src/qps/query_elements/constraint/UsesSConstraint.h
        src/qps/query_elements/constraint/UsesPConstraint.cpp
        src/qps/query_elements/constraint/UsesPConstraint.h
        src/qps/query_elements/constraint/ModifiesSConstraint.cpp
        src/qps/query_elements/constraint/ModifiesSConstraint.h
        src/qps/query_elements/constraint/ModifiesPConstraint.cpp
        src/qps/query_elements/constraint/ModifiesPConstraint.h
        src/qps/query_elements/constraint_argument/statement_reference/StatementRefWIldCard.cpp
        src/qps/query_elements/constraint_argument/statement_reference/StatementRefWIldCard.h
        src/qps/query_elements/constraint/ConcretePatternConstraint.cpp
        src/qps/query_elements/constraint/ConcretePatternConstraint.h)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


