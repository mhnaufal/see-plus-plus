#include "modern.h"
#include <any>
#include <chrono>
#include <iostream>
#include <optional>

/**
 * I know the code in here it's not completely the modern C++ (>= C++11) syntax,
 * but at least I learn to make another CMakeLists.txt :)
 */

void some_cool_things() {
  /* [1] Any type */
  std::any any_type_var;
  std::cout << &any_type_var << std::endl;

  any_type_var = 619;
  std::cout << std::any_cast<int>(any_type_var) << std::endl;

  any_type_var = 3.14;
  std::cout << std::any_cast<double>(any_type_var) << std::endl;

  any_type_var = true;
  std::cout << std::boolalpha << std::any_cast<bool>(any_type_var) << std::endl;

  /* [2] Optional return */
  auto start_time = std::chrono::steady_clock::now();
  std::cout << pick_character(2).value_or("--[Yami Yugi]--") << std::endl;
  auto end_time = std::chrono::steady_clock::now();

  std::chrono::duration<double> second = end_time - start_time;
  std::cout << "Time to run the function: " << second.count() << "s"
            << std::endl;

  std::cout << std::endl;
}

std::optional<std::string> pick_character(int id_monster) {
  if (id_monster == 1) {
    return "--[Seto Kaiba]--";
  } else if (id_monster == 2) {
    return "--[Yami Malik]--";
  }
  return {};
}
