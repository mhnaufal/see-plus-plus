#ifndef SHE_PLUS_PLUS_MODERN_H
#define SHE_PLUS_PLUS_MODERN_H

#include <functional>
#include <iostream>
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
int lambdas(const std::vector<int> &values);

// template
template <typename T> void PrintData(T data) {
  std::cout << "template: " << data << std::endl;
}

// const and mutable
void ConstKeyword();

class Entity {
private:
  std::string m_Name;
  mutable int m_DebugCount = 0;

public:
  // the "&" before the function name, mark that this function will return by
  // reference. The "const" after the function name indicated that this function
  // will not change any value and when get called, this function will also not
  // change any value
  [[nodiscard]] const std::string &GetName() const {
    m_DebugCount++;
    return m_Name;
  }

  int GetDebugCount() const { return m_DebugCount; }
};

void MutableKeyword();

#endif // SHE_PLUS_PLUS_MODERN_H
