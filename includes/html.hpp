#pragma once
#include <map>
#include <string>
#include <string_view>
#include <vector>

namespace html {
struct node {
  const std::string name;
  std::vector<node> children;
  std::map<std::string, std::string> attrs;
  node(std::string &name) : name{name}, children{}, attrs{} {}
  node(std::string &&name) : name{std::move(name)}, children{}, attrs{} {}
  static node to_tree(std::string &html);
  static node to_tree(std::string &&html);
};

class html_tree {
  node root;

public:
  std::vector<node> getby_type(std::string_view type);
  node *getby_id(std::string_view id);
  html_tree(std::string &html_text) : root{node::to_tree(html_text)} {}
  html_tree(std::string &&html_text)
      : root{node::to_tree(std::move(html_text))} {}
};

} // namespace html