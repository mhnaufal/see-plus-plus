// #include "Basic-CPP/basic.h"
#include <basic.h> // we can use this because we use `target_include_directories` in root CMakeLists.txt
#include <iostream>
#include <modern.h>

int main() {
  /* BASIC */
  std::cout << "[BASIC]" << std::endl;
  create_response();
  create_base_data(10);
  read_file_to_string();
  append_to_file();
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;
  /* MODERN */
  std::cout << "[MODERN]" << std::endl;
  some_cool_things();
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;
  /* OOP */
  std::cout << "[OOP]" << std::endl;
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;
  return 0;
}
