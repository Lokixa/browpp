#include "includes/curl.hpp"
#include "includes/html.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void is_true(std::string &&claim, bool expr) {
  printf("%s: %s\n", claim.c_str(), expr ? "Yes" : "No");
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Just URL Required\n");
    exit(1);
  }
  std::string url{argv[argc - 1]};

  curl curl;
  std::string html_text = curl.get(url.c_str());
  if (html_text.empty()) {
    printf("Not supported for now.");
    exit(1);
  }
  // printf("HTML: %s\n\n", html_text.c_str());
  html::html_tree tree{std::move(html_text)};
  tree.display();
  //   printf("Meta's: %zu", tree.getby_type("meta").size());
}
