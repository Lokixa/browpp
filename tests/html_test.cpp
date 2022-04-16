#include "../includes/html.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HTMLTest, BasicAssertions) {
  html::html_tree tree{""};
  EXPECT_EQ(tree.getby_id(""), nullptr);
}
