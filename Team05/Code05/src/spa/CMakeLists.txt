file(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/qps/query_elements/QueryObject.cpp
        src/qps/query_elements/QueryObject.h
        src/qps/query_elements/QueryObject.h
        src/qps/query_elements/Returnable.h
        src/qps/query_elements/Returnable.h
        src/qps/query_elements/Constraint.h
        src/qps/query_elements/QueryEnums.h
        src/qps/query_elements/QueryEnums.cpp
        src/qps/query_elements/Entity.h
        src/qps/query_elements/Entity.h
        src/qps/query_elements/Declaration.h
        src/qps/query_elements/Declaration.h
        src/qps/query_elements/ConstraintArgument.h
        src/qps/query_elements/StatementReference.h
        src/qps/query_elements/StatementReference.h
        src/qps/query_elements/StatementReference.cpp
        src/qps/query_elements/StatementReference.cpp
        src/qps/query_elements/StatementEntity.cpp
        src/qps/query_elements/StatementEntity.h
        src/qps/query_elements/StatementEntity.h
        src/qps/query_elements/ReadEntity.cpp
        src/qps/query_elements/ReadEntity.h
        src/qps/query_elements/ReadEntity.h
        src/qps/query_elements/PrintEntity.cpp
        src/qps/query_elements/PrintEntity.h
        src/qps/query_elements/AssignEntity.cpp
        src/qps/query_elements/AssignEntity.h
        src/qps/query_elements/AssignEntity.h
        src/qps/query_elements/CallEntity.cpp
        src/qps/query_elements/CallEntity.h
        src/qps/query_elements/CallEntity.h
        src/qps/query_elements/IfEntity.cpp
        src/qps/query_elements/IfEntity.h
        src/qps/query_elements/IfEntity.h
        src/qps/query_elements/WhileEntity.cpp
        src/qps/query_elements/WhileEntity.h
        src/qps/query_elements/IntegerArgument.cpp
        src/qps/query_elements/IntegerArgument.h
        src/qps/query_elements/WildCard.cpp
        src/qps/query_elements/WildCard.h
        src/qps/query_elements/WildCard.h
        src/qps/query_elements/RelationshipConstraint.cpp
        src/qps/query_elements/RelationshipConstraint.h
        src/qps/query_elements/RelationshipConstraint.h
        src/qps/query_elements/FollowsConstraint.cpp
        src/qps/query_elements/FollowsConstraint.h
        src/qps/query_elements/FollowsTConstraint.cpp
        src/qps/query_elements/FollowsTConstraint.h)
# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


