#include "../includes/html.hpp"
#include <regex>

/*
<html>
<body>
<a href="#" abrakadabra="\"Diuner\""></a>
<br/>
</body>
</html>

*/
namespace html {
node node::to_tree(std::string &html) {
  node root{"html"};
  return root;
}
node node::to_tree(std::string &&html) {
  node root{"html"};
  return root;
}
node *html_tree::getby_id(std::string_view id) { return nullptr; }
std::vector<node> html_tree::getby_type(std::string_view id) {
  return std::vector<node>{};
}
} // namespace html