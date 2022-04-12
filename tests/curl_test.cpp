#include "../includes/curl.hpp"
#include "../includes/testing.hpp"
#include <iostream>

int main() {
  curl curl{};
  assert(!curl.get("https://lyubenk.com").empty());
  return 0;
}