#pragma once
#include <exception>
#include <iostream>

inline void assert(bool query) {
  if (!query) {
    std::cerr << "ERROR\n";
    exit(1);
  }
}
inline void assert(bool query, const char *message_on_fail) {
  if (!query) {
    std::cerr << "ERROR: " << message_on_fail << '\n';
    exit(1);
  }
}