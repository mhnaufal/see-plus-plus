#include <pybind11/pybind11.h>

namespace py = pybind11;

std::string name = "John Wick";

int add(int i, int j) { return i + j; }

class ExampleClass {
  float multiplier;

public:
  explicit ExampleClass(float multiplier_) : multiplier(multiplier_) {}
  [[nodiscard]] float multiply(float input = 2) const {
    return input * multiplier;
  }
};

PYBIND11_MODULE(example, handler) {
  // export doc
  handler.doc() =
      "Homemade pybind11 module implemented using C++ (of course) 🙃";

  // export variable
  handler.attr("name") = name;

  // export function
  handler.def("add", &add, "A function that adds two numbers");

  // export class
  py::class_<ExampleClass>(handler, "ExampleClass")
      .def(py::init<float>()) // export constructor
      .def("multiply", &ExampleClass::multiply,
           py::arg("input") = 2); // export function member
}
