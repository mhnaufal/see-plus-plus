#ifndef SHE_PLUS_PLUS_OOP_H
#define SHE_PLUS_PLUS_OOP_H

#include <iostream>

class Enemy {
public:
  Enemy(); // default constructor
  Enemy(int x_coordinate, int y_coordinate, float spawn_time);
  Enemy(Enemy &&var) = default;
  Enemy(const Enemy &var) = default;
  Enemy &operator=(Enemy &&var) = default;
  Enemy &operator=(const Enemy &var) = default;
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

#endif // SHE_PLUS_PLUS_OOP_H
