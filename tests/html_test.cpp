#include "../includes/html.hpp"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HTMLTest, AssertionOnEmpty) {
  html::html_tree tree{""};
  // No shared_ptr to point to. (i.e. empty)
  EXPECT_TRUE(tree.getby_id("").use_count() == 0);
}
TEST(HTMLTest, BasicHTML) {
  html::html_tree tree{
      R"(<!doctype html>
<html>
<head>
    <title>Example Domain</title>

    <meta charset="utf-8" />
    <meta http-equiv="Content-type" content="text/html; charset=utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <style type="text/css">
    body {
        background-color: #f0f0f2;
        margin: 0;
        padding: 0;
        font-family: -apple-system, system-ui, BlinkMacSystemFont, "Segoe UI", "Open Sans", "Helvetica Neue", Helvetica, Arial, sans-serif;
        
    }
    div {
        width: 600px;
        margin: 5em auto;
        padding: 2em;
        background-color: #fdfdff;
        border-radius: 0.5em;
        box-shadow: 2px 3px 7px 2px rgba(0,0,0,0.02);
    }
    a:link, a:visited {
        color: #38488f;
        text-decoration: none;
    }
    @media (max-width: 700px) {
        div {
            margin: 0 auto;
            width: auto;
        }
    }
    </style>    
</head>

<body>
<div>
    <h1>Example Domain</h1>
    <p>This domain is for use in illustrative examples in documents. You may use this
    domain in literature without prior coordination or asking for permission.</p>
    <p><a href="https://www.iana.org/domains/example">More information...</a></p>
</div>
</body>
</html>)"};

  ASSERT_EQ(tree.getby_type("html").size(), 1);
  ASSERT_EQ(tree.getby_type("body").size(), 1);
  ASSERT_EQ(tree.getby_type("a").size(), 1);
}
