#include "../includes/curl.hpp"
#include <gtest/gtest.h>

TEST(CURLTest, BasicAssertions) {
  curl curl{};
  ASSERT_TRUE(!curl.get("https://lyubenk.com").empty());
}
