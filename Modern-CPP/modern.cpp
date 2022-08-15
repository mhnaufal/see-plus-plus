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

void print_bird(Bird bird) {
  std::cout << "x coordinate: " << bird.x_coordinate << "\n"
            << "y coordinate: " << bird.y_coordinate << "\n"
            << "speed: " << bird.speed << "\n";
  std::cout << std::endl;
}

void Bird::fly(Bird bird) {
  std::cout << "I fly with speed " << bird.speed << " km/s" << std::endl;
}

void hello_func_pointer(int num) {
  std::cout << "Hello mom 😍 " << num << std::endl;
}

void PrintValue(int value) { std::cout << value << " "; }

void ForEach(const std::vector<int> &values, void (*func)(int)) {
  for (int value : values) {
    func(value);
  }
  std::cout << std::endl;
}

int lambdas(const std::vector<int> &values) {
  auto iterators = std::find_if(values.begin(), values.end(),
                                [](int value) { return value > 5; });
  std::cout << "lambda: " << *iterators << std::endl;
  return *iterators;
}
