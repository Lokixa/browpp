#pragma once
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace html {
struct node {
  std::string name;
  std::vector<std::shared_ptr<node>> children;
  std::map<std::string, std::string> attrs;
  // TODO Refactor
  bool is_text_node = false;
  bool is_void_node = false;
  node() : name{}, children{}, attrs{} {}

  static std::shared_ptr<node> to_tree(std::string &html);
  static std::shared_ptr<node> to_tree(std::string &&html);
};

class html_tree {
  std::shared_ptr<node> root;

public:
  html_tree(std::string &html_text) : root{node::to_tree(html_text)} {}

  html_tree(std::string &&html_text)
      : root{node::to_tree(std::move(html_text))} {}

  std::vector<std::weak_ptr<node>> getby_type(std::string_view type);
  std::weak_ptr<node> getby_id(std::string_view id);

  void display();
};

} // namespace html