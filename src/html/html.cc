#include "../../includes/html.hpp"
#include <memory>

namespace html {
// TODO Should make it obvious that there was no node on search for each getby_*
std::weak_ptr<node> html_tree::getby_id(std::string_view id) {
  // TODO Implement
  return std::weak_ptr<node>{};
}
std::vector<std::weak_ptr<node>> html_tree::getby_type(std::string_view type) {
  // Return empty
  if (this->root.get() == nullptr)
    return {};

  std::vector<std::weak_ptr<node>> result;

  std::vector<std::shared_ptr<node>> stack;
  stack.push_back(this->root);

  // Standard BFS
  std::shared_ptr<node> traverse;
  while (!stack.empty()) {
    traverse = stack.back();
    stack.pop_back();

    if (traverse->name == type) {
      result.push_back(traverse);
    }

    if (!traverse->children.empty()) {
      for (const auto &child : traverse->children) {
        stack.push_back(child);
      }
    }
  }

  return result;
}
} // namespace html