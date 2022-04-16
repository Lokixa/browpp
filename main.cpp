#include "includes/curl.hpp"
#include <iostream>
#include <string>

using std::cout;
struct Testing {
  std::string name;
  int age;
};
int main() {
  cout << "Hello! :)\n";
  Testing t {"Hello!"};
  cout << t.name;
}
