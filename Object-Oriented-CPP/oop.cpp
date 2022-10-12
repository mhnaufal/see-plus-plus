#include "oop.h"

Enemy::Enemy() = default;
Enemy::Enemy(int x_coordinate, int y_coordinate, float spawn_time) {
  x_coordinate_ = x_coordinate;
  y_coordinate_ = y_coordinate;
  spawn_time_ = spawn_time;
}
Enemy::~Enemy() = default;

std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
  return os << "x: " << enemy.get_x_coordinate()
            << " y: " << enemy.get_y_coordinate()
            << " spawn: " << enemy.get_spawn_time() << std::endl;
}

auto &singleton = Singleton::GetInstance();

void oopPlayground() {
  auto boss_enemy = BossEnemy(313);
  boss_enemy.print("Luh");
}
