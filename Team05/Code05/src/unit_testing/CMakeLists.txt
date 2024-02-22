file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_executable(unit_testing ${srcs}
        ../spa/src/utilSpa/base_exception/BaseException.h
        src/unit/sp/test/ReadExtractorTest.cpp
        src/unit/sp/test/CallExtractorTest.cpp)

target_link_libraries(unit_testing spa)

