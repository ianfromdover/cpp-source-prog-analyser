file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")

add_library(spa ${srcs} ${headers}
        src/qps/QueryProjector/Formattable.cpp
        src/qps/query_elements/constraint_argument/entity_reference/QuotedIdentity.cpp
        src/qps/query_elements/constraint_argument/entity_reference/QuotedIdentity.h)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


