// #include "Basic-CPP/basic.h"
#include <basic.h> // we can use this because we use `target_include_directories` in root CMakeLists.txt
#include <iostream>

int main() {
  std::cout << "HOME" << std::endl;

  /* BASIC */
  create_response();
  create_base_data(10);

  /* MODERN */

  return 0;
}
