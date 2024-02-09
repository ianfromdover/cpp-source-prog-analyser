file(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/utilSpa/SpaTypes.h
        src/pkb/PKB.cpp
        src/pkb/PopulatePKB.h
        src/pkb/PopulatePKB.cpp
        src/pkb/QueryPKB.h
        src/pkb/QueryPKB.cpp
        src/pkb/entityTables/StmtTable.h
        src/pkb/entityTables/StmtTable.cpp
        src/pkb/entityTables/ParentTable.cpp
        src/utilSpa/DoubleMap.h
        src/utilSpa/DoubleMap.cpp)
# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


