#include "includes/curl.hpp"
#include <iostream>

int main() {
  curl curl{};
  std::cout << curl.get("https://lyubenk.com") << std::endl;
}
