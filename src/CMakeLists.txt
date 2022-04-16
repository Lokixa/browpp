add_library(html html.cc)
add_library(curlpp curlpp.cc)
target_link_libraries(curlpp PUBLIC curl)