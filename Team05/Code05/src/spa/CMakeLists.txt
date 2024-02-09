file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/QPS/QueryPreprocessor/ConcreteQueryBuilder.cpp
        src/QPS/QueryPreprocessor/ConcreteQueryBuilder.h
        src/QPS/QueryPreprocessor/DeclarationComponent.cpp
        src/QPS/QueryPreprocessor/DeclarationComponent.h
        src/QPS/QueryPreprocessor/DeclarationHandler.cpp
        src/QPS/QueryPreprocessor/DeclarationHandler.h
        src/QPS/QueryPreprocessor/SelectHandler.cpp
        src/QPS/QueryPreprocessor/SelectHandler.h
        src/QPS/QueryPreprocessor/RelationshipConstraintHandler.cpp
        src/QPS/QueryPreprocessor/RelationshipConstraintHandler.h
        src/Utils/Utils.cpp
        src/Utils/Utils.h)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


