#include "pointer.h"
#include <iostream>
#include <utility>

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

/* It is not directly correlate with pointer (it's class and object thing), but
 * put it inside pointer part is the correct thing to do */
class Pokemon {
private:
  std::string name_;

public:
  Pokemon() : name_("Pocketol") {}
  explicit Pokemon(std::string name) : name_(std::move(name)) {}
  [[nodiscard]] const std::string &getName() const { return name_; }
};

void play_pokemon() {
  /* Allocate object in static world
   * no need to manually delete because it will automatically get deleted when
   * goes out of scope, object can only live inside the scope */
  {
    Pokemon pk1;
    std::cout << "pk1 name: " << pk1.getName() << std::endl;
  }
  //  std::cout << "pk1 name: " << pk1.getName() << std::endl; // ERROR: beside
  //  the variable pk1 is undeclared, the
  // object in static world is already dead too

  /* Allocate object in heap world
   * need to manually call delete, object can live even already out of scope */
  auto *pk2 = new Pokemon("Fire Blast");
  std::cout << "pk2 name: " << pk2->getName() << std::endl;
  delete pk2;

  std::cout << std::endl;
}