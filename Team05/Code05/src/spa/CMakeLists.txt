file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_library(spa ${srcs} ${headers}
        src/pkb/constraintTables/ParentTable.cpp
        src/utilSpa/base_exception/BaseException.h
        src/sp/ProgramVisitor.cpp
        src/sp/ProgramVisitor.h
        src/sp/SemanticAnalyzer.cpp
        src/sp/SemanticAnalyzer.h
        src/sp/SemanticAnalysisException.h)

# this makes the headers accessible for other projects which uses spa lib
target_include_directories(spa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


