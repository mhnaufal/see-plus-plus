#include "pointer.h"
#include <iostream>

void basic_pointer() {
  int *null_ptr; // initialize a pointer using "*" next to variable name
  std::cout << null_ptr << std::endl;

  int level = 1;
  null_ptr = (int *)level; // WARN: we can set null_ptr to a non memory address
                           // value, but it's a stupid things to do, however at
                           // least you know that we can do this
  std::cout << null_ptr << std::endl;

  null_ptr = &level; // set the variable null_ptr point to a memory address
  std::cout << null_ptr << std::endl;

  int &ref =
      *null_ptr; // "*" in null_ptr means we dereference memory address pointed
                 // by null_ptr, and we will get the original value back
                 // "&" reference to another variable. Reference it's just a
                 // way to give a memory address/variable another name
  std::cout << null_ptr << " " << ref << std::endl;

  int &ref2 = level;
  level = 2;
  std::cout << null_ptr << " " << ref2 << std::endl;

  // reference need to point to an EXISTING variable
  // it means that we cant create a new reference variable and put a new value
  // on it. Reference doesn't have actual memory, because IT IS JUST A REFERENCE
  // int &ref2 = 2; // ERROR: lvalue of type int& with rvalue of type int

  int score = 100;
  increase(score);
  std::cout << "score: " << score << std::endl;
}

void increase(int &score) { score++; }