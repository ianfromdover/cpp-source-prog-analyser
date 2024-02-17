file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/qps/query_builder/constrainbuilders/FollowsConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/FollowsConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/FollowsTConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/FollowsTConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/ParentConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/ParentConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/ParentTConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/ParentTConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/UsesSConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/UsesSConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/UsesPConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/UsesPConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/ModifiesSConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/ModifiesSConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/ModifiesPConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/ModifiesPConstraintBuilder.h
        src/qps/query_builder/constrainbuilders/ConcretePatternConstraintBuilder.cpp
        src/qps/query_builder/constrainbuilders/ConcretePatternConstraintBuilder.h
)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


