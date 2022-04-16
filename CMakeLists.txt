cmake_minimum_required(VERSION 3.15)
project(browpp VERSION 0.01)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(br main.cpp)
target_include_directories(br PUBLIC "${PROJECT_BINARY_DIR}")

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(br INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Og;-Wall;-Wextra;-Wshadow;-Wunused;-pedantic;-Weffc++>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

add_subdirectory(src)
add_subdirectory(tests)