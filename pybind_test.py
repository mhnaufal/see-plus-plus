import importlib

example = importlib.import_module("cmake-build-debug-wsl.example")

print("module intro: " + str(example.__doc__))
print()

print("module dir: " + str(dir(example)))
print()

print("example variable: " + example.name)
print()

print("example add result: " + str(example.add(1, 2)))
print()

print("example class: " + str(example.ExampleClass))
print()

print("example member function inside a class: " + str(example.ExampleClass(10).multiply(2)))
print()

print("example another function: " + str(example.multiply_two(3, 4)))
print()
