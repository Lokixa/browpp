cmake_minimum_required(VERSION 3.15)
project(browpp VERSION 0.01)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(COMPILE_TESTS "Compile unit tests" true)

add_executable(br main.cpp)
target_include_directories(br PUBLIC ${PROJECT_BINARY_DIR})
target_link_libraries(br html curlpp)

add_subdirectory(src)
if(COMPILE_TESTS)
    add_subdirectory(tests)
endif()