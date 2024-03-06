file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_executable(unit_testing ${srcs}
        src/unit/sp/helper/TokenFactory.cpp
        src/unit/sp/test/ParserTest.cpp
        src/unit/sp/test/ExprFormatterTest.cpp)
target_link_libraries(unit_testing spa)

