include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
function(do_test test_name to_link)
    add_executable(
        ${test_name}
        ${test_name}.cpp
    )
    target_link_libraries(
        ${test_name}
        gtest_main ${to_link}
    )
    gtest_discover_tests(${test_name})
endfunction()

do_test(html_test html)
do_test(curl_test curlpp)
