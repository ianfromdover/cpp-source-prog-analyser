file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/qps/query_elements/constraint/patternConstraint/WhilePatternConstraint.cpp
        src/qps/query_elements/constraint/patternConstraint/WhilePatternConstraint.h
        src/qps/query_builder/constrain_builder/pattern_builders/WhilePatternConstraintBuilder.cpp
        src/qps/query_builder/constrain_builder/pattern_builders/WhilePatternConstraintBuilder.h
        src/qps/query_elements/constraint/patternConstraint/IfPatternConstraint.cpp
        src/qps/query_elements/constraint/patternConstraint/IfPatternConstraint.h
        src/qps/query_builder/constrain_builder/pattern_builders/IfPatternConstraintBuilder.cpp
        src/qps/query_builder/constrain_builder/pattern_builders/IfPatternConstraintBuilder.h)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


