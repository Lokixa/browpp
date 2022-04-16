set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
add_compile_options(
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Og;-Wall;-Wextra;-Wshadow;-Wunused;-pedantic;-Weffc++>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
add_library(html html.cc)
add_library(curlpp curlpp.cc)
target_link_libraries(curlpp PUBLIC curl)