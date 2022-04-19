#include "../../includes/html.hpp"
#include <algorithm>
#include <memory>
namespace html {
// TODO Refactor
std::vector<std::string> void_nodes = {
    "area", "base", "br", "col", "hr", "img", "input", "link", "meta", "param"};

// TODO Refactor into something less complex
std::shared_ptr<node> node::to_tree(std::string &&html) {
  return to_tree(html);
}
std::shared_ptr<node> node::to_tree(std::string &html) {
  std::shared_ptr<node> root;
  std::vector<std::shared_ptr<node>> tag_stack;
  bool in_tag = false;
  bool is_closing_tag = false;
  bool has_attrs = false;

  size_t html_len = html.size();
  for (size_t i = 0; i < html_len; ++i) {
    const char c = html.at(i);
    switch (c) {
    // Opening node setup
    case '<': {
      if (tag_stack.size() > 0 && tag_stack.back()->children.size() > 0)
        printf("Text tag: '%s'\n",
               tag_stack.back()->children.back()->name.c_str());
      // TODO Add better error handling
      if (in_tag)
        printf("Invalid taggin\n");

      printf("Tags: [ ");
      for (const auto &tag : tag_stack) {
        printf("%s ", tag->name.c_str());
      }
      printf("]\n");

      // Check if closing tag
      if (i + 1 < html_len && html.at(i + 1) == '/') {
        is_closing_tag = true;
      } else {
        // else push new empty node
        tag_stack.push_back(std::make_shared<node>());
      }

      in_tag = true;
      break;
    }
    // Closing node cleanup
    case '>': {
      // On closing tag
      if (tag_stack.size() > 1) {
        std::shared_ptr<node> popped = tag_stack.back();
        if (is_closing_tag) {
          // Get latest tag
          tag_stack.pop_back();

          // if (tag_stack.size() > 0) {
          // Assumes last tag is the same
          // as the opening tag so adds
          // popped tag to children

          // TODO: Figure out to where
          // the child should be added to
          tag_stack.back()->children.push_back(popped);
          is_closing_tag = false;
          // }
        } else if (std::find(void_nodes.begin(), void_nodes.end(),
                             popped->name) != void_nodes.end()) {
          tag_stack.pop_back();
          tag_stack.back()->children.push_back(popped);
        }
      }

      // If the next character
      // is not a new node
      if (i + 1 < html_len && html.at(i + 1) != '<') {
        // Add a "node" for raw text
        tag_stack.back()->children.push_back(std::make_shared<node>());
        tag_stack.back()->children.back()->is_text_node = true;
      }

      // Set root to first element, if not set
      if (root.get() == nullptr && tag_stack.size() > 0) {
        root = tag_stack.front();
      }

      // Leaving tag and clearing flags
      in_tag = false;
      has_attrs = false;
      break;
    }
    // Writing characters
    default: {
      // Only if there are any tags
      if (tag_stack.size() > 0) {
        if (is_closing_tag) {
          // Do nothing for closing tag
        } else if (in_tag) {
          // Check for potential attributes
          if (!has_attrs && c == ' ') {
            has_attrs = true;
          }

          if (has_attrs) {
            // TODO Implement attribute state machine
            tag_stack.back()->attrs["attrs"].push_back(c);
          } else {
            // If it ain't attributes,
            // then it's a name
            tag_stack.back()->name.push_back(c);
          }

        } else {
          // If it ain't a tag, then
          // it's raw text
          // am pushing to name, as
          // there isn't a pure textnode
          const auto &child = tag_stack.back()->children.back();
          child->name.push_back(c);
        }
      }
      break;
    }
    }
  }
  return root;
}
} // namespace html