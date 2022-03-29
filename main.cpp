#include "includes/curl.h"
#include <iostream>

int main() {
  curl curl{};
  std::cout << curl.get("https://example.com") << std::endl;
}