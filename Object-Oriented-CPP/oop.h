#ifndef SHE_PLUS_PLUS_OOP_H
#define SHE_PLUS_PLUS_OOP_H

#include <iostream>

/* abstract class */
class IEnemy {
public:
  virtual void print() const = 0; // pure virtual function
  virtual void print_all()
      const; // "just" virtual function, we still need to create the definition
};

class Enemy {
public:
  Enemy(); // default constructor
  Enemy(int x_coordinate, int y_coordinate, float spawn_time);
  Enemy(Enemy &&var) = default;
  Enemy(const Enemy &var) = default;
  Enemy &operator=(Enemy &&var) = default;
  Enemy &operator=(const Enemy &var) = default;
  //  Enemy &operator=(const Enemy &var) = delete; // use = delete to delete
  //  this special function
  ~Enemy(); // destructor
  [[nodiscard]] float get_spawn_time() const { return spawn_time_; }
  [[nodiscard]] int get_x_coordinate() const { return x_coordinate_; }
  [[nodiscard]] int get_y_coordinate() const { return y_coordinate_; }

private:
  int x_coordinate_{}; // private data are ended with underscore "_"
  int y_coordinate_{};
  float spawn_time_{};
};

std::ostream &operator<<(std::ostream &os, const Enemy &enemy);

class SmallEnemy : public Enemy {
public:
  explicit SmallEnemy(int coordinate, float spawn_time)
      : Enemy(coordinate, coordinate, spawn_time) {}
};

/* Singleton pattern only allow ONE and EXACTLY ONE object in the program */
class Singleton {
private:
  Singleton() = default;
  ~Singleton() = default;

public:
  Singleton(const Singleton &) = delete;
  void operator=(const Singleton &) = delete;
  static Singleton &GetInstance() {
    static Singleton instance;
    return instance;
  }
};

#endif // SHE_PLUS_PLUS_OOP_H
