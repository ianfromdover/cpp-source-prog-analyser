file(GLOB_RECURSE srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")
add_executable(autotester ${srcs}
        ../spa/src/utilSpa/base_exception/BaseException.h)
target_link_libraries(autotester spa ${AUTOTESTER_LIBRARIES})

if (NOT WIN32)
    target_link_libraries(autotester pthread)
endif()
