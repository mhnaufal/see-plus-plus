// #include "Basic-CPP/basic.h"
#include <basic.h> // we can use this because we use `target_include_directories` in root CMakeLists.txt
#include <iostream>
#include <modern.h>
#include <nodeflux.h>
#include <oop.h>
#include <pointer.h>

int main() {
  /* BASIC */
  std::cout << "[BASIC]" << std::endl;
  create_response();
  create_base_data(10);

  // File
  read_file_to_string();
  //  append_to_file();

  // lvalue and rvalue
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
  std::cout << std::endl;

  // enum
  std::cout << "enum token: \n";
  print_token_type();
  std::cout << std::endl;

  // union
  std::cout << "union: \n";
  dataType();
  std::cout << std::endl;
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;

  /* MODERN */
  std::cout << "[MODERN]" << std::endl;
  // type
  some_cool_things();

  Bird bird{
      bird.x_coordinate = 10,
      bird.y_coordinate = 9,
      bird.speed = 8,
  };
  Bird::fly(bird);
  print_bird(bird);
  std::cout << std::endl;

  // function pointer
  auto call_func = hello_func_pointer;
  // typedef void(*HelloFuncPointer)(int); // this is same with previous one
  call_func(313);
  std::vector<int> values = {1, 3, 5, 2, 8};
  ForEach(values, PrintValue);
  lambdas(values);
  std::cout << std::endl;

  // template
  PrintData<int>(300);
  PrintData<float>(30.3);
  std::cout << std::endl;

  // const and mutable
  ConstKeyword();
  std::cout << std::endl;
  MutableKeyword();
  std::cout << std::endl;
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
  // raw pointer
  std::cout << "raw pointer: \n";
  basic_pointer();
  play_pokemon();

  // smart pointer
  std::cout << "smart pointer: \n";
  smartPointer();
  std::cout << std::endl;
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;

  /* Nodeflux */
  std::cout << "[NODEFLUX]" << std::endl;
  MsgPackMain();
  std::cout << std::endl;
  std::cout << "+-----------------------------------+" << std::endl
            << std::endl;
  return 0;
}
