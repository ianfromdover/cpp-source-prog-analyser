file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/pkb/apis/QueryPKBVirtual.h
        src/utilSpa/IntColumn.h
        src/pkb/tables/relation/FollowsTable.h
        src/pkb/tables/entity/ReadTable.h
        src/pkb/tables/entity/CallTable.h
        src/pkb/tables/entity/IfTable.h
        src/pkb/tables/entity/WhileTable.h
        src/pkb/tables/entity/PrintTable.cpp
        src/pkb/tables/entity/VariableTable.cpp
        src/pkb/tables/entity/ConstantTable.cpp
        src/pkb/tables/entity/ProcedureTable.h
        src/pkb/tables/relation/FollowsTTable.h
        src/pkb/tables/relation/ParentTTable.h)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


