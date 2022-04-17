#include "../includes/html.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HTMLTest, AssertionOnEmpty) {
  html::html_tree tree{""};
  // No shared_ptr to point to. (i.e. empty)
  EXPECT_TRUE(tree.getby_id("").use_count() == 0);
}
TEST(HTMLTest, RegexCheck) {
  html::html_tree tree{
      R"(<html><body><a href="testing">Ahahahah</a></body></html>)"};

  ASSERT_EQ(tree.getby_type("html").size(), 1);
  ASSERT_EQ(tree.getby_type("body").size(), 1);
  ASSERT_EQ(tree.getby_type("a").size(), 1);
}
