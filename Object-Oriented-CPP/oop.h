#ifndef SHE_PLUS_PLUS_OOP_H
#define SHE_PLUS_PLUS_OOP_H

#include <iostream>

/* abstract class */
class IEnemy {
private:
  std::string m_name;

public:
  virtual void print(std::string name) const = 0; // pure virtual function
  // "only" a virtual function, we still need to create the definition
  //  virtual void print_all() const;
};

class BossEnemy : IEnemy {
public:
  explicit BossEnemy(const int power) {
    std::cout << "Boss power: " << power << std::endl;
  }

  void print(std::string name) const override {
    std::cout << "I, " << name << ", am your fucking Boss!" << std::endl;
  }
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

void oopPlayground();

#endif // SHE_PLUS_PLUS_OOP_H
