#ifndef SHE_PLUS_PLUS_MODERN_H
#define SHE_PLUS_PLUS_MODERN_H

#include <optional>
#include <vector>

// type
struct Bird {
  int x_coordinate;
  int y_coordinate;
  int speed;
  static void fly(Bird); // we can create function, but it's not recommended
};

void some_cool_things();
std::optional<std::string> pick_character(int id_monster);
void print_bird(Bird bird);

// function pointer
void hello_func_pointer(int num);
void PrintValue(int value);
void ForEach(const std::vector<int> &values, void (*func)(int));

#endif // SHE_PLUS_PLUS_MODERN_H
