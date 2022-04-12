#include "../includes/html.hpp"
#include "../includes/testing.hpp"

int main() {
  html::html_tree tree{""};
  assert(tree.getby_id("") != nullptr);
  return 0;
}