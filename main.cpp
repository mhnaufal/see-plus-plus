// #include "Basic-CPP/basic.h"
#include <basic.h> // we can use this because we use `target_include_directories` in root CMakeLists.txt
#include <iostream>
#include <modern.h>
#include <oop.h>
#include <pointer.h>

int main() {
  /* BASIC */
  std::cout << "[BASIC]" << std::endl;
  create_response();
  create_base_data(10);

  read_file_to_string();
  //  append_to_file();

  std::string hello = "Hello ", mom = "mom!", world = "world!";
  print(hello);          // "hello" is a lvalue
  print("world!");       // "world!" is an rvalue
  print(std::move(mom)); // "mom!" is an rvalue
  //  print(std::move(mom)); // WARN = don't ever to try access variable "mom"
  //  again!

  std::string firstname = "Mr", lastname = "X";
  print_name("Mr. X");
  print_name(firstname + lastname); // we can do this because we use const in
                                    // the parameter of the function
  // print_full_name(firstname); // ERROR: because this function only accept
  // rvalue reference
  print_full_name(firstname + lastname); // we input rvalue as the argument
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;

  /* MODERN */
  std::cout << "[MODERN]" << std::endl;
  some_cool_things();

  Bird bird{
      bird.x_coordinate = 10,
      bird.y_coordinate = 9,
      bird.speed = 8,
  };
  Bird::fly(bird);
  print_bird(bird);
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;

  /* OOP */
  std::cout << "[OOP]" << std::endl;
  Enemy enemy{3, 5, 1.2};
  std::cout << enemy << std::endl;

  SmallEnemy sm(3, 9.9); // SmallEnemy only need to specify 2 arguments instead
                         // of 3 like Enemy
  std::cout << "small-enemy: " << sm << std::endl;
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;

  /* POINTER */
  std::cout << "[POINTER]" << std::endl;
  basic_pointer();
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;
  return 0;
}
