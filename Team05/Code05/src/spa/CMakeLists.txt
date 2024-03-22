file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/qps/query_builder/constrain_builder/NextConstraintBuilder.h
        src/qps/query_elements/constraint/NextConstraint.h
        src/sp/extractor/cfg_extractor/NextExtractor.cpp
        src/sp/extractor/CfgExtractor.h)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

