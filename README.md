# 🕵️‍ She-Plus-Plus

_Because it's hard to understand her, I'll try to understand C++ instead_
_and it turns out that a lot of Rust's concept, borrowed from C++_

## 📚 Knowledge Gained

### 1️⃣ Build C++

There are 3 options to compile and run C++ file(s)

- Using command line
- Using Makefile
- **Using CMake**

Maybe there's another options, but all I know for now are those 3 options.

1. **CMake**

   To build C++ file using CMake, create a `CMakeLists.txt` inside the top level of the directory.
   After that run

   ```cmake
   cmake [options] -S <path-to-source> -B <path-to-build>
   ```

   ```cmake
   cmake -S . -B build
   ```

   run cmake based on configuration file located inside **.** (current directory) and placed the result inside **build**
   directory

   or sometime people used to use this kind of setup

   Create a directory called **build** and `cd` into it

   ```shell
   mkdir build
   cd build
   ```

   Run `cmake`. **..** means, run cmake with source file (CMakeLists.txt) is located in previous directory and placed
   the
   result inside this directory

   ```cmake
   cmake ..
   ```

2. **CMake Syntax**

   The hard part are the **cmake syntax** and **connect multiple C++ files**
   [CMake CheatSheet](https://usercontent.one/wp/cheatsheet.czutro.ch/wp-content/uploads/2020/09/CMake_Cheatsheet.pdf)

   **Must** have configurations in **CMakeLists.txt** file:
    - `cmake_minimum_required(VERSION 3.10)`
    - `project(project_name)`
    - `add_executable(project_name, list_of_cpp_source_file)`
    - `target_include_directories(project_name visibility list_of_directory)`: use this so that we can use *#include <
      directory_name>* instead of normal double quotes
    - `target_link_directories(project_name visibility list_of_directory)`
    - `target_link_libraries(project_name, list_of_library)`
    - `add_library(library_name list_of_cpp_file)`: use this inside the sub folder to make this sub folder as a library
      so that the parent cmake can connect it

3. **CMake Levels**

   What happen if we want to link our executables that placed in a different folder/sub folder? Basically, we need to **
   create a CMakeLists.txt** inside that sub folder.

   **In root CMakeLists.txt** add this:
    - `add_subdirectory()`: only accept 1 directory as the parameter
    - `target_include_directories()`
    - `target_link_directories()`
    - `target_link_libraries()`

   **In the sub folder CMakeLists.txt** add this:
    - `add_library()`

### 2️⃣ Basic C++

1. **C++ Term**

    - **Translation Unit**
      There are a bunch of definitions about this, but for me it's **A source file after includes with header files and
      other conditional preprocessing**
    - **Class** and **Struct**
      `class` and `struct` in C++ define a **new type**. Use `struct` as a data container without any function within,
      and use `class` as data container with function. Although we can create function inside struct.
    - **Static**
      `static` functions and data are functions and data that are only visible within the same translation unit. In C++
      class, we use `::` double colon to access them.
    - **using**
      `using` to shorten your code!

2. **File**

   We can read, write, and append from a file in _ASCII_ format and _binary format_.
   It's a lot and I have practice it,
   so [go ahead to this](https://www.delftstack.com/howto/cpp/how-to-append-text-to-a-file-in-cpp/) instead.

3. **lvalue** and **rvalue**
    - `lvalue` = written in the **left** of assigment operator **=**
    - `rvalue` = written in the **right** of assigment operator **=**. Explicit `rvalue` defined using `&&`
       ```c++
       int b = a + 2;
       ```
      _b_ is lvalue and _a + 2_ is rvalue.
       ```c++
       int&& c = std::move(b);
       ```
      _b_ is initially and lvalue, but then we use `std::move()` to change it into rvalue, and then we put the result in
      a _c_ which is an rvalue because we moved it from lvalue into rvalue using _&&_
    - `std::move(x)` = means "give me an **rvalue reference to x**". It can be said that `std::move()` is an **
      ownership** (rusty thing 🦀). [Nice read](https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/)

### 3️⃣ Object Oriented C++

1. **Class**
   In other OOP programming languages, we call functions inside a class as **methods**, but here in C++ we called it **
   Member Functions**. Also applies for **attributes**, we call it **Data Members**. Class members are **private** by
   default, not like Struct where they are **public** by default.

   Class need **at least one constructor** and **exactly one destructor**.

   **Const correctness**: `const` after function name state that this function does not change the object. It's not only
   for functions but other things to correct too. Only available for member functions!
   example:
   ```c++
   const std::string name() const {
      return name_;
   }
   ```
   The first `const` ack as the return type and the second `const` mark that this function will not change the object.

2. **Operator Overloading**
   Operator in C++ it's just another function with the word **operator**.

   Format: `<RETURN_TYPE> operator<NAME>(<PARAMS>)`

   where <NAME> are one of `>, <, =, ==, <<`. For example if we create a `<<` operator overloading, so when
   using `std::cout <<` we don't need to specify the elements that we want to print (look in code example for more clear
   explanation!)

3. **Class Special Functions**
   There are 6 class special functions and compiler already **generate them** automatically if we don't specify one.
   However, if we specify at least one, the compiler will not generate the rest. One for None.

### 4️⃣ Testing C++

### 5️⃣ Modern C++

1. **Map**

   Maps are always sorted according to the **key**. It means that even we randomly insert our key-value pairs, the C++
   map will automatically sort it based on the key.
   In modern C++ (C++11), we can define and access elements inside map using different signature as follows:
    - **Define**
       ```c++
       map<string, string> person { { "name", "johny depp"}, { "born", "1919" } };
       ```
    - **Access**
       ```c++
       cout << my_map.at("name");
       ```
      will result
       ```shell
       "johny depp"
       ```

2. **Vector**

   In vector, we have 2 important term to know, which are **size** and **capacity**
    - **Size**: How many element already filled inside this vector
    - **Capacity**: The maximum number of elements this vector can handle

   Before the capacity reach it's maximum number, C++ will automatically expand it. To prevent this kind of behaviour,
   we
   can use **vector.reserve(int size)**

   **C++11**: To insert a new element into a vector we can use: `vector.emplace_back()`

3. **Unordered Map**

   Faster than std::map. Implemented using **hashtable** and key type must be _hashable_
    - `map.first`: same as take the key
    - `map.second`: same as take the value

4. **STL Algorithm**

   It's a lot and you can [reference it here!](https://en.cppreference.com/w/cpp/algorithm)

5. **Smart Pointer**

   [Microsoft C++](https://docs.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-170)
   One of the reason smart pointer exists is that **memory leak** that often occur in C. Modern C++ use concept
   called **RAII** (Resource Acquisition is Initialization) or in english means, **resource** (heap memory, file,
   socket) should be **owned** by an object (again, this is "rusty 🦀" thing).

6. **Move Semantic**
   Before dive into move semantic, understand **lvalue** and **rvalue** first!

99. **Other Interesting In Modern C++**

- **any**: It's a data type, but more like ANY type.
- **optional**: Function that optionally return something.
- **chrono**: Benchmark our C++ code.
- **constexpr**: Use this as a macro instead of `#define`

## 💡 Acknowledgments

Thanks to these awesome resources:

- [Nodeflux](https://www.nodeflux.io)
- [The Cherno](https://www.youtube.com/c/TheChernoProject)
- [Modern C++ Lecture](https://www.youtube.com/playlist?list=PLgnQpQtFTOGRM59sr3nSL8BmeMZR9GCIA)
- [CMake Dude](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&index=1&t=0s)
- [CLion](https://www.jetbrains.com/clion/)
