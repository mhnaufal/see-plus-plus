#ifndef SHE_PLUS_PLUS_OOP_H
#define SHE_PLUS_PLUS_OOP_H

class Pipe {
public:
  Pipe();  // default constructor
  ~Pipe(); // destructor
  [[nodiscard]] float get_spawn_time() const {
    return spawn_time_;
  }

private:
  int x_coordinate_{}; // private data are ended with underscore "_"
  int y_coordinate_{};
  float spawn_time_{};
};

#endif // SHE_PLUS_PLUS_OOP_H
